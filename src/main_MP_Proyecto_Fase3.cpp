/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
// 
// Fichero: main_MP_Proyecto_Fase2.cpp
//
// Función main del proyecto. 
//
// Proyecto. FASE 02. 
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

#include "utils.h"

using namespace std;



int main()
{



    string texto = "12345678A*Laureano Amadeo*Abad Arrabal*01/01/1970*1*";

    Profesor prueba1 (texto);

    Profesor prueba2;

    prueba2 = prueba1;


    cout << "Prueba1: " << endl;
    cout << prueba1.ToString() << endl;

    cout << "Prueba2: " << endl;
    cout << prueba2.ToString() << endl;

    prueba1.setDni("77391418Y");
    prueba1.setCategoria(49);

    cout << "Prueba1: " << endl;
    cout << prueba1.ToString() << endl;

    cout << "Prueba2: " << endl;
    cout << prueba2.ToString() << endl;

    // pruebo el constructor de copia

    Profesor prueba3 (prueba1);

    cout << "Prueba3: " << endl;
    cout << prueba3.ToString() << endl;

    prueba1.setDni("12345678A");
    prueba1.setCategoria(69);

    cout << "Prueba1: " << endl;
    cout << prueba1.ToString() << endl;

    cout << "Prueba3: " << endl;
    cout << prueba3.ToString() << endl;




    
    return 0;




}