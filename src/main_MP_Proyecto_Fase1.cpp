/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: main_MP_Proyecto_Fase1.cpp
//
// Contiene el main del proyecto
//
/***************************************************************************/


#include <iostream>
#include <cstring>


#include "Departamento.h"
#include "Profesor.h"
#include "Encargos.h"
#include "Adscripciones.h"
#include "utils.h"
#include "Fecha.h"  

using namespace std;

// FUNCION MAIN

int main(){


    string linea;
    int cuenta_dep = 0;
    int cuenta_prof = 0;
    int cuenta_enc = 0;
    int cuenta_ads = 0;
    
    
    
    
    // Comienzo leyendo el fichero de entrada
    // Supondré que nunca habrá de primeras un terminador FIN


    // El primer bucle leerá los datos de la clase Departamento

    cout << "--------------------------------------------------------------";
    cout << endl;
    cout << "DEPARTAMENTOS:" << endl;
    cout << "--------------------------------------------------------------";
    cout << endl;

    // Voy leyendo las lineas, las almaceno en la clase y las imprimo
    getline(cin, linea);
    
    do 
    {
        Departamento dep(linea);
        cout << dep.ToString();
        cuenta_dep++;        

    }
     while (getline(cin, linea) && linea != "FIN");


    cout << "Total Departamentos = " << cuenta_dep << endl << endl;






     // El segundo bucle leerá los datos de la clase Profesor

    cout << "--------------------------------------------------------------";
    cout << endl;
    cout << "PROFESORES:" << endl;
    cout << "--------------------------------------------------------------";
    cout << endl;

    // Voy leyendo las lineas, las almaceno en la clase y las imprimo
    getline(cin, linea);

    do 
    {
        Profesor prof(linea);
        cout << prof.ToString();   
        cuenta_prof++;     

    }
     while (getline(cin, linea) && linea != "FIN");


    cout << "Total Profesores = " << cuenta_prof << endl << endl;





    // El tercer bucle leerá los datos de la clase Encargos

    cout << "--------------------------------------------------------------";
    cout << endl;
    cout << "ENCARGOS:" << endl;
    cout << "--------------------------------------------------------------";
    cout << endl;

    // Voy leyendo las lineas, las almaceno en la clase y las imprimo
    getline(cin, linea);

    do 
    {
        Encargo enc(linea);
        cout << enc.ToString();    
        cuenta_enc++;    

    }
     while (getline(cin, linea) && linea != "FIN");


    cout << "Total Encargos = " << cuenta_enc << endl << endl;



    
    // El cuarto bucle leerá los datos de la clase Adscripciones

    cout << "--------------------------------------------------------------";
    cout << endl;
    cout << "ADSCRIPCION DE PROFESORES A DEPARTAMENTOS:" << endl;
    cout << "--------------------------------------------------------------";
    cout << endl;

    // Voy leyendo las lineas, las almaceno en la clase y las imprimo
    getline(cin, linea);

    do 
    {
        Adscripcion ads(linea);
        cout << ads.ToString();     
        cuenta_ads++;   

    }
     while (getline(cin, linea) && linea != "FIN");


    cout << "Total Adscripciones = " << cuenta_ads << endl << endl;




    return 0;








}




