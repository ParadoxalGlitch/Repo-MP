/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: Adscripciones.cpp
//
// Contiene las implementaciones de la clase "Adscripciones"
//
/***************************************************************************/


#include "Adscripciones.h"

#include <iostream>

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Constructor por defecto

Adscripciones :: Adscripciones()
{
    dni = "Sin DNI";
    Id_depto = "Sin ID";
}

/***************************************************************************/
// Constructor con argumentos

Adscripciones :: Adscripciones(string linea, char delimitador)
{

    // Creo un string auxiliar donde iré guardando los datos

    string aux = "";
    int i = 0;
    
    // Voy leyendo los datos del string hasta encontrar el delimitador
    while(linea[i] != delimitador)
    {
        aux += linea[i];
        i++;
    }

    // Guardo el DNI en la clase
    dni = aux;
    aux = "";

    i++;

    // Sigo leyendo los datos del string hasta encontrar el delimitador

    while(linea[i] != delimitador)
    {
        aux += linea[i];
        i++;
    }

    // Guardo el ID en la clase
    Id_depto = aux;

    i++;
}

/***************************************************************************/
// Métodos get

string Adscripciones :: getDni()
{
    return dni;
}

string Adscripciones :: getId_depto()
{
    return Id_depto;
}

/***************************************************************************/
// Métodos set

void Adscripciones :: setDni(string d)
{
    dni = d;
}

void Adscripciones :: setId_depto(string id)
{
    Id_depto = id;
}

/***************************************************************************/
// Método ToString

string Adscripciones :: ToString()
{
    string cadena = dni + " " + Id_depto + "\n";
    return cadena;
}
