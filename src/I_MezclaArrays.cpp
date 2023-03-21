/*****************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: I_MezclaArrays.cpp
//
// Contiene la función main.
//
/*****************************************************************************/



#include <iostream>
#include "ProcesamientoArrayInt.h"
using namespace std;

int main(int argc, char * argv[]){


    const int TOPE = 100;
    int v1[TOPE];
    int v2[TOPE];
    int res[2*TOPE];
    int res2[2*TOPE];
    int tam_v1 = TOPE, tam_v2 = TOPE;
    int tam_res;
    int tam_res2;
    int menor = 1, mayor = 200;
    int opcion;




    // Actualizo los valores de tam_v1, tam_v2 , menor y mayor 
    // en función de los argumentos presentados por el usuario

    if (argc > 4) {
        cerr << "Error: demasiados argumentos" << endl << endl;
        exit (1);
    }

    else if(argc > 1){
        tam_v1 = atoi(argv[1]);
        tam_v2 = atoi(argv[1]);

        if (argc > 2){
            if (argc > 3)
                menor = atoi(argv[3]);

            else
                menor = 1;

            mayor = atoi(argv[2]);
        }
    }






    // Actualizo el tamaño del vector res respecto al tamaño de los
    // otros vectores v1 y v2.

    tam_res = tam_v1 + tam_v2;
    tam_res2 = tam_res;





    // Compruebo que los valores a generar han sido proporcionados
    // de manera correcta


    ComprobarOpcionAleatorios(menor,mayor);






    // Relleno el primer vector

    RellenaVector(v1, tam_v1, menor, mayor);

    // Relleno el segundo vector

    RellenaVector(v2, tam_v2, menor, mayor);




    // Los muestro por pantalla

    cout << "Vector  1:" << endl;
    MuestraVector(v1, tam_v1);
    cout << endl;

    cout << "Vector 2:" << endl;
    MuestraVector(v2, tam_v2);
    cout << endl << endl << endl; 



    
    // Ordeno los vectores por Seleccion
    
    OrdenaSeleccion(v1, 0, tam_v1-1);
    OrdenaSeleccion(v2, 0, tam_v2-1);




    
    // Muestro los vectores ordenados

    cout << "Vector Ordenado 1:" << endl;
    MuestraVector(v1, tam_v1);
    cout << endl;

    cout << "Vector Ordenado 2:" << endl;
    MuestraVector(v2, tam_v2);
    cout << endl << endl << endl;







    // Los mezclo de forma estándar.

    MezclarVectores(v1, v2, res, tam_v1, tam_v2);

    // Los mezclo de forma selectiva.

    tam_res2 = MezclarVectoresSelectiva(v1, v2, res2, tam_v1, tam_v2);







    // Muestro los vectores mezclados

    cout << "Vector Mezclado normal:" << endl;
    MuestraVector(res, tam_res);

    cout << endl << endl;

    cout << "Vector Mezclado selectivo:" << endl;
    
    MuestraVector(res2, tam_res2);

    cout << endl;

}