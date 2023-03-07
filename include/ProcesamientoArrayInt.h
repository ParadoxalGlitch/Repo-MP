/*****************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: ProcesamientoArrayInt.h
//
// Contiene la declaración de las funciones usadas en
//          I_PosMayor_Basico.cpp (por ahora)
//
/*****************************************************************************/

#ifndef FUNCIONES_PROCESS_ARRAY
#define FUNCIONES_PROCESS_ARRAY

#include <random>  // para la generación de números pseudoaleatorios
#include <chrono>  // para la semilla
using namespace std;

///////////////////////////////////////////////////////////////////////////////
class GeneradorAleatorioEnteros
{  
private:
	
	mt19937 generador_mersenne;    // Mersenne twister
	uniform_int_distribution<int>  distribucion_uniforme;

public:
	
/*****************************************************************************/
// Constructor sin argumentos: Inicializa el generador
// para proporcionar números aleatorios entre 0 y 1
		
	GeneradorAleatorioEnteros();

/*****************************************************************************/
// Constructor con argumentos: Inicializa el generador
// para proporcionar números aleatorios entre "min" y "max"

    GeneradorAleatorioEnteros(int min, int max);
    
/*****************************************************************************/
// Devuelve un numero aleatorio
	
	int Siguiente();

/*****************************************************************************/

private:

/*****************************************************************************/

    long long Nanosec(); 

/*****************************************************************************/
};

///////////////////////////////////////////////////////////////////////////////

/*****************************************************************************/
// Busca el valor más alto en un array de enteros dado un intervalo.
// Parámetros:  *pv, puntero que apunta a una casilla del vector a procesar.
//              izda, extremo izquierdo del intervalo a procesar.
//              dcha, extremo derecho del intervalo a procesar.
//

int * PosMayor (int *pv, int izda, int dcha);

/*****************************************************************************/

///////////////////////////////////////////////////////////////////////////////

/*****************************************************************************/
// Ordena un vector mediante el sistema de selección. En cada iteración,
// se busca el componente más pequeño del sub-vector derecho y se coloca
// en el sub-vector izquierdo
// Parámetros: int *v, puntero que apunta a una casilla del vector a procesar.
//			   pos_inic, extremo izquierdo del intervalo a procesar.
//			   pos_fin, extremo derecho del intervalo a procesar.
//

void OrdenaSeleccion (int *v, int pos_inic, int pos_fin);

/*****************************************************************************/

///////////////////////////////////////////////////////////////////////////////

/*****************************************************************************/
// Ordena un vector mediante el sistema de inserción. Se divide el vector
// en dos sub-vectores, el ordenado (izquierda) y el desordenado (derecha).
// Se busca el primer elemento del sector desordenado y se coloca de
// forma ordenada en el sector ordenado
// Parámetros: int *v, puntero que apunta a una casilla del vector a procesar.
//			   pos_inic, extremo izquierdo del intervalo a procesar.
//			   pos_fin, extremo derecho del intervalo a procesar.
//

void OrdenaInsercion (int *v, int pos_inic, int pos_fin);

/*****************************************************************************/

///////////////////////////////////////////////////////////////////////////////

/*****************************************************************************/
// Ordena un vector mediante el sistema de intercambio directo. Se divide
// el vector en dos sectores, el izquierdo ordenado y el derecho desordenado.
// En el vector derecho se van comparando desde el final 2 a 2 y se va
// moviendo el mas pequeño, y así en repetidas iteraciones.
//

void OrdenaIntercambio (int *v, int pos_inic, int pos_fin);

#endif