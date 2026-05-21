#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <sstream>
#include <string>
#include <random>
using namespace std;

//GUI del Menú de inicio del juego
void menuGUI(){
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t   "<<".------..------..------..------..------..------..------..------..------."<<endl;
	cout<<"\t\t\t\t\t---"<<"|1.--. ||2.--. ||3.--. ||4.--. ||5.--. ||6.--. ||7.--. ||8.--. ||9.--. |"<<"---"<<endl;
	cout<<"\t\t\t\t\t---"<<"| :/\\: || (\\/) || :(): || :/\\: || :/\\: || (\\/) || :(): || :/\\: || :/\\: |"<<"---"<<endl;
	cout<<"\t\t\t\t\t---"<<"| (__) || :\\/: || ()() || :\\/: || (__) || :\\/: || ()() || :\\/: || (__) |"<<"---"<<endl;
	cout<<"\t\t\t\t\t---"<<"| '--'1|| '--'2|| '--'3|| '--'4|| '--'5|| '--'6|| '--'7|| '--'8|| '--'9|"<<"---"<<endl;
	cout<<"\t\t\t\t\t   "<<"`------'`------'`------'`------'`------'`------'`------'`------'`------'"<<endl<<endl;
	
	cout<<"\t\t\t\t"<<"  ______   _____          _        ______  ___  ____      _____     _        ______  ___  ____   "<<endl;
	cout<<"\t\t\t\t"<<"||_   _ \\ |_   _|        / \\     .' ___  ||_  ||_  _|    |_   _|   / \\     .' ___  ||_  ||_  _||  "<<endl;
	cout<<"\t\t\t\t"<<"   | |_) |  | |         / _ \\   / .'   \\_|  | |_/ /        | |    / _ \\   / .'   \\_|  | |_/ /    "<<endl;
	cout<<"\t\t\t\t"<<"   |  __'.  | |   _    / ___ \\  | |         |  __'.    _   | |   / ___ \\  | |         |  __'.    "<<endl;
	cout<<"\t\t\t\t"<<"  _| |__) |_| |__/ | _/ /   \\ \\_\\ `.___.'\\ _| |  \\ \\_ | |__' | _/ /   \\ \\_\\ `.___.'\\ _| |  \\ \\_  "<<endl;
	cout<<"\t\t\t\t"<<"||_______/|________||____| |____|`.____ .'|____||____|`.____.'|____| |____|`.____ .'|____||____|| "<<endl<<endl<<endl;
	
	cout<<"\t\t\t\t\t\t\t\t       "<<"1. Empezar juego"<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t\t           "<<"2. Salir"<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t       "<<"Digite el numero de su opcion: ";
}

//Función para elegir si salir del juego o empezar a jugar
int menuOpciones(int opcion){
	switch(opcion){
		case 1:
			cout<<endl<<"\t\t\t\t\t\t\t\t       "<<"Iniciando Juego";
			for (int ciclo = 0; ciclo < 5; ciclo++){
				for (int puntos = 0; puntos < 3; puntos++){
					cout<<"."<<flush;
					this_thread::sleep_for(chrono::milliseconds(500));
				}
				cout<<"\r"<<flush;
				cout<<"\r\t\t\t\t\t\t\t\t       Iniciando Juego   \r\t\t\t\t\t\t\t\t       Iniciando Juego"<<flush;
			}
			cout<<endl<<endl<<"\t\t\t\t\t\t\t\t        Juego Iniciado"<<endl;
			return opcion;
		case 2:
			cout<<endl<<"\t\t\t\t\t\t\t\t      "<<"Saliendo del Juego";
			return 0;
		default:
			cout<<endl<<"\t\t\t\t\t\t\t\t       "<<"Opcion no valida"<<endl<<endl;
			cout<<"\t\t\t\t\t\t\t\t       "<<"1. Empezar juego"<<endl<<endl;
			cout<<"\t\t\t\t\t\t\t\t           "<<"2. Salir"<<endl<<endl;
			cout<<"\t\t\t\t\t\t\t       "<<"Digite el numero de su opcion: ";
			cin>>opcion;
			menuOpciones(opcion);
	}
}

//Logica General de las cartas
void logicaCartas(){
	vector<vector<int> > cartas = {
	{2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11},
	{2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11},
	{2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11},
	{2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11}
	};
	
	vector<string> pintas = {"Corazones", "Diamantes", "Picas", "Treboles"};
	
	vector<vector<string> > cartasStr = {
	{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"},
	{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"},
	{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"},
	{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"}
	};
	
	/*Para generar un valor aleatorio con cada ejecución, la semilla sera los microsegundos
	actuales del computador para poder variar constantemente la semilla
	"unsigned" llama especificamente a un numero entero POSITIVO o 0, es un tipo de variable especial
	Se una porque el motor matematico que genera la semiila (mt19937) solo puede tomar números no negativos*/
	unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
		
	//Se inicializa un valor aleatorio (semilla, generador de valores y controlador de rango)
	mt19937 gen(seed);
	uniform_int_distribution<> distrPinta(0, 3);
	uniform_int_distribution<> distrCarta(0, 12);
		
	for (int i = 0; i < 12; i++){
		/*Variables aleatoria para la pinta y para la carta, se generan dentro del for
		para poder cambiar el valor con cada ciclo completado*/
		int pinta = distrPinta(gen);
		int carta = distrCarta(gen);
		
		//Codigo para probar que el sistema de random funcione
		if (cartas[0][carta] == 0){
			//Si la carta es 0 es porque ya fue usada, es para evitar que las cartas se repitan
			continue;
		} else {
			//Se imprime como prueba
			cout<<"Pinta: "<<pintas[pinta]<<"/ Numero que saldra en el codigo: "<<cartasStr[pinta][carta]<<"/ Numero de matriz int: ";
			cout<<cartas[pinta][carta];
			//Se convierte la posición actuales de cartas en 0 para indicar que ya fue usada
			cartas[pinta][carta] = 0;
			cout<<" / Resultado vector: ";
			//Se imprime el vector para verificar si está convirtiendo los valores a 0
			for (int j = 0; j < cartas[pinta].size(); j++){
				cout<<cartas[pinta][j]<<" ";
			}
			cout<<endl;
		}
		
	}
}

//Codigo General
int main(){
	int opcion;
	menuGUI();
	cin>>opcion;
	menuOpciones(opcion);
	if (opcion == 1){
		logicaCartas();	
	} else if (opcion == 2){
		return 0;
	}
}
