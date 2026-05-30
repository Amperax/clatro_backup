#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <ctime>
#include <fstream>
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
	
	cout<<"\t\t\t\t\t\t\t       "<<"1. Empezar juego ---------------"<<endl<<endl;
	cout<<"\t\t\t\t\t\t               "<<"2. Cargar juego ----------------"<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t       "<<"3. Salir -----------------------"<<endl<<endl;
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
			cout<<endl<<endl<<"\t\t\t\t\t\t\t\t       Juego Iniciado\n\n";
			this_thread::sleep_for(chrono::milliseconds(1000));
			//ANSI Escape Sequences - Toca buscar que es eso para el informe
			//"\033[2J" Limpia la pantalla visible
			//"\033[3J" Limpia lo que se imprimio (el buffer)
			//"\033[H" te lleva hasta el orgien de la impresion por consola (Esquina superior izq.)
			cout<<"\033[2J\033[3J\033[H"<<flush;
			return opcion;
		case 2:
			cout<<endl<<"\t\t\t\t\t\t\t\t       "<<"Cargando Juego";
			for (int ciclo = 0; ciclo < 2; ciclo++){
				for (int puntos = 0; puntos < 3; puntos++){
					cout<<"."<<flush;
					this_thread::sleep_for(chrono::milliseconds(500));
				}
				cout<<"\r"<<flush;
				cout<<"\r\t\t\t\t\t\t\t\t       Cargando Juego   \r\t\t\t\t\t\t\t\t       Cargando Juego"<<flush;
			}
			cout<<endl<<endl<<"\t\t\t\t\t\t\t\t       Carga Completa\n\n";
			this_thread::sleep_for(chrono::milliseconds(1000));
			//ANSI Escape Sequences - Toca buscar que es eso para el informe
			//"\033[2J" Limpia la pantalla visible
			//"\033[3J" Limpia lo que se imprimio (el buffer)
			//"\033[H" te lleva hasta el orgien de la impresion por consola (Esquina superior izq.)
			cout<<"\033[2J\033[3J\033[H"<<flush;
			return opcion;
		case 3:
			cout<<endl<<"\t\t\t\t\t\t\t\t      "<<"Saliendo del Juego";
			this_thread::sleep_for(chrono::milliseconds(5000));
			return 0;
		
		//Return temporal como salva vidas
		return 0;
	}
}

void accionesPrint(){
	cout<<endl<<"Sus posibles acciones son:\n";
	cout<<"\t1. Hit (Pedir otra carta)\n\t2. Stand (No pedir mas cartas)\n";
	cout<<"\t3. Double Down (Doblar la apuesta - recibe solo una carta mas - pierde el doble de lo apostado)\n";
}

int logicaApuestas(int saldoRonda, string accion, string codigo, int* apuesta){
	if (accion == "bet"){
		//Que se ingrese la apuesta que se quiera hacer
		while (true){
			cout<<"Su saldo inicial es de: $"<<saldoRonda<<endl;
			cout<<"Ingrese la cantidad de dinero que desea apostar: $";
			cin>>*apuesta;
			if (cin.fail()){
				cin.clear();
				//El primer parametro dentro del ignore es una cantidad de letras que el programa limpiara y borrara del buffer
				//El segundo es el limite, en este caso, cuando se encuentre un \n se simpia y se boora todo del buffer
				cin.ignore(10000, '\n');
				cout<<endl<<"Entrada invalida. Debe ser un numero entero."<<endl<<endl;
				this_thread::sleep_for(chrono::milliseconds(2000));
				//Pendiente con esto de aqui abajo
				cout<<"\033[2J\033[3J\033[H"<<flush;
				continue;
			}
			cin.ignore(10000, '\n');
			if (*apuesta > saldoRonda || *apuesta <= 0){
				cout<<"\nValor de apuesta invalido, por favor intente de nuevo\n\n";
				this_thread::sleep_for(chrono::milliseconds(2000));
				//Pendiente con esto de aqui abajo
				cout<<"\033[2J\033[3J\033[H"<<flush;
			} else if (*apuesta <= saldoRonda && *apuesta > 0){
				cout<<"Apostara $"<<*apuesta<<endl;
				cout<<"Saldo $"<<saldoRonda - *apuesta<<endl<<endl;
				saldoRonda -= *apuesta;
				return saldoRonda;
			}
		}
	} else if (accion == "calc"){
		if (codigo == "E"){
			return saldoRonda + *apuesta;
		} else if (codigo == "W"){
			saldoRonda = saldoRonda + *apuesta*2;
			return saldoRonda;
		} else if (codigo == "W21"){
			saldoRonda = saldoRonda + *apuesta + (*apuesta * 1.5);
			return saldoRonda;
		} else if (codigo == "L"){
			return saldoRonda;
		} else if (codigo == "LDD"){
			saldoRonda -= *apuesta;
			return saldoRonda;
		} else if (codigo == "WDD"){
			saldoRonda -= *apuesta;
			saldoRonda = saldoRonda + *apuesta*4;
			return saldoRonda;
		}
	}
}

