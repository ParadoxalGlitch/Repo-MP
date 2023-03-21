//*****************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: SecuenciaEnteros.cpp
//
// Contiene la definición de la clase Secuencia Enteros
//
/*****************************************************************************/


#include <iostream>
#include <string>
#include <cstring>
#include "GeneradorAleatorioEnteros.h
#include "SecuenciaEnteros.h"
using namespace std;


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
    /***********************************************************************/
    // Constructor sin argumentos

    SecuenciaEnteros :: SecuenciaEnteros (void) : total_utilizados (0)
    {}

    /***********************************************************************/
    // Constructor con argumentos:
    // Construye una secuencia mediante un array dado
    // Pre: 0 <= n_datos <= TAMANIO
    // PRE: A partir de "p" hay "n_datos" valores

    SecuenciaEnteros :: SecuenciaEnteros (int *p, in n_datos) : \
                                          total_utilizados(0)
    {
        for (int i=0; i<n_datos; i++){

            Aniade(*(p+1));
            total_utilizados++;

        }
    }

    /*******************************************************/
    // Construye una secuencia con "n_datos" valores iguales
    // PRE: 0 <= n_datos <= TAMANIO

    SecuenciaEnteros :: SecuenciaEnteros (int n_datos, int valor) : \
                                          total_utilizados(0)
    {

        for (int i=0; i<n_datos; i++){

            Aniade(valor);
            total_utilizados++;

        }

    }



    /*******************************************************/
    // Construye una secuencia con "n_datos" valores aleatorios
    // PRE: 0 <= n_datos <= TAMANIO

    SecuenciaEnteros :: SecuenciaEnteros (int n_datos, int min_aleat, \
                                          int max_aleat) : total_utilizados(0)
    {

        GeneradorAleatorioEnteros generador (min_aleat, max_aleat);

        for (int i=0; i < n_datos; i++){

            Aniade(generador.Siguiente);
            total_utilizados++;

        }

    }

    /***********************************************************************/
    // Devuelve el número de casillas ocupadas

    int SecuenciaEnteros :: TotalUtilizados (void)
    {
        return (total_utilizados);
    }

    /***********************************************************************/
    // Devuelve el número de casillas disponibles

    int SecuenciaEnteros :: Capacidad (void)
    {
        return (TAMANIO);
    }

    /***********************************************************************/
    // Añade un elemento ("nuevo") al vector.
    // PRE: total_utilizados < TAMANIO
    // 		La adición se realiza si hay alguna casilla disponible.
    // 		El nuevo elemento se coloca al final del vector.
    // 		Si no hay espacio, no se hace nada.

    void SecuenciaEnteros :: Aniade (int nuevo)
    {
        if (total_utilizados < TAMANIO){
            vector_privado[total_utilizados] = nuevo;
            total_utilizados++;
        }
    }

    /***********************************************************************/
    // Devuelve el elemento de la casilla "indice"
    // PRE: 0 <= indice < total_utilizados

    int  SecuenciaEnteros :: Elemento (int indice)
    {
        return (vector_privado[indice]);
    }

    /***********************************************************************/
    // Eliminar el carácter de la posición dada por "indice".
    // Realiza un borrado físico (desplazamiento y sustitución).
    // PRE: 0 <= indice < total_utilizados

    void SecuenciaEnteros :: Elimina (int indice)
    {

        int * ptr_indice = &(Elemento[indice]);

        if ((indice >= 0) && (indice < total_utilizados)){

            memmove(ptr_indice, ptr_indice+1, (total_utilizados-indice-1)*\
                   sizeof(int));

            total_utilizados--;
        }
    }

    /***********************************************************************/
    // Inserta el carácter c en la posición dada por "indice".
    // Realiza un borrado físico (desplazamiento y sustitución).
    // PRE: 0 <= indice < total_utilizados

    void SecuenciaEnteros :: Inserta (int indice, int num)
    {
        int * ptr_indice = &(Elemento[indice]);

        if ((indice >= 0) && (indice < total_utilizados)){

            total_utilizados++;
            memmove(ptr_indice + 1, ptr_indice, (total_utilizados-indice+1)*\
                   sizeof(int));

            *(ptr_indice) = num;

        }

    }

    /*******************************************************/
    // Devuelve una ref. al elemento de la casilla "indice"
    // PRE: 0 <= indice < total_utilizados
    int& SecuenciaEnteros :: Valor (int indice)
    {
        if ((indice >= 0) && (indice < total_utilizados))
        {
            return (vector_privado[indice]);
        }
    }


    /*******************************************************/
    // Devuelve true si la secuencia implícita es igual a "otra"
    // ATENCIÓN: La función debería ser de tipo const, no obstante
    // llama a la función VALOR, que no lo es, por lo que no puedo.
    bool SecuenciaEnteros :: EsIgualA (const SecuenciaEnteros & otra)
    {
    
        bool Iguales = true;
        int i=0;

        if (TotalUtilizados() != otra.TotalUtilizados())
            bool Iguales = false;
        
        else{
            while (i < TotalUtilizados && Iguales){

                if (Valor(i) != otra.Valor(i))
                    Iguales = false;
                
                else
                    i++;
            }

        return (Iguales);

    }


 
    /***********************************************************************/
    // Compone un string con todos los valores que están
    // almacenados en la secuencia y lo devuelve.

    string ToString()
    {
        string cadena = "{";

		if (total_utilizados > 0) {

	        for (int i=0; i<total_utilizados-1; i++)

	        	cadena = cadena + to_string(vector_privado[i])+", ";

			// Añadie el último seguido de '}'
	        cadena = cadena + to_string(vector_privado[total_utilizados-1]);
		}

        cadena = cadena + "}";

        return (cadena);
    }

	/***********************************************************************/
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/
/***************************************************************************/

int main (void)
{

    const int MIN_VALOR =  1;
    const int MAX_VALOR = 10;

    SecuenciaEnteros sec; 

    // Rellenar secuencia

    for (int valor=MIN_VALOR; valor<=MAX_VALOR; valor++)
        sec.Aniade (valor);

    // Mostrar secuencia


    cout << endl; 
    cout << sec.ToString () << endl;
    cout << "Num. valores en la secuencia = " << sec.TotalUtilizados() << endl;     
    cout << endl; 

    return 0;
}

/***************************************************************************/
/***************************************************************************/