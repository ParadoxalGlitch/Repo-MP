/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: utils.cpp
//
// Contiene las implementaciones de funciones útiles para el programa
//
/***************************************************************************/

#include "utils.h"

#include <iostream>

#include <string>

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Convierte el dato numero a un string con num_casillas casillas, que
// contiene el valor textual de numero. Si num_casillas es mayor que el
// número de digitos de entero se rellena (por la izquierda) con el carácter
// relleno.

string FormatInt (int numero, int num_casillas, char relleno){

    string aux = "";

    // Convierto el entero a string
    aux = to_string(numero);

    // Si el número de casillas es mayor que el número de dígitos del entero
    // lo relleno con el relleno hasta llenar las casillas pedidas
    if(num_casillas > aux.length())
    {
        while (aux.length() < num_casillas)
        {
            aux += relleno;
        }
    }

    return aux;

}

/***************************************************************************/
/***************************************************************************/
// Convierte el dato numero a un string que contiene el valor textual de
// numero de acuerdo con el formato indicado según los valores de
// num_casilas y num_dec. Si hiciera falta rellena los huecos con el carácter
// relleno.

string FormatDouble (double numero, int num_casillas, int num_dec, 
                     char relleno){


    // Primero obtengo la parte enetera y la parte decimal del número

    int parte_entera = numero;
    double parte_decimal = numero - parte_entera;

    // convierto a string la parte decimal puesto que
    // es posible que deba acortarla

    string aux_decimal = to_string(parte_decimal);



    // Creo un string auxiliar

    string aux = "";



    // Convierto la parte entera a string y la guardo
    aux = to_string(parte_entera);



    // Compruebo el numero de decimales que se piden

    if(num_dec > 0)
    {
        // Como se piden almenos 1 decimal, añado el punto
        aux += ".";

        // Añado la parte decimal que se me pide
        // (Uso +2 para ignorar el 0.)

        int i = 0;

        while(i < num_dec)
        {
            if (i < aux_decimal.length()){
                aux += aux_decimal[i+2];
                i++;
            }
            
            else
            {
                aux += '0';
                i++;
            }
        }

    }

    // Llegados a este punto, el string ya contiene el número, por lo que
    // solo queda rellenar con el caracter relleno si hiciera falta


    if(num_casillas > aux.length())
    {
        while (aux.length() < num_casillas)
        {
            aux += relleno;
        }
    }

    return aux;

}



/***************************************************************************/
/***************************************************************************/
// Convierte el dato string la_cadena a un string con num_casillas casillas,
// rellenando (si procede, por la izquierda) con el caracter relleno.
// alineación indica el ajuste o justificación de la_cadena en el espacio
// indicado por num_casillas
// PRE: la cadena es mas larga que el numero de casillas que se piden

string FormatString (string la_cadena, int num_casillas, 
                     TipoAlineacion alineacion, char relleno)
{
    // Compruebo si la cadena tiene menos caracteres que las casillas pedidas

    if(la_cadena.length() < num_casillas)
    {
        // Si es así, relleno la cadena con el caracter relleno
        //Dependiendo del tipo de alineación

        while(la_cadena.length() < num_casillas)
        {
            if(alineacion == TipoAlineacion::AlinIzquierda)
            {
                la_cadena += relleno;
            }

            else if(alineacion == TipoAlineacion::AlinCentro)
            {
                la_cadena = relleno + la_cadena + relleno;
            }

            else if(alineacion == TipoAlineacion::AlinDerecha)
            {
                la_cadena = relleno + la_cadena;
            }
        }
    }

    return la_cadena;

}