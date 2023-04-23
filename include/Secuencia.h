/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: Fecha.h
//
// Contiene las cabeceras de la clase "Secuencia"
//
/***************************************************************************/

#ifndef SECUENCIA
#define SECUENCIA

#include <string>
#include "TipoBase.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Clase "Secuencia"

class Secuencia
{

private:

    TipoBase * datos;
    int tam;


public:

/***************************************************************************/
// Constructor por defecto

    Secuencia();


/***************************************************************************/
// Constructor con 1 argumento, tamaño

    Secuencia(int num);

/***************************************************************************/
// Constructor de copia

    Secuencia(const Secuencia & otra);

/***************************************************************************/
// Destructor

    ~Secuencia();

/***************************************************************************/
// Reserva memoria para la matriz

    void ReservaMemoria(int num);

/***************************************************************************/
// LIbera la memoria de la matriz

    void EliminaTodos();

/***************************************************************************/
// Método clona
// Clona en el vector con el que se llama el contenido del vector que se pasa
// como argumento

    void Clona(const Secuencia & otra);

/***************************************************************************/
// Método set & get, mediante referencia
// Pre: 0 <= pos < tam

    TipoBase & Valor(int pos);


};
#endif
