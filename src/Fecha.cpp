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
    dia = 1;
    mes = "Ene";
    anio = 2000 ;
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
    dia = stoi(aux);
    aux = "";

    i++;

    // Sigo leyendo los datos del string hasta encontrar el delimitador

    while(linea[i] != delim )
    {
        aux += linea[i];
        i++;
    }

    // Convierto el mes a texto
    
    switch(stoi(aux))
    {
        case 1:
            mes = "Ene";
            break;
        case 2:
            mes = "Feb";
            break;
        case 3:
            mes = "Mar";
            break;
        case 4:
            mes = "Abr";
            break;
        case 5:
            mes = "May";
            break;
        case 6:
            mes = "Jun";
            break;
        case 7:
            mes = "Jul";
            break;
        case 8:
            mes = "Ago";
            break;
        case 9:
            mes = "Sep";
            break;
        case 10:
            mes = "Oct";
            break;
        case 11:
            mes = "Nov";
            break;
        case 12:
            mes = "Dic";
            break;
    }

    aux = "";

    i++;

    // Sigo leyendo los datos del string hasta encontrar el delimitador
    while(i < linea.length())
    {
        aux += linea[i];
        i++;
    }

    // Guardo el año en la clase
    anio = stoi(aux);
}

/***************************************************************************/
// Métodos get

int Fecha :: getDia()
{
    return dia;
}

string Fecha :: getMes()
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

void Fecha :: setMes(string m)
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
    string fecha = to_string(dia) + " " + mes + " " + to_string(anio);

    return fecha;


}

/***************************************************************************/
/***************************************************************************/



