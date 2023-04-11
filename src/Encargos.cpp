/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: Encargos.cpp
//
// Contiene las implementaciones de la clase "Encargos"
//
/***************************************************************************/

#include "Encargos.h"

#include <iostream>

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Constructor por defecto

Encargos :: Encargos()
{
    categoria = 0;
    creditos = 0;
}

/***************************************************************************/
// Constructor con argumentos

Encargos :: Encargos(string linea, char delimitador)
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

int Encargos :: getCategoria()
{
    return categoria;
}

double Encargos :: getCreditos()
{
    return creditos;
}

/***************************************************************************/
// Métodos set

void Encargos :: setCategoria(int cat)
{
    categoria = cat;
}

void Encargos :: setCreditos(double cred)
{
    creditos = cred;
}

/***************************************************************************/
// Método ToString

string Encargos :: ToString()
{


    string cad;
    /*string numero = FormatDouble(creditos,3,2);
    string cadena = " " + to_string(categoria) + "  " + \
    FormatString(numero,numero.length()+5,TipoAlineacion::AlinDerecha) + "\n";
    return cadena;*/

    cad += FormatString(to_string(getCategoria()), 3, TipoAlineacion::AlinCentro);
    cad += " ";
    cad += FormatString(FormatDouble(getCreditos(),4,2),5,TipoAlineacion::AlinDerecha);
    cad += "\n";

    return cad;

}

/***************************************************************************/
/***************************************************************************/