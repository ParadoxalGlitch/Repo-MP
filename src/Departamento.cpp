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
#include <fstream>


using namespace std;

/***************************************************************************/
// Constructor por defecto

Departamento :: Departamento()
{
    nombre = nullptr;
    Id_depto = nullptr;
}


/***************************************************************************/
// Constructor de copia

Departamento :: Departamento(const Departamento & otro)
{
    // Inicializo los atributos
    nombre = nullptr;
    Id_depto = nullptr;

    // Copio los atributos
    clona(otro);
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

string Departamento :: getNombre() const
{
    return nombre;
}

string Departamento :: getId () const
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
// Método ReservaMemoria
// Se llama a esta función cuando se va a clonar un objeto
// por lo que se elimina el contenido anterior y se reserva
// para el nuevo

void Departamento :: ReservaMemoria(const Departamento & objeto)
{

    // Me deshago de la memoria de lo que ya hay guardado

    
    LiberarMemoria();

    // Reservo memoria para el DNI
    char * aux = new char [strlen(objeto.nombre) + 1];

    nombre = aux;

    // Reservo memoria para el ID
    aux = new char [(objeto.getId()).length() + 1];

    Id_depto = aux;

}

/************************************************************/
/************************************************************/
// Libera memoria

void Departamento :: LiberarMemoria(void)
{


    if (nombre && Id_depto){

        delete[] nombre;
        nombre = nullptr;

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
void Departamento :: CopiarDatos (const Departamento & otro)
{

   // Copiar DNI
    for (int i = 0; i <= strlen(otro.nombre); i++) {
        nombre[i] = otro.nombre[i];
    }

    // Copiar Id_depto
    for (int i = 0; i <= strlen(otro.Id_depto); i++) {
        Id_depto[i] = otro.Id_depto[i];
    }
    

}



/***************************************************************************/
/***************************************************************************/
// Método clona

void Departamento :: clona(const Departamento & original)
{

    ReservaMemoria(original);

    CopiarDatos(original);

}


/**************************************************************************/
/**************************************************************************/
// Operador de asignación

Departamento & Departamento:: operator = (const Departamento & original)
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

ofstream & operator << (ofstream & fo, Departamento & dep)
{

    // Guardo los datos separados por DELIMITADOR

    //Guardo el ID del departamento:
    fo << dep.getId() << '*';

    // Guardo el Nombre del departamento

    fo << dep.getNombre() << '*';


    return fo;

}

ifstream & operator >> (ifstream & fi, Departamento & dep)
{


    string linea;

    // Sigo leyendo lineas, hasta encontrar una que
    // no empiece por # (es decir, ignorar comentarios) s

    getline(fi,linea); // Lectura adelantada

    while (linea.at(0) == '#'){

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

    dep.setId(aux); // Actualizo el valor de Id
    aux = ""; //Reinicio aux

    
    // Ahora, toca leer el nombre

    i++; // Ignorar el delimitador

    while(linea[i] != DELIMITADOR)
    {
        aux += linea[i];
        i++;
    }

    dep.setNombre(aux);

    // Ya hemos acabado de leer los datos
    
    return fi;

}




