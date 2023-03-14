//*****************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: MiCadenaClasica.cpp
//
// Contiene la definición de las funciones usadas en
//          I_MostrarInicioPalabras.cpp
//
/*****************************************************************************/
#include "MiCadenaClasica.h"
#include <cctype>
#include <cstring>

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Longitud de una cadena. 
// Parametros: 
//		cadena, puntero a la cadena (direccion del primer caracter)
// Devuelve:
//		Numero de caracteres de la cadena 

int longitud_cadena (const char *cadena)
{
	const char *p;
	for (p=cadena; *p != '\0'; p++); // Buscar el caracter '\0'
	
	return (p-cadena);
}


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

int compara_cadenas (const char *cad1, const char *cad2)
{
	bool sigo = true; 

	while ((sigo) && (*cad1 != '\0') && (*cad2 != '\0')) 
		if (*cad1 == *cad2) {
			cad1++;
			cad2++;
		} 
		else sigo = false; 

	return (*cad1 - *cad2); 
}

/***************************************************************************/
/***************************************************************************/
// Comprueba si la cadena es palíndromo
// Recibe:
//		cad, puntero a la cadena que se va a comprobar
//
// Devuelve:
//		TRUE, si la cadena es palíndromo
//		FALSE, si la cadena NO es palíndromo

bool es_palindromo (const char *cad, int long_cad)
{
	int inicio = 0;
	int final = long_cad;
	bool es_palindromo = true;
	
	while((es_palindromo) && (inicio < final)){
		if (*(cad+inicio) == *(cad+final)){
			inicio++;
			final--;
		}
		else es_palindromo = false; 
	}
	return (es_palindromo);
}