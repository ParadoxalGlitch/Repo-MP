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

using namespace std;

int main(int argc, char * argv[]){

    int tam_palabra = 0;
    int cuenta_palabras = 0;
    string linea;

    if (argc < 2 || argc > 2){
        cerr << "Número de argumentos incorrecto" << endl;
        exit(1);
    }

    else    
        tam_palabra = stoi(argv[1]);



    // Leo el fichero entero

    while (cin >> linea){

        if (linea.length() == tam_palabra)
            cuenta_palabras++;

    }

    cout << "Hay " << cuenta_palabras << " palabra(s) de longitud ";
    cout << tam_palabra << endl;




}