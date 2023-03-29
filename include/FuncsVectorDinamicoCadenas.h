/*****************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: FuncsVectorDinamico.h
//
// Contiene la declaración de la funciones de VectorDinamicoCadenas
//
/*****************************************************************************/

#ifndef FUNCS_VECT_DIN_CAD
#define FUNCS_VECT_DIN_CAD

using namespace std;

// Capacidad inicial
const int TAM_INICIAL = 10;
// Tamanio del bloque para redimensionar (modalidad EnBloques)
const int TAM_BLOQUE = 5;


enum class TipoRedimension {DeUnoEnUno,EnBloques,Duplicando};



typedef struct {
	char ** lineas; // Puntero para acceder a los datos
	int usados; // Num. casillas usadas
	int capacidad; // Num. casillas reservadas

	// PRE: 0 <= usados <= capacidad
	// Inicialmente, capacidad = TAM_INICIAL

	TipoRedimension tipo_redim; // Modelo de crecimiento

} VectorDinamico;




/***************************************************************************/
/***************************************************************************/
// Crear vector dinámico
// Argumentos: cap_inic, número de casillas con las que se crea el vector.
// Devuelve: el vector dinámico creado.
// POST: El número de casillas usadas es 0
//       El número de casillas reservadas es "capacidad_inicial"

VectorDinamico CreaVectorDinamico (int cap_inic, TipoRedimension tipo);



/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por un vector dinámico
// Argumentos: v (referencia) El vector que se va liberar.
// POST: El número de casillas usadas es 0
//       El número de casillas reservadas es 0

void DestruyeVectorDinamico (VectorDinamico & v);



/***************************************************************************/
/***************************************************************************/
// Añade un valor al vector dinámico
// Argumentos: 	
//		v (referencia), referencia al vector que se va a modificar. 
//		valor, valor que se va a añadir al vector. 
// NOTA: Si no hay espacio libre, la función pide espacio adicional usando 
//		 la función RedimensionaVectorDinamico. 

void AniadeVectorDinamico (VectorDinamico &v, const char *cadena);



/***************************************************************************/
/***************************************************************************/
// Redimensiona el vector dinámico "v" de acuerdo al tipo de redimensi�n 
// registrado en "v". 
// Además, copia todos los datos en el nuevo vector.  
// Argumentos: 	
//		v (referencia), referencia al vector que se va a redimensionar. 
			
void RedimensionaVectorDinamico (VectorDinamico & v);


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
	                                 int & cl, int & cv, int & cp);




/***************************************************************************/
/***************************************************************************/
// Mostrar contenido de una linea de la colección del vector dinámico.
// Argumentos: 	
//		v (referencia), vector dinamico de cadenas clasicas
//		linea, linea a leer de la cadena.
// PRE: la linea debe estar entre 0 y v.usados

void ImprimeLineaVectorDinamico(VectorDinamico v, int linea);



/***************************************************************************/
/***************************************************************************/
// Mostrar contenido de todas las lineas del vector dinámico.
// Argumentos: 	
//		v (referencia), vector dinamico de cadenas clasicas

void ImprimeTodoVectorDinamico(VectorDinamico v);








#endif