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

#include <cstdlib>
#include <cctype>
#include <random>  // para la generación de números pseudoaleatorios
#include <chrono>  // para la semilla
using namespace std;


////////////////////////////////////////////////////////
class GeneradorAleatorioEnteros
{
private:	
	mt19937 generador_mersenne; // Mersenne twister
	uniform_int_distribution<int> distribucion_uniforme;
public:
	/****************************************************/
	// Constructor sin argumentos: Inicializa el generador
	// para proporcionar n ́umeros aleatorios entre 0 y 1

	GeneradorAleatorioEnteros();
	
	/****************************************************/
	// Constructor con argumentos: Inicializa el generador
	// para proporcionar n ́umeroS aleat. entre "min" y "max"

	GeneradorAleatorioEnteros(int min, int max);

	/****************************************************/
	// Devuelve un nuevo n ́umero aleatorio

	int Siguiente();
	/****************************************************/

private:
	/****************************************************/

	long long Nanosec();

	/****************************************************/
};

////////////////////////////////////////////////////////

#endif