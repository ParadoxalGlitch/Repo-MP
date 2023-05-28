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

class Adscripcion
{

private:

    char * dni;
    char * Id_depto;

public:


/***************************************************************************/
// Constructor por defecto

    Adscripcion();

/***************************************************************************/
// Constructor de copia

    Adscripcion(const Adscripcion & otro);


/***************************************************************************/
// Constructor con argumentos

    Adscripcion(string linea, char delimitador=DELIMITADOR);


/***************************************************************************/
// Destructor
    ~Adscripcion();

    

/***************************************************************************/
// Métodos get

    string getDni() const;
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

    void clona(const Adscripcion & original);


/***************************************************************************/
// Método ReservaMemoria

    void ReservaMemoria(const Adscripcion & objeto);


/***************************************************************************/
// Libera memoria
void LiberarMemoria (void);


/***************************************************************************/
// Método CopiarDatos

    void CopiarDatos (const Adscripcion & otro);

/***************************************************************************/
// Sobrecarga del operador =

    Adscripcion & operator=(const Adscripcion& original);

/**************************************************************************/
// Operador << y >>

friend ofstream & operator << (ofstream & fo, Adscripcion & adscripcion);

friend ifstream & operator >> (ifstream & fi, Adscripcion & adscripcion);

};

#endif




