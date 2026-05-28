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
			if (*apuesta > saldoRonda || *apuesta < 0){
				cout<<"\nValor de apuesta invalido, por favor intente de nuevo\n\n";
				this_thread::sleep_for(chrono::milliseconds(2000));
				//Pendiente con esto de aqui abajo
				cout<<"\033[2J\033[3J\033[H"<<flush;
			} else if (*apuesta <= saldoRonda && *apuesta > 0){
				cout<<"Apostara $"<<*apuesta<<endl;
				cout<<"Saldo $"<<saldoRonda - *apuesta<<endl<<endl;
				break;
			}
		}
		
	} else if (accion == "calc"){
		
		//Este te descuenta la apuesta para hacer los calculos reales
		saldoRonda -= *apuesta;
		
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
	int sumaPlayer = 0;
	int sumaDealer = 0;
		
	for (int i = 0; i < cartasPlayer.size(); i++){
		sumaPlayer += cartasPlayer[i];
	}
		
	for (int i = 0; i < cartasDealer.size(); i++){
		sumaDealer += cartasDealer[i];
	}
		
	if (sumaDealer == 21 && sumaPlayer != 21){
		cout<<"El dealer saco 21!\n";
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
			cout<<"\nLa carta visible del dealer es:\n";
			cout<<cartasDealerPinta[0]<<" "<<cartasDealerStr[0]<<endl;
			continue;
		}
		cout<<"\n";
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
					cout<<" - Suma: "<<sumaPlayer<<endl;
					
					if (sumaPlayer > 21){
						cout<<"Te pasate de 21! - Perdida automatica\n"<<endl<<"Las cartas del dealer fueron:";
						for (int i = 0; i < cartasDealer.size(); i++){
							cout<<endl<<cartasDealerPinta[i]<<" "<<cartasDealer[i];
						}
						cout<<endl;
						//Return 3 significa perder la partida 
						return 3;
					} else if (sumaPlayer == 21){
						cout<<"Sacaste 21!\n";
						cout<<"Suma del dealer: "<<sumaDealer<<endl<<"Las cartas del dealer fueron:";
						for (int i = 0; i < cartasDealer.size(); i++){
							cout<<endl<<cartasDealerPinta[i]<<" "<<cartasDealer[i];
						}
						cout<<endl;
						//Return 1 significa ganar la partida
						return 1;
					}
				} else {
					cout<<"Tu carta nueva es: "<<pintas[pinta]<<" "<<cartasStr[pinta][carta];
					cout<<" - Suma: "<<sumaPlayer<<endl;
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
				
				if (sumaDealer > 21){
					cout<<"El dealer se paso de 21\n";
					cout<<"Las cartas del dealer fueron:";
					for (int i = 0; i < cartasDealer.size(); i++){
						cout<<endl<<cartasDealerPinta[i]<<" "<<cartasDealer[i];
					}
					cout<<"\nSuma: "<<sumaDealer<<endl;
					//Return 1 significa ganar la partida
					return 1;
				}
				
				if (sumaDealer == sumaPlayer){
					cout<<"Fue un empate!\n";
					cout<<"Suma tuya: "<<sumaPlayer<<" - Suma del dealer: "<<sumaDealer<<endl<<"Las cartas del dealer fueron:";
					for (int i = 0; i < cartasDealer.size(); i++){
						cout<<endl<<cartasDealerPinta[i]<<" "<<cartasDealer[i];
					}
					cout<<endl;
					//Return 0 significa empate
					return 0;
				} else if (sumaDealer > sumaPlayer){
					cout<<"El dealer estuvo mas cerca de 21\n";
					cout<<"Suma del dealer: "<<sumaDealer<<endl<<"Las cartas del dealer fueron:";
					for (int i = 0; i < cartasDealer.size(); i++){
						cout<<endl<<cartasDealerPinta[i]<<" "<<cartasDealer[i];
					}
					cout<<endl;
					//Return 3 significa perder la partida 
					return 3;
				} else if (sumaPlayer == 21){
					cout<<"Sacaste 21!\n";
					cout<<"Suma del dealer: "<<sumaDealer<<endl<<"Las cartas del dealer fueron:";
					for (int i = 0; i < cartasDealer.size(); i++){
						cout<<endl<<cartasDealerPinta[i]<<" "<<cartasDealer[i];
					}
					cout<<endl;
					//Return 1 significa ganar la partida
					return 1;
				} else if (sumaDealer < sumaPlayer){
					cout<<"Estuviste mas cerca de 21 que el dealer\n";
					cout<<"Suma del dealer: "<<sumaDealer<<" - Suma tuya: "<<sumaPlayer<<endl<<"Las cartas del dealer fueron:";
					for (int i = 0; i < cartasDealer.size(); i++){
						cout<<endl<<cartasDealerPinta[i]<<" "<<cartasDealer[i];
					}
					cout<<endl;
					//Return 1 significa ganar la partida
					return 1;
				}
				//Return 6 solo acaba el codigo			
				return 6;
			}
			
			case 3:{
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
					cout<<" - Suma: "<<sumaPlayer<<endl<<endl;
					
					if (sumaPlayer > 21){
						cout<<"Te pasate de 21! - Perdida automatica\n"<<endl<<"Las cartas del dealer fueron:";
						for (int i = 0; i < cartasDealer.size(); i++){
							cout<<endl<<cartasDealerPinta[i]<<" "<<cartasDealer[i];
						}
						cout<<endl;
						//Return 4 significa perder la partida en double down
						return 4;
					} else if (sumaPlayer == 21){
						cout<<"Sacaste 21!\n";
						cout<<"Suma del dealer: "<<sumaDealer<<endl<<"Las cartas del dealer fueron: ";
						for (int i = 0; i < cartasDealer.size(); i++){
							cout<<endl<<cartasDealerPinta[i]<<" "<<cartasDealer[i];
						}
						cout<<endl;
						//Return 5 significa ganar la partida en double down
						return 5;
					}
					
				} else {
					cout<<"Tu carta nueva es: "<<pintas[pinta]<<" "<<cartasStr[pinta][carta];
					cout<<" - Suma: "<<sumaPlayer<<endl<<endl;
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
					
					//cout<<pintas[pinta]<<" "<<cartasStr[pinta][carta]<<endl;
					cartasDealer.push_back(cartas[pinta][carta]);
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
				
				if (sumaDealer > 21){
					cout<<"El dealer se paso de 21\n";
					cout<<"Las cartas del dealer fueron:";
					for (int i = 0; i < cartasDealer.size(); i++){
						cout<<endl<<cartasDealerPinta[i]<<" "<<cartasDealer[i];
					}
					cout<<"\nSuma: "<<sumaDealer<<endl;
					//Return 5 significa ganar la partida en double down
					return 5;
				}
				
				if (sumaDealer == sumaPlayer){
					cout<<"Fue un empate!\n";
					cout<<"Suma tuya: "<<sumaPlayer<<" - Suma del dealer: "<<sumaDealer<<endl<<"Las cartas del dealer fueron:";
					for (int i = 0; i < cartasDealer.size(); i++){
						cout<<endl<<cartasDealerPinta[i]<<" "<<cartasDealer[i];
					}
					cout<<endl;
					//Return 0 significa empate
					return 0;
				} else if (sumaDealer > sumaPlayer){
					cout<<"El dealer estuvo mas cerca de 21\n";
					cout<<"Suma del dealer: "<<sumaDealer<<endl<<"Las cartas del dealer fueron:";
					for (int i = 0; i < cartasDealer.size(); i++){
						cout<<endl<<cartasDealerPinta[i]<<" "<<cartasDealer[i];
					}
					cout<<endl;
					//Return 4 significa perder la partida en double down
					return 4;
				} else if (sumaPlayer == 21){
					cout<<"Sacaste 21!\n";
					cout<<"Suma del dealer: "<<sumaDealer<<endl<<"Las cartas del dealer fueron:";
					for (int i = 0; i < cartasDealer.size(); i++){
						cout<<endl<<cartasDealerPinta[i]<<" "<<cartasDealer[i];
					}
					cout<<endl;
					//Return 5 significa ganar la partida en double down
					return 5;
				} else if (sumaDealer < sumaPlayer){
					cout<<"Estuviste mas cerca de 21 que el dealer\n";
					cout<<"Suma del dealer: "<<sumaDealer<<" - Suma tuya: "<<sumaPlayer<<endl<<"Las cartas del dealer fueron:";
					for (int i = 0; i < cartasDealer.size(); i++){
						cout<<endl<<cartasDealerPinta[i]<<" "<<cartasDealer[i];
					}
					cout<<endl;
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
				cout<<"\nLa carta visible del dealer es:\n";
				cout<<cartasDealerPinta[0]<<" "<<cartasDealerStr[0]<<endl;
				continue;
			}
		}
	}
	//Return salvavidas por si pasa algo
	return 0;
}