//Logica General de las cartas
int logicaCartas(int saldo, int* apuesta){
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
	vector<string> cartasPlayerStr;
	vector<string> cartasPlayerPinta;
	for (int tusCartas = 0; tusCartas < 2; tusCartas++){
		int pinta = distrPinta(gen);
		int carta = distrCarta(gen);
		if (cartas[pinta][carta] == 0){
			tusCartas--;
			continue;
		} else {
			cartasPlayer.push_back(cartas[pinta][carta]);
			cartasPlayerStr.push_back(cartasStr[pinta][carta]);
			cartasPlayerPinta.push_back(pintas[pinta]);
			cout<<pintas[pinta]<<" "<<cartasStr[pinta][carta]<<" ";
			
			//La carta actual se vuelve 0 para indicar que ya se usó
			cartas[pinta][carta] = 0;
		}
	}
	
	//Muestra la suma de las cartas entregadas
	int sumaPlayer = 0;
		
	for (int i = 0; i < cartasPlayer.size(); i++){
		sumaPlayer += cartasPlayer[i];
	}
	
	cout<<"- Total: "<<sumaPlayer<<endl;
	
	//Le da las cartas al dealer, las guarda en un vector, muestra una carta
	cout<<"\nLa carta visible del dealer es:\n";
	vector<int> cartasDealer;
	vector<string> cartasDealerStr;
	vector<string> cartasDealerPinta;
	string cartaInicialDealer;
	for (int cartaDealer = 0; cartaDealer < 2; cartaDealer++){
		int pinta = distrPinta(gen);
		int carta = distrCarta(gen);
		if (cartas[pinta][carta] == 0){
			cartaDealer--;
			continue;
		} else {
			cartasDealer.push_back(cartas[pinta][carta]);
			cartasDealerStr.push_back(cartasStr[pinta][carta]);
			cartasDealerPinta.push_back(pintas[pinta]);
			if (cartaDealer == 0){	
				cout<<pintas[pinta]<<" "<<cartasStr[pinta][carta]<<endl;
			}
			
			//La carta actual se vuelve 0 para indicar que ya se usó
			cartas[pinta][carta] = 0;
		}
	}
	
	//Si llegaste a 21 de una, analiza si el dealer también lo hizo
	//Si no lo hizo, es victoria instantanea para el jugador
	sumaPlayer = 0;
	int sumaDealer = 0;
		
	for (int i = 0; i < cartasPlayer.size(); i++){
		sumaPlayer += cartasPlayer[i];
	}
		
	for (int i = 0; i < cartasDealer.size(); i++){
		sumaDealer += cartasDealer[i];
	}
		
	if (sumaDealer == 21 && sumaPlayer != 21){
		cout<<"\nEl dealer saco 21!\n";
		//Return 3 significa perder la partida 
		return 3;
	}
		
	if (sumaPlayer == 21){	
		if (sumaDealer == 21){
			cout<<"\nEmpate de 21! - No pierdes la apuesta";
			//Return 0 significa empatar la partida
			return 0;
		} else {
			cout<<"\n¡Victoria Instantanea! - Ganas 3 a 2 de tu apuesta";
			//Return 2 significa una win instantanea
			return 2;
		}
	}
	
	while (true){
		int playCard;
		accionesPrint();
		cout<<"Seleccione su accion: ";
		cin>>playCard;
		cout<<"\n";
		if (cin.fail()){
			cin.clear();
			//El primer parametro dentro del ignore es una cantidad de letras que el programa limpiara y borrara del buffer
			//El segundo es el limite, en este caso, cuando se encuentre un \n se simpia y se boora todo del buffer
			cin.ignore(10000, '\n');
			cout<<endl<<"Accion invalida. Por favor introduzca un numero de las opciones (1, 2 o 3)."<<endl<<endl;
			cout<<"Sus cartas son:\n";
			for (int i = 0; i < cartasPlayer.size(); i++){
				cout<<cartasPlayerPinta[i]<<" "<<cartasPlayerStr[i]<<" ";
			}
			cout<<"- Total: "<<sumaPlayer;
			cout<<"\n\nLa carta visible del dealer es:\n";
			cout<<cartasDealerPinta[0]<<" "<<cartasDealerStr[0]<<endl;
			continue;
		}
		
		//Ignorar basura a la derecha de un input
		cin.ignore(10000, '\n');
		
		switch(playCard){
			//Hit, otra carta
			case 1:{
				int pinta = distrPinta(gen);
				int carta = distrCarta(gen);
				while (cartas[pinta][carta] == 0){
					pinta = distrPinta(gen);
					carta = distrCarta(gen);
				}
				
				cartasPlayer.push_back(cartas[pinta][carta]);
				//La carta actual se vuelve 0 para indicar que ya se usó
				cartas[pinta][carta] = 0;
				
				sumaPlayer = 0;
				sumaDealer = 0;
				
				//Suma las cartas para saber si no te pasaste de 21
				for (int i = 0; i < cartasPlayer.size(); i++){
					sumaPlayer += cartasPlayer[i];
				}
				
				//Caso tal te pases, analiza si no tienes un As para pasarlo de 11 a 1
				//Si no es tu caso, pierdes el juego automaticamente
				if (sumaPlayer > 21){
					for (int j = 0; j < cartasPlayer.size(); j++){
						if (sumaPlayer > 21 && cartasPlayer[j] == 11){
							cartasPlayer[j] = 1;
							
							sumaPlayer = 0;
					
							for (int i = 0; i < cartasPlayer.size(); i++){
								sumaPlayer += cartasPlayer[i];
							}
						}
					}
					
					sumaPlayer = 0;
					
					for (int i = 0; i < cartasPlayer.size(); i++){
						sumaPlayer += cartasPlayer[i];
					}
					
					cout<<"Tu carta nueva es: "<<pintas[pinta]<<" "<<cartasStr[pinta][carta];
					cout<<" - Total: "<<sumaPlayer<<endl;
					
					if (sumaPlayer > 21){
						cout<<"Te pasate de 21! - Perdida automatica\n"<<endl<<"Las cartas del dealer fueron:";
						for (int i = 0; i < cartasDealer.size(); i++){
							cout<<endl<<cartasDealerPinta[i]<<" "<<cartasDealerStr[i];
						}
						
						sumaDealer = 0;
						
						for (int i = 0; i < cartasDealer.size(); i++){
							sumaDealer += cartasDealer[i];
						}
						cout<<"\n\nTotal del dealer: "<<sumaDealer<<endl;
						//Return 3 significa perder la partida 
						return 3;
					} else if (sumaPlayer == 21){
						cout<<"Sacaste 21!\n";
						cout<<"Total del dealer: "<<sumaDealer<<endl<<"Las cartas del dealer fueron:";
						for (int i = 0; i < cartasDealer.size(); i++){
							cout<<endl<<cartasDealerPinta[i]<<" "<<cartasDealerStr[i];
						}
						cout<<endl;
						//Return 1 significa ganar la partida
						return 1;
					}
				} else {
					cout<<"Tu carta nueva es: "<<pintas[pinta]<<" "<<cartasStr[pinta][carta];
					cout<<" - Total: "<<sumaPlayer<<endl;
				}
				
				break;
			}
				
			//Stand, no más cartas
			case 2:{
				sumaPlayer = 0;
				sumaDealer = 0;
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
						pinta = distrPinta(gen);
						carta = distrCarta(gen);
					}
					
					cartasDealer.push_back(cartas[pinta][carta]);
					cartasDealerStr.push_back(cartasStr[pinta][carta]);
					cartasDealerPinta.push_back(pintas[pinta]);
					
					//La carta actual se vuelve 0 para indicar que ya se usó
					cartas[pinta][carta] = 0;
					sumaDealer = 0;
					
					for (int i = 0; i < cartasDealer.size(); i++){
						sumaDealer += cartasDealer[i];
					}
					
					if (sumaDealer > 21){
						for (int j = 0; j < cartasDealer.size(); j++){
							if (cartasDealer[j] == 11){
								cartasDealer[j] = 1;
								
								sumaDealer = 0;
								
								for (int i = 0; i < cartasDealer.size(); i++){
									sumaDealer += cartasDealer[i];
								}
							}
						}
					
						sumaDealer = 0;
					
						for (int i = 0; i < cartasDealer.size(); i++){
							sumaDealer += cartasDealer[i];
						}
					}
				}
				
				sumaDealer = 0;
				
				for (int i = 0; i < cartasDealer.size(); i++){
					sumaDealer += cartasDealer[i];
				}
				
				cout<<"Las cartas del dealer fueron:";
				for (int i = 0; i < cartasDealer.size(); i++){
					cout<<endl<<cartasDealerPinta[i]<<" "<<cartasDealerStr[i];
				}
				cout<<"\n\nTotal del dealer: "<<sumaDealer<<endl;
				cout<<"Total tuyo: "<<sumaPlayer<<endl<<endl;
				
				if (sumaDealer > 21){
					cout<<"El dealer se paso de 21. Ganaste!\n";
					//Return 1 significa ganar la partida
					return 1;
				}
				
				if (sumaDealer == sumaPlayer){
					cout<<"Fue un empate! - No pierdes la apuesta\n";
					//Return 0 significa empate
					return 0;
				} else if (sumaDealer > sumaPlayer){
					cout<<"El dealer estuvo mas cerca de 21. Perdiste!\n";
					//Return 3 significa perder la partida 
					return 3;
				} else if (sumaPlayer == 21){
					cout<<"Sacaste 21! Ganaste!\n";
					//Return 1 significa ganar la partida
					return 1;
				} else if (sumaDealer < sumaPlayer){
					cout<<"Estuviste mas cerca de 21 que el dealer. Ganaste!\n";
					//Return 1 significa ganar la partida
					return 1;
				}
				//Return 6 solo acaba el codigo			
				return 6;
			}
			
			case 3:{
				if (saldo < *apuesta){
					cout<<"El saldo no es suficiente para poder realizar un Double Down\n";
					continue;
				}
				int pinta = distrPinta(gen);
				int carta = distrCarta(gen);
				while (cartas[pinta][carta] == 0){
					pinta = distrPinta(gen);
					carta = distrCarta(gen);
				}
				
				cartasPlayer.push_back(cartas[pinta][carta]);
				//La carta actual se vuelve 0 para indicar que ya se usó
				cartas[pinta][carta] = 0;
				
				sumaPlayer = 0;
				sumaDealer = 0;
				
				//Suma las cartas para saber si no te pasaste de 21
				for (int i = 0; i < cartasPlayer.size(); i++){
					sumaPlayer += cartasPlayer[i];
				}
				
				//Caso tal te pases, analiza si no tienes un As para pasarlo de 11 a 1
				//Si no es tu caso, pierdes el juego automaticamente
				if (sumaPlayer > 21){
					for (int j = 0; j < cartasPlayer.size(); j++){
						if (sumaPlayer > 21 && cartasPlayer[j] == 11){
							cartasPlayer[j] = 1;
							
							sumaPlayer = 0;
					
							for (int i = 0; i < cartasPlayer.size(); i++){
								sumaPlayer += cartasPlayer[i];
							}
						}
					}
					
					sumaPlayer = 0;
					
					for (int i = 0; i < cartasPlayer.size(); i++){
						sumaPlayer += cartasPlayer[i];
					}
					
					cout<<"Tu carta nueva es: "<<pintas[pinta]<<" "<<cartasStr[pinta][carta];
					cout<<" - Total: "<<sumaPlayer<<endl<<endl;
					
					if (sumaPlayer > 21){
						cout<<"Te pasate de 21! - Perdida automatica\n"<<endl<<"Las cartas del dealer fueron:";
						for (int i = 0; i < cartasDealer.size(); i++){
							cout<<endl<<cartasDealerPinta[i]<<" "<<cartasDealerStr[i];
						}
						
						sumaDealer = 0;
						
						for (int i = 0; i < cartasDealer.size(); i++){
							sumaDealer += cartasDealer[i];
						}
						cout<<"\n\nTotal del dealer: "<<sumaDealer<<endl;
						//Return 4 significa perder la partida en double down
						return 4;
					} else if (sumaPlayer == 21){
						cout<<"Sacaste 21!\n";
						cout<<"Total del dealer: "<<sumaDealer<<endl<<"Las cartas del dealer fueron: ";
						for (int i = 0; i < cartasDealer.size(); i++){
							cout<<endl<<cartasDealerPinta[i]<<" "<<cartasDealerStr[i];
						}
						cout<<endl;
						//Return 5 significa ganar la partida en double down
						return 5;
					}
					
				} else {
					cout<<"Tu carta nueva es: "<<pintas[pinta]<<" "<<cartasStr[pinta][carta];
					cout<<" - Total: "<<sumaPlayer<<endl<<endl;
				}
				
				//Aqui se hace el stand automatico del double down
				sumaPlayer = 0;
				sumaDealer = 0;
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
						pinta = distrPinta(gen);
						carta = distrCarta(gen);
					}
					
					cartasDealer.push_back(cartas[pinta][carta]);
					cartasDealerStr.push_back(cartasStr[pinta][carta]);
					cartasDealerPinta.push_back(pintas[pinta]);

					
					//La carta actual se vuelve 0 para indicar que ya se usó
					cartas[pinta][carta] = 0;
					sumaDealer = 0;
					
					for (int i = 0; i < cartasDealer.size(); i++){
						sumaDealer += cartasDealer[i];
					}
					
					if (sumaDealer > 21){
						for (int j = 0; j < cartasDealer.size(); j++){
							if (cartasDealer[j] == 11){
								cartasDealer[j] = 1;
								
								sumaDealer = 0;
								
								for (int i = 0; i < cartasDealer.size(); i++){
									sumaDealer += cartasDealer[i];
								}
							}
						}
					
						sumaDealer = 0;
					
						for (int i = 0; i < cartasDealer.size(); i++){
							sumaDealer += cartasDealer[i];
						}
					}
				}
				
				sumaDealer = 0;
					
				for (int i = 0; i < cartasDealer.size(); i++){
					sumaDealer += cartasDealer[i];
				}
				
				sumaDealer = 0;
				
				for (int i = 0; i < cartasDealer.size(); i++){
					sumaDealer += cartasDealer[i];
				}
				
				cout<<"Las cartas del dealer fueron:";
				for (int i = 0; i < cartasDealer.size(); i++){
					cout<<endl<<cartasDealerPinta[i]<<" "<<cartasDealerStr[i];
				}
				cout<<"\n\nTotal del dealer: "<<sumaDealer<<endl;
				cout<<"Total tuyo: "<<sumaPlayer<<endl<<endl;
				
				if (sumaDealer > 21){
					cout<<"El dealer se paso de 21. Ganaste!\n";
					//Return 5 significa ganar la partida en double down
					return 5;
				}
				
				if (sumaDealer == sumaPlayer){
					cout<<"Fue un empate! - No pierdes la apuesta\n";
					//Return 0 significa empate
					return 0;
				} else if (sumaDealer > sumaPlayer){
					cout<<"El dealer estuvo mas cerca de 21. Perdiste\n";
					//Return 4 significa perder la partida en double down
					return 4;
				} else if (sumaPlayer == 21){
					cout<<"Sacaste 21! Ganaste!\n";
					//Return 5 significa ganar la partida en double down
					return 5;
				} else if (sumaDealer < sumaPlayer){
					cout<<"Estuviste mas cerca de 21 que el dealer. Ganaste!\n";
					//Return 5 significa ganar la partida en double down
					return 5;
				}
			}
			
			default:{
				cout<<"Ese numero no esta dentro de las opciones, intente de nuevo"<<endl<<endl;
				cout<<"Sus cartas son:\n";
				for (int i = 0; i < cartasPlayer.size(); i++){
					cout<<cartasPlayerPinta[i]<<" "<<cartasPlayerStr[i]<<" ";
				}
				cout<<"- Total: "<<sumaPlayer;
				cout<<"\n\nLa carta visible del dealer es:\n";
				cout<<cartasDealerPinta[0]<<" "<<cartasDealerStr[0]<<endl;
				continue;
			}
		}
	}
	//Return salvavidas por si pasa algo
	return 0;
}

