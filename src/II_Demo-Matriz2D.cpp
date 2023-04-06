/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Pruebas sobre el tipo Matriz2D
//
// Matriz2D: Matriz 2D dinamica de datos "TipoBase" en la que cada 
//           fila es un vector dinamico independiente.
//
// Fichero: Demo-BasicoMatriz2D.cpp 
//
/***************************************************************************/

#include <iostream>

#include "Matriz2D.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	// Lectura de las dimensiones de la matriz

	int num_filas, num_cols; 

	do  {
		cout << endl;
		cout << "Introduzca num. filas de la matriz: ";
		cin >> num_filas; 
	} while (num_filas <= 0);	

	do  {
		cout << endl;
		cout << "Introduzca num. columnas de la matriz: ";
		cin >> num_cols; 
	} while (num_cols <= 0);	

	cout << endl << endl;

	// .....................................................................
	// Creación de una matriz y rellenar sus casillas  

	Matriz2D m = CreaMatriz (num_filas, num_cols, 5);

	cout << "Matriz rellena: ";
	cout << ToString (m);

	// .....................................................................
	// Destruye la matriz

	DestruyeMatriz (m);






	// .....................................................................
	// Creación de una matriz (todas las casillas a cero) y mostrala 

	Matriz2D m0 = CreaMatriz (num_filas, num_cols);

	cout << "Matriz con todos 0: ";
	cout << ToString (m0);

	// .....................................................................
	// Creación de una matriz (todas las casillas a 9) y mostrala 

	Matriz2D m9 = CreaMatriz (num_filas, num_cols, 9);

	cout << "Matriz con todos 9: ";
	cout << ToString (m9);

	// .....................................................................
	// Creación de una matriz vacia (0x0, todas las casillas a 0) y mostrala 

	Matriz2D m_vacia = CreaMatriz ();

	cout << "Matriz vacia: ";
	cout << ToString (m_vacia);

	// .....................................................................
	// Destruye las matrices 

	DestruyeMatriz (m0);
	DestruyeMatriz (m9);
	DestruyeMatriz (m_vacia);

	// .....................................................................




	// .....................................................................
	// Creación de una matriz 5x4 con todas las casillas a 7 y mostrarla

	Matriz2D m7 = CreaMatriz(5,4,7);

	cout << "Matriz con todos 7: ";
	cout << ToString(m7);



	// .....................................................................
	// Modificación de algunos valores de casillas y mostrarla



	Valor(m7,0,0) = 5;
	Valor(m7,0,2) = 3;
	Valor(m7,2,1) = 4;
	Valor(m7,3,3) = 2;
	Valor(m7,4,0) = 1;
	Valor(m7,4,3) = 0;


	cout << "Matriz modificada: ";
	cout << ToString(m7);


	// .....................................................................
	// Creo una nueva matriz vacía y clono m7 en ella

	Matriz2D clon = CreaMatriz();


	cout << "Matriz prueba vacía: ";
	cout << ToString(clon);

	Clona(clon, m7);

	cout << "Matriz prueba clonada: ";
	cout << ToString(clon);


	// .....................................................................
	// Elimino la fila 3 de la matriz clon

	EliminaFila(clon, 3);

	cout << "Matriz clon con fila 3 eliminada: ";
	cout << ToString(clon);

	// .....................................................................
	// Elimino la columna 3 de la matriz clon

	EliminaColumna(clon, 0);

	cout << "Matriz clon con columna 3 eliminada: ";
	cout << ToString(clon);


	// .....................................................................
	// Destruyo la matriz clon, pues ya no la voy a usar

	DestruyeMatriz(clon);


	// .....................................................................
	// Creo una matriz nueva, llamada submatriz, donde guardaré
	// una submatriz de m7

	Matriz2D submatriz = CreaMatriz();

	SubMatriz(submatriz, m7, 2, 1, 3, 3);

	cout << "Submatriz de 3x3 supuestamente de m7: ";
	cout << ToString(submatriz);
	


	return 0; 
}



/***************************************************************************/
/***************************************************************************/