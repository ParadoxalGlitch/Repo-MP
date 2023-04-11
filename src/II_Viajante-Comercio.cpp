/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
/***************************************************************************/


#include <iostream>
#include "Matriz2D.h"
#include "FuncsVectorDinamico.h"
#include "TipoBase.h"
using namespace std;



// DECLARAION DE FUNCIONES

/*****************************************************************************/
// Busca en la matriz de precios de viaje entre ciudades el precio más barato
// de viajar desde la ciudad (fila) elegida hasta la ciudad que sea, siempre
// que esta no esté en el vector de ciudad ya visitadas

int BuscaPrecioMinimo(const Matriz2D & precios, int fila, 
                       VectorDinamico & visitadas);



// FUNCION MAIN


int main(){

    int n; // Numero de ciudades
    int origen; // Ciudad de origen
    int precio = 0; // Precio total de viaje entre ciudades



    // Pregunto el número de ciudades y creo la matriz de precios de viaje 
    // entre ciudades, y compruebo que el valor proporcionado es válido
    // (número de ciudades mayor que 1)

    
    do{

        cout << "Introduzca el numero de ciudades (n > 1): ";
        cin >> n;

    }while(n < 2);


    cout << endl << endl;



    // Creo la matriz de precios de viaje entre ciudades y 
    // la relleno con los datos proporcionados por el usuario

    Matriz2D precios = CreaMatriz(n,n);

    cout << "Introduzca los precios de viaje entre ciudades: " << endl;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i != j){

                // compruebo que el precio establecido sea mayor que 0

                do{

                    cout << "Precio de viaje de la ciudad " << i+1;
                    cout << " a la ciudad " << j+1 << ": ";
                    cin >> Valor(precios,i,j);

                }while(Valor(precios,i,j) < 1);
            }

            else
                Valor(precios,i,j) = 0;
        }
    }

    cout << endl << endl;

    

    // Imprimo la matriz de precios de viaje entre ciudades

    cout << "La matriz de precios de viaje entre ciudades es:";
    cout << ToString(precios) << endl;


    // Creo el vector de ciudades visitadas

    VectorDinamico itinerario = CreaVectorDinamico(n);



    // Pregunto la ciudad de origen y la añado al vector de ciudades visitadas
    // Compruebo que el valor proporcionado es válido 
    // (ciudad de origen entre 1 y n)

    do{

        cout << "Introduzca la ciudad de origen (1 <= origen <= " << n << "): ";
        cin >> origen;
    
    }while(origen < 1 || origen > n);

    AniadeVectorDinamico(itinerario, origen-1);



    

    // Busco el precio más barato de viajar desde la ciudad de origen hasta
    // cualquier otra ciudad que no esté en el vector de ciudades visitadas

    // A su vez, voy sumando los costes de viaje para obtener el precio total

    for (int i=0; i < n-1; i++){

        
        precio += BuscaPrecioMinimo(precios, \
                  ValorVectorDinamico(itinerario, i), itinerario);

        
        
    }




    // Por ultimo, necesito el precio de ir de la ultima ciudad a la primera
   
    precio += Valor(precios, ValorVectorDinamico(itinerario, n-1), \
                    ValorVectorDinamico(itinerario, 0));






    // Modifico el itinerario para que las ciudades empiecen desde el 1
    // y no desde el 0 y así sea mas legible por el usuario

    for (int i = 0; i < CapacidadVectorDinamico(itinerario); i++){
        ValorVectorDinamico(itinerario,i) += 1;
    }




    // Imprimo el itinerario y el precio total del viaje
    // No uso ToString para evitar que se muestren los 
    // mensajes de datos del vector

    cout << endl << endl;
    cout << "El itinerario es: (";

    for (int i = 0; i < UsadosVectorDinamico(itinerario); i++){

        cout << "Ciudad " << ValorVectorDinamico(itinerario,i) << " --> ";

    }

    cout << "Ciudad " << ValorVectorDinamico(itinerario,0) << ")" << endl;


    cout << "El precio total del viaje es: " << precio << endl;

    // Destruyo la matriz de precios de viaje entre ciudades y el vector de
    // ciudades visitadas

    DestruyeVectorDinamico(itinerario);
    DestruyeMatriz(precios);

}


// FUNCIONES


/*****************************************************************************/
// Busca en la matriz de precios de viaje entre ciudades el precio más barato
// de viajar desde la ciudad (fila) elegida hasta la ciudad que sea, siempre
// que esta no esté en el vector de ciudad ya visitadas

int BuscaPrecioMinimo(const Matriz2D & precios, int fila, 
                       VectorDinamico & visitadas){

    int precio_minimo = 0;
    int ciudad_minima = 0;
    bool YaVisitada = false;
    int j = 0;

    for (int i = 0; i < NumColumnas(precios); i++){

        // Compruebo si la ciudad i está en el vector de ciudades visitadas

        YaVisitada = false;
        j = 0;

        while(!YaVisitada && j < UsadosVectorDinamico(visitadas)){
            if (i == ValorVectorDinamico(visitadas,j))
                YaVisitada = true;
            else
                j++;
        }

        if (i != fila && !YaVisitada){
            if (precio_minimo == 0 || Valor(precios,fila,i) < precio_minimo){

                precio_minimo = Valor(precios,fila,i);
                ciudad_minima = i;
            }
        }

    }

    AniadeVectorDinamico(visitadas, (ciudad_minima));


    return(precio_minimo);
}
