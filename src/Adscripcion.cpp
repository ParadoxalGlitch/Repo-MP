/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: Adscripciones.cpp
//
// Contiene las implementaciones de la clase "Adscripciones"
//
/***************************************************************************/


#include "Adscripcion.h"

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;


/***************************************************************************/
/***************************************************************************/
// Constructor por defecto

Adscripcion :: Adscripcion()
{
    dni = nullptr;
    Id_depto = nullptr;
}

/***************************************************************************/
/***************************************************************************/
// Constructor de copia

Adscripcion :: Adscripcion(const Adscripcion & otro)
{
    // Inicializo los atributos
    dni = nullptr;
    Id_depto = nullptr;

    // Copio los atributos
    clona(otro);
}

/***************************************************************************/
/***************************************************************************/
// Constructor con argumentos

Adscripcion :: Adscripcion(string linea, char delimitador)
{

    // Inicializo los atributos
    dni = nullptr;
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
// Destructor

Adscripcion :: ~Adscripcion()
{
    delete [] dni;
    dni = nullptr;
    delete [] Id_depto;
    Id_depto = nullptr;
}

/***************************************************************************/
/***************************************************************************/
// Métodos get

string Adscripcion :: getDni() const
{
    return CharToString(dni);
}

string Adscripcion :: getId_depto()
{
    return CharToString(Id_depto);
}

/***************************************************************************/
/***************************************************************************/
// Métodos set

void Adscripcion :: setDni(string d)
{
    // Me deshago de la memoria de lo que ya hay guardado
    // si es que lo hay

    if (dni){

        delete[] dni;
        dni = nullptr;

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

void Adscripcion :: setId_depto(string id)
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
/***************************************************************************/
// Método ToString

string Adscripcion :: ToString()
{
    if (!dni && !Id_depto)

        return "No hay datos";

    else{

    string cadena = CharToString(dni) + " " + CharToString(Id_depto) + "\n";
    return cadena;

    }

}



/***************************************************************************/
/***************************************************************************/
// Método ReservaMemoria
// Se llama a esta función cuando se va a clonar un objeto
// por lo que se elimina el contenido anterior y se reserva
// para el nuevo

void Adscripcion :: ReservaMemoria(const Adscripcion & objeto)
{

    // Me deshago de la memoria de lo que ya hay guardado

    
    LiberarMemoria();


    // Reservo memoria para el DNI
    char * aux = new char [strlen(objeto.dni) + 1];
    

    dni = aux;

    // Reservo memoria para el ID
    aux = new char [strlen(objeto.Id_depto) + 1];

    Id_depto = aux;

}



/************************************************************/
/************************************************************/
// Libera memoria

void Adscripcion :: LiberarMemoria(void)
{


    if (dni && Id_depto){

        delete[] dni;
        dni = nullptr;

        delete[] Id_depto;
        Id_depto = nullptr;

    }
}



/************************************************************/
/************************************************************/
// Copiar datos desde otro objeto de la clase
// Parámetros: otro (referencia), objeto que sirve de modelo.
//
// PRE: Se ha reservado memoria para los datos
void Adscripcion :: CopiarDatos (const Adscripcion & otro)
{

   // Copiar DNI
    for (int i = 0; i <= strlen(otro.dni); i++) {
        dni[i] = otro.dni[i];
    }

    // Copiar Id_depto
    for (int i = 0; i <= strlen(otro.Id_depto); i++) {
        Id_depto[i] = otro.Id_depto[i];
    }
    

}

/***************************************************************************/
/***************************************************************************/
// Método clona

void Adscripcion :: clona(const Adscripcion & original)
{
    
    ReservaMemoria(original);

    CopiarDatos(original);

}




/**************************************************************************/
/**************************************************************************/
// Operador de asignación

Adscripcion & Adscripcion:: operator = (const Adscripcion & original)
{
    if (this != &original)
    {
        clona (original);
    }
    return *this;
}


/**************************************************************************/
/**************************************************************************/
// Operador << y >>

ofstream & operator << (ofstream & fo, Adscripcion & adscripcion)
{

    // Guardo los datos separados por DELIMITADOR

    //Guardo el ID del departamento:
    fo << adscripcion.getDni() << '*';

    // Guardo el Nombre del departamento

    fo << adscripcion.getId_depto() << '*';


    return fo;

}

ifstream & operator >> (ifstream & fi, Adscripcion & adscripcion)
{

    string linea;

    // Sigo leyendo lineas, hasta encontrar una que
    // no empiece por # (es decir, ignorar comentarios) 
    
    getline(fi,linea); // Lectura adelantada

    while(linea.at(0) == '#'){

        getline(fi,linea);

    }

    // Aquí deberiamos haber encontrado los datos. Si estos no están
    // el departamento quedará vacío de todas formas

    // Voy guardando en un string aux los datos hasta
    // encontrar el delimitador, lo cual será el ID
    string aux;
    int i=0;

    while(linea[i] != DELIMITADOR)
    {
        aux += linea[i];
        i++;
    }

    adscripcion.setDni(aux); // Actualizo el valor de Id
    aux = ""; //Reinicio aux

    
    // Ahora, toca leer el nombre

    i++; // Ignorar el delimitador

    while(linea[i] != DELIMITADOR)
    {
        aux += linea[i];
        i++;
    }

    adscripcion.setId_depto(aux);

    // Ya hemos acabado de leer los datos
    
    return fi;

}
