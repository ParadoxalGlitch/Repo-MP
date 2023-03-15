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
#include <iostream>



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
//
// Nota:
//		Si la cadena cuenta con espacios al principio O al final,
//		será detectada como NO palíndromo
//

bool es_palindromo (const char *cad)
{
	int inicio = 0;
	int final = longitud_cadena(cad) - 1;
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

/*****************************************************************************/
/*****************************************************************************/
// Copia una cadena en otra
// Recibe:
// 		origen, cadena que se va a copiar
//		destino, cadena donde se va a copiar la cadena origen
//
//

char * copiar_cadena(char* destino, const char* origen)
{
	int i = 0;

	while (*(origen+i) != '\0'){
		*(destino+i) = *(origen+i);
		i++;
	}

	*(destino+i) = '\0';

	return (destino);
}



/*****************************************************************************/
/*****************************************************************************/
// Invierte una cadena y devuelve una nueva con ese contenido
// Recibe:
//		origen, cadena que se va a invertir
//		destino, cadena donde se va a copiar la inversión
//


char * invertir_cadena(char * resultado, const char * origen)
{

	int i = longitud_cadena(origen)-1;
	int j = 0;

	while (i >= 0){
		*(resultado + j) = *(origen + i);
		i--;
		j++;
	}

	*(resultado+j) = '\0';

	return (resultado);
}


/*****************************************************************************/
/*****************************************************************************/
// Busca las palabras de una cadena y guarda en un vector de punteros
// las primeras letras de estos.
// Recibe: 
//		palabras, vector de datos char * que apuntan a la primera
// 				  letra de cada palabra
//		cadena, cadena donde se van a buscar las palabras
//
// Devuelve:
//		numero de palabras que contiene la cadena.

int encuentra_palabras (char ** palabras, const char * cadena, int max_num)
{

	char **ptr_palabras = palabras;
	bool dentro_palabra = false;
	char **ptr_lim_palabras = palabras + max_num;
	int num_palabras = 0;


	// Mientras se encuentre fuera de una palbabra, y esté en un espacio, 
	// no cambiará el condicional.
	// Lo mismo mientras esté dentro de una palabra y no encuentre espacios.
	for (const char* ptr = cadena; *ptr != '\0'; ptr++){
	
		// Si está fuera y deja de encontrar espacios, 
		// es que está dentro de una palabra.
		// Guarda la primera letra y continúa hasta encontrar un espacio
		if (!dentro_palabra && *ptr != ' '){
			dentro_palabra = true;
			/*
				
			Poner un filtro de que no se llene ptr_palabras;
				
			*/
			*(ptr_palabras) = (char *) ptr;
			ptr_palabras++;
			num_palabras++;

	}

		// Si está dentro de una palabra y encuentra un espacio, 
		// es que está ya fuera de la palabra
		//
		// Seguirá comprobando que esté en espacios 
		// hasta llegar a la siguiente palabra.
		else if (dentro_palabra && *ptr == ' '){
			dentro_palabra = false;
		}
	}

	return(num_palabras);

}



