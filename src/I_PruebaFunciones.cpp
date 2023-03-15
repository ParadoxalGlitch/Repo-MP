/*****************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: I_PruebaFunciones.cpp
//
// Contiene la función main.

// Fichero de prueba de funciones
//
/*****************************************************************************/


#include <iostream>
#include "MiCadenaClasica.h"

using namespace std;


int main(){

    const int TAM = 80;
    char cad[TAM];
    char cad2[TAM];
    char palindromo[TAM] = "farigiraf";
    char cad3[TAM];
    char cad4[TAM];
    int longitud;
    int iguales;





    // Inicio prueba, introducir cadena cualesquiera

    cout << "Prueba de funciones MiCadenaClasica" << endl;  

    cout << "Introduce una cadena: ";
    cin.getline(cad, TAM);

    cout << "Introduce una segunda cadena: ";
    cin.getline(cad2, TAM);



    // Prueba de longitud_cadena

    longitud = longitud_cadena(cad);
    cout << "La longitud de la cadena 1 es: " << longitud << endl;


    // Prueba comparar_cadenas

    iguales = compara_cadenas(cad, cad2);

    cout << "0 = iguales, positivo = cad > cad2, negativo cad2 > cad" << endl;
    cout << "El resultado de la comparación entre cad y cad2 es:" << endl;
    cout << iguales << endl;


    // Prueba es_palindromo

    cout << "Es palíndromo " << palindromo << " ?" << endl;

    if (es_palindromo(palindromo))
        cout << "Si, es palindromo" << endl;
    else
        cout << "No, no es palindromo" << endl;



    // Prueba copiar_cadena

    copiar_cadena(cad3, palindromo);

    cout << "He copiado la cadena palindromo en cad3, ";
    cout << "y ahora cad3 es: " << cad3;
    cout << endl;

    invertir_cadena(cad4, cad);

    cout << "La cadena cad4 es cad pero invertida, y es: " << cad4;
    cout << endl;

    return(0);

}
