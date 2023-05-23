/***************************************************************************/
// David Pérez Tobarra
//
// Pruebas sobre el tipo Matriz2D
//
// Fichero: V_Demo-BasicoMatriz2D.cpp 
//
/***************************************************************************/

#include <iostream>

#include "Matriz2D.h"
#include "TipoBase.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/

int main (void)
{

    Matriz2D m1 (4,7,9);

    cout << "He creado una matriz de dimension 4x7 con todos los valores a 9";
    cout << endl;

    cout << m1;

    Matriz2D m2;

    cin >> m2;

    cout << "He rellenado la matriz m2 con datos:" << endl;
    cout << m2; 

    return (0);
}