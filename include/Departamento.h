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
// Constructor de copia

    Departamento(const Departamento & otro);


/***************************************************************************/
// Constructor con argumentos
    
    Departamento(string linea, char delimitador=DELIMITADOR);


/***************************************************************************/
// Destructor
    ~Departamento();

/***************************************************************************/
// Métodos get

string getNombre() const;

string getId() const;

/***************************************************************************/
// Métodos set

void setNombre(string nom);

void setId(string id);

/***************************************************************************/
// Método ToString

string ToString();

/***************************************************************************/
// Método ReservaMemoria
// Se llama a esta función cuando se va a clonar un objeto
// por lo que se elimina el contenido anterior y se reserva
// para el nuevo

void ReservaMemoria(const Departamento & objeto);

/************************************************************/
// Libera memoria

void LiberarMemoria(void);


/************************************************************/
// Copiar datos desde otro objeto de la clase
// Parámetros: otro (referencia), objeto que sirve de modelo.
//
// PRE: Se ha reservado memoria para los datos
void CopiarDatos (const Departamento & otro);

/***************************************************************************/
// Método clona

void clona(const Departamento & original);

/**************************************************************************/
// Operador de asignación

Departamento & operator = (const Departamento & original);

/**************************************************************************/
// Operador << y >>

friend ofstream & operator << (ofstream & fo, Departamento & dep);

friend ifstream & operator >> (ifstream & fi, Departamento & dep);



};


#endif
