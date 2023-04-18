/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: Departamento.h
//
// Contiene las cabeceras de la clase "Departamento"
//
/***************************************************************************/

#ifndef DEPARTAMENTO
#define DEPARTAMENTO

#include <string>

#include "utils.h"

/***************************************************************************/
/***************************************************************************/
// Clase "Departamento"

class Departamento
{

private:

    char * nombre;
    char * Id_depto;

public:


/***************************************************************************/
// Constructor por defecto

    Departamento();


/***************************************************************************/
// Constructor con argumentos
    
    Departamento(string linea, char delimitador=DELIMITADOR);


/***************************************************************************/
// Destructor
    ~Departamento();

/***************************************************************************/
// Métodos get

string getNombre();

string getId();

/***************************************************************************/
// Métodos set

void setNombre(string nom);

void setId(string id);

/***************************************************************************/
// Método ToString

string ToString();

/***************************************************************************/
// Método clona

void clona(Departamento& original);



};


#endif
