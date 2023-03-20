/*****************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: I_MezclaArrays_ref.cpp
//
// Contiene la función main.
//
/*****************************************************************************/



#include <iostream>
#include "ProcesamientoArrayInt.h"
using namespace std;

int main(/*RELLENAR*/){


    const int TOPE = 100;
    const int MAX_CHAR = 100;
    int v1[TOPE];
    int v2[TOPE];
    int res[2*TOPE];
    char selectiva[MAX_CHAR] = "si";
    int tam_v1, tam_v2; // 0 <= tam_v1, tam_v2 < TOPE
    int tam_res = 12; // 0 <= tam_res < 2*TOPE
    int menor, mayor;
    int opcion;


    // Le pregunto al usuario cuantas casillas quiere que tenga cada
    // vector, comprobando que los datos sean correctos.


    // Pregunto sobre el vector v1

    cout << "Introduce el número de casillas a rellenar del vector v1: ";
    cin >> tam_v1;

    while(!ComprobarNumDatos(tam_v1, TOPE)){
        cin >> tam_v1;
    }

    // Pregunto sobre el vector v2

    cout << "Introduce el número de casillas a rellenar del vector v2: ";
    cin >> tam_v2;

    while(!ComprobarNumDatos(tam_v2, TOPE)){
        cin >> tam_v2;
    }

    // Relleno el vector con números aleatorios. 
    // El usuario elije entre qué numeros generar.

    cout << "Introduce entre qué numeros generar." << endl;
    cout << "Menor: ";
    cin >> menor;
    cout << "Mayor: ";
    cin >> mayor;


/*


HACER COMPROBACIÓN


*/


    // Relleno el primer vector

    RellenaVector(v1, tam_v1, menor, mayor);

    // Relleno el segundo vector

    RellenaVector(v2, tam_v2, menor, mayor);





    cout << "Vector  1:" << endl;
    MuestraVector(v1, tam_v1);
    cout << endl;

    cout << "Vector 2:" << endl;
    MuestraVector(v2, tam_v2);
    cout << endl;









    
    // Ordeno los vectores por Seleccion
    
    OrdenaSeleccion(v1, 0, tam_v1-1);
    OrdenaSeleccion(v2, 0, tam_v2-1);


    
    // Muestro los vectores

    cout << "Vector Ordenado 1:" << endl;
    MuestraVector(v1, tam_v1);
    cout << endl;

    cout << "Vector Ordenado 2:" << endl;
    MuestraVector(v2, tam_v2);
    cout << endl;


    //Los mezclo a petición del usuario

   /* cout << "¿Quiere mezclarlos por selección?: " << endl;
    
    cin.getline(selectiva, MAX_CHAR);*/
    
    MezclarVectoresNuevo(v1, v2, res, tam_res, tam_v1, tam_v2, "si");
    

    // MUestro los vectores mezclados

    cout << "Vector Mezclado:" << endl;
    MuestraVector(res, tam_res);

    cout << endl;

}


