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
#include <cstring>
#include <fstream>

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
// Constructor de copia

Profesor :: Profesor(const Profesor & otro)
{
    // Inicializo los atributos
    dni = nullptr;
    nombre = nullptr;
    apellidos = nullptr;
    fechaNacimiento = Fecha();
    categoria = 0;
    
    // Copio los atributos
    clona(otro);
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

string Profesor :: getDni() const
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
    
    aux[d.size()] = '\0';

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

    aux[n.size()] = '\0';

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

    aux[a.size()] = '\0';

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
/***************************************************************************/
// Método ReservaMemoria
// Se llama a esta función cuando se va a clonar un objeto
// por lo que se elimina el contenido anterior y se reserva
// para el nuevo

void Profesor :: ReservaMemoria(const Profesor & objeto)
{

    // Me deshago de la memoria de lo que ya hay guardado

    
    LiberarMemoria();


    // Reservo memoria para el DNI
    dni = new char [strlen(objeto.dni) + 1];

    // Reservo memoria para el nombre
    nombre = new char [strlen(objeto.nombre) + 1];

    // Reservo memoria para los apellidos
    apellidos = new char [strlen(objeto.apellidos) + 1];

}

/************************************************************/
/************************************************************/
// Libera memoria

void Profesor :: LiberarMemoria(void)
{


    if (dni && nombre && apellidos){

        delete[] dni;
        dni = nullptr;

        delete[] nombre;
        nombre = nullptr;

        delete[] apellidos;
        apellidos = nullptr;

    }
}



/************************************************************/
/************************************************************/
// Copiar datos desde otro objeto de la clase
// Parámetros: otro (referencia), objeto que sirve de modelo.
//
// PRE: Se ha reservado memoria para los datos

void Profesor :: CopiarDatos (const Profesor & otro)
{

   // Copiar DNI
    for (int i = 0; i <= strlen(otro.dni); i++) {
        dni[i] = otro.dni[i];
    }

    // Copiar nombre
    for (int i = 0; i <= strlen(otro.nombre); i++) {
        nombre[i] = otro.nombre[i];
    }

    // Copiar apellidos
    for (int i = 0; i <= strlen(otro.apellidos); i++) {
        apellidos[i] = otro.apellidos[i];
    }

    // Copiar fecha de nacimiento
    fechaNacimiento = otro.fechaNacimiento;

    // Copiar categoría
    categoria = otro.categoria;
    

}

/***************************************************************************/
/***************************************************************************/
// Método clona

void Profesor :: clona(const Profesor & original)
{
    
    ReservaMemoria(original);

    CopiarDatos(original);

}


/**************************************************************************/
/**************************************************************************/
// Operador de asignación

Profesor & Profesor:: operator = (const Profesor & original)
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

ofstream & operator << (ofstream & fo, Profesor & profesor)
{

    // Guardo los datos separados por DELIMITADOR

    //Guardo el ID del departamento:
    fo << profesor.getDni() << '*';

    // Guardo el Nombre del departamento

    fo << profesor.getNombre() << '*';

    // Guardo los apellidos del profesor

    fo << profesor.getApellidos() << '*';

    // Guardo la fecha de nacimiento del profesor

    fo << profesor.getFechaNacimiento() << '*';

    // Guardo la categoria del profesor

    fo << profesor.getCategoria() << '*';


    return fo;

}

ifstream & operator >> (ifstream & fi, Profesor & profesor)
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

    profesor.setDni(aux); // Actualizo el valor de Id
    aux = ""; //Reinicio aux

    
    // Ahora, toca leer el nombre

    i++; // Ignorar el delimitador

    while(linea[i] != DELIMITADOR)
    {
        aux += linea[i];
        i++;
    }

    profesor.setNombre(aux);
    aux = "";

    // Ahora leemos los apellidos

    i++; // Ignorar el delimitador

    while(linea[i] != DELIMITADOR)
    {
        aux += linea[i];
        i++;
    }

    profesor.setApellidos(aux);
    aux = "";

    // Ahora leemos la fecha de nacimiento

    i++; // Ignorar el delimitador

    while(linea[i] != DELIMITADOR)
    {
        aux += linea[i];
        i++;
    }
    
    profesor.setFechaNacimiento(aux);
    aux = "";

    i++; // Ignorar el delimitador

    while(linea[i] != DELIMITADOR)
    {
        aux += linea[i];
        i++;
    }

    profesor.setCategoria(stoi(aux));

    // Ya hemos acabado de leer los datos
        
    
    return fi;

}