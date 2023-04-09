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
    string Id_depto;
public:


/***************************************************************************/
// Constructor por defecto

    Departamento();

/***************************************************************************/
// Constructor con argumentos

Departamento(string nom, string id);

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




};


#endif
