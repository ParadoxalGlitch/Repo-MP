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
#include <cstring>
#include "ProcesamientoArrayInt.h"

using namespace std;

int main(int argc, char * argv[]){



    const int TOPE = 100;
    const int MAX_CHAR = 100;
    int v1[TOPE];
    int v2[TOPE];
    int res[2*TOPE];
    char selectiva[MAX_CHAR];
    int tam_v1 = TOPE, tam_v2 = TOPE;
    int tam_res = 0;
    int menor = 1, mayor = 200;
    int opcion;




    // Actualizo los valores de tam_v1, tam_v2 , menor y mayor 
    // en función de los argumentos presentados por el usuario



    // Mensaje de error si se superan los argumentos permitidos

    if (argc > 4) {
        cerr << "Error: demasiados argumentos" << endl;

        // Mensaje de ayuda
        cerr << "Argumentos posibles: " << endl;
        cerr << "arg 1: tamaño vectores" << endl;
        cerr << "arg 2: menor a generar" << endl;
        cerr << "arg 3: mayor a generar" << endl;
        exit (1);
    }

    else if(argc > 1){

        tam_v1 = atoi(argv[1]);
        tam_v2 = atoi(argv[1]);

        
        // Mensaje de error si se elige un tamaño de vectores incorrecto
        if (tam_v1 < 2 || tam_v1 > 100){
            cerr << "Error: tamaño de vectores debe ser mayor o igual a 2";
            cerr << " y menor o igual a 100" << endl << endl;
            exit (1);
        }

        

        if (argc > 2){
            if (argc > 3)
                menor = atoi(argv[3]);

            else
                menor = 1;

            mayor = atoi(argv[2]);
        }
    }


    // Compruebo que han sido elegidos correctamente y
    // los corrijo de ser necesario

    ComprobarOpcionAleatorios(menor,mayor);






    // Relleno el primer vector

    RellenaVector(v1, tam_v1, menor, mayor);

    // Relleno el segundo vector

    RellenaVector(v2, tam_v2, menor, mayor);








    // Muestro ambos vectores ya rellenados

    cout << "Vector  1:" << endl;
    MuestraVector(v1, tam_v1);
    cout << endl;

    cout << "Vector 2:" << endl;
    MuestraVector(v2, tam_v2);
    cout << endl << endl << endl;
    





    
    // Ordeno los vectores por Seleccion
    
    OrdenaSeleccion(v1, 0, tam_v1-1);
    OrdenaSeleccion(v2, 0, tam_v2-1);




    
    // Muestro los vectores

    cout << "Vector Ordenado 1:" << endl;
    MuestraVector(v1, tam_v1);
    cout << endl;

    cout << "Vector Ordenado 2:" << endl;
    MuestraVector(v2, tam_v2);
    cout << endl << endl << endl; 





    //Los mezclo a petición del usuario

    cout << "¿Quiere mezclarlos por selección? (si/no): ";

    cin.getline(selectiva, MAX_CHAR);
    cout << endl;







    // Llamo a la función de mezclar en función de
    // la respuesta del usuario

    if (strcmp(selectiva, "si") == 0 || \
        strcmp(selectiva, "sI") == 0 || \
        strcmp(selectiva, "Si") == 0 || \
        strcmp(selectiva, "SI") == 0)

        MezclarVectoresNuevo(v1, v2, res, tam_res, tam_v1, tam_v2, selectiva);
    
    else
        MezclarVectoresNuevo(v1, v2, res, tam_res, tam_v1, tam_v2);



    
   // Muestro los vectores mezclados

    cout << "Vector Mezclado:" << endl;
    MuestraVector(res, tam_res);

    cout << endl;

}


