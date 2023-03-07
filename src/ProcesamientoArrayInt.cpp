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