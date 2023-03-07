/*****************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: I_PosMayor_Basico.cpp
//
// Contiene la función main.
//
/*****************************************************************************/


#include <iostream>
#include <ProcesamientoArrayInt.h>
using namespace std;


int main()
{

    const int TOPE = 100;
    int vector [TOPE];
    int dcha, izda;

    //por ahora el vector va a ser rellenado por mi para testeo

    vector[0] = 7;
    vector[1] = 4;
    vector[2] = 8;
    vector[3] = 12;
    vector[4] = 2;
    vector[5] = 1;

    cout << "Introduce el extremo inferior del intervalo a procesar: ";
    cin >> izda;
    cout << "Introduce el extremo superior del intervalo a procesar: ";
    cin >> dcha;

    int* mayor = PosMayor(vector, izda, dcha);
    cout << *mayor;



    



}