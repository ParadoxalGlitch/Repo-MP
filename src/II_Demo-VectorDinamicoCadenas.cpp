/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: II_Demo_VectorDinamicoCadenas.cpp
//
// Contiene el demo de las funciones de VectorDinamico
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

#include "FuncsVectorDinamicoCadenas.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/

int main() {

    VectorDinamico v = CreaVectorDinamico(10, TipoRedimension::DeUnoEnUno);


    int num_lineas = 0;
    int num_lineas_vacias = 0;
    int num_parrafos = 0;

    const int MAX_CAD = 100;

    char linea[MAX_CAD];
    
    while (cin.getline(linea, MAX_CAD)) {
    

        AniadeVectorDinamico(v,linea);
    

    }


    CalculosLineasVectorDinamico(v, num_lineas, num_lineas_vacias, num_parrafos);

    cout << "Numero de lineas: " << num_lineas;
    cout << endl;

    cout << "Numero de lineas vacias: " << num_lineas_vacias;
    cout << endl;

    cout << "Numero de parrafos: " << num_parrafos;
    cout << endl;


    cout << "El texto procesado es el siguiente: ";
    cout << endl << endl;


    ImprimeTodoVectorDinamico(v);





    return 0;



}

