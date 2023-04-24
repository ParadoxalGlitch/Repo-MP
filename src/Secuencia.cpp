/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: Fecha.cpp
//
// Contiene las implementaciones de la clase "Secuencia"
//
/***************************************************************************/


#include "Secuencia.h"
#include "TipoBase.h"

#include <string>
#include <cstring>
#include <iostream>




using namespace std;

/***************************************************************************/
/***************************************************************************/
// Constructor por defecto

Secuencia :: Secuencia()
{
    datos = nullptr;
    tam = 0;
}

/***************************************************************************/
// Constructor con 1 argumento, tamaño

Secuencia :: Secuencia(int num)
{
    // Inicializo los atributos
    tam = num;

    // Reservo memoria para la matriz
    ReservaMemoria(num);

}

/***************************************************************************/
// Constructor de copia

Secuencia :: Secuencia(const Secuencia & otra)
{
    // Inicializo los atributos
    tam = otra.tam;

    Clona(otra);
}

/***************************************************************************/
// Destructor

Secuencia :: ~Secuencia()
{
    // Libero la memoria
    delete [] datos;
}

/***************************************************************************/
// Reserva memoria para la matriz

void Secuencia :: ReservaMemoria(int num)
{
    // Reservo memoria para el vector
    datos = new TipoBase[num];

}

/***************************************************************************/
// LIbera la memoria de la matriz

void Secuencia :: EliminaTodos()
{
    // Libero la memoria
    delete [] datos;
    datos = nullptr;
}

/***************************************************************************/
// Método clona
// Clona en el vector con el que se llama el contenido del vector que se pasa
// como argumento

void Secuencia :: Clona(const Secuencia & otra)
{

    // Libero la memoria
    EliminaTodos();

    // Reservo memoria para el vector
    ReservaMemoria(otra.tam);

    // Copio el contenido del vector que se pasa como argumento
    for (int i = 0; i < otra.tam; i++)
    {
        datos[i] = otra.datos[i];
    }
}

/***************************************************************************/
// Método set & get, mediante referencia
// Pre: 0 <= pos < tam

TipoBase & Secuencia :: Valor(int pos)
{
    return datos[pos];
}


/***************************************************************************/
// Método ToString

string Secuencia :: ToString()
{
    string cadena;


    for (int i = 0; i < tam; i++)
    {
        cadena += to_string(datos[i]) + " ";
    }

    return cadena;
}

/***************************************************************************/
// Sobrecarga del operador de asignación

Secuencia & Secuencia :: operator = (const Secuencia & otra)
{
    // Compruebo que no se esté intentando asignar un vector a sí mismo
    if (this != &otra)
    {
        // Clono el vector que se pasa como argumento
        Clona(otra);
    }

    return *this;
}