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
    Id_depto = "Sin abreviatura";
}

/***************************************************************************/
// Constructor con argumentos

Departamento :: Departamento(string nom, string id)
{
    nombre = nom;
    Id_depto = id;
}


/***************************************************************************/
// Métodos get

string Departamento :: getNombre()
{
    return nombre;
}

string Departamento :: getId()
{
    return Id_depto;
}

/***************************************************************************/
// Métodos set

void Departamento :: setNombre(string nom)
{
    nombre = nom;
}

void Departamento :: setId(string id)
{
    Id_depto = id;
}

/***************************************************************************/
// Método ToString

string Departamento :: ToString()
{
    string cadena = "( " + Id_depto + " ) " + "    " + nombre + "\n";
    return cadena;
}

/***************************************************************************/
/***************************************************************************/
