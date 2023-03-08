/*****************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: I_OrdenayMezclaVectores.cpp
//
// Contiene la función main.
//
/*****************************************************************************/

#include <iostream>
#include <ProcesamientoArrayInt.h>
using namespace std;

int main(){

    const int TOPE = 100;
    int v1[TOPE];
    int v2[TOPE];
    int res[2*TOPE];
    int tam_v1, tam_v2; // 0 <= tam_v1, tam_v2 < TOPE
    int tam_res; // 0 <= tam_res < 2*TOPE
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

    while(!ComprobarNumDatos(tam_v1, TOPE)){
        cin >> tam_v2;
    }

    // Actualizo el tamaño del vector res respecto al tamaño de los
    // otros vectores v1 y v2.

    tam_res = tam_v1 + tam_v2;


    // Relleno el vector con números aleatorios. 
    // El usuario elije entre qué numeros generar.

    cout << "Introduce entre qué numeros generar." << endl;
    cout << "Menor: ";
    cin >> menor;
    cout << "Mayor: ";
    cin >> mayor;


    // Relleno el primer vector

    RellenaVector(v1, tam_v1, menor, mayor);

    // Relleno el segundo vector

    RellenaVector(v2, tam_v2, menor, mayor);


    // Imprimo ambos vectores sin ordenar aún

    cout << "El vector v1 generado es el siguiente:" << endl;
    for (int i=0; i<tam_v1; i++)
        cout << "[" << v1[i] << "]";
    cout << endl;

    // Imprimo el vector generado sin ordenar

    cout << "El vector v2 generado es el siguiente:" << endl;
    for (int i=0; i<tam_v2; i++)
        cout << "[" << v2[i] << "]";
    cout << endl;


    // Le pregunto al usuario que método
    // de ordenación prefiere

    cout << "Introduzca el método de ordenación que quiere usar" << endl;
    cout << "(1 = Seleccion, 2 = Insercion, 3 = Intercambio): ";
    cin >> opcion;

    // Compruebo que la opción es correcta 
    // y muestro según la opción

    while (!ComprobarOpcion(opcion)){
        cin >> opcion;
    }
    if (opcion = 1){
        OrdenaSeleccion(v1, 0, tam_v1);
        cout << "Vector ordenado por Selección:" << endl;
        for (int i=0; i<tam_v1; i++)
            cout << "[" << v1[i] << "]";

        cout << endl;

        OrdenaSeleccion(v2, 0, tam_v2);
        cout << "Vector ordenado por Selección:" << endl;
        for (int i=0; i<tam_v2; i++)
            cout << "[" << v2[i] << "]";

    }

    else if (opcion = 2){
        OrdenaInsercion(v1, 0, tam_v1);
        cout << "Vector ordenado por Insercción:" << endl;
        for (int i=0; i<tam_v1; i++)
            cout << "[" << v1[i] << "]";

        cout << endl;

        OrdenaInsercion(v2, 0, tam_v2);
        cout << "Vector ordenado por Insercción:" << endl;
        for (int i=0; i<tam_v2; i++)
            cout << "[" << v2[i] << "]";
    }
     
    else if (opcion = 3){
        OrdenaSeleccion(v1, 0, tam_v1);
        cout << "Vector ordenado por Intercambio:" << endl;
        for (int i=0; i<tam_v1; i++)
            cout << "[" << v1[i] << "]";

        cout << endl;

        OrdenaSeleccion(v2, 0, tam_v2);
        cout << "Vector ordenado por Intercambio:" << endl;
        for (int i=0; i<tam_v2; i++)
            cout << "[" << v2[i] << "]";
    }
}


