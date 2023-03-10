/*****************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: I_OrdenaVector.cpp
//
// Contiene la función main.
//
/*****************************************************************************/

#include <iostream>
#include <ProcesamientoArrayInt.h>
using namespace std;

int main(){

    const int TOPE = 100;
    int vector [TOPE];
    int util_v = 0;
    int num_datos;
    int dcha, izda;
    int menor, mayor;
    int opcion = 0;


    // Le pregunto al usuario con cuantas casillas quiere
    // rellenar del vector

    cout << "Introduce el número de casillas a rellenar: ";
    cin >> num_datos;

    // Compruebo que el numero de casillas es adecuado al
    // programa, es decir, almenos 2 y nunca superior al tope.

    while(!ComprobarNumDatos(num_datos, TOPE)){
        cin >> num_datos;
    }

    // Una vez comprobado, relleno el vector con
    // números aleatorios. El usuario elije entre 
    // qué numeros generar.
    // Puesto que si se elije una combinación
    // incorrecta la propia función ya da aviso de ello,
    // he decidido no comprobarlo yo con otra función.

    cout << "Introduce entre qué numeros generar." << endl;
    cout << "Menor: ";
    cin >> menor;
    cout << "Mayor: ";
    cin >> mayor;

    // Relleno el vector

    RellenaVector(vector, num_datos, menor, mayor);

    // Imprimo el vector generado sin ordenar

    cout << "El vector generado es el siguiente:" << endl;
    MuestraVector(vector, num_datos);
    cout << endl;

    // Pregunto al usuario el intervalo que quiere ordenar,
    // asegurándome de que dicho intervalo sea correcto
    // y adecuado al programa.

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


            

    // Le pregunto al usuario de qué manera quiere
    // que le ordene el intervalo.

    cout << "Introduzca el método de ordenación que quiere usar" << endl;
    cout << "(1 = Seleccion, 2 = Insercion, 3 = Intercambio): ";
    cin >> opcion;

    // Compruebo que la opción es correcta 
    // y muestro según la opción

    while (!ComprobarOpcion(opcion)){
        cin >> opcion;
    }
    if (opcion == 1){
        OrdenaSeleccion(vector, izda, dcha);
        cout << "Vector ordenado por Selección:" << endl;
        MuestraVector(vector, num_datos);
    }

    else if (opcion == 2){
        OrdenaInsercion(vector, izda, dcha);
        cout << "Vector ordenado por Insercción:" << endl;
        MuestraVector(vector, num_datos);
    }
     
    else if (opcion == 3){
        OrdenaIntercambio(vector, izda, dcha);
        cout << "Vector ordenado por Intercambio:" << endl;
        MuestraVector(vector, num_datos);
    }

}









