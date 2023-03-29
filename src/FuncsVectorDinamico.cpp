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

#include "FuncsVectorDinamico.h"

using namespace std; 


/***************************************************************************/
/***************************************************************************/
// Crear vector dinámico
// Argumentos: cap_inic, número de casillas con las que se crea el vector.
// Devuelve: el vector dinámico creado.
// POST: El número de casillas usadas es 0
//       El número de casillas reservadas es "capacidad_inicial"

VectorDinamico CreaVectorDinamico (int cap_inic, TipoRedimension tipo)    // USADO
{
	VectorDinamico nuevo;

	// Pedir memoria para el nuevo almacen 
	nuevo.datos = new TipoBase[cap_inic]; 

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
	if (v.datos)
		delete [] v.datos;

	// Modificar las propiedades de "v" para que quede "vacío"
	v.datos = 0; // Puntero "nulo"
	
	v.usados = 0;
	v.capacidad = 0;
}



/***************************************************************************/
/***************************************************************************/
// Calcula el número de casillas usadas de un vector dinámico.
// Argumentos: v, el vector que se va a consultar.
// Devuelve: el número de casillas usadas de un vector dinámico

int  UsadosVectorDinamico (const VectorDinamico & v) 
{
	return (v.usados);
}	




/***************************************************************************/   // USADO
/***************************************************************************/
// Calcula el n�mero de casillas reservadas de un vector din�mico.
// Argumentos: v, el vector que se va a consultar.
// Devuelve: el n�mero de casillas reservadas de un vector din�mico

 int CapacidadVectorDinamico (const VectorDinamico & v) 
{
	return (v.capacidad);
}	



/***************************************************************************/  // USADO
/***************************************************************************/
// Comprueba si el vector está vacío
// Argumentos: v (referencia) El vector que se va a comprobar

bool EstaVacioVectorDinamico (const VectorDinamico & v) 
{
	bool vacio = false;

	if (v.usados == 0)
		vacio = true;

	return(vacio);
}


/***************************************************************************/ // USADO
/***************************************************************************/
// Deja el vector dinámico vacío
// Argumentos: v (referencia) El vector que se va "vaciar"
// POST: El número de casillas usadas es 0

void EliminaTodosVectorDinamico (VectorDinamico & v) 
{
	v.usados = 0;
}




/*****************************************************************************/ // USADO
/*****************************************************************************/
// Inicializa el vector dinámico, sustituyendo el contenido de todas
// las casillas usadas por el valor "valor".
// PRE: El vector debe existir y estar vacío

void EcualizaVectorDinamico (VectorDinamico & v, const TipoBase valor)
{
	

	for (int i=0; i<v.capacidad; i++){

		AniadeVectorDinamico(v,valor);

	}

	
}




/***************************************************************************/ // USADO
/***************************************************************************/
// Consulta y modifica el valor de una casilla dada. Si se utiliza como 
// rvalue se emplea para consultar el valor de la casilla "num_casilla". 
// Si se utiliza como lvalue se emplea para modificar el valor de la 
// casilla num_"casilla".
// 
// Argumentos: 	
//		v (referencia), referencia al vector. 
//		num_casilla, número de casilla (índice) en la que estamos interesados.
//
// PRE: 0<=num_casilla<UsadosVectorDinamico(v)

TipoBase & ValorVectorDinamico (const VectorDinamico & v, int num_casilla) 
{
	return (v.datos[num_casilla]);
}	



/***************************************************************************/ // USADO
/***************************************************************************/
// Hace una copia profunda de origen en destino
// Si no tiene capacidad suficiente, destruye el vector y vuelve 
// a pedir memoria nueva adaptada al tamaño de origen

void ClonaVectorDinamico (VectorDinamico & destino, \
						  const VectorDinamico & origen)
{
	DestruyeVectorDinamico(destino);
	destino = CreaVectorDinamico(origen.capacidad, origen.tipo_redim);

	for (int i=0; i<origen.usados; i++)
		AniadeVectorDinamico(destino, *(origen.datos+i));

}



/***************************************************************************/
/***************************************************************************/
// Serializa un dato de tipo "VectorDinamico"
// Argumentos: v (referencia), el vector que se va a serializar.

string ToString (const VectorDinamico & v)
{
	string cad; 
	cad = cad + "Capacidad = " + to_string(v.capacidad); 
	cad = cad + "  Ocupadas  = " + to_string(v.usados) + "\n";

	if (v.usados > 0)  {

		cad = cad + "Valores almacenados en el vector: \n"; 

		cad = cad + "[ ";

		for (int i=0; i<v.usados-1; i++) 
			cad = cad + to_string(ValorVectorDinamico (v, i)) + ", "; 

		cad = cad + to_string(ValorVectorDinamico (v, v.usados-1)); 
		cad = cad + " ]";
	}
	else 
		cad = cad + "Vector vacio";

	cad = cad + "\n\n";

	return (cad);
}

/***************************************************************************/
/***************************************************************************/
// Añade un valor al vector dinámico
// Argumentos: 	
//		v (referencia), referencia al vector que se va a modificar. 
//		valor, valor que se va a añadir al vector. 
// NOTA: Si no hay espacio libre, la función pide espacio adicional usando 
//		 la función RedimensionaVectorDinamico. 

void AniadeVectorDinamico (VectorDinamico &v, const TipoBase valor)
{
	// Si no cabe --> redimensionar

	if (v.usados == v.capacidad) {

		// Redimensionar 
		RedimensionaVectorDinamico (v);
	}

	// Se haya redimensionado o no, en este punto hay sitio para la inserción

	v.datos[v.usados] = valor;
	v.usados++;
}




/***************************************************************************/
/***************************************************************************/
// Inserta un valor en la casilla del vector dinámico dada
// Argumentos: 	
//		v (referencia), referencia al vector que se va a modificar. 
//		valor, valor que se va a añadir al vector. 
//		num_casilla, casilla donde se va a añadir el valor
// NOTA: Si no hay espacio libre, la función pide espacio adicional usando 
//		 la función RedimensionaVectorDinamico. 
// PRE: 0<=num_casilla<UsadosVectorDInamico(v)

void InsertaVectorDinamico (VectorDinamico &v, const TipoBase valor,
						   const int num_casilla)
{

	// Si no cabe --> redimensionar

	if (v.usados == v.capacidad) {

		// Redimensionar 
		RedimensionaVectorDinamico (v);
	}

	// Se haya redimensionado o no, en este punto hay sitio para la inserción


	memmove(v.datos+num_casilla+1, v.datos+num_casilla, \
		   (v.usados-num_casilla)*sizeof(TipoBase));

	ValorVectorDinamico(v, num_casilla) = valor;

	v.usados++;
	
	

}



/***************************************************************************/
/***************************************************************************/
// ELimina un valor de la casilla del vector dinámico dada
// Argumentos: 	
//		v (referencia), referencia al vector que se va a modificar. 
//		num_casilla, casilla donde se va a eliminarse el valor 

void EliminaVectorDinamico (VectorDinamico &v, const int num_casilla)
{


	TipoBase * ptr_indice = v.datos+num_casilla;

    memmove(ptr_indice, ptr_indice+1,(v.usados-num_casilla-1)*sizeof(TipoBase));

	v.usados--;

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
	TipoBase * tmp = new TipoBase[nueva_capacidad]; 

	// Copiar los datos 
	for (int i=0; i<v.usados; i++) 
	tmp[i] = v.datos[i]; 
		
	// Considerar esta copia eficiente:
	//memcpy (tmp, v.datos, v.usados*sizeof(TipoBase)); 
	
	// Liberar la memoria del antiguo almac�n
	delete [] v.datos; 

	// Actualizar vector din�mico redimensionado

	v.datos = tmp;
	v.capacidad = nueva_capacidad;
	// v.usados se mantiene como estaba
}

/***************************************************************************/
/***************************************************************************/
// Redimensiona un vector dinámico para que no haya espacio libre.
// Copia todos los datos en el nuevo vector.
// Argumentos: 	
//		v (referencia), referencia al vector que se va a reajustar. 
// POST: capacidad = usados

void  ReajustaVectorDinamico (VectorDinamico & v)
{
	int nueva_capacidad = v.usados;

	cout << endl;
	cout << "REAJUSTANDO HASTA --> "<<nueva_capacidad << " CASILLAS"<< endl;
	cout << endl;

	// Pedir memoria para el nuevo almacen 
	TipoBase* tmp = new int[nueva_capacidad]; 

	// Copiar los datos 
	for (int i=0; i<v.usados; i++) 
		tmp[i] = v.datos[i]; 
		
	// Considerar esta copia eficiente:
	// memcpy (tmp, v.datos, v.usados*sizeof(TipoBase)); 
	
	// Liberar la memoria del antiguo almac�n
	delete [] v.datos; 

	// Actualizar vector din�mico redimensionado

	v.datos = tmp;
	v.capacidad = nueva_capacidad;
	// v.usados se mantiene como estaba
}

/***************************************************************************/
/***************************************************************************/