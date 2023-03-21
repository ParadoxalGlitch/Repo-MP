/*****************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: GeneradorAleatorioEnteros.h
//
// Contiene la declaración de la clase GeneradorAleatorioEnteros
//
/*****************************************************************************/

#ifndef GENERADOR_ALEAT_INT
#define GENERADOR_ALEAT_INT


#include <random>  // para la generación de números pseudoaleatorios
#include <chrono>  // para la semilla
#include "GeneradorAleatorioEnteros.h"
using namespace std;





class GeneradorAleatorioEnteros
{  
	private:
		
		mt19937 generador_mersenne;    // Mersenne twister
		uniform_int_distribution<int>  distribucion_uniforme;

	public:
		
	/**************************************************************************/
	// Constructor sin argumentos: Inicializa el generador
	// para proporcionar números aleatorios entre 0 y 1
			
		GeneradorAleatorioEnteros();

	/**************************************************************************/
	// Constructor con argumentos: Inicializa el generador
	// para proporcionar números aleatorios entre "min" y "max"

		GeneradorAleatorioEnteros(int min, int max);
		
	/**************************************************************************/
	// Devuelve un numero aleatorio
		
		int Siguiente();

	/**************************************************************************/

	private:

	/**************************************************************************/

		long long Nanosec(); 

	/**************************************************************************/
};


#endif