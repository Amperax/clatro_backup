#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <string>

using namespace std;

// Asegúrate de tener -lwinmm en Tools > Compiler Options > Linker

int main() {
    // IMPORTANTE: Usamos 'type mpegvideo' porque acepta comandos de volumen correctamente
    // Reemplaza "music.wav" por tu archivo (también puedes usar un .mp3 directamente)
    mciSendString("open \"prueba.wav\" type mpegvideo alias my_music", NULL, 0, NULL);

    // Volumen inicial (Escala MCI mpegvideo: 0 a 1000)
    int volume = 500; 
    string volCmd = "setaudio my_music volume to " + to_string(volume);
    mciSendString(volCmd.c_str(), NULL, 0, NULL);

    // Reproducir en bucle infinito
    mciSendString("play my_music repeat", NULL, 0, NULL);

    cout << "=========================================" << endl;
    cout << "  REPRODUCTOR CONTRALADO POR TECLAS      " << endl;
    cout << "=========================================" << endl;
    cout << "  [FLECHA ARRIBA] : Subir Volumen" << endl;
    cout << "  [FLECHA ABAJO]  : Bajar Volumen" << endl;
    cout << "  [F10]           : Mutear / Desmutear" << endl;
    cout << "  [ESC]           : Salir del Programa" << endl;
    cout << "=========================================" << endl;
    cout << "Volumen Actual: " << volume << " / 1000" << endl;

    bool isMuted = false;
    int savedVolume = volume;

    // Bucle principal del juego/programa
    while (true) {
        // [ESC] para salir limpiamente
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            break; 
        }

        // [FLECHA ARRIBA] - Subir Volumen
        if (GetAsyncKeyState(VK_UP) & 0x8000) {
            if (volume < 1000) {
                volume += 20; 
                if (volume > 1000) volume = 1000;
                isMuted = false;
                
                string cmd = "setaudio my_music volume to " + to_string(volume);
                mciSendString(cmd.c_str(), NULL, 0, NULL);
                cout << "Volumen: " << volume << " / 1000      \r" << flush;
            }
            Sleep(50); // Evita saltos bruscos
        }

        // [FLECHA ABAJO] - Bajar Volumen
        if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
            if (volume > 0) {
                volume -= 20;
                if (volume < 0) volume = 0;
                isMuted = false;

                string cmd = "setaudio my_music volume to " + to_string(volume);
                mciSendString(cmd.c_str(), NULL, 0, NULL);
                cout << "Volumen: " << volume << " / 1000      \r" << flush;
            }
            Sleep(50);
        }

        // [F10] - Mutear/Desmutear
        if (GetAsyncKeyState(VK_F10) & 0x8000) {
            if (!isMuted) {
                savedVolume = volume; 
                volume = 0;
                isMuted = true;
                mciSendString("setaudio my_music volume to 0", NULL, 0, NULL);
                cout << "Volumen: SILENCIADO          \r" << flush;
            } else {
                volume = savedVolume; 
                isMuted = false;
                string cmd = "setaudio my_music volume to " + to_string(volume);
                mciSendString(cmd.c_str(), NULL, 0, NULL);
                cout << "Volumen: " << volume << " / 1000      \r" << flush;
            }
            Sleep(300); // Retraso para evitar doble pulsación
        }

        Sleep(10); // Mantiene el uso del procesador en 0%
    }

    // Detener todo al salir
    mciSendString("stop my_music", NULL, 0, NULL);
    mciSendString("close my_music", NULL, 0, NULL);

    return 0;
}

