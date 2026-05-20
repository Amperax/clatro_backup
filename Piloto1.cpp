#include <iostream>
#include <vector>
#include <sstream>
#include <string>
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
	cout<<"\t\t\t\t\t\t\t\t           "<<"2. Salir"<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t       "<<"Digite el numero de su opcion: ";
	
}

//Función para elegir si salir del juego o empezar a jugar
int menuOpciones(int opcion){
	switch(opcion){
		case 1:
			cout<<endl<<endl<<"\t\t\t\t\t\t\t\t         "<<"Iniciando Juego"; //Se puede agregar una loading bar
			return opcion;
			//Programar que tiene que pasar cuando inicia el juego, aparte de la loading bar
		case 2:
			cout<<endl<<endl<<"\t\t\t\t\t\t\t\t      "<<"Saliendo del Juego";
			return 0;
		default:
			cout<<endl<<endl<<"\t\t\t\t\t\t\t\t       "<<"Opcion no valida";
			return 0;
	}
}

int logicaCartas(){
	vector<vector<int> > cartas = {
	{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 10, 11},
	{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 10, 11},
	{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 10, 11},
	{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 10, 11}
	};
	
	vector<vector<string> > cartasStr = {
	{"Corazones", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"},
	{"Diamantes", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"},
	{"Picas", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"},
	{"Treboles", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"}
	};
}

//Codigo General
int main(){
	int opcion;
	menuGUI();
	cin>>opcion;
	menuOpciones(opcion);
}