int opcionesGenerales(int* opcion, int saldoGuardar){
	while (true){
		cout<<"Que desea hacer?\n";
		cout<<"\t1. Continuar la partida\n";
		cout<<"\t2. Resetear Juego (Soft Reset)\n";
		cout<<"\t3. Guardar la partida y Continuar\n";
		cout<<"\t4. Guardar y salir\n";
		cout<<"\t5. Salir\n";
		cout<<endl<<"Digite su opcion: ";
		cin>>*opcion;
		if (cin.fail()){
			cin.clear();
			//El primer parametro dentro del ignore es una cantidad de letras que el programa limpiara y borrara del buffer
			//El segundo es el limite, en este caso, cuando se encuentre un \n se simpia y se boora todo del buffer
			cin.ignore(10000, '\n');
			cout<<endl<<"Entrada invalida. Ingrese un NUMERO o una opcion VALIDA"<<endl<<endl;
			continue;
		}
		
		cin.ignore(10000, '\n');
		
		switch(*opcion){
			//Continuar Juego
			case 1:{
				return 0;
			}
			
			//Resetear
			case 2:{
				return 1;
			}
				
			//Guardar Juego
			case 3:{
				ofstream saveFile("input-output/saveFile.txt");
				fstream recordFile;
				recordFile.open("input-output/gameRecords.txt", ios::out | ios::app);
				if (recordFile.is_open()){
					//Estas lineas de codigo toman el tiempo actual del computador
					time_t now = time(nullptr);
					tm* local_time = localtime(&now);
					char buffer[11];
					strftime(buffer, sizeof(buffer), "%Y/%m/%d", local_time);
					
					//Esto imprime en el archivo cada partida guardada
					recordFile<<"Saldo: "<<saldoGuardar<<" - Fecha: "<<buffer;
					saveFile<<"Saldo: "<<saldoGuardar<<" - Fecha: "<<buffer;
					
					//Estas lineas toman la hora actual del PC
					char time_string[9];
					strftime(time_string, sizeof(time_string), "%X", local_time);
					
					//Imprime la hora en cada archivo
					recordFile<<" - Hora: "<<time_string<<endl;
					saveFile<<" - Hora: "<<time_string<<endl;
					
				} else {
					cout<<"\nNo se pudo abrir el archivo";
				}
				cout<<"El juego se ha guardado con exito\n\n";
				return 2;
			}
				
			//Guardar y Salir
			case 4:{
				ofstream saveFile("input-output/saveFile.txt");
				fstream recordFile;
				recordFile.open("input-output/gameRecords.txt", ios::out | ios::app);
				if (recordFile.is_open()){
					//Estas lineas de codigo toman el tiempo actual del computador
					time_t now = time(nullptr);
					tm* local_time = localtime(&now);
					char buffer[11];
					strftime(buffer, sizeof(buffer), "%Y/%m/%d", local_time);
					
					//Esto imprime en el archivo cada partida guardada
					recordFile<<"Saldo: "<<saldoGuardar<<" - Fecha: "<<buffer;
					saveFile<<"Saldo: "<<saldoGuardar<<" - Fecha: "<<buffer;
					
					//Estas lineas toman la hora actual del PC
					char time_string[9];
					strftime(time_string, sizeof(time_string), "%X", local_time);
					
					//Imprime la hora en cada archivo
					recordFile<<" - Hora: "<<time_string<<endl;
					saveFile<<" - Hora: "<<time_string<<endl;
					
				} else {
					cout<<"\nNo se pudo abrir el archivo";
				}
				cout<<"El juego se ha guardado con exito\n\n";
				this_thread::sleep_for(chrono::milliseconds(2000));
				return 3;
			}
				
			//Salir
			case 5:{
				cout<<"\nSalio con exito!\n";
				return 4;
			}
				
			default:{
				cout<<endl<<"Entrada invalida. Ingrese un NUMERO o una opcion VALIDA"<<endl<<endl;
				continue;
			}
			
			//Break salvavidas
			break;
		}
		
		//Return salvavidas
		return 0;
	}
}

/*
- Este es el codigo para la música del juego, necesitas estudiar como funciona
- Se declaran fuera de la main al ser variables globales
- Playlist de canciones (balatro, luigi's casino, openning title SM64 Lofi version) respectivamente
*/

string playlist[] = {"music/cancion1.mp3", "music/cancion2.mp3", "music/cancion3.mp3"};
int totalCanciones = 3;
int cancionActual = 0;

/*
- Paran la música y la cierran ("stop" y "close"), son palabras del MCI (media control interface) de windows
- Son codigos predeterminados para indicar acciones de reproducción de contenidos (play, stop, pause, resume...)
- NULL es como decirle a windows "No necesito que me regreses información" (El primer NULL)
- El "0" es para tener un buffer (almacenamiento temporal) de lo que sea que reciba el primer NULL (como es NULL
no guarda ninguna información)
- El segundo NULL es para una cosa de programación avanzada
*/

void detenerMusica(){
	mciSendString("stop musica", NULL, 0, NULL);
	mciSendString("close musica", NULL, 0, NULL);
}

void reproducirMusica(){
	//Primero se tiene que parar cualquier musica que haya estado sonando
	detenerMusica();
	
	/*
	- Se abre la canción acutal y se le apoda "musica" para que el MCI la pueda controlar
	- type mpegvideo: le cuenta al sistema que el archivo a abrir es un audio o video comprimido (MP3 ó MP4)
	- alias musica: se le asigna el alias de musica a la canción actual para no tener que ingresar la ruta de
	nombre todas las veces que nos queramos referir a ese archivo
	*/
	
	string comando = "open \"" + playlist[cancionActual] + "\" type mpegvideo alias musica";
	
	/*
	- .c_str() -> convierte un "objeto moderno" (ej. string) en un arreglo tradicional de caracteres
	- Como windows está montado sobre C, es necesario hacer esta traducción para que el codigo pueda leer
	la ruta del archivo sin problema, ya que C no reconoce strings, solo arreglos de caracteres
	*/
	
	mciSendString(comando.c_str(), NULL, 0, NULL);
	mciSendString("play musica", NULL, 0, NULL);
}

//Esta función permite que el juego use la playlist para reproducir la música
void revisarLoopMusica(){
	
	/*
	- Este buffer permite recibir el dato que windows nos de con respecto al estado del archivo
	si está detenido manda un "stopped", reproduciendo un "playing", etc. Con el fin de guardar
	el estado del archivo, se crea un buffer de 128 bytes que sea lo suficientemente grande para guardar
	las palabras clave que mande el MCI de windows, ya que por letra es un byte y por palabras entre 7 y 8 bytes
	*/
	
	char buffer[128];
	
	/*Se le pregunta a windows el estado de la música (se supone que ya entiendes esto)
	mode es para saber si esta abierto o cerrado y status si se reproduce o no*/
	mciSendString("status musica mode", buffer, sizeof(buffer), NULL);
	
	//Se convierte el arreglo de caracteres es un string moderno
	string estado(buffer);
	
	/*Si el texto que devolvió el buffer es "stopped", la canción habría acabado. la funcion "npos" es una
	función especial de C++ que busca en todo un string que significa "No encontrado"; es verdadera
	si en el texto no se encuentra en un string, y es falsa si el texto si se encuentra en un string*/
	if (estado.find("stopped") != string::npos){
		
		//Salta a la canción siguiente
		cancionActual += 1;
		
		/*Si el indice de la canción actual es igual al total de canciones en la lista
		vuelve al indice 0 otra vez para seguir el bucle*/
		if (cancionActual >= totalCanciones){
			cancionActual = 0;
		}
		
		//Reproduce la canción con el nuevo indice (la siguiente canción o el bucle)
		reproducirMusica();
	}
}

//Codigo General
int main(){
	//Inicia a reproducir la música
	reproducirMusica();
	
	//Inicia el juego
	int opcionGeneral = 0;
	while (opcionGeneral != 3 && opcionGeneral != 4){
		int opcion = 0;
		do{
			menuGUI();
			cin>>opcion;
			if (cin.fail()){
				cin.clear();
				//El primer parametro dentro del ignore es una cantidad de letras que el programa limpiara y borrara del buffer
				//El segundo es el limite, en este caso, cuando se encuentre un \n se simpia y se boora todo del buffer
				cin.ignore(10000, '\n');
				cout<<endl<<"\t\t\t\t\t\t\t       Introduzca un NUMERO, por favor"<<endl<<endl;
				this_thread::sleep_for(chrono::milliseconds(2000));
				//Pendiente con esto de aqui abajo
				cout<<"\033[2J\033[3J\033[H"<<flush;
				opcion = 0;
				continue;
			}
			
			cin.ignore(10000, '\n');
			
			if (opcion != 1 && opcion != 2 && opcion != 3){
				cout<<endl<<"\t\t\t\t\t\t\t\t       "<<"Opcion no valida"<<endl<<endl;
				this_thread::sleep_for(chrono::milliseconds(2000));
			}
			
			//ANSI Escape Sequences - Toca buscar que es eso para el informe
			//"\033[2J" Limpia la pantalla visible
			//"\033[3J" Limpia lo que se imprimio (el buffer)
			//"\033[H" te lleva hasta el orgien de la impresion por consola (Esquina superior izq.)
			cout<<"\033[2J\033[3J\033[H"<<flush;
			
		} while (opcion != 1 && opcion != 2 && opcion != 3);
		
		if (menuOpciones(opcion) == 0){
			break;
		}
		
		//Saldo Inicial
		int saldo;
		if (opcion == 1){
			saldo = 100;
		} else if (opcion == 2){
			//Saldo Guardado
			ifstream loadFile("input-output/saveFile.txt");
			
			//El operador >> descarta automaticamente cualquier espacio o cantidad de espacios en blanco
			//Lo que permite, o permitira editar sin problema el saveFile para partidas personalizadas
			string line;
			string etiqueta;
			int saveSaldo;
			
			getline(loadFile, line);
			stringstream data(line);
			
			//Así extrae, es necesario estudiar esto para el informe
			data >> etiqueta >> saveSaldo;
			
			saldo = saveSaldo;
		}
		
		
		//Sistema de guardado
		while (opcion == 1 || opcion == 2){
			//Revisa si hay que saltar de canción o no
			revisarLoopMusica();
			int apuestaActual = 0;
			saldo = logicaApuestas(saldo, "bet", "", &apuestaActual);
			//Toca agregar lo de continuar, guardar, etc. para poder hacer un while que corra
			//el juego mientras se elija continuar. Que actue con respecto a la decisión del jugador
			int resultado = logicaCartas(saldo, &apuestaActual);
			if (resultado == 0){
				saldo = logicaApuestas(saldo, "calc", "E", &apuestaActual);
			} else if (resultado == 1){
				saldo = logicaApuestas(saldo, "calc", "W", &apuestaActual);
			} else if (resultado == 2){
				saldo = logicaApuestas(saldo, "calc", "W21", &apuestaActual);
			} else if (resultado == 3){
				saldo = logicaApuestas(saldo, "calc", "L", &apuestaActual);
			} else if (resultado == 4){
				saldo = logicaApuestas(saldo, "calc", "LDD", &apuestaActual);
			} else if (resultado == 5){
				saldo = logicaApuestas(saldo, "calc", "WDD", &apuestaActual);
			}
			cout<<"\nTu nuevo saldo es: $"<<saldo<<endl<<endl;
			
			if (saldo <= 0){
				cout<<"Perdiste el juego!\n";
				this_thread::sleep_for(chrono::milliseconds(10000));
				opcionGeneral = 1;
				if (opcionGeneral == 1){
					break;
				}
			}
			
			while (true){
				opcionGeneral = opcionesGenerales(&opcionGeneral, saldo);
				if (opcionGeneral == 0){
					break;
				} else if (opcionGeneral == 1){
					break;
				} else if (opcionGeneral == 2){
					break;
				} else if (opcionGeneral == 3){
					break;
				} else if (opcionGeneral == 4){
					break;
				}
			}
			
			if (opcionGeneral == 1 || opcionGeneral == 3 || opcionGeneral == 4){
				break;
			} else if (opcionGeneral == 0 || opcionGeneral == 2){
				continue;
			}
		}
		
		if (opcionGeneral == 1){
			cout<<"\033[2J\033[3J\033[H"<<flush;
			//Hay que resetear las variables de control para que no tome los valores anteriores
			opcion = 0;
			opcionGeneral = 0;
			continue;
		} else if (opcionGeneral == 3 || opcionGeneral == 4){
			break;
		}
	}
	return 0;
}
