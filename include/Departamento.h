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

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Clase "Departamento"

class Departamento
{

private:

    string nombre;
    string abreviatura;
public:


/***************************************************************************/
// Constructor por defecto

    Departamento();

/***************************************************************************/
// Constructor con argumentos

Departamento(string nom, string abrev);

/***************************************************************************/
// Métodos get

string getNombre();

string getAbreviatura();

/***************************************************************************/
// Métodos set

void setNombre(string nom);

void setAbreviatura(string abrev);

/***************************************************************************/
// Método ToString

string ToString();




};


#endif
