/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: Adscripciones.h
//
// Contiene las cabeceras de la clase "Adscripciones"
//
/***************************************************************************/

#ifndef ADSCRIPCIONES
#define ADSCRIPCIONES

#include <string>

#include "utils.h"

using namespace std;


/***************************************************************************/
/***************************************************************************/
// Clase "Adscripciones"

class Adscripciones
{

private:

    char * dni;
    char * Id_depto;

public:


/***************************************************************************/
// Constructor por defecto

    Adscripciones();


/***************************************************************************/
// Constructor con argumentos

    Adscripciones(string linea, char delimitador=DELIMITADOR);


/***************************************************************************/
// Destructor
    ~Adscripciones();

    

/***************************************************************************/
// Métodos get

    string getDni();
    string getId_depto();

/***************************************************************************/
// Métodos set

    void setDni(string d);
    void setId_depto(string id);

/***************************************************************************/
// Método ToString

    string ToString();

/***************************************************************************/
// Método clona

    void clona(Adscripciones& original);

};

#endif




