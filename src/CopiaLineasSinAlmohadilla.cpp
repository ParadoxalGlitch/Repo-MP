/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: CopiaLineasSinAlmohadilla.cpp
//
// Programa que lee una entrada e imprime dicha entrada sin las lineas que
// comiencen por '#'
//
/***************************************************************************/



#include <iostream>

using namespace std;


int main(){

    string total;
    string linea;

    while(getline(cin, linea)){

        if (linea.at(0) != '#')
            cout << linea << endl;

    }


    return 0;

}