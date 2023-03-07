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
    int util_v = 0;
    int max = 0;
    int dcha = 0, izda = 0;

    // Declaro el objeto de la clase GeneradorAleatorioEnteros
    // para posteriormente usarlo para rellenar el vector

    GeneradorAleatorioEnteros aleatorio(0, 100);


    // Relleno el vector con el objeto declarado anteriormente
    // y antes le pregunto al usuario cuantas casillas quiere
    // rellenar del vector

    cout << "Introduce el número de casillas a rellenar: ";
    cin >> max;

    // Compruebo que el numero de casillas es adecuado al
    // programa, es decir, almenos 1 y nunca negativo

    while(max < 1 || max > TOPE){
        cout << "El valor introducido es inválido" << endl;
        cout << "Inténtalo de nuevo: ";
        cin >> max;
    }

    // Una vez comprobado, relleno el vector con
    // números aleatorios

    for (int i=0; i<max; i++){
        vector[i] = aleatorio.Siguiente();
        util_v++;
    }

    // Pregunto al usuario el intervalo donde quiere
    // buscar el máximo, asegurándome de que dicho intervalo
    // sea correcto y adecuado al programa

    cout << "Introduce el extremo inferior del intervalo a procesar" << endl;
    cout << "(Debe ser igual o superior a 0):";
    cin >> izda;

    // Extremo inferior

    while (izda < 0){
        cout << "El valor introducido es inválido." << endl;
        cout << "Inténtalo de nuevo: ";
        cin >> izda;
    }

    cout << "Introduce el extremo superior del intervalo a procesar" << endl;
    cout << "(Debe ser igual o inferior a " << max-1 << " ):";
    cin >> dcha;

    // Extremo superior

    while (dcha > max-1){
        cout << "El valor introducido es inválido." << endl;
        cout << "Inténtalo de nuevo: ";
        cin >> dcha;
    }


    // Llamo a la función PosMayor pasándole el vector y los extremos
    // para que calcule el mayor de ese intervalo.
    int* mayor = PosMayor(vector, izda, dcha);


    // Imprimo el mayor


    cout << "El número mayor del intervalo es: " << *mayor;
}
