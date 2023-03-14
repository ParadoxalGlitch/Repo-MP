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

// Busca el valor más alto en un array de enteros dado un intervalo.
// Parámetros:  *pv, puntero que apunta a una casilla del vector a procesar.
//              izda, extremo izquierdo del intervalo a procesar.
//              dcha, extremo derecho del intervalo a procesar.
//
/*****************************************************************************/

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

/*****************************************************************************/

///////////////////////////////////////////////////////////////////////////////

/*****************************************************************************/
// Rellena el vector usando la función GenerarAleatoriosEnteros, según los
// parámetros indicados por el usuario. 
// Parámetros: int *p, puntero que apunta a una casilla del vector a rellenar.
//             num_datos, cantidad de casillas a rellenar.
//             min_aleat, el número mas pequeño entre los que se elegirá
//                        para generar el contenido del vector.
//             max_aleat, el número mas grande entre los que se elegirá
//                        para generar el contenido del vector.
//

void RellenaVector (int *p, int num_datos, int min_aleat, int max_aleat);

/*****************************************************************************/

///////////////////////////////////////////////////////////////////////////////

/*****************************************************************************/
// Comprueba si los datlos proporcionados para rellenar el vector son correctos
// Parámetros: num_datos, cantidad de casillas que se quieren rellenar.
//             tope, capacidad máxima del vector.
//

bool ComprobarNumDatos (int num_datos, int tope);

/*****************************************************************************/

///////////////////////////////////////////////////////////////////////////////

/*****************************************************************************/
// Comprueba si los datos proporcionados sobre el intervalo son correctos.
// Parámetros: izda, extremo inferior del intervalo.
//             dcha, extremo superior del intervalo.
//             num_Datos, cantidad de casillas que posee el vector.
//

bool ComprobarIntervalo (int izda, int dcha, int num_datos);

/*****************************************************************************/

///////////////////////////////////////////////////////////////////////////////

/*****************************************************************************/
// Comprueba si ha sido elegida de forma correcta una forma de ordenación del
// intervalo.
// Parametros: opcion, opcion elegida en relación a las distintas formas
//                     de ordenar el intervalo
//

bool ComprobarOpcion (int opcion);

/*****************************************************************************/

///////////////////////////////////////////////////////////////////////////////

/*****************************************************************************/
// Recibe 3 vectores, 2 los cuales entremezclará y guardará en el tercero,
// sobreescribiendo principalmente lo que haya en este. La idea es que el
// tercer vector venga vacío y preparado con el tamaño exacto necesario.
// El algoritmo irá introduciendo cada vez 1 elemento de 1 vector y 1 de
// otor, intercalándolos.
// Parametros: 

void MezclarVectores (int *v1, int *v2, int *res, int tam_v1, int tam_v2);

/*****************************************************************************/

///////////////////////////////////////////////////////////////////////////////

/*****************************************************************************/
// Muestra un vector en pantalla
//Parametros: int *p, vector a mostrar.
//            int n_datos, tamaño del vector
//

void MuestraVector (int *p, int n_datos);

/*****************************************************************************/

#endif