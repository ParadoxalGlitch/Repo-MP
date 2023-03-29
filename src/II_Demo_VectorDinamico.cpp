/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: II_Demo_VectorDinamico.cpp
//
// Contiene el demo de las funciones de VectorDinamico
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

#include "FuncsVectorDinamico.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/

int main (int argc, char * argv[])
{

	TipoRedimension ModoRedimension;

	if (argc > 2){
        cerr << "Error: demasiados argumentos" << endl;

        //Mensaje de ayuda
        cerr << "Argumentos posibles: " << endl;
        cerr << "arg 1: Modo de redimensión (1 = De uno en uno,";
        cerr << " 2 = En bloques fijos, 3 = Duplicando tamaño)";
		cerr << endl << endl;
        exit (1);
    }

	else if (argc == 1)
		ModoRedimension = (TipoRedimension) 0;

	else if (argc == 2){
			
		if (atoi(argv[1]) > 3 || atoi(argv[1]) < 1 ){
			cerr << "Error: valor del argumento inválido.";
			cerr << endl << "Este debe ser entre 1 y 3";
			cerr << endl;
			exit(1);
		}

		else	
			ModoRedimension = (TipoRedimension) (atoi(argv[1])-1);

	}
	// ......................................................................
	// Crear un vector dinámico
	
	VectorDinamico v = CreaVectorDinamico(10,ModoRedimension); 

	// Se han reservado TAM_INICIAL casillas y se están usando 0.
	

	// ......................................................................
	// Leer valores y guardarlos en el vector dinámico. 
	// El redimensionamiento se produce cuando no hay espacio para otro dato. 
	// La función "AniadeVectorDinamico" es la que se encarga del 
	// redimensionamiento cuando sea necesario.
	
	const int TAM_CAD = 20;
	char  valor[TAM_CAD];

	// Primera lectura
	cout << "Introducir un valor (FIN para finalizar): "; 
	cin.getline (valor, TAM_CAD);

	while (strcmp(valor, "FIN")) {

		int el_valor = atoi (valor); 

		// Añadir "valor". Si no cabe se redimensiona 

		AniadeVectorDinamico (v, el_valor);

		// Nueva lectura
		cout << "Introducir un valor (FIN para finalizar): "; 
		cin.getline (valor, TAM_CAD);
	}




	// ......................................................................
	// Muestra el vector

	cout << endl;
	cout << ToString (v);
	cout << endl;






	// ......................................................................
	// Reajusta y muestra el vector

	ReajustaVectorDinamico (v);

	cout << endl;
	cout << ToString (v);
	cout << endl;






	// ......................................................................
	// Muestro su capacidad
	cout << "// Prueba CapacidadVectorDinamico //";
	cout << endl << endl;

	cout << "Capacidad del vector dinámico: " << CapacidadVectorDinamico(v);
	cout << endl << endl;






	// ......................................................................
	// Creo un vector dinámico vacío y compruebo si lo está

	cout << "// Prueba EliminaTodosVectorDinamico, ";
	cout << "EstaVacioVectorDinamico y AniadeVectorDinamico //";
	cout << endl << endl;

	VectorDinamico prueba = CreaVectorDinamico ();

	cout << "Se ha creado un vector vacío";
	cout << endl;

	if(EstaVacioVectorDinamico(prueba))
		cout << "El nuevo vector creado está vacío";
	
	else
		cout << "El nuevo vector creado no está vacío";

	cout << endl << endl;




	


	// ......................................................................
	// Añado un valor al nuevo vector y compruebo si está vacío

	AniadeVectorDinamico(prueba, 6);

	cout << "Se ha añadido el numero 6 al nuevo vector";
	cout << endl;

	if(EstaVacioVectorDinamico(prueba))
		cout << "AHora el nuevo vector creado está vacío";
	
	else
		cout << "Ahora el nuevo vector creado no está vacío";

	cout << endl << endl;
	




	
	// ......................................................................
	// Vuelvo a dejar el vector vacío y compruebo si lo está


	EliminaTodosVectorDinamico(prueba);

	cout << "Se ha eliminado todo el contendio del nuevo vector";
	cout << endl;

	if(EstaVacioVectorDinamico(prueba))
		cout << "Ahora el nuevo vector creado está vacío";
	
	else
		cout << "Ahora el nuevo vector creado no está vacío";

	cout << endl << endl;







	// ......................................................................
	// Relleno el vector hasta su capacidad máxima con un valor y lo imprimo

	cout << "// Prueba EcualizaVectorDinámico //";
	cout << endl << endl;

	EcualizaVectorDinamico(prueba, 7);

	cout << "He rellenado todo el vector nuevo con 7";
	cout << endl;
	cout << ToString(prueba);
	cout << endl << endl;







	// ......................................................................
	// Modifico la casilla 2 del vector nuevo con un 6, lo muestro y leo
	// dicho valor

	cout << "// Prueba ValorVectorDInamico //";
	cout << endl << endl;

	ValorVectorDinamico(prueba, 2) = 6;
	cout << "He modificado la casilla 2 con el valor ";
	cout << ValorVectorDinamico(prueba, 2);
	cout << endl << endl;

	cout << ToString(prueba);
	cout << endl << endl;







	// ......................................................................
	// Clono el vector v sobre el vector nuevo

	cout << "// Prueba ClonaVectorDinamico //";
	cout << endl << endl;

	ClonaVectorDinamico(prueba, v);
	cout << "He clonado el vector v en el vector prueba";

	cout << endl;
	cout << ToString(prueba);
	cout << endl << endl; 







	// ......................................................................
	// Inserto en la casilla 4 el valor 9 y elimino el valor de la casilla 2
	// y muestro cuantos se han usado


	cout << "// Prueba InsertaVectorDinamico, EliminaVectorDinamico y ";
	cout << "UsadosVectorDinámico //";
	cout << endl << endl;

	InsertaVectorDinamico(v, 9, 3);
	cout << "He insertado el valor 9 en la casilla 4";

	cout << endl;
	cout << ToString(v);
	cout << endl << endl;

	EliminaVectorDinamico(v, 2);
	cout << "He eliminado el valor de la casilla 2";

	cout << endl;
	cout << ToString(v);
	cout << endl << endl;

	cout << "Se han usado " << UsadosVectorDinamico(v) << " elementos en v ";
	cout << "la ultima vez que se modificó";
	cout << endl << endl;









	// ......................................................................
	// Liberar memoria
	
	cout << "Liberando memoria ocupada por ambos vectores" << endl;
	cout << endl;

	DestruyeVectorDinamico(v);
	DestruyeVectorDinamico(prueba);
	
	return 0;
}

/***************************************************************************/
/***************************************************************************/
