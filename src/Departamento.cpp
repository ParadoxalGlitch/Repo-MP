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
#include <cstring>


using namespace std;

/***************************************************************************/
// Constructor por defecto

Departamento :: Departamento()
{
    nombre = nullptr;
    Id_depto = nullptr;
}


/***************************************************************************/
// Constructor con argumentos

Departamento :: Departamento(string linea, char delimitador)
{

    nombre = nullptr;
    Id_depto = nullptr;


    // Creo un string auxiliar donde iré guardando los datos

    string aux = "";
    int i = 0;
    
    // Voy leyendo los datos del string hasta encontrar el delimitador
    while(linea[i] != delimitador)
    {
        aux += linea[i];
        i++;
    }

    // Guardo los datos

    setId(aux);


    // Reinicio auxiliar
    aux = "";
    i++;

    // Sigo leyendo los datos del string hasta encontrar el delimitador

    while(linea[i] != delimitador)
    {
        aux += linea[i];
        i++;

    }


    // Guardo los datos

    setNombre(aux);

}


/***************************************************************************/
/***************************************************************************/
// Destructor

Departamento :: ~Departamento()
{
    delete [] nombre;
    nombre = nullptr;
    delete [] Id_depto;
    Id_depto = nullptr;
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

    // Me deshago de la memoria de lo que ya hay guardado
    // si es que lo hay

    if (nombre){

        delete[] nombre;
        nombre = nullptr;

    }

    // Pido memoria para el nuevo string

    char * aux = new char [nom.size()];

    // Copio los valores de nom en aux

    for (int i = 0; i <= nom.size(); i++)
    {
        aux[i] = nom[i];
    }

    // Igualo nombre a aux
    nombre = aux;

}

void Departamento :: setId(string id)
{
    // Me deshago de la memoria de lo que ya hay guardado
    // si es que lo hay


    if (Id_depto){

        delete[] Id_depto;
        Id_depto = nullptr;

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
// Método ToString


string Departamento :: ToString()
{
    
    string cadena;

    if (!nombre){

        cadena = "no hay datos";

    }

    else{

    cadena = FormatString(("(" + (CharToString(Id_depto) + ")")),6) + "    " + \
             CharToString(nombre) + "\n";

    }

    return cadena;

}


/***************************************************************************/
/***************************************************************************/
// Método clona

void Departamento :: clona(Departamento& original)
{

    string nom = original.getNombre();
    setNombre(nom);

    string id = original.getId();
    setId(id);
    
}