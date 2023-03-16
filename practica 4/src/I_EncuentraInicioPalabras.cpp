/*****************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: I_EncuentraInicioPalabras.cpp
//
// Contiene la función main.
//
/*****************************************************************************/

#include "MiCadenaClasica.h"
#include <iostream>

using namespace std;



/*****************************************************************************/
// FUNCIONES
/*****************************************************************************/



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

	const char* ptr = cadena;
	char **ptr_palabras = palabras;
	bool dentro_palabra = false;
	char **ptr_lim_palabras = palabras + max_num;
	int num_palabras = 0;


	// Mientras se encuentre fuera de una palbabra, y esté en un espacio, 
	// no cambiará el condicional.
	// Lo mismo mientras esté dentro de una palabra y no encuentre espacios.

	while(*ptr != '\0' && ptr_palabras < ptr_lim_palabras){

		// Si está fuera y deja de encontrar espacios, 
		// es que está dentro de una palabra.
		// Guarda la primera letra y continúa hasta encontrar un espacio

		if (!dentro_palabra && *ptr != ' '){
			dentro_palabra = true;
			*(ptr_palabras) = (char *) ptr;
			ptr_palabras++;
			num_palabras++;

		}

		// Si está dentro de una palabra y encuentra un espacio, 
		// es que está ya fuera de la palabra
		// Seguirá comprobando que esté en espacios 
		// hasta llegar a la siguiente palabra.

		else if (dentro_palabra && *ptr == ' '){
			dentro_palabra = false;
		}
		
		ptr++;
	}

    if (ptr_palabras == ptr_lim_palabras){

        cout << "AVISO:" << endl;
        cout << "Se ha alcanzado el límite de palabras" << endl;
        cout << "Es posible que no se hayan podido guardar";
        cout << " todas las letras" << endl << endl << endl;

    }

	return(num_palabras);
}




/*****************************************************************************/
// FUNCION MAIN
/*****************************************************************************/



int main()
{

    const int MAX_CARACTERES = 100;
    const int MAX_PALABRAS = 20;
    char la_cadena[MAX_CARACTERES];
    char * las_palabras[MAX_PALABRAS];
    int n_palabras;

    
    // Pido al usuario introducir la cadena a procesar
    // comprobando que no esté vacía.

    do{

        cout << "Introduce la cadena (esta no puede estar vacía): " << endl;
        cin.getline(la_cadena, MAX_CARACTERES);

    }while(longitud_cadena(la_cadena) == 0);

    cout << endl << endl;
    

    // Llamo a la función encuentra_palabras, y guardo
    // el número de palabras en n_palabras.
    // Esto rellenará el vector de las_palabras
     

    n_palabras = encuentra_palabras(las_palabras, la_cadena, MAX_PALABRAS);



    // Compruebo si la cadena contiene solo espacios, es decir
    // 0 palabras, e imprimo el resultado correspondiente.


    if (n_palabras == 0){

        cout << "La cadena introducida no contiene palabras";

    }
    
    else{

        // Imprimo por consola la cantidad de palabras que hay.

        cout << "La cantidad de palabras que hay es: " << n_palabras << endl;
        cout << endl << endl;

        // Imprimo cada letra

        cout << "Las letras guardadas son las siguientes: " << endl << endl;

        for (int i=0; i < n_palabras; i++)
            cout << *(*(las_palabras+i)) << endl;

    }



    return (0);

}

