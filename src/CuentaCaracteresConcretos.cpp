/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: CuentaCaracteresConcretos.cpp
//
// Programa que lee una secuencia indefinida y muestra la cantidad del
// caracter especificado por argumento en la consola que hay en la secuencia
//
/***************************************************************************/

#include <iostream>
using namespace std;

int main(int argc, char * argv[]){


    char el_caracter;
    string linea;
    int cuenta = 0;

    if (argc == 1)
        el_caracter = 'a'; // Valor por defecto

    else if (argc == 2)
        el_caracter = *argv[1];

    else{
        cerr << "ERROR: Número de argumentos inválido" << endl;
        exit(1);        
    }


    while (getline(cin, linea)){

        for (int i=0; i<linea.length(); i++)
            if (linea[i] == el_caracter)
                cuenta++;

    }


    cout << "En el fichero, aparece el caracter " << el_caracter << " ";
    cout << cuenta << " veces" << endl;

}