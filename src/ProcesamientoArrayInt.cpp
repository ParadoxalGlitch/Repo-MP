/*****************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: ProcesamientoArrayInt.cpp
//
// Contiene la definición de las funciones usadas en
//          I_PosMayor_Basico.cpp (por ahora)
//
/*****************************************************************************/

#include "ProcesamientoArrayInt.h"
using namespace std;


/*****************************************************************************/
// Constructor sin argumentos: Inicializa el generador
// para proporcionar números aleatorios entre 0 y 1
GeneradorAleatorioEnteros :: GeneradorAleatorioEnteros()
 : GeneradorAleatorioEnteros(0, 1) { }

 /****************************************************************************/
 // Constructor con argumentos: Inicializa el generador
// para proporcionar números aleatorios entre "min" y "max"
GeneradorAleatorioEnteros ::
	GeneradorAleatorioEnteros(int min, int max) 
{
	
	const int A_DESCARTAR = 70000;
	// ACM TOMS Volume 32 Issue 1, March 2006
    		
	auto semilla = Nanosec();
	generador_mersenne.seed(semilla);
	generador_mersenne.discard(A_DESCARTAR);
	distribucion_uniforme = uniform_int_distribution<int> (min, max);

}
/*****************************************************************************/
// Devuelve un nuevo número aleatorio

int GeneradorAleatorioEnteros :: Siguiente()
{
	return (distribucion_uniforme(generador_mersenne));
}
/*****************************************************************************/

/*****************************************************************************/
// MÉTODOS PRIVADOS
/*****************************************************************************/

long long GeneradorAleatorioEnteros :: Nanosec()
{
	return (chrono::high_resolution_clock::now().time_since_epoch().count());
}
/*****************************************************************************/







/*****************************************************************************/
// Busca el valor más alto en un array de enteros dado un intervalo.
// Parámetros:  *pv, puntero que apunta a una casilla del vector a procesar.
//              izda, extremo inferior del intervalo a procesar.
//              dcha, extremo superior del intervalo a procesar.
//

int * PosMayor (int *pv, int izda, int dcha)
{

    int* ptr = pv + izda;
    int* ultimo = pv + dcha;
    int* resultado = nullptr;
    int mayor = 0;

    while ( ptr<=ultimo ) {
        if ((*ptr) > mayor) {
            mayor = *ptr;
            resultado = ptr;
        }

        ptr++;

    }

    return (resultado);


}




/*****************************************************************************/


/*****************************************************************************/
// Ordena un vector mediante el sistema de selección. En cada iteración,
// se busca el componente más pequeño del sub-vector derecho y se coloca
// en el sub-vector izquierdo
// Parámetros: int *v, puntero que apunta a una casilla del vector a procesar.
//			   pos_inic, extremo izquierdo del intervalo a procesar.
//			   pos_fin, extremo derecho del intervalo a procesar.
//

void OrdenaSeleccion (int *v, int pos_inic, int pos_fin)
{

    int pos_min;
    int min;
    int intercambia;

    for (int izda = 0 ; izda < pos_fin-1; izda++){
        min = *(v+izda);
        pos_min = izda;
        for (int i = izda + 1; i < pos_fin; i++){
            if (*(v+i) < min){
                min = *(v+i);
                pos_min = i;
            }
        }
        intercambia = *(v+izda);
        *(v+izda) = min;
        *(v+pos_min) = intercambia;
    }
}


/*****************************************************************************/


/*****************************************************************************/
// Ordena un vector mediante el sistema de inserción. Se divide el vector
// en dos sub-vectores, el ordenado (izquierda) y el desordenado (derecha).
// Se busca el primer elemento del sector desordenado y se coloca de
// forma ordenada en el sector ordenado
// Parámetros: int *v, puntero que apunta a una casilla del vector a procesar.
//			   pos_inic, extremo izquierdo del intervalo a procesar.
//			   pos_fin, extremo derecho del intervalo a procesar.
//

void OrdenaInsercion (int *v, int pos_inic, int pos_fin){

    int a_desplazar;
    int i;

    for (int izda = 1; izda < pos_fin; izda++){
        a_desplazar = *(v+izda);

        for (i = izda; i > 0 && a_desplazar < *(v+i-1); i--)
            *(v+i) = *(v+i-1);

        *(v+i) = a_desplazar;
    }

}