/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: Fecha.cpp
//
// Contiene las implementaciones de la clase "Fecha"
//
/***************************************************************************/


#include "Fecha.h"

#include "utils.h"

#include <iostream>


using namespace std;

/***************************************************************************/
/***************************************************************************/
// Constructor por defecto

Fecha :: Fecha()
{
    dia = 0;
    mes = 0;
    anio = 0;
}

/***************************************************************************/
// Constructor de copia

Fecha :: Fecha(Fecha & otra)
{
    // Inicializo los atributos
    dia = 0;
    mes = 0;
    anio = 0;

    // Copio los atributos
    clona(otra);
}

/***************************************************************************/
// Constructor con argumentos

Fecha :: Fecha(string linea)
{
    // Creo un string auxiliar donde iré guardando los datos


    string aux = "";
    int i = 0;
    char delim = '/';
    

    // En este caso, el delimitador sera distinto al resto.
    // Este será "/"
    // A su vez, el formato de la fecha será dd /mes abreviado / año

    // Voy leyendo los datos del string hasta encontrar el delimitador
    

    while(linea[i] != delim)
    {
        aux += linea[i];
        i++;
    }

    
    // Guardo el día en la clase
    setDia(stoi(aux));



    aux = "";
    i++;

    // Sigo leyendo los datos del string hasta encontrar el delimitador

    while(linea[i] != delim )
    {
        aux += linea[i];
        i++;
    }

    // Convierto el mes a texto
    setMes(stoi(aux));
    
    aux = "";

    i++;

    // Sigo leyendo los datos del string hasta encontrar el delimitador
    while(i < linea.length())
    {
        aux += linea[i];
        i++;
    }

    // Guardo el año en la clase
    setAnio(stoi(aux));
}

/***************************************************************************/
// Métodos get

int Fecha :: getDia()
{
    return dia;
}

int Fecha :: getMes()
{
    return mes;
}

int Fecha :: getAnio()
{
    return anio;
}

/***************************************************************************/
// Métodos set

void Fecha :: setDia(int d)
{
    dia = d;
}

void Fecha :: setMes(int m)
{
    mes = m;
}

void Fecha :: setAnio(int a)
{
    anio = a;
}

/***************************************************************************/
// Método ToString

string Fecha :: ToString()
{

    string meses[12] = {"Ene", "Feb", "Mar", "Abr", "May", "Jun", "Jul", \
                      "Ago", "Sep", "Oct", "Nov", "Dic"};

    string fecha = to_string(dia) + " " + meses[mes-1] + " " + to_string(anio);

    return fecha;


}

/***************************************************************************/
// Método clona

void Fecha :: clona(Fecha original)
{
    setDia(original.getDia());

    setMes(original.getMes());

    setAnio(original.getAnio());
    
}

/***************************************************************************/
/***************************************************************************/



