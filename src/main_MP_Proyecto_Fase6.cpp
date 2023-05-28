/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
// 
// Fichero: main_MP_Proyecto_Fase6.cpp
//
// Función main del proyecto. 
//
// Proyecto. FASE 06. 
//
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


	//................................................................
	// DEPARTAMENTOS

	VectorDepartamento departamentos ("departamentos.txt");

	cout << endl; 
	cout << Cabecera ("DEPARTAMENTOS:");
	cout << endl; 	
	cout << departamentos.toString() << endl;
	cout << endl; 

	departamentos.GuardarVectorDepartamento ("copia_departamentos.txt");

	VectorDepartamento copia_departamentos ("copia_departamentos.txt");

	cout << endl; 
	cout << Cabecera ("COPIA DEPARTAMENTOS:");
	cout << endl; 	
	cout << copia_departamentos.toString() << endl;
	cout << endl; 

	Departamento dep ("ABCD*Nuevo Departamento*");
	departamentos += dep; 

	cout << endl; 
	cout << Cabecera ("DEPARTAMENTOS TRAS ADICION");
	cout << endl; 	
	cout << departamentos.toString() << endl;
	cout << endl; 

	departamentos.RecuperarVectorDepartamento("departamentos.txt");

	cout << endl; 
	cout << Cabecera ("DEPARTAMENTOS ORIGINAL");
	cout << endl; 	
	cout << departamentos.toString() << endl;
	cout << endl; 


	//................................................................
	// PROFESORES

	VectorProfesor profesores ("profesores.txt");

	cout << endl; 
	cout << Cabecera ("PROFESORES:");
	cout << endl; 	
	cout << profesores.toString() << endl;
	cout << endl; 

	profesores.RecuperarVectorProfesor ("copia_profesores.txt");

	VectorProfesor copia_profesores ("copia_profesores.txt");

	cout << endl; 
	cout << Cabecera ("COPIA PROFESORES:");
	cout << endl; 	
	cout << copia_profesores.toString() << endl;
	cout << endl; 

	Profesor prof ("xxxxxxxxx*Nombre*Apellidos*01/01/2000*1*");
	profesores += prof; 

	cout << endl; 
	cout << Cabecera ("PROFESORES TRAS ADICION");
	cout << endl; 	
	cout << profesores.toString() << endl;
	cout << endl; 

	profesores.RecuperarVectorProfesor("profesores.txt");

	cout << endl; 
	cout << Cabecera ("PROFESORES ORIGINAL");
	cout << endl; 	
	cout << profesores.toString() << endl;
	cout << endl; 


	//................................................................
	// ENCARGOS

	VectorEncargo encargos ("encargos.txt");

	cout << endl; 
	cout << Cabecera ("ENCARGOS:");
	cout << endl; 	
	cout << encargos.toString() << endl;
	cout << endl; 

	encargos.GuardarVectorEncargo ("copia_encargos.txt");

	VectorEncargo copia_encargos ("copia_encargos.txt");

	cout << endl; 
	cout << Cabecera ("COPIA ENCARGOS:");
	cout << endl; 	
	cout << copia_encargos.toString() << endl;
	cout << endl; 

	Encargo encargo ("0*0.0*");
	encargos += encargo; 

	cout << endl; 
	cout << Cabecera ("ENCARGOS TRAS ADICION");
	cout << endl; 	
	cout << encargos.toString() << endl;
	cout << endl; 

	encargos.RecuperarVectorEncargo ("encargos.txt");

	cout << endl; 
	cout << Cabecera ("ENCARGOS ORIGINAL");
	cout << endl; 	
	cout << encargos.toString() << endl;
	cout << endl; 

	
	//................................................................
	// ADSCRIPCIONES

	VectorAdscripcion adscripciones ("adscripciones.txt");

	cout << endl; 
	cout << Cabecera ("ADSCRIPCIONES:");
	cout << endl; 	
	cout << adscripciones.toString() << endl;
	cout << endl; 

	adscripciones.GuardarVectorAdscripcion ("copia_adscripciones.txt");

	VectorAdscripcion copia_adscripciones ("copia_adscripciones.txt");

	cout << endl; 
	cout << Cabecera ("COPIA ADSCRIPCIONES:");
	cout << endl; 	
	cout << copia_adscripciones.toString() << endl;
	cout << endl; 

	Adscripcion adscripcion ("xxxxxxxxx*WXYZ*");
	adscripciones += adscripcion; 

	cout << endl; 
	cout << Cabecera ("ADSCRIPCIONES TRAS ADICION");
	cout << endl; 	
	cout << adscripciones.toString() << endl;
	cout << endl; 

	adscripciones.RecuperarVectorAdscripcion ("adscripciones.txt");

	cout << endl; 
	cout << Cabecera ("ADSCRIPCIONES ORIGINAL");
	cout << endl; 	
	cout << adscripciones.toString() << endl;
	cout << endl; 

	


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
