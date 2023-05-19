/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: CuentaPalabrasLongitudConcreta.cpp
//
// Programa que cuenta la cantidad de palabras que poseen una longitud
// concreta
//
/***************************************************************************/


#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char * argv[]){

    if (argc != 2){
        cerr << "Número de argumentos incorrecto" << endl;
        //añadir manera
        exit(1);
    }

    int tam_palabra = 0;
    int cuenta_palabras = 0;
    string linea;
    
    tam_palabra = atoi(argv[1]);


    // Leo el fichero entero

    while (cin >> linea){

        if (linea.length() == tam_palabra)
            cuenta_palabras++;

    }

    cout << "Hay " << cuenta_palabras << " palabra(s) de longitud ";
    cout << tam_palabra << endl;


    return 0;

}