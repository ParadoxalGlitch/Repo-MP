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
#include "ProcesamientoArrayInt.h"
using namespace std;


int main()
{

    const int TOPE = 100;
    int vector [TOPE];
    int util_v = 0;
    int num_datos;
    int dcha, izda;
    int menor, mayor;


    // Le pregunto al usuario con cuantas casillas quiere
    // rellenar del vector

    cout << "Introduce el número de casillas a rellenar: ";
    cin >> num_datos;

    // Compruebo que el numero de casillas es adecuado al
    // programa, es decir, almenos 2 y nunca superior al tope.

    while(!ComprobarNumDatos(num_datos, TOPE)){
        cin >> num_datos;
    }

    util_v = num_datos;

    // Una vez comprobado, relleno el vector con
    // números aleatorios. El usuario elije entre 
    // qué numeros generar

    cout << "Introduce entre qué numeros generar." << endl;
    cout << "Menor: ";
    cin >> menor;
    cout << "Mayor: ";
    cin >> mayor;
    cout << endl;

    // Relleno el vector

    RellenaVector(vector, num_datos, menor, mayor);

    // Muestro el vector generado por pantalla
    
    MuestraVector(vector, num_datos);
    cout << endl;

    // Pregunto al usuario el intervalo donde quiere
    // buscar el máximo, asegurándome de que dicho intervalo
    // sea correcto y adecuado al programa

    cout << "Introduce el extremo inferior del intervalo a procesar" << endl;
    cin >> izda;
    cout << "Introduce el extremo superior del intervalo a procesar" << endl;
    cin >> dcha;

    while(!ComprobarIntervalo(izda, dcha, num_datos)){
        cout << "Menor: ";
        cin >> izda;
        cout << "Mayor: ";
        cin >> dcha;
 
    }



    // Llamo a la función PosMayor pasándole el vector y los extremos
    // para que calcule el mayor de ese intervalo.
    int* casilla_mayor= PosMayor(vector, izda, dcha);


    // Imprimo el mayor

cout << "El número mayor del intervalo es: " << *casilla_mayor;
}
