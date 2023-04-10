/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: utils.h
//
// Contiene las cabeceras de funciones útiles para el programa
//
/***************************************************************************/

#ifndef UTILS
#define UTILS

#include <string>

using namespace std;



// definicion del delimitador

const char DELIMITADOR = '*';

// definicion del tipo enumerado

enum class TipoAlineacion {AlinIzquierda, AlinCentro, AlinDerecha};

/***************************************************************************/
/***************************************************************************/
// Convierte el dato numero a un string con num_casillas casillas, que
// contiene el valor textual de numero. Si num_casillas es mayor que el
// número de digitos de entero se rellena (por la izquierda) con el carácter
// relleno.

string FormatInt (int numero, int num_casillas, char relleno= ' ');


/***************************************************************************/
/***************************************************************************/
// Convierte el dato numero a un string que contiene el valor textual de
// numero de acuerdo con el formato indicado según los valores de
// num_casilas y num_dec. Si hiciera falta rellena los huecos con el carácter
// relleno.

string FormatDouble (double numero, int num_casillas, int num_dec, 
                     char relleno= ' ');

/***************************************************************************/
/***************************************************************************/
// Convierte el dato string la_cadena a un string con num_casillas casillas,
// rellenando (si procede, por la izquierda) con el caracter relleno.
// alineación indica el ajuste o justificación de la_cadena en el espacio
// indicado por num_casillas

string FormatString (string la_cadena, int num_casillas, 
                     TipoAlineacion alineacion = TipoAlineacion::AlinIzquierda,
                     char relleno= ' ');








#endif