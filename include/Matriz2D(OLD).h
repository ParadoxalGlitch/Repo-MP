/*****************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: Matriz2D.h
//
// Contiene la declaración de la funciones de Matriz2D
//
/*****************************************************************************/

#ifndef MATRIZ2DOLD
#define MATRIZ2DOLD

#include <string>
#include "TipoBase.h"
using namespace std; 


/*
// Tipo de los datos almacenados (en este caso, int)
typedef int TipoBase;

// Valor por defecto del tipo de los datos almacenados
const TipoBase VALOR_DEF = 0;

*/

/***************************************************************************/
// Definiciones de tipos

typedef struct {

	int ** datos;	// Puntero a vector de punteros a los datos

	int fils;			// Num. de filas
	int cols; 			// Num. de columnas

} Matriz2D;


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

Matriz2D CreaMatriz (int nfils=0, int ncols=0, TipoBase valor=VALOR_DEF);

/***************************************************************************/
/***************************************************************************/
// "Destruye" una matriz dinámica y la deja en un estado no útil (vacía). 
// Parámetros: 
//		matriz (referencia), la matriz que va a "destruirse". 
// POST: La matriz queda vacía (todos sus campos a cero)

void DestruyeMatriz (Matriz2D & matriz);

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

Matriz2D ReservaMemoria (int nfils, int ncols);

/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por una matriz dinámica. 
// Parámetros: 
//		matriz (referencia), la matriz que va a "liberarse". 
// POST: La matriz queda vacía (todos sus campos a cero)

void EliminaTodos (Matriz2D & matriz);

/***************************************************************************/
/***************************************************************************/
// Devuelve un string con el resultado de "serializar" una matriz.
// Parámetros: matriz (referencia), la matriz que va a serializarse. 

string ToString (const Matriz2D & matriz);

/***************************************************************************/
/***************************************************************************/


/***************************************************************************/
/***************************************************************************/
// Devuelve el número de filas/columnas de la matriz.
// Parámetros: matriz (referencia), la matriz que se va a consultar. 

int NumFilas (const Matriz2D & matriz);
int NumColumnas (const Matriz2D & matriz);

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

TipoBase & Valor (const Matriz2D & matriz, int num_fila, int num_columna); 

/***************************************************************************/
/***************************************************************************/
/***************************************************************************/
/***************************************************************************/
// Comprueba si la matriz dada está vacía o ocupada
// Parámetros: matriz, la matriz.

bool EstaVacia (const Matriz2D & matriz);



/***************************************************************************/
/***************************************************************************/
// Cambia todos los valores de la matriz por valor.
// Parámetros: matriz, la matriz
//			   valor, valor a establecer en toda la matriz

void Ecualiza (Matriz2D & matriz, TipoBase valor=VALOR_DEF);



/***************************************************************************/
/***************************************************************************/
// Hace una copia profunda de origen en destino
// Parámetros: destino, la matriz donde se va a clonar origen
//		       origen, la matriz a clonar

void Clona (Matriz2D & destino, const Matriz2D & origen);


/***************************************************************************/
/***************************************************************************/
// Comprueba si dos matrices son iguales en dimensiones y contenido
// Parámetros: una, la primera matriz
//			   otra, la segunda matriz

bool SonIguales (const Matriz2D & una, const Matriz2D & otra);


/***************************************************************************/
/***************************************************************************/
// Elimina una fila de la matriz
// Parámetros: matriz, la matriz
//			   num_fila, fila a eliminar
// PRE: matriz NO vacía

void EliminaFila (Matriz2D & matriz, int num_fila);


/***************************************************************************/
/***************************************************************************/
// Elimina una columna de la matriz
// Parámetros: matriz, la matriz
//			   num_col, fila a eliminar
// PRE: matriz NO vacía

void EliminaColumna (Matriz2D & matriz, int num_col);

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

void SubMatriz (Matriz2D & resultado, const Matriz2D & original, \
				int fila_inic, int col_inic, int num_filas, int num_cols);



/***************************************************************************/
/***************************************************************************/
// Cambia de orden las filas de matriz, en modo espejo
// Parámetros: matriz, la matriz a invertir en espejo

void EspejoHorizontal (Matriz2D & matriz);


/***************************************************************************/
/***************************************************************************/
// Cambia de orden las columnas de matriz, en modo espejo
// Parámetros: matriz, la matriz a invertir en espejo

void EspejoVertical (Matriz2D & matriz);







#endif