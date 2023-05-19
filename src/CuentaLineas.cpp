/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: Cuentalineas.cpp
//
// Programa que cuenta lineas de un conjunto de cadenas de texto indefinida
//
/***************************************************************************/

#include <iostream>

using namespace std;

int main(){

    string linea;
    int total_lineas = 0;
    int lineas_vacias = 0;
    int lineas_rellenas = 0;


    while(getline(cin, linea)){

        


        if (linea == "")
            lineas_vacias++; // Cuenta las lineas si tienen espacios!
                             // usar flujos para comprobar q haya palabras
        else
            lineas_rellenas++;

        total_lineas++;

    }

    cout << "Lineas vacias: " << lineas_vacias << endl;
    cout << "Lineas no vacias: " << lineas_rellenas << endl;
    cout << "Total de lineas: " << total_lineas << endl;

    return 0;


    // considera una lectura de los caracteres para contar correctamente 
    // las ultimas lineas si estan vacias




    /* FORMA DE HACERLO CON LECTURA ADELANTADA
    
    getline(cin, linea);

    while (!cin.eof()){

       if (linea == "")
            lineas_vacias++; // Cuenta las lineas si tienen espacios!
        else
            lineas_rellenas++;

        total_lineas++;

        getline(cin, linea);

    }
    
    
    
    
    
    
    
    */

}