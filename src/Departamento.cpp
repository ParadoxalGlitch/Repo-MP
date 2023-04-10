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

Departamento :: Departamento(string linea, char delimitador)
{

    // Creo un string auxiliar donde iré guardando los datos

    string aux = "";
    int i = 0;
    
    // Voy leyendo los datos del string hasta encontrar el delimitador

    aux += "(";
    
    while(linea[i] != delimitador)
    {
        aux += linea[i];
        i++;
    }

    aux += ")";

    // Guardo el ID del departamento en la clase
    Id_depto = aux;
    Id_depto = FormatString(Id_depto, 6);
    aux = "";

    i++;

    // Sigo leyendo los datos del string hasta encontrar el delimitador

    while(linea[i] != delimitador)
    {
        aux += linea[i];
        i++;
    }

    // Guardo el nombre del departamento en la clase

    nombre = aux;

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
    string cadena = Id_depto + "    " + nombre + "\n";
    return cadena;
}

/***************************************************************************/
/***************************************************************************/
