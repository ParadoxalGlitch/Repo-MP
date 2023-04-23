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

int Encargo :: getCategoria()
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