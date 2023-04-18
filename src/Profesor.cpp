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
// Constructor por defecto

Profesor :: Profesor()
{
    dni = nullptr;
    nombre = nullptr;
    apellidos = nullptr;
    fechaNacimiento = Fecha();
    categoria = 0;
}


/***************************************************************************/
// Constructor con argumentos

Profesor :: Profesor(string linea, char delimitador)
{

    dni = nullptr;
    nombre = nullptr;
    apellidos = nullptr;
    fechaNacimiento = Fecha();
    categoria = 0;


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

    // Guardo el nombre en la clase
    setNombre(aux);


    // Reinicio aux
    aux = "";
    i++;

    // Sigo leyendo los datos del string hasta encontrar el delimitador

    while(linea[i] != delimitador)
    {
        aux += linea[i];
        i++;
    }

    // Guardo los apellidos en la clase
    setApellidos(aux);


    // Reinicio aux
    aux = "";
    i++;

    // Sigo leyendo los datos del string hasta encontrar el delimitador

    while(linea[i] != delimitador)
    {
        aux += linea[i];
        i++;
    }

    
    // Guardo la fecha de nacimiento en la clase
    setFechaNacimiento(aux);


    // Reinicio aux
    aux = "";
    i++;

    // Sigo leyendo los datos del string hasta encontrar el delimitador

    while(linea[i] != delimitador)
    {
        aux += linea[i];
        i++;
    }

    // Guardo la categoría en la clase
    setCategoria(stoi(aux));
}


/***************************************************************************/
// Destructor

Profesor :: ~Profesor()
{
    delete [] dni;
    dni = nullptr;
    delete [] nombre;
    nombre = nullptr;
    delete [] apellidos;
    apellidos = nullptr;
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
    string fecha;
    fecha = to_string(fechaNacimiento.getDia()) + "/" +\
            to_string(fechaNacimiento.getMes()) + "/" + \
            to_string(fechaNacimiento.getAnio());

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

void Profesor :: setNombre(string n)
{
    
    // Me deshago de la memoria de lo que ya hay guardado
    // si es que lo hay

    if (nombre){

        delete[] nombre;
        nombre = nullptr;

    }

    // Pido memoria para el nuevo string

    char * aux = new char [n.size()];

    // Copio los valores de nom en aux

    for (int i = 0; i <= n.size(); i++)
    {
        aux[i] = n[i];
    }

    // Igualo id a aux
    nombre = aux;
    
}

void Profesor :: setApellidos(string a)
{
    
// Me deshago de la memoria de lo que ya hay guardado
    // si es que lo hay

    if (apellidos){

        delete[] apellidos;
        apellidos = nullptr;

    }

    // Pido memoria para el nuevo string

    char * aux = new char [a.size()];

    // Copio los valores de nom en aux

    for (int i = 0; i <= a.size(); i++)
    {
        aux[i] = a[i];
    }

    // Igualo id a aux
    apellidos = aux;

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

    string cadena;

    if (!dni && !nombre && !apellidos)
    {
        cadena = "No hay datos";
    }

    else{

    cadena = CharToString(dni) + " " + \
    FormatString(CharToString(apellidos) + ", " + CharToString(nombre),32) + \
    fechaNacimiento.ToString() + "   " + to_string(categoria) + "\n";

    }

    return cadena;
}


/***************************************************************************/
// Método clona

void Profesor :: clona(Profesor& original)
{
    setDni(original.getDni());

    setNombre(original.getNombre());

    setApellidos(original.getApellidos());

    setFechaNacimiento(original.getFechaNacimiento());

    setCategoria(original.getCategoria());
    
}