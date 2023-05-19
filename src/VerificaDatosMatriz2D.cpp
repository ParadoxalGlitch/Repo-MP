/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: VerificaDatosMatriz2D.cpp
//
// Programa que lee un fichero de datos para Matriz2D y comprueba si es
// válido 
//
/***************************************************************************/

#include <iostream>
#include <sstream>

using namespace std;


int main(){

	bool correcto = true;
	string linea;
	int filas = 0;
	int columnas = 0;
	int num_elementos = 0;
	int contador_elementos = 0;


	// Compruebo que esté la palabra "MATRIZ2D"

	getline (cin, linea);

	if (linea != "MATRIZ2D"){

		correcto = false;

	}

	else{

		// Compruebo los valores de filas y columnas

		cin >> filas;
		cin >> columnas;

		// Calculo el número de elementos que se espera recibir

		num_elementos = filas*columnas;

		// Si el numero es negativo, lo pongo a 0

		if (num_elementos < 0){

			num_elementos = 0;
		}


		// Recorrro el resto del fichero comprobando cuantos números hay

		string palabra;
		while (cin >> palabra && sigo){ // Comprobar q haya las justas
			// comprobar si es entero
			contador_elementos++;
		}
		
	}

	// Comprobar que no hay mas datos despues


	if (contador_elementos != num_elementos) // esto sobraría
		correcto = false;


	if (correcto)
		cout << "El fichero es válido" << endl;

	else
		cout << "EL fichero no es válido" << endl;


	return (0);
	
}