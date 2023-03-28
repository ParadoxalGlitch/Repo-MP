/*****************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: II_Demo_VectorDinamico.cpp
//
// Contiene la función main.
//
/*****************************************************************************/


#include <iostream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstdlib>
#include "FuncsVectorDinamico.h"

using namespace std;









int main(int argc, char * argv[]){


    VectorDinamico v;
    const int TAM_INICIAL = 20;
    const int MAX_ELEMENTOS = 100;
    char cadena[MAX_ELEMENTOS];
    int valor;
    string cadena_leer;



    v = CreaVectorDinamico(TAM_INICIAL);

        cout << "Introduce la cadena: " << endl;
        cin.getline(cadena, MAX_ELEMENTOS);

    do{
        valor = atoi(cadena);
        AniadeVectorDinamico(v, valor);
        cout << "Introduce la cadena: " << endl;
        cin.getline(cadena, MAX_ELEMENTOS);
        
    }while(cadena != "FIN");


    cadena_leer = ToString(v);

    cout << endl << endl;

    cout << cadena_leer;




















}


