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

        cout << "Introduce la cadena (esta no puede estar vacía): ";
        cin.getline(la_cadena, MAX_CARACTERES);

    }while(longitud_cadena(la_cadena) = 0;)

    

    // Llamo a la función encuentra_palabras, y guardo
    // el número de palabras en n_palabras.
    // Esto rellenará el vector de las_palabras
     

    n_palabras = encuentra_palabras(las_palabras, la_cadena);




    //Imprimo por consola la cantidad de palabras que hay.
    cout << "La cantidad de palabras que hay es: " << n_palabras << endl;


    for (int j=0; j < n_palabras; j++)
        cout << *(*(las_palabras+j)) << endl;



}

