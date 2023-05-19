/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: Cuenta_palabras_por_linea.cpp
//
// Programa que cuenta la cantidad de palabras que posee cada linea
//
/***************************************************************************/

#include <iostream>
#include <sstream>
using namespace std;

int main(){


    string linea;
    string aux;
    int i=0;
    int contador_palabras=0;
    bool en_palabra = false;


    while (getline(cin, linea)){

        contador_palabras = 0;

        istringstream iss;
        iss.str(linea);

        aux = linea;

        while (iss >> aux){

            contador_palabras++;

        }


        cout << "Linea   " << i+1 <<":     " << contador_palabras;
        cout << " palabras" << endl;
        i++;

    }

    return 0;
}