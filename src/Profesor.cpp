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
    fechaNacimiento = Fecha();
    categoria = 0;

}

/***************************************************************************/
// Constructor con argumentos

Profesor :: Profesor(string linea, char delimitador)
{

    // Creo un string auxiliar donde guardaré los datos que vaya leyendo

    string aux = "";
    int i = 0;


    
    // Voy leyendo los datos del string hasta encontrar el delimitador
    while(linea[i] != delimitador)
    {
        aux += linea[i];
        i++;
    }

    // Guardo el DNI del profesor en la clase
    dni = aux;
    aux = "";

    i++;

    // Sigo leyendo los datos del string hasta encontrar el delimitador

    while(linea[i] != delimitador)
    {
        aux += linea[i];
        i++;
    }

    // Guardo el nombre en la clase
    nombre = aux;
    aux = "";

    i++;

    // Sigo leyendo los datos del string hasta encontrar el delimitador

    while(linea[i] != delimitador)
    {
        aux += linea[i];
        i++;
    }

    // Guardo los apellidos en la clase
    apellidos = aux;
    aux = "";

    i++;

    // Sigo leyendo los datos del string hasta encontrar el delimitador

    while(linea[i] != delimitador)
    {
        aux += linea[i];
        i++;
    }

    
    // Guardo la fecha de nacimiento en la clase
    fechaNacimiento = Fecha(aux);
    aux = "";

    i++;

    // Sigo leyendo los datos del string hasta encontrar el delimitador

    while(linea[i] != delimitador)
    {
        aux += linea[i];
        i++;
    }

    // Guardo la categoría en la clase
    categoria = stoi(aux);
    aux = "";

    i++;
   
}

/***************************************************************************/
// Métodos get

string Profesor :: getDNI()
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
    string fecha;
    fecha = to_string(fechaNacimiento.getAnio()) + fechaNacimiento.getMes() + \
            to_string(fechaNacimiento.getDia());

    return fecha;
}

int Profesor :: getCategoria()
{
    return categoria;
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
    Fecha tmp(f);
    fechaNacimiento = tmp;
}

void Profesor :: setCategoria(int c)
{
    categoria = c;
}

/***************************************************************************/
// Método ToString

string Profesor :: ToString()
{
    string cadena = dni + " " + FormatString((apellidos + ", " + nombre),32) + \
    fechaNacimiento.ToString() + "   " + to_string(categoria) + "\n";
    return cadena;
}


/***************************************************************************/
/***************************************************************************/