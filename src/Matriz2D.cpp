/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Fichero con la definición de las funciones asociadas el tipo Matriz2D
//
// Matriz2D: Matriz 2D dinamica de datos int en la que cada 
// fila es un vector dinamico independiente. 
//
// Tipo básico descrito en el video dedicado a la implementación de Matriz2D
//
// Fichero: Matriz2D.cpp
//
/***************************************************************************/

#include "Matriz2D.h"

#include <string>
using namespace std; 

/***************************************************************************/
/***************************************************************************/
// Crea una matriz dinámica con "nfils" filas y "ncols" columnas. 
// El contenido de las "fils"x"cols" casillas se inicializa a un valor común, 
// el indicado en el parámetro "valor"
// Parámetros:
//		nfils, número de filas de la matriz (por defecto 0).
//		ncols, número de columnas de la matriz (por defecto 0).
//		valor, valor común que se copiará en las casillas (por defecto 0). 
// Devuelve: un dato de tipo Matriz2D.
//
// PRE: nfils >= 0 && ncols >= 0
// NOTA: Tanto "nfils" como "nols" deben ser estrictamente positivos para poder 
// 		 disponer de una matriz no vacía. Si alguno de los dos valores fuera 0  
//		 no se reserva memoria, y la matriz queda vacía. 

Matriz2D CreaMatriz (int nfils, int ncols, TipoBase valor)
{
	// Pedir memoria para los datos
	
	Matriz2D matriz = ReservaMemoria (nfils, ncols); 
	
	// Inicializar las casillas de la matriz

	for (int f=0; f<matriz.fils; f++) 
		for (int c=0; c<matriz.cols; c++) 
			matriz.datos[f][c] = valor;

	return (matriz); 
}

/***************************************************************************/
/***************************************************************************/
// "Destruye" una matriz dinámica y la deja en un estado no útil (vacía). 
// Parámetros: 
//		matriz (referencia), la matriz que va a "destruirse". 
// POST: La matriz queda vacía (todos sus campos a cero)

void DestruyeMatriz (Matriz2D & matriz)
{
	EliminaTodos (matriz); 
}

/***************************************************************************/
/***************************************************************************/
// Reserva memoria para los datos de una matriz dinámica con "nfils" filas 
// y "ncols" columnas. 
// El contenido de las "nfils"x"ncols" casillas queda INDEFINIDO.
// Parámetros:
//		nfils, número de filas de la matriz.
//		ncols, número de columnas de la matriz. 
// Devuelve: un dato Matriz2D con memoria reservada.
// 		El contenido de las "fils"x"cols" casillas queda indefinido. 
//
// PRE: nfils >= 0 && ncols >= 0
// NOTA: Tanto "nfils" como "nols" deben ser estrictamente positivos para poder 
// 		 disponer de una matriz no vacía. Si alguno de los dos valores fuera 0  
//		 no se reserva memoria, y la matriz queda vacía. 

Matriz2D ReservaMemoria (int nfils, int ncols)
{
	Matriz2D matriz; 

	// Por defecto, matriz vacía
	matriz.datos = 0;
	matriz.fils  = 0;
	matriz.cols  = 0;

	// Solo si se cumplen las precondiciones se reserva memoria 

	if (nfils>0 && ncols>0) {


		matriz.datos = new int*[nfils];

		// "matriz" apuntará a un vector de punteros a las filas
		matriz.datos[0] = new int [nfils*ncols];
		

		for (int f=0; f<nfils; f++) {

			// "matriz[f]" apuntará a un vector de datos int
			matriz.datos[f] = matriz.datos[0] + (f*ncols);
		}

		matriz.fils = nfils;
		matriz.cols = ncols;
	}

	return (matriz);
}

/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por una matriz dinámica. 
// Parámetros: 
//		matriz (referencia), la matriz que va a "liberarse". 
// POST: La matriz queda vacía (todos sus campos a cero)

