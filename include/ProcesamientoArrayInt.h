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

#endif