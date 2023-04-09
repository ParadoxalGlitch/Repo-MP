/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: Profesor.cpp
//
// Contiene las implementaciones de la clase "Profesor"
//
/***************************************************************************/ 


#include "Profesor.h"

#include <iostream>

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Constructor por defecto

Profesor :: Profesor()
{
    dni = "Sin DNI";
    nombre = "Sin nombre";
    apellidos = "Sin apellidos";
    fechaNacimiento = "Sin fecha de nacimiento";

}

/***************************************************************************/
// Constructor con argumentos

Profesor :: Profesor(string d, string n, string a, string f)
{
    dni = d;
    nombre = n;
    apellidos = a;
    fechaNacimiento = f;
}

/***************************************************************************/
// Métodos get

string Profesor :: getDni()
{
    return dni;
}

string Profesor :: getNombre()
{
    return nombre;
}

string Profesor :: getApellidos()
{
    return apellidos;
}

string Profesor :: getFechaNacimiento()
{
    return fechaNacimiento;
}


/***************************************************************************/
// Métodos set

void Profesor :: setDni(string d)
{
    dni = d;
}

void Profesor :: setNombre(string n)
{
    nombre = n;
}

void Profesor :: setApellidos(string a)
{
    apellidos = a;
}

void Profesor :: setFechaNacimiento(string f)
{
    fechaNacimiento = f;
}

/***************************************************************************/
// Método ToString

string Profesor :: ToString()
{
    string cadena = "DNI: " + dni + " Nombre: " + nombre + " Apellidos: " \
    + apellidos + " Fecha de nacimiento: " + fechaNacimiento;
    return cadena;
}


/***************************************************************************/
/***************************************************************************/