/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: FuncsVectorDinamico.cpp
//
// Contiene la definición de las funciones de VectorDinamico
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstdlib>

#include "FuncsVectorDinamicoCadenas.h"

using namespace std; 


/***************************************************************************/
/***************************************************************************/
// Crear vector dinámico
// Argumentos: cap_inic, número de casillas con las que se crea el vector.
// Devuelve: el vector dinámico creado.
// POST: El número de casillas usadas es 0
//       El número de casillas reservadas es "capacidad_inicial"

VectorDinamico CreaVectorDinamico (int cap_inic, TipoRedimension tipo)
{
	VectorDinamico nuevo;

	// Pedir memoria para el nuevo almacen 
	nuevo.lineas = new char*[cap_inic]; 

	// Iniciar capacidad y ocupación
	nuevo.capacidad = cap_inic;
	nuevo.usados = 0;

	nuevo.tipo_redim = tipo;

	return (nuevo);
}

/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por un vector dinámico
// Argumentos: v (referencia) El vector que se va liberar.
// POST: El número de casillas usadas es 0
//       El número de casillas reservadas es 0

void DestruyeVectorDinamico (VectorDinamico & v) 
{
	if (v.lineas)
		delete [] v.lineas;

	// Modificar las propiedades de "v" para que quede "vacío"
	v.lineas = 0; // Puntero "nulo"
	
	v.usados = 0;
	v.capacidad = 0;
}





/***************************************************************************/
/***************************************************************************/
// Añade un valor al vector dinámico
// Argumentos: 	
//		v (referencia), referencia al vector que se va a modificar. 
//		valor, valor que se va a añadir al vector. 
// NOTA: Si no hay espacio libre, la función pide espacio adicional usando 
//		 la función RedimensionaVectorDinamico. 

void AniadeVectorDinamico (VectorDinamico &v, const char *cadena)
{
    // Si no cabe --> redimensionar
    if (v.usados == v.capacidad) {
        // Redimensionar 
        RedimensionaVectorDinamico (v);
    }

    // Reservar memoria para la cadena y copiarla
    char *nueva_cadena = new char[strlen(cadena) + 1];
    strcpy(nueva_cadena, cadena);

    // Asignar la cadena al vector dinámico
    v.lineas[v.usados] = nueva_cadena;
    v.usados++;
}



/***************************************************************************/
/***************************************************************************/
// Redimensiona el vector dinámico "v" de acuerdo al tipo de redimensi�n 
// registrado en "v". 
// Además, copia todos los datos en el nuevo vector.  
// Argumentos: 	
//		v (referencia), referencia al vector que se va a redimensionar. 
			
void RedimensionaVectorDinamico (VectorDinamico & v)
{
    int nueva_capacidad = 0;

    if (v.tipo_redim == TipoRedimension::DeUnoEnUno)
        nueva_capacidad = v.capacidad + 1;

    if (v.tipo_redim == TipoRedimension::Duplicando)
        nueva_capacidad = v.capacidad * 2;

    if (v.tipo_redim == TipoRedimension::EnBloques)
        nueva_capacidad = v.capacidad + TAM_BLOQUE;

    cout << endl;
    cout << "REDIMENSIONADO HASTA --> " << nueva_capacidad << " CASILLAS"<< endl;
    cout << endl;

    // Pedir memoria para el nuevo almacen
    char **tmp = new char*[nueva_capacidad];

    // Copiar los datos
    for (int i = 0; i < v.usados; i++) {
        // Pedir memoria para la nueva cadena y copiar el contenido de la cadena antigua
        tmp[i] = new char[strlen(v.lineas[i]) + 1];
        strcpy(tmp[i], v.lineas[i]);
    }

    // Liberar la memoria del antiguo almacén
    for (int i = 0; i < v.usados; i++) {
        delete [] v.lineas[i];
    }
    delete [] v.lineas;

    // Actualizar vector dinámico redimensionado
    v.lineas = tmp;
    v.capacidad = nueva_capacidad;
    // v.usados se mantiene como estaba
}


/***************************************************************************/
/***************************************************************************/
// Calcula el número de líneas totales y vacías, además del número de 
// párrafos en "lineas".
// Argumentos: 	
//		v (referencia),  colección de cadenas donde se consulta.  
//		cl (referencia), número de líneas. 
//		cv (referencia), número de líneas vacías.
//		cp (referencia), número de párrafos.

void CalculosLineasVectorDinamico(const VectorDinamico & v, 
	                                 int & cl, int & cv, int & cp)
{
	// Número de líneas (trivial)

	cl = v.usados;

	char ** cad;	 

	// Número de líneas vacías

	cad = v.lineas; // Nos colocamos al principio

	cv = 0;

	for (int l=0; l<v.usados; l++) {

		int long_cad = strlen(*(cad));

		if (long_cad==0) cv++;

		// Actualizamos "cad" para que apunte a la siguiente cadena.

		cad++;
	}


	// Número de párrafos

	cad = v.lineas; // Nos colocamos al principio
	
	cp = 0;

	bool en_parrafo = false;

	for (int l=0; l<v.usados; l++) {

		int long_cad = strlen(*(cad));

		if (long_cad==0 && en_parrafo) // fin de párrafo
			en_parrafo = false;	
	
		if (long_cad!=0 && !en_parrafo) { // nuevo párrafo
			en_parrafo = true;
			cp++;
		}

		cad++;
	}

}






/***************************************************************************/
/***************************************************************************/
// Mostrar contenido de una linea de la colección del vector dinámico.
// Argumentos: 	
//		v (referencia), vector dinamico de cadenas clasicas
//		linea, linea a leer de la cadena.
// PRE: la linea debe estar entre 0 y v.usados

void ImprimeLineaVectorDinamico(VectorDinamico v, int linea){

	cout << v.lineas[linea];
	cout << endl;


}





/***************************************************************************/
/***************************************************************************/
// Mostrar contenido de todas las lineas del vector dinámico.
// Argumentos: 	
//		v (referencia), vector dinamico de cadenas clasicas

void ImprimeTodoVectorDinamico(VectorDinamico v){

	for (int i=0; i<v.usados; i++)
		ImprimeLineaVectorDinamico(v,i);

}
