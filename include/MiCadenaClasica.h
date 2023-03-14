/*****************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: MiCadenaClasica.h
//
// Contiene la declaración de las funciones usadas en
// I_MostrarInicioPalabras.cpp
//
/*****************************************************************************/

#ifndef FUNCIONES_PROCESS_ARRAY
#define FUNCIONES_PROCESS_ARRAY

/***************************************************************************/
/***************************************************************************/
// Longitud de una cadena. 
// Parametros: 
//		cadena, puntero a la cadena (direccion del primer caracter)
// Devuelve:
//		Numero de caracteres de la cadena 

int longitud_cadena (const char *cadena);

/***************************************************************************/
/***************************************************************************/
// Compara dos cadenas
// Recibe: 
//		cad1 y cad2, punteros a las cadenas que se van a comparar
//			(direccion del primer caracter de cada una de ellas)
// Devuelve:
//		0, si las dos cadenas son iguales
//		un valor positivo, si cad1 > cad2
//		un valor negativo, si cad1 < cad2

int compara_cadenas (const char *cad1, const char *cad2);

/***************************************************************************/
/***************************************************************************/
// Comprueba si la cadena es palíndromo
// Recibe:
//		cad, puntero a la cadena que se va a comprobar
//
// Devuelve:
//		TRUE, si la cadena es palíndromo
//		FALSE, si la cadena NO es palíndromo

bool es_palindromo (const char *cad, int long_cad);








#endif
