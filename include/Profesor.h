/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: Profesor.h
//
// Contiene las cabeceras de la clase "Profesor"
//
/***************************************************************************/

#ifndef PROFESOR
#define PROFESOR

#include <string>

#include "utils.h"
#include "Fecha.h"

using namespace std;


/***************************************************************************/
/***************************************************************************/
// Clase "Profesor"

class Profesor
{

private:

    char * dni;
    char * nombre;
    char * apellidos;
    Fecha fechaNacimiento; 
    int categoria; // Valor entre 1 y 4

public:


/***************************************************************************/
// Constructor por defecto

    Profesor();


/***************************************************************************/
// Constructor con argumentos

    Profesor(string linea, char delimitador=DELIMITADOR);



/***************************************************************************/
// Destructor
    ~Profesor();

    

/***************************************************************************/
// Métodos get

    string getDni();
    string getNombre();
    string getApellidos();
    string getFechaNacimiento();
    int getCategoria();

/***************************************************************************/
// Métodos set

    void setDni(string d);
    void setNombre(string n);
    void setApellidos(string a);
    void setFechaNacimiento(string f);
    void setCategoria(int c);

/***************************************************************************/
// Método ToString

    string ToString();
    
/***************************************************************************/
// Método clona

void clona(Profesor& original);

};

#endif