#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;
//structura para la pila
struct Nodo{
	char dato;
	Nodo *siguiente;
};
//estructura para la cola
struct Nodo2{
	char dato2;
	Nodo2 *siguiente2;
};
//Estructura para obtener el resultado de las opercines e insertar los datos tipo entero 
struct Nodo3{
	float dato;
	Nodo3 *siguiente; 
};
void menu();
void inPila(Nodo *&,char);
void inPos(Nodo2 *&,Nodo2 *&,char);
void vaciarParentesis(Nodo *&,Nodo2 *&,Nodo2 *&);
void cambio(Nodo *&,Nodo2 *&,Nodo2 *&,char);
bool menor(char,int);
void vaciarPila(Nodo *&,Nodo2 *&,Nodo2 *&);
void vaciarCola(Nodo2 *&);
void resultado2(Nodo3 *&,float);
void operaciones(Nodo3 *&,float);
void cambio2(Nodo *&,Nodo2 *&,Nodo2 *&,char);

//Funcion principal
int main(){
	Nodo *pila=NULL;
	Nodo *auxPila=NULL;
	Nodo2 *frente=NULL;
	Nodo2 *fin=NULL;
	Nodo *aux=NULL;
	Nodo2 *auxMostrar=NULL;
	Nodo2 *auxMostrar2=NULL;
	Nodo3 *pila3=NULL;
	Nodo2 *ptrFrente=NULL;
	float resultado;
	char opcion;//variable para elegir la opcion del menu
	int numCaracteres;//Variable que almacenara el numero de caracteres que se van a ingresar
	char *caracter;//Variable para crear arreglo de caracteres dinamico
	char auxCaracter;//Variable que guardara los caracteres del arreglo y para pasar los caracteres a las funciones 
	char auxC;//Variable que servira como auxiliar para eliminar el caracter ( de la pila
	int posicion=0;//Envia una posicion para comparar los caracteres
	
	do{
		menu();
		cin>>opcion;
		fflush(stdin);
		switch(opcion){
			case '1':
				cout<<"\n1.Insertar datos."<<endl
				    <<"\nCuantos caracteres desea ingresar? "; cin>>numCaracteres;
				fflush(stdin);
				caracter = new char[numCaracteres];
				cout<<"\nIngresar expresion matematica: "; cin.getline(caracter,numCaracteres+10,'\n');//+50 para que el programa no se cicle si se ingresan mas caracteres 
				fflush(stdin);
				for(int i=0; i<numCaracteres; i++){
					auxCaracter=caracter[i];
					cout<<auxCaracter<<" ";
					switch(auxCaracter){
						case '(':
							inPila(pila,auxCaracter);
							break;
						case ')':
							while(pila->dato !='('){
								vaciarParentesis(pila,frente,fin);
							}
							aux = pila;
							auxC = aux->dato;
							pila = aux->siguiente;
							delete aux;
							break;
						case '+':
							if(pila==NULL){
								inPila(pila,auxCaracter);
							}else if(pila->dato==auxCaracter){
								inPos(frente,fin,auxCaracter);
							}else if(pila->dato=='('){
								inPila(pila,auxCaracter);
							}else{
								cambio(pila,frente,fin,auxCaracter);
							}
							if(pila !=NULL){
								if(pila->siguiente !=NULL){
									switch(pila->siguiente->dato){
										case '-':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
					            		case '+':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
					            		case '*':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
					            		case '/':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
					            		case '^':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
									}
								}
							}
							break;
						case '-':
							if(pila==NULL){
								inPila(pila,auxCaracter);
							}else if(pila->dato==auxCaracter){
								inPos(frente,fin,auxCaracter);
							}else if(pila->dato=='('){
								inPila(pila,auxCaracter);
							}else{
								cambio(pila,frente,fin,auxCaracter);
							}
							if(pila !=NULL){
								if(pila->siguiente !=NULL){
									switch(pila->siguiente->dato){
										case '-':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
					            		case '+':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
					            		case '*':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
					            		case '/':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
					            		case '^':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
									}
								}
							}
							break;
						case '*':
							posicion=2;
							if(pila==NULL){
								inPila(pila,auxCaracter);
							}else if(pila->dato==auxCaracter){
								inPos(frente,fin,auxCaracter);
							}else if(pila->dato=='('){
								inPila(pila,auxCaracter);
							}else if(menor(auxCaracter,posicion)){
								cambio(pila,frente,fin,auxCaracter);
							}else{
								inPila(pila,auxCaracter);
							}
							if(pila !=NULL){
								if(pila->siguiente !=NULL){
									switch(pila->siguiente->dato){
					            		case '*':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
					            		case '/':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
					            		case '^':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
									}
								}
							}
							break;
						case '/':
							posicion=3;
							if(pila==NULL){
								inPila(pila,auxCaracter);
							}else if(pila->dato==auxCaracter){
								inPos(frente,fin,auxCaracter);
							}else if(pila->dato=='*'){
								cambio(pila,frente,fin,auxCaracter);
							}else if(pila->dato=='('){
								inPila(pila,auxCaracter);
							}else if(menor(auxCaracter,posicion)){
								cambio(pila,frente,fin,auxCaracter);
							}else{
								inPila(pila,auxCaracter);
							}
							if(pila !=NULL){
								if(pila->siguiente !=NULL){
									switch(pila->siguiente->dato){
					            		case '*':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
					            		case '/':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
					            		case '^':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
									}
								}
							}
							break;
						case '^':
							posicion=1;
							if(pila==NULL){
								inPila(pila,auxCaracter);
							}else if(pila->dato==auxCaracter){
								inPos(frente,fin,auxCaracter);
							}else if(pila->dato=='('){
								inPila(pila,auxCaracter);
							}else if(menor(auxCaracter,posicion)){
								cambio(pila,frente,fin,auxCaracter);
							}else{
								inPila(pila,auxCaracter);
							}
							if(pila !=NULL){
								if(pila->siguiente !=NULL){
									switch(pila->siguiente->dato){
										case '^':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
									}
								}
							}
							break;
						default:
							inPos(frente,fin,auxCaracter);
							break;
					}
				}
				//Si pila diferente de NULL hay datos en la pila 
				while(pila !=NULL){
					vaciarPila(pila,frente,fin);//Vaciando la pila y insertantodos en la cola
				}
				break;
			case '2':
				cout<<"2.Mostrar datos."<<endl
				    <<"Datos en postorden: ";
				auxMostrar = frente;
				while(auxMostrar !=NULL){
					cout<<auxMostrar->dato2<<" ";
					auxMostrar=auxMostrar->siguiente2;
				}
				break;
			case '3':
				ptrFrente=frente;
				while(ptrFrente !=NULL){
					switch(ptrFrente->dato2){
						case '^':
							resultado=pow(pila3->siguiente->dato,pila3->dato);
							operaciones(pila3,resultado);
							break;
						case '*':
							resultado=pila3->siguiente->dato*pila3->dato;
							operaciones(pila3,resultado);
							break;
						case '/':
							resultado=pila3->siguiente->dato/pila3->dato;
							operaciones(pila3,resultado);
							break;
						case '+':
							resultado=pila3->siguiente->dato+pila3->dato;
							operaciones(pila3,resultado);
							break;
						case '-':
							resultado=pila3->siguiente->dato-pila3->dato;
							operaciones(pila3,resultado);
							break;
						default:
							char auxCaracter3=ptrFrente->dato2;
							float convertir = auxCaracter3-'0';
							resultado2(pila3,convertir);
							break;
					}
					ptrFrente=ptrFrente->siguiente2;
				}
				cout<<"\nEl resultado es: "<<pila3->dato;
				break;
			case '4':
				cout<<"\n3.Eliminar datos."<<endl;
				while(frente !=NULL){
					vaciarCola(frente);
				}
				break;
			case '5':
			    cout<<"\nSalio del programa correctamente..."<<endl;
				break;
			default:
				cout<<"\nError: Opcion invalida."<<endl;
				break;
		}
		cout<<"\nPresione una tecla para continuar."<<endl;
		getch();//Pausa en el programa
		system("cls");//Limpiar pantalla
	}while(opcion !='5');
	return 0;
}//Fin de funcion principal

//Funcion para mostrar menu al usuario
void menu(){
	cout<<"\n\tMENU"<<endl
	    <<"1.Insertar caracteres a la lista."<<endl
	    <<"2.Mostrar datos de la lista."<<endl
	    <<"3.Mostrar resultado."<<endl
	    <<"4.Eliminar datos."<<endl
	    <<"5.Salir del programa."<<endl
	    <<"Ingresar el numero de opcion: ";
}
//Funcion para agregar caracteres a la pila 
void inPila(Nodo *&pila,char dato){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->dato = dato;
	nuevoNodo->siguiente = pila;
	pila = nuevoNodo;
}
//Se insertan los caracteres ordenados en postorden
void inPos(Nodo2 *&frente,Nodo2 *&fin,char dato){
	Nodo2 *nuevoNodo2 = new Nodo2();
	nuevoNodo2->dato2 = dato;
	if(frente==NULL){
		frente=nuevoNodo2;
	}else{
		fin->siguiente2 = nuevoNodo2;
	}
	fin=nuevoNodo2;
}
//al encontrar un caracter ) vacia la pila hasta el caracter (
void vaciarParentesis(Nodo *&pila,Nodo2 *&frente,Nodo2 *&fin){
	Nodo *aux = pila;
	char auxCaracter;
	auxCaracter = aux->dato;
	inPos(frente,fin,auxCaracter);
	pila = aux->siguiente;
	delete aux;
}
//Hace el cambio en la pila y manda el nuevo dato a la cola
void cambio(Nodo *&pila,Nodo2 *&frente,Nodo2 *&fin,char auxDato){
	Nodo *aux=pila;
	char auxCaracter;
	auxCaracter = aux->dato;
	inPos(frente,fin,auxCaracter);
	pila = aux->siguiente;
	delete aux;
	inPila(pila,auxDato);
}
//Verifica la jerarquia de los signos
bool menor(char caracter,int posicion){
	char signos[]={'^','*','/','+','-'};
	for(int i=posicion; i<5; i++){
		if(caracter==signos[i]){
			return true;
		}
	}
	return false;
}
//Cuando el ciclo for termina manda todos los caracteres de la pila a la cola 
void vaciarPila(Nodo *&pila,Nodo2 *&frente,Nodo2 *&fin){
	char auxCaracter;
	Nodo *aux = NULL;
	aux = pila;
	auxCaracter = aux->dato;
	inPos(frente,fin,auxCaracter);
	pila = aux->siguiente;
	delete aux;
}
//Elimina los datos de la cola
void vaciarCola(Nodo2 *&frente){
	Nodo2 *aux = new Nodo2();
	aux = frente;
	frente = aux->siguiente2;
	delete aux;
}

void resultado2(Nodo3 *&pila3,float dato){
	Nodo3 *nuevoNodo = new Nodo3();
	nuevoNodo->dato = dato;
	nuevoNodo->siguiente = pila3;
	pila3 = nuevoNodo;
}

void operaciones(Nodo3 *&pila3,float dato){
	int auxNum;
	Nodo3 *aux = pila3;
	
	auxNum = aux->dato;
	pila3 = aux->siguiente->siguiente;
	delete aux;
	resultado2(pila3,dato);
}

void cambio2(Nodo *&pila,Nodo2 *&frente,Nodo2 *&fin,char dato){
	Nodo *aux=pila;
	char auxCaracter;
	auxCaracter = aux->dato;
	inPos(frente,fin,dato);
	pila = aux->siguiente->siguiente;
	delete aux;
	inPila(pila,auxCaracter);
}
