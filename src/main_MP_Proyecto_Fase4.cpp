/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
// 
// Fichero: main_MP_Proyecto_Fase3.cpp
//
// Función main del proyecto. 
//
// Proyecto. FASE 03. 
//
/***************************************************************************/
/***************************************************************************/

#define DEBUG_DEPARTAMENTOS
#define DEBUG_PROFESORES
#define DEBUG_ADSCRIPCIONES

/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

#include "Fecha.h"
#include "Departamento.h"
#include "Profesor.h"
#include "Encargo.h"
#include "Adscripcion.h"

#include "VectorDepartamento.h"
#include "VectorProfesor.h"
#include "VectorEncargo.h"
#include "VectorAdscripcion.h"

#include "utils.h"

using namespace std;


/***************************************************************************/
/***************************************************************************/

string Cabecera (const char * titulo);

/***************************************************************************/
/***************************************************************************/

int main()
{
    cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales

	int cont_departamentos = 0;
	int cont_profesores = 0;
	int cont_encargos = 0;
	int cont_adscripciones = 0;

    VectorDepartamento v_departamentos;
    VectorProfesor v_profesores;
    VectorEncargo v_encargos;
    VectorAdscripcion v_adscripciones;


	// Terminador para los datos leidos/escritos 
	const string TERMINADOR = "FIN";

	// Cada linea del fichero se lee en un dato string. 
	string linea;


	//......................................................................
	// DEPARTAMENTOS

	cout << Cabecera ("DEPARTAMENTOS:");

	getline(cin, linea); // Lectura adelantada

	// guardo un objeto de la clase para usarlo mas adelante
	Departamento departamento_aux (linea);

	while (linea != TERMINADOR) {
		
		cont_departamentos++; // Un departamento más (no se leyó TERMINADOR)	
			

		Departamento un_departamento (linea);
        
        v_departamentos.aniade(un_departamento);

		cout << "Leido: " << un_departamento.ToString() << endl; 

		// Leer la siguiente linea 
		getline(cin, linea); 
		
	} // while (linea != TERMINADOR)
	

	cout << "Total Departamentos = "<< setw(3) << cont_departamentos << endl; 
	cout << endl; 


	//......................................................................
	// PROFESORES

	
	cout << Cabecera ("PROFESORES:");

	getline(cin, linea); // Lectura adelantada

	// guardo un objeto de la clase para usarlo mas adelante
	Profesor profesor_aux (linea);

	while (linea != TERMINADOR) {
		
		cont_profesores++; // Un profesor más (no se leyó TERMINADOR)	
			

		Profesor un_profesor (linea);

        v_profesores.aniade(un_profesor);

		cout << "Leido: " << un_profesor.ToString() << endl; 

		// Leer la siguiente linea 
		getline(cin, linea); 
		
	} // while (linea != TERMINADOR)
	

	cout << "Total Profesores = "<< setw(3) << cont_profesores << endl; 
	cout << endl; 

	//......................................................................
	// CATEGORIAS
	 

	cout << Cabecera ("ENCARGOS:");

	getline(cin, linea); // Lectura adelantada

	while (linea != TERMINADOR) {
		
		cont_encargos++; // Un encargo más (no se leyó TERMINADOR)	
			

		Encargo un_encargo (linea);

        v_encargos.aniade(un_encargo);

		cout << "Leido: " << un_encargo.ToString() << endl; 


		// Leer la siguiente linea 
		getline(cin, linea); 
		
	} // while (linea != TERMINADOR)
	

	cout << "Total Encargos = "<< setw(3) << cont_encargos << endl; 
	cout << endl; 
	


	//......................................................................
	// ADSCRIPCIONES
	  

	cout << Cabecera ("ADSCRIPCION DE PROFESORES A DEPARTAMENTOS:");

	getline(cin, linea); // Lectura adelantada

	while (linea != TERMINADOR) {
		
		cont_adscripciones++; // Una adscripción más (no se leyó TERMINADOR)	


		Adscripcion una_adscripcion (linea);

        v_adscripciones.aniade(una_adscripcion);

		cout << "Leido: " << una_adscripcion.ToString() << endl; 

		// Leer la siguiente linea 
		getline(cin, linea); 
		
	} // while (linea != TERMINADOR)
	

	cout << "Total Adscripciones = "<< setw(3) << cont_adscripciones << endl; 
	cout << endl; 


    // Output de los vectores de las clases

    cout << Cabecera ("DEPARTAMENTOS:");
    cout << v_departamentos.toString() << endl;

    cout << Cabecera ("PROFESORES:");
    cout << v_profesores.toString() << endl;

    cout << Cabecera ("ENCARGOS:");
    cout << v_encargos.toString() << endl;

    cout << Cabecera ("ADSCRIPCIONES:");
    cout << v_adscripciones.toString() << endl;






	// pruebas sueltas de funciones extra


	//acceder a un dato de un vector

	cout << "acceder a un dato de un vector" << endl;
	cout << v_departamentos[1].ToString() << endl;

	//editar un dato de un vector

	cout << "editar un dato de un vector" << endl;
	v_departamentos[2] = departamento_aux;

	cout << v_departamentos.toString() << endl;

	//insertar un dato en un vector
	v_profesores.inserta(profesor_aux, 3);
	cout << v_profesores.toString() << endl;

	//borrar un dato de un vector
	v_profesores.elimina(1);

	//ajustar el tamaño de un vector

	v_profesores.ajusta();
	cout << v_profesores.toString() << endl;





	// PRUEBAS OPERADORES FASE 5

	cout << "/***********PRUEBAS OPERADORES FASE 5***********/" << endl;

	// prueba operador binario +

	VectorDepartamento v_dep2;
	v_dep2.aniade(v_departamentos[1]);

	cout << v_departamentos.toString() << endl;
	cout << v_dep2.toString() << endl;

	v_departamentos = v_departamentos + v_dep2;

	cout << "v_departamentos deberia mantenerse igual: " << endl;
	cout << "v_departamentos = v_departamentos + v_dep2: "<< endl;
	cout << v_departamentos.toString() << endl;

	Departamento dep_aux;
	dep_aux.setId("ABCD");
	dep_aux.setNombre("Departamento Estandar");

	v_dep2.aniade(dep_aux);

	cout << "añadido departamento distinto a v_dep2";
	cout << v_dep2.toString() << endl;

	VectorDepartamento v_dep3;
	v_dep3 = v_departamentos + v_dep2;

	cout << "v_dep3 = v_departamentos + v_dep2: "<< endl;
	cout << v_departamentos.toString() << endl;



















	return 0;
}

/***************************************************************************/
/***************************************************************************/

string Cabecera (const char * titulo)
{
	const int TAM_GUIONES = 70; 
	char guiones[TAM_GUIONES]; 

	memset (guiones, '-', TAM_GUIONES-1); 
	guiones[TAM_GUIONES-1] = '\0'; 

	string cad_guiones (guiones); 

	string cad;

	cad = cad + cad_guiones + "\n";
	cad = cad + titulo + "\n";
	cad = cad + cad_guiones + "\n";

	return cad; 
}



/***************************************************************************/
/***************************************************************************/
