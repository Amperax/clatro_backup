#include <iostream>
using namespace std;

int main() {
    int opcion = 1;

    switch (opcion) {
        case 1:
            cout << "Has seleccionado la Opción 1" << endl;
            break;
        case 2:
            cout << "Has seleccionado la Opción 2" << endl;
            break;
        default:
            cout << "Opción no válida" << endl;
    }
    return 0;
}

