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
using namespace std;

int main(){


    string linea;
    string aux;
    int i=0;
    int contador_palabras=0;


    while (getline(cin, linea)){

        aux = linea;
        contador_palabras = 0;


        while(cin >> aux){

            contador_palabras++;

        }

        cout << "Linea   " << i+1 <<":     " << contador_palabras;
        cout << " palabras";
        i++;
            

    }










}