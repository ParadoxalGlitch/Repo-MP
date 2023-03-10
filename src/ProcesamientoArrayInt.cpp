/*****************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: ProcesamientoArrayInt.cpp
//
// Contiene la definición de las funciones usadas en
//          I_PosMayor_Basico.cpp (por ahora)
//
/*****************************************************************************/

#include "ProcesamientoArrayInt.h"
#include <iostream>
using namespace std;


/*****************************************************************************/
// Constructor sin argumentos: Inicializa el generador
// para proporcionar números aleatorios entre 0 y 1
GeneradorAleatorioEnteros :: GeneradorAleatorioEnteros()
 : GeneradorAleatorioEnteros(0, 1) { }

 /****************************************************************************/
 // Constructor con argumentos: Inicializa el generador
// para proporcionar números aleatorios entre "min" y "max"
GeneradorAleatorioEnteros ::
	GeneradorAleatorioEnteros(int min, int max) 
{
	
	const int A_DESCARTAR = 70000;
	// ACM TOMS Volume 32 Issue 1, March 2006
    		
	auto semilla = Nanosec();
	generador_mersenne.seed(semilla);
	generador_mersenne.discard(A_DESCARTAR);
	distribucion_uniforme = uniform_int_distribution<int> (min, max);

}
/*****************************************************************************/
// Devuelve un nuevo número aleatorio

int GeneradorAleatorioEnteros :: Siguiente()
{
	return (distribucion_uniforme(generador_mersenne));
}
/*****************************************************************************/

/*****************************************************************************/
// MÉTODOS PRIVADOS
/*****************************************************************************/

long long GeneradorAleatorioEnteros :: Nanosec()
{
	return (chrono::high_resolution_clock::now().time_since_epoch().count());
}
/*****************************************************************************/







/*****************************************************************************/
// Busca el valor más alto en un array de enteros dado un intervalo.
// Parámetros:  *pv, puntero que apunta a una casilla del vector a procesar.
//              izda, extremo inferior del intervalo a procesar.
//              dcha, extremo superior del intervalo a procesar.
//

int * PosMayor (int *pv, int izda, int dcha)
{

    int* ptr = pv + izda;
    int* ultimo = pv + dcha;
    int* resultado = nullptr;
    int mayor = 0;

    while ( ptr<=ultimo ) {
        if ((*ptr) > mayor) {
            mayor = *ptr;
            resultado = ptr;
        }

        ptr++;

    }

    return (resultado);


}




/*****************************************************************************/


/*****************************************************************************/
// Ordena un vector mediante el sistema de selección. En cada iteración,
// se busca el componente más pequeño del sub-vector derecho y se coloca
// en el sub-vector izquierdo
// Parámetros: int *v, puntero que apunta a una casilla del vector a procesar.
//			   pos_inic, extremo izquierdo del intervalo a procesar.
//			   pos_fin, extremo derecho del intervalo a procesar.
//

void OrdenaSeleccion (int *v, int pos_inic, int pos_fin)
{

    int pos_min;
    int min;
    int intercambia;

    for (int izda = pos_inic ; izda <= pos_fin; izda++){
        min = *(v+izda);
        pos_min = izda;
        for (int i = izda + 1; i <= pos_fin; i++){
            if (*(v+i) < min){
                min = *(v+i);
                pos_min = i;
            }
        }
        intercambia = *(v+izda);
        *(v+izda) = min;
        *(v+pos_min) = intercambia;
    }
}


/*****************************************************************************/


/*****************************************************************************/
// Ordena un vector mediante el sistema de inserción. Se divide el vector
// en dos sub-vectores, el ordenado (izquierda) y el desordenado (derecha).
// Se busca el primer elemento del sector desordenado y se coloca de
// forma ordenada en el sector ordenado
// Parámetros: int *v, puntero que apunta a una casilla del vector a procesar.
//			   pos_inic, extremo izquierdo del intervalo a procesar.
//			   pos_fin, extremo derecho del intervalo a procesar.
//

void OrdenaInsercion (int *v, int pos_inic, int pos_fin){

    int a_desplazar;
    int i;

    for (int izda = pos_inic; izda < pos_fin; izda++){
        a_desplazar = *(v+izda);

        for (i = izda; i > pos_inic && a_desplazar < *(v+i-1); i--)
            *(v+i) = *(v+i-1);

        *(v+i) = a_desplazar;
    }
}

/*****************************************************************************/

/*****************************************************************************/
// Ordena un vector mediante el sistema de intercambio directo. Se divide
// el vector en dos sectores, el izquierdo ordenado y el derecho desordenado.
// En el vector derecho se van comparando desde el final 2 a 2 y se va
// moviendo el mas pequeño, y así en repetidas iteraciones.
// Parámetros: int *v, puntero que apunta a una casilla del vector a procesar.
//			   pos_inic, extremo izquierdo del intervalo a procesar.
//			   pos_fin, extremo derecho del intervalo a procesar.
//

void OrdenaIntercambio (int *v, int pos_inic, int pos_fin){


    int intercambia = 0;

    for (int izda = pos_inic; izda < pos_fin; izda++){
        for (int i = pos_fin-1 ; i > izda ; i--){
            if (*(v+i) < *(v+i-1)){
                intercambia = *(v+i);
                *(v+i) = *(v+i-1);
                *(v+i-1) = intercambia;
            }
        }
    }
}

/*****************************************************************************/

/*****************************************************************************/
// Rellena el vector usando la función GenerarAleatoriosEnteros, según los
// parámetros indicados por el usuario. 
// Parámetros: int *p, puntero que apunta a una casilla del vector a rellenar.
//             num_datos, cantidad de casillas a rellenar.
//             min_aleat, el número mas pequeño entre los que se elegirá
//                        para generar el contenido del vector.
//             max_aleat, el número mas grande entre los que se elegirá
//                        para generar el contenido del vector.
//

void RellenaVector (int *p, int num_datos, int min_aleat, int max_aleat){

    GeneradorAleatorioEnteros aleatorio(min_aleat, max_aleat);

    for (int i=0; i<num_datos; i++){
        *(p+i) = aleatorio.Siguiente();
    }
}

/*****************************************************************************/

/*****************************************************************************/
// Comprueba si los datos proporcionados para rellenar el vector son correctos
// Parámetros: num_datos, cantidad de casillas que se quieren rellenar.
//             tope, capacidad máxima del vector.
//

bool ComprobarNumDatos (int num_datos, int tope){

    bool Correcto = true;

    if (num_datos < 2){
        Correcto = false;
        cout << "El vector debe tener almenos dos casillas" << endl;
    }
    if (num_datos > tope){
        Correcto = false;
        cout << "El vector no puede tener mas de " << tope << " casillas\n";
    }

    if (!Correcto)
        cout << "Por favor, inténtelo de nuevo" << endl;
    
    return Correcto;


}

/*****************************************************************************/

/*****************************************************************************/
// Comprueba si los datos proporcionados sobre el intervalo son correctos.
// Parámetros: izda, extremo inferior del intervalo.
//             dcha, extremo superior del intervalo.
//             num_Datos, cantidad de casillas que posee el vector.
//

bool ComprobarIntervalo (int izda, int dcha, int num_datos){
    bool Correcto = true;

    if (izda < 0){
        Correcto = false;
        cout << "El extremo inferior debe ser igual o superior a 0" << endl;
    }
    if (dcha > num_datos-1){
        Correcto = false;
        cout << "El extremo superior debe ser inferior o igual a ";
        cout << num_datos-1 << endl;
    }
    if (izda > dcha){
        Correcto = false;
        cout << "El extremo inferior no debe ser superior al extremo superior";
        cout << endl;
    }
    
    if (!Correcto)
        cout << "Por favor, inténtalo de nuevo" << endl;

    return Correcto;


}

/*****************************************************************************/

/*****************************************************************************/
// Comprueba si ha sido elegida de forma correcta una forma de ordenación del
// intervalo.
// Parametros: opcion, opcion elegida en relación a las distintas formas
//                     de ordenar el intervalo
//

bool ComprobarOpcion (int opcion){
    bool Correcto = true;

    if (opcion < 1 || opcion > 3){
        Correcto = false;
        cout << "No ha introducido una opción correcta." << endl;
        cout << "Por favor, inténtelo de nuevo";
    }

    return Correcto;
}

/*****************************************************************************/

/*****************************************************************************/
// Recibe 3 vectores, 2 los cuales entremezclará y guardará en el tercero,
// sobreescribiendo principalmente lo que haya en este. La idea es que el
// tercer vector venga vacío y preparado con el tamaño exacto necesario.
// El algoritmo irá introduciendo cada vez 1 elemento de 1 vector y 1 de
// otor, intercalándolos.
// Parametros: int *v1, vector 1 a mezclar
//             int *v2, vector 2 a mezclar
//             int *res, vector donde se mezclan
//             int tam_v1, tamaño del vector 1
//             int tam_v2, tamaño del vector 2
//

void MezclarVectores (int *v1, int *v2, int *res, int tam_v1, int tam_v2){


    int i = 0;
    int j = 0;
    int k = 0;

    //intercalo los elementos de ambos vectores hasta que uno acabe

    while (i < tam_v1 || j < tam_v2){
        if (i < tam_v1){
            *(res + k) = *(v1 + i);
            i++;
            k++;
        }
        if (j < tam_v2){
            *(res + k) = *(v2 + j);
            j++;
            k++;
        }
    }

    // compruebo cual vector es el que ha acabado y continuo con el
    // correspondiente. Si han acabado a la vez, no se ejecuta nada.

    if ( i == tam_v1){

        while(j < tam_v2){
            *(res + k) = *(v2 + j);
            k++;
            i++;
        }
    }

    else if (j == tam_v2){
        
        while(i < tam_v1){
            *(res + k) = *(v1 + i);
            i++;
            k++;
        }
    }
    

}

/*****************************************************************************/

/*****************************************************************************/
// Muestra un vector en pantalla
//Parametros: int *p, vector a mostrar.
//            int n_datos, tamaño del vector
//

void MuestraVector (int *p, int n_datos){

    for (int i=0; i < n_datos; i++)
        cout << "[" << *(p+i) << "]";

}

