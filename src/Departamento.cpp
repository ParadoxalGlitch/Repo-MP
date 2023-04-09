/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: Departamento.cpp
//
// Contiene las implementaciones de la clase "Departamento"
//
/***************************************************************************/   


#include "Departamento.h"

#include <iostream>


using namespace std;

/***************************************************************************/
/***************************************************************************/
// Constructor por defecto

Departamento :: Departamento()
{
    nombre = "Sin nombre";
    abreviatura = "Sin abreviatura";
}

/***************************************************************************/
// Constructor con argumentos

Departamento :: Departamento(string nom, string abrev)
{
    nombre = nom;
    abreviatura = abrev;
}


/***************************************************************************/
// Métodos get

string Departamento :: getNombre()
{
    return nombre;
}

string Departamento :: getAbreviatura()
{
    return abreviatura;
}

/***************************************************************************/
// Métodos set

void Departamento :: setNombre(string nom)
{
    nombre = nom;
}

void Departamento :: setAbreviatura(string abrev)
{
    abreviatura = abrev;
}

/***************************************************************************/
// Método ToString

string Departamento :: ToString()
{
    string cadena = "( " + abreviatura + " ) " + "    " + nombre + "\n";
    return cadena;
}
