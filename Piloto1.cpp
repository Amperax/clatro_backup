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
			for (int ciclo = 0; ciclo < 2; ciclo++){
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

void accionesPrint(){
	cout<<endl<<"Sus posibles acciones son:\n";
	cout<<"\t1. Hit (Pedir otra carta)\n\t2. Stand (No pedir mas cartas)\n";
	cout<<"\t3. Double Down (Doblar la apuesta - recibe solo una carta mas)\n";
}

//Logica General de las cartas
int logicaCartas(){
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
	
	//Le da las cartas al jugador, las guarda en un vector
	cout<<"Sus cartas son:\n";
	vector<int> cartasPlayer;
	for (int tusCartas = 0; tusCartas < 2; tusCartas++){
		int pinta = distrPinta(gen);
		int carta = distrCarta(gen);
		if (cartas[pinta][carta] == 0){
			if (tusCartas == 1){
				tusCartas--;
				continue;
			} 
		} else {
			cartasPlayer.push_back(cartas[pinta][carta]);
			cout<<pintas[pinta]<<" "<<cartasStr[pinta][carta]<<" ";
			
			//La carta actual se vuelve 0 para indicar que ya se usó
			cartas[pinta][carta] = 0;
		}
	}
	
	//Le da las cartas al dealer, las guarda en un vector, muestra una carta
	cout<<"\nLa carta visible del dealer es:\n";
	vector<int> cartasDealer;
	string cartaInicialDealer;
	for (int cartaDealer = 0; cartaDealer < 2; cartaDealer++){
		int pinta = distrPinta(gen);
		int carta = distrCarta(gen);
		if (cartas[pinta][carta] == 0){
			if (cartaDealer == 1){
				cartaDealer--;
				continue;
			}
		} else {
			cartasDealer.push_back(cartas[pinta][carta]);
			if (cartaDealer == 0){
				cartaInicialDealer = cartasStr[pinta][carta];	
			}
			if (cartaDealer == 1){
				cout<<pintas[pinta]<<" "<<cartasStr[pinta][carta]<<endl;
			}
			
			//La carta actual se vuelve 0 para indicar que ya se usó
			cartas[pinta][carta] = 0;
		}
	}
	
	//Si llegaste a 21 de una, analiza si el dealer también lo hizo
	//Si no lo hizo, es victoria instantanea para el jugador
	int sumaPlayer = 0;
	int sumaDealer = 0;
		
	for (int i = 0; i < cartasPlayer.size(); i++){
		sumaPlayer += cartasPlayer[i];
	}
		
	for (int i = 0; i < cartasDealer.size(); i++){
		sumaDealer += cartasDealer[i];
	}
		
	if (sumaDealer == 21 && sumaPlayer != 21){
		cout<<"¡El dealer saco 21!\n";
		//Return temporal, aquí iria un return para abrir el menú general
		return 0;
	}
		
	if (sumaPlayer == 21){	
		if (sumaDealer == 21){
			cout<<"\n¡Empate de 21! - No pierdes la apuesta";
			//Return temporal, aquí iria un return para abrir el menú general
			return 0;
		} else {
			cout<<"\n¡Victoria Instantanea! - Ganas 3 a 2 de tu apuesta";
			//Return temporal, aquí iria un return para abrir el menú general
			return 0;
		}
	}
	
	while (true){
		int playCard;
		accionesPrint();
		cout<<"Seleccione su accion: ";
		cin>>playCard;
		cout<<"\n";
		switch(playCard){
			//Hit, otra carta
			case 1:{
				int pinta = distrPinta(gen);
				int carta = distrCarta(gen);
				while (cartas[pinta][carta] == 0){
					int pinta = distrPinta(gen);
					int carta = distrCarta(gen);
				}
				
				cartasPlayer.push_back(cartas[pinta][carta]);
				cout<<"Tu carta nueva es: "<<pintas[pinta]<<" "<<cartasStr[pinta][carta]<<endl;
				//La carta actual se vuelve 0 para indicar que ya se usó
				cartas[pinta][carta] = 0;
				
				int sumaPlayer = 0;
				int sumaDealer = 0;
				
				//Suma las cartas para saber si no te pasaste de 21
				for (int i = 0; i < cartasPlayer.size(); i++){
					sumaPlayer += cartasPlayer[i];
				}
				
				//Caso tal te pases, analiza si no tienes un As para pasarlo de 11 a 1
				//Si no es tu caso, pierdes el juego automaticamente
				if (sumaPlayer > 21){
					for (int j = 0; j < cartasPlayer.size(); j++){
						if (cartasPlayer[j] == 11){
							cartasPlayer[j] = 1;
							break;
						}
					}
					
					sumaPlayer = 0;
					
					for (int i = 0; i < cartasPlayer.size(); i++){
						sumaPlayer += cartasPlayer[i];
					}
					
					if (sumaPlayer > 21){
						cout<<"Te pasate de 21\n";
						cout<<"Suma: "<<sumaPlayer;
						//Return temporal, aquí iria un return para abrir el menú general
						return 0;
					} else {
						break;
					}
				}
			}
				
			//Stand, no más cartas
			case 2:{
				int sumaPlayer = 0;
				int sumaDealer = 0;
				for (int i = 0; i < cartasPlayer.size(); i++){
					sumaPlayer += cartasPlayer[i];
				}
				for (int i = 0; i < cartasDealer.size(); i++){
					sumaDealer += cartasDealer[i];
				}
				
				//Si la suma del dealer es menor que 17, tiene que coger otra carta
				while (sumaDealer < 17){
					int pinta = distrPinta(gen);
					int carta = distrCarta(gen);
					while (cartas[pinta][carta] == 0){
						int pinta = distrPinta(gen);
						int carta = distrCarta(gen);
					}
					
					//cout<<pintas[pinta]<<" "<<cartasStr[pinta][carta]<<endl;
					cartasDealer.push_back(cartas[pinta][carta]);
					//La carta actual se vuelve 0 para indicar que ya se usó
					cartas[pinta][carta] = 0;
					sumaDealer = 0;
					for (int i = 0; i < cartasDealer.size(); i++){
						sumaDealer += cartasDealer[i];
					}
				}
				
				if (sumaDealer > 21){
					for (int j = 0; j < cartasDealer.size(); j++){
						if (cartasDealer[j] == 11){
							cartasDealer[j] = 1;
							break;
						}
					}
					
					sumaDealer = 0;
					
					for (int i = 0; i < cartasDealer.size(); i++){
						sumaDealer += cartasDealer[i];
					}
					
					if (sumaDealer > 21){
						cout<<"El dealer se paso de 21\n";
						cout<<"Suma: "<<sumaDealer;
						//Return temporal, aquí iria un return para abrir el menú general
						return 0;
					}
				}
				
				//VER COMO OPTIMIZAR ESTO
				while (sumaDealer < 17){
					int pinta = distrPinta(gen);
					int carta = distrCarta(gen);
					while (cartas[pinta][carta] == 0){
						int pinta = distrPinta(gen);
						int carta = distrCarta(gen);
					}
					
					cartasDealer.push_back(cartas[pinta][carta]);
					//La carta actual se vuelve 0 para indicar que ya se usó
					cartas[pinta][carta] = 0;
					sumaDealer = 0;
					for (int i = 0; i < cartasDealer.size(); i++){
						sumaDealer += cartasDealer[i];
					}
				}
				
				if (sumaDealer == sumaPlayer){
					cout<<"¡Fue un empate!\n";
					cout<<"Suma tuya: "<<sumaPlayer<<" - Suma del dealer: "<<sumaDealer; //Pensar en como mostrar todas las cartas del dealer
					//Return temporal, aquí iria un return para abrir el menú general
					return 0;
				} else if (sumaDealer > sumaPlayer && sumaDealer < 21){
					cout<<"El dealer estuvo mas cerca de 21\n";
					cout<<"Carta inicial del dealer: "<<cartaInicialDealer<<" - Suma del dealer: "<<sumaDealer;
					//Return temporal, aquí iria un return para abrir el menú general
					return 0;
				} else if (sumaDealer < sumaPlayer && sumaPlayer < 21){
					cout<<"Estuviste mas cerca de 21 que el dealer\n";
					cout<<"Suma del dealer: "<<sumaDealer<<" - Suma tuya: "<<sumaPlayer;
					//Return temporal, aquí iria un return para abrir el menú general
					return 0;
				} else if (sumaPlayer == 21){
					cout<<"¡Sacaste 21!\n";
					cout<<"Carta inicial del dealer: "<<cartaInicialDealer<<" - Suma del dealer: "<<sumaDealer;
				}
			//Return temporal, aquí iria un return para abrir el menú general
			return 0;
			
			//Double Down, doblar la apuesta (programar mañana)
			//case 3:
				
			//Split, romper la mano de cartas en dos manos (Considerar si hacerlo y pensar como hacerlo)
			//case 4:
			//	return 4;
		}
	}
}
	
//	for (int i = 0; i < 12; i++){
//		/*Variables aleatoria para la pinta y para la carta, se generan dentro del for
//		para poder cambiar el valor con cada ciclo completado*/
//		int pinta = distrPinta(gen);
//		int carta = distrCarta(gen);
//		
//		//Codigo para probar que el sistema de random funcione
//		if (cartas[pinta][carta] == 0){
//			//Si la carta es 0 es porque ya fue usada, es para evitar que las cartas se repitan
//			continue;
//		} else {
//						
//			//Se imprime como prueba
//			cout<<"Pinta: "<<pintas[pinta]<<"/ Numero que saldra en el codigo: "<<cartasStr[pinta][carta]<<"/ Numero de matriz int: ";
//			cout<<cartas[pinta][carta];
//			//Se convierte la posición actuales de cartas en 0 para indicar que ya fue usada
//			cartas[pinta][carta] = 0;
//			cout<<" / Resultado vector: ";
//			//Se imprime el vector para verificar si está convirtiendo los valores a 0
//			for (int j = 0; j < cartas[pinta].size(); j++){
//				cout<<cartas[pinta][j]<<" ";
//			}
//			cout<<endl;
//			
//			//La carta actual se vuelve 0 para indicar que ya se usó
//			cartas[pinta][carta] = 0;
//		}
//		
//	}

}

/*void opcionesGenerales(int opcionGeneral){
	switch(opcionGeneral){
		//Continuar Juego
		//case 1:
		
		//Guardar Juego
		//case 2:
		
		//Guardar y Salir
		//case 3:
		
		//Salir Sin Guardar
		//case 4:
	}
}*/

//Codigo General
int main(){
	int opcion;
	menuGUI();
	cin>>opcion;
	menuOpciones(opcion);
	if (opcion == 1){
		logicaCartas();
	} else if (opcion == 0){
		return 0;
	}
}
