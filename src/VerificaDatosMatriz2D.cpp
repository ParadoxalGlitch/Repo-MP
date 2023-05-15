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

using namespace std;


int main(){

	bool correcto = false;
	string linea;


	// Compruebo que esté la palabra "MATRIZ2D"

	cin >> linea;

	if (linea != "MATRIZ2D"){

		correcto = false;

	}

	// Compruebo que los siguientes dos numeros son numeros y son enteros

	cin >> linea

	if (stoi(linea))
	
}