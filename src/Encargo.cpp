/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: Encargos.cpp
//
// Contiene las implementaciones de la clase "Encargos"
//
/***************************************************************************/

#include "Encargo.h"

#include <iostream>
#include <fstream>

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Constructor por defecto

Encargo :: Encargo()
{
    categoria = 0;
    creditos = 0,0;
}

/***************************************************************************/
/***************************************************************************/
// Constructor de copia

Encargo :: Encargo(Encargo & otro)
{
    // Inicializo los atributos
    categoria = 0;
    creditos = 0,0;

    // Copio los atributos
    clona(otro);
}

/***************************************************************************/
// Constructor con argumentos

Encargo :: Encargo(string linea, char delimitador)
{
    
        // Creo un string auxiliar donde iré guardando los datos
    
        string aux = "";
        int i = 0;
        
        // Voy leyendo los datos del string hasta encontrar el delimitador
        while(linea[i] != delimitador)
        {
            aux += linea[i];
            i++;
        }
    
        // Guardo la categoría en la clase
        categoria = stoi(aux);
        aux = "";
    
        i++;
    
        // Sigo leyendo los datos del string hasta encontrar el delimitador
    
        while(linea[i] != delimitador)
        {
            aux += linea[i];
            i++;
        }
    
        // Guardo los créditos en la clase
        creditos = stod(aux);
}

/***************************************************************************/
// Métodos get

int Encargo :: getCategoria() const
{
    return categoria;
}

double Encargo :: getCreditos()
{
    return creditos;
}

/***************************************************************************/
// Métodos set

void Encargo :: setCategoria(int cat)
{
    categoria = cat;
}

void Encargo :: setCreditos(double cred)
{
    creditos = cred;
}

/***************************************************************************/
// Método ToString

string Encargo :: ToString()
{


    string cad;
    /*string numero = FormatDouble(creditos,3,2);
    string cadena = " " + to_string(categoria) + "  " + \
    FormatString(numero,numero.length()+5,TipoAlineacion::AlinDerecha) + "\n";
    return cadena;*/

    cad += FormatString(to_string(getCategoria()), 3, \
                        TipoAlineacion::AlinCentro);
    cad += " ";
    cad += FormatString(FormatDouble(getCreditos(),4,2),5,\
                        TipoAlineacion::AlinDerecha);
    cad += "\n";

    return cad;

}


/***************************************************************************/
/***************************************************************************/
// Método clona

void Encargo :: clona(Encargo & otro)
{
    
    setCategoria(otro.getCategoria());

    setCreditos(otro.getCreditos());

}

/**************************************************************************/
/**************************************************************************/
// Operador << y >>


ofstream & operator << (ofstream & fo, Encargo & encargo)
{

    // Guardo los datos separados por DELIMITADOR

    //Guardo el ID del departamento:
    fo << encargo.getCategoria() << '*';

    // Guardo el Nombre del departamento

    fo << encargo.getCreditos() << '*';


    return fo;

}

ifstream & operator >> (ifstream & fi, Encargo & encargo)
{

    string linea;

    // Sigo leyendo lineas, hasta encontrar una que
    // no empiece por # (es decir, ignorar comentarios) 

    getline(fi,linea); // Lectura adelantada

    while(linea.at(0) == '#'){

        getline(fi,linea);

    }

    // Aquí deberiamos haber encontrado los datos. Si estos no están
    // el departamento quedará vacío de todas formas

    // Voy guardando en un string aux los datos hasta
    // encontrar el delimitador, lo cual será el ID
    string aux;
    int i=0;

    while(linea[i] != DELIMITADOR)
    {
        aux += linea[i];
        i++;
    }

    encargo.setCategoria(stoi(aux)); // Actualizo el valor de Id
    aux = ""; //Reinicio aux


    // Ahora, toca leer el nombre

    i++; // Ignorar el delimitador

    while(linea[i] != DELIMITADOR)
    {
        aux += linea[i];
        i++;
    }

    encargo.setCreditos(stod(aux));

    // Ya hemos acabado de leer los datos
        
    
    return fi;

}