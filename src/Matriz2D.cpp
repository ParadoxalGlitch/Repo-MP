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
#include <cstring>
#include <iostream>
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
// Usarse cuando no se planea usar la matriz mas
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
// Libera la memoria ocupada por una matriz dinámica. Usarse si se planea
// seguir usando la matriz
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

		matriz.datos = nullptr;
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

	// Eliminamos el contenido del destino

	EliminaTodos(destino);

	// Volvemos a inicializarla con los datos de origen

	destino = CreaMatriz(origen.fils, origen.cols);

	// Copio los datos de origen en destino

	memcpy(destino.datos[0], origen.datos[0], \
		origen.fils*origen.cols*sizeof(TipoBase));


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



/***************************************************************************/
/***************************************************************************/
// Elimina una fila de la matriz
// Parámetros: matriz, la matriz
//			   num_fila, fila a eliminar
// PRE: matriz NO vacía, valor de fila válido

void EliminaFila (Matriz2D & matriz, int num_fila){
	

	memmove(matriz.datos[num_fila], matriz.datos[num_fila+1],\
			matriz.cols*(matriz.fils - num_fila-1) *sizeof(TipoBase));

	
	// Almaceno los datos de la matriz a modificar para
	// tener acceso a ellos tras borrarla

	TipoBase * tmp = new TipoBase [matriz.fils*matriz.cols];
	memcpy(tmp, matriz.datos[0], matriz.fils*matriz.cols*sizeof(TipoBase));

	int fils = matriz.fils - 1;
	int cols = matriz.cols;


	// Elimino la memoria de la matriz y reservo nueva
	// acorde a las nuevas características

	EliminaTodos(matriz);
	matriz = CreaMatriz(fils, cols);

	// Copio el contenido en la nueva matriz
	
	memcpy(matriz.datos[0], tmp, fils*cols*sizeof(TipoBase));

	// Me deshago del vector temporal

	delete [] tmp;

}




/***************************************************************************/
/***************************************************************************/
// Elimina una columna de la matriz
// Parámetros: matriz, la matriz
//			   num_col, fila a eliminar
// PRE: matriz NO vacía, valor de columna válido

void EliminaColumna(Matriz2D & matriz, int num_col){


	// Creo Matriz auxiliar con los datos necesarios
	Matriz2D tmp = CreaMatriz(matriz.fils, (matriz.cols-1));

	// Voy fila por fila copiando los elementos que quiero 
	// saltandome la columna
	for (int i=0; i < matriz.fils; i++){
		memcpy(tmp.datos[i], matriz.datos[i], num_col*sizeof(TipoBase));
		memcpy(tmp.datos[i]+num_col, matriz.datos[i]+num_col+1, (matriz.cols-num_col-1)*sizeof(TipoBase));
	}

	Clona(matriz, tmp);

	DestruyeMatriz(tmp);

}



/***************************************************************************/
/***************************************************************************/
// Extrae una submatriz de original y la deja en resultado
// Parámetros: resultado, la submatriz resultante
//			   original, matriz original
//			   fila_inic, fila desde donde se extrae la submatriz
//			   col_inic, columa desde donde se extrae la submatriz
//		       num_filas, tamaño de filas de la submatriz
//			   num_cols, tamaño de columnas de la submatriz
// PRE: matriz NO vacía, valor de columna válido

void SubMatriz (Matriz2D & resultado, const Matriz2D & original, int fila_inic, int col_inic, int num_filas, int num_cols){


	// Compruebo que las casillas elegidas son correctas
	// De no serlo, filas o columnas, o ambas estarán a 0
	// y al crear la submatriz, esta estará vacía

	if (fila_inic < 0 || fila_inic >= original.fils)
		num_filas = 0;

	if (col_inic < 0 || col_inic >= original.cols)
		num_cols = 0;


	// Compruebo que el numero de filas y columnas que se me pide
	// es válido o no, y actualizo de acuerdo a ello

	if (num_filas > original.fils-fila_inic)
		num_filas = original.fils-fila_inic;
	
	if (num_cols > original.cols-col_inic)
		num_cols = original.cols-col_inic;

	

	// Una vez que tengo todos los parámetros comprobados
	// creo la nueva matriz


	// "Reinicio" la matriz

	EliminaTodos(resultado);

	// La inicializo con los valores calculados
	// incluso si va a quedarse vacía, la dejo inicializada
	// ya que el usuario querrá seguir usándola

	resultado = CreaMatriz(num_filas, num_cols);


	// Comienzo a copiar los valores


	for (int i=0; i<resultado.fils; i++){

		memcpy(resultado.datos[i], original.datos[i+fila_inic]+col_inic, (num_cols)*sizeof(TipoBase));

	}


}





			