int opcionesGenerales(){
	while (true){
		cout<<"Que desea hacer?\n";
		cout<<"\t1. Continuar la partida\n";
		cout<<"\t2. Guardar la partida\n";
		cout<<"\t3. Guardar y salir\n";
		cout<<"\t4. Salir sin guardar\n";
		cout<<endl<<"Digite su opcion: ";
		int opcionGeneral;
		cin>>opcionGeneral;
		if (cin.fail()){
			cin.clear();
			//El primer parametro dentro del ignore es una cantidad de letras que el programa limpiara y borrara del buffer
			//El segundo es el limite, en este caso, cuando se encuentre un \n se simpia y se boora todo del buffer
			cin.ignore(10000, '\n');
			cout<<endl<<"Entrada invalida. Ingrese un NUMERO"<<endl<<endl;
			continue;
		}
		/*switch(){
			//Continuar Juego
			case 1:
			
			//Guardar Juego
			case 2:
			
			//Guardar y Salir
			case 3:
			
			//Salir Sin Guardar
			case 4:
			
			default:
				cout<<"Entrada invalida. No esta dentro de las opciones"<<endl<<endl;
				cout<<"¿Que desea hacer?\n";
				cout<<"\t1. Continuar la partida\n";
				cout<<"\t2. Guardar la partida\n";
				cout<<"\t3. Guardar y salir\n";
				cout<<"\t4. Salir sin guardar\n";
				continue;
		}*/
	}
}

//Codigo General
int main(){
	int opcion;
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
	
	menuOpciones(opcion);
	
	//Saldo Inicial
	int saldo = 100;
	
	//Sistema de guardado
	while (opcion == 1){
		int apuestaActual = 0;
		logicaApuestas(saldo, "bet", "", &apuestaActual);
		//Toca agregar lo de continuar, guardar, etc. para poder hacer un while que corra
		//el juego mientras se elija continuar. Que actue con respecto a la decisión del jugador
		int resultado = logicaCartas();
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
		
		opcionesGenerales();
	}
	
	return 0;
}
