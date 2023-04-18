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
    setDni(aux);

    // Reinicio aux
    aux = "";
    i++;

    // Sigo leyendo los datos del string hasta encontrar el delimitador

    while(linea[i] != delimitador)
    {
        aux += linea[i];
        i++;
    }

    // Guardo el ID en la clase
    setId_depto(aux);

}

/***************************************************************************/
/***************************************************************************/
// Métodos get

string Adscripciones :: getDni()
{
    return CharToString(dni);
}

string Adscripciones :: getId_depto()
{
    return CharToString(Id_depto);
}

/***************************************************************************/
/***************************************************************************/
// Métodos set

void Adscripciones :: setDni(string d)
{
    // Me deshago de la memoria de lo que ya hay guardado
    // si es que lo hay

    if (!dni){

        delete[] dni;

    }

    // Pido memoria para el nuevo string

    char * aux = new char [d.size()];

    // Copio los valores de nom en aux

    for (int i = 0; i <= d.size(); i++)
    {
        aux[i] = d[i];
    }

    // Igualo id a aux
    dni = aux;
}

void Adscripciones :: setId_depto(string id)
{
    // Me deshago de la memoria de lo que ya hay guardado
    // si es que lo hay

    if (!Id_depto){

        delete[] Id_depto;

    }

    // Pido memoria para el nuevo string

    char * aux = new char [id.size()];

    // Copio los valores de nom en aux

    for (int i = 0; i <= id.size(); i++)
    {
        aux[i] = id[i];
    }

    // Igualo id a aux
    Id_depto = aux;
}

/***************************************************************************/
/***************************************************************************/
// Método ToString

string Adscripciones :: ToString()
{
    string cadena = CharToString(dni) + " " + CharToString(Id_depto) + "\n";
    return cadena;
}

/***************************************************************************/
/***************************************************************************/
// Destructor

Adscripciones :: ~Adscripciones()
{
    delete [] dni;
    dni = nullptr;
    delete [] Id_depto;
    Id_depto = nullptr;
}