void EliminaTodos (Matriz2D & matriz)
{
	if (matriz.datos != 0) {

		// Liberar cada una de las filas
        delete [] matriz.datos[0];

 		// Liberar el vector de punteros
 		delete [] matriz.datos; 
   
		// La matriz debe quedar "vacía" --> la referencia "matriz" pone a 0 
		// el puntero que da acceso al vector de punteros a filas

		matriz.datos = 0;
		matriz.fils  = 0;
		matriz.cols  = 0;
	}
}

/***************************************************************************/
/***************************************************************************/
// Devuelve un string con el resultado de "serializar" una matriz.
// Parámetros: matriz (referencia), la matriz que va a serializarse. 

string ToString (const Matriz2D & matriz)
{
	string cad;

	string delimitador = "..................................";

	cad = "\n" + delimitador + "\n";
	cad = cad + "Filas = " + to_string(matriz.fils) + 
	      ", Columnas = " + to_string (matriz.cols) + "\n\n";

	for (int f=0; f<matriz.fils; f++) {
		cad = cad + "Fila " + to_string(f) + " --> ";
		
		for (int c=0; c<matriz.cols; c++) 
			cad = cad + to_string(matriz.datos[f][c]) + "  ";
		cad = cad + "\n";
	}
	cad = cad + delimitador + "\n\n";

	return (cad);
}

/***************************************************************************/
/***************************************************************************/


/***************************************************************************/
/***************************************************************************/
// Devuelve el número de filas/columnas de la matriz.
// Parámetros: matriz (referencia), la matriz que se va a consultar. 

int NumFilas (const Matriz2D & matriz)
{
	return (matriz.fils);
}

/***************************************************************************/
/***************************************************************************/

int NumColumnas (const Matriz2D & matriz)
{
	return (matriz.cols);
}

/***************************************************************************/
/***************************************************************************/
// Consulta ó modifica el valor de una casilla dada. Si se utiliza como 
// rvalue se emplea para consulta. Si se utiliza como lvalue se emplea 
// para modificación.
// Parámetros: matriz (referencia), la matriz. 
//			   num_fila, número de fila.
//			   num_columna, número de columna.
// PRE: 0<=num_fila<NumFilas(m)
// PRE: 0<=num_columna<NumColumnas(m)

TipoBase & Valor (const Matriz2D & matriz, int num_fila, int num_columna) 
{
	return (matriz.datos[num_fila][num_columna]);
}	

/***************************************************************************/
/***************************************************************************/
// Comprueba si la matriz dada está vacía o ocupada
// Parámetros: matriz, la matriz.

bool EstaVacia (const Matriz2D & matriz){

	bool vacia = false;

	if (!matriz.datos)
		vacia = true;

	return(vacia);

}


/***************************************************************************/
/***************************************************************************/
// Cambia todos los valores de la matriz por valor.
// Parámetros: matriz, la matriz
//			   valor, valor a establecer en toda la matriz
// PRE: matriz NO vacía

void Ecualiza (Matriz2D & matriz, TipoBase valor){

	for (int i=0; i<matriz.fils; i++)
		for (int j=0; j<matriz.cols; j++)
			matriz.datos[i][j] = valor;

}



/***************************************************************************/
/***************************************************************************/
// Hace una copia profunda de origen en destino
// Parámetros: destino, la matriz donde se va a clonar origen
//		       origen, la matriz a clonar

void Clona (Matriz2D & destino, const Matriz2D & origen){








}


/***************************************************************************/
/***************************************************************************/
// Comprueba si dos matrices son iguales en dimensiones y contenido
// Parámetros: una, la primera matriz
//			   otra, la segunda matriz

bool SonIguales (const Matriz2D & una, const Matriz2D & otra){

	bool Iguales = true;
	int i;

	if (una.cols != otra.cols)
		Iguales = false;
	
	if(una.fils != otra.fils)
		Iguales = false;

	while (i < una.fils && Iguales){

		int j = 0;

		while(j < una.cols && Iguales){
			
			if (una.datos[i][j] != otra.datos[i][j])
				Iguales = false;
			else
				j++;

		}

		i++;
	}

	
	return (Iguales);


}



			   
