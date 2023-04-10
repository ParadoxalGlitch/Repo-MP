/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: Fecha.h
//
// Contiene las cabeceras de la clase "Fecha"
//
/***************************************************************************/

#ifndef FECHA
#define FECHA

#include <string>

#include "utils.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Clase "Fecha"

class Fecha
{

private:

    int dia;
    string mes;
    int anio;

public:

/***************************************************************************/
// Constructor por defecto

    Fecha();

/***************************************************************************/
// Constructor con argumentos

    Fecha(string linea);

/***************************************************************************/
// Métodos get

    int getDia();
    string getMes();
    int getAnio();

/***************************************************************************/
// Métodos set

    void setDia(int d);
    void setMes(string m);
    void setAnio(int a);

/***************************************************************************/
// Método ToString

    string ToString();

};

#endif