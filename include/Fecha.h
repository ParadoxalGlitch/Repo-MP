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
    int mes;
    int anio;

public:

/***************************************************************************/
// Constructor por defecto

    Fecha();

/***************************************************************************/
// Constructor de copia

    Fecha(Fecha & otra);

/***************************************************************************/
// Constructor con argumentos

    Fecha(string linea);

/***************************************************************************/
// Métodos get

    int getDia();
    int getMes();
    int getAnio();

/***************************************************************************/
// Métodos set

    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);

/***************************************************************************/
// Método ToString

    string ToString();

/***************************************************************************/
// Método clona

    void clona(Fecha original);

    
};

#endif