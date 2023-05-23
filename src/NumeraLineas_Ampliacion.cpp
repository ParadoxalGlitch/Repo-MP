/*****************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: NumeraLineas_Ampliacion.cpp
//
// Programa de enumeración de lineas
//
/*****************************************************************************/


#include <iostream>
#include <fstream>

using namespace std;


// FUNCIONES


void enumera (ostream & salida, istream & entrada)
{

    // Datos a leer/utilizar
    string linea;
    int i=1;

    // Lectura

    while (getline(entrada, linea)){

        salida << i << " " << linea << endl;
        i++;

    }

}




// FUNCION MAIN



int main(int argc, char * argv[]){


    // Compruebo los argumentos

    if (argc > 3){

        cerr << "El número de argumentos es incorrecto" << endl;
        cerr << "Uso: " << endl;
        cerr << argv[0] << endl;
        cerr << argv[0] << " fichero1" << endl;
        cerr << argv[0] << " fichero1 fichero2" << endl;

        return (1);
    }



    if (argc == 2){

        ifstream fi; // Flujo de salida

        fi.open(argv[1]);

        if (!fi){
            cerr << "Error: no pudo abrirse " << argv[1] << endl;
            exit (2);
        }

        enumera(cout, fi);

    }

    else if (argc == 3){

        ifstream fi; // Flujo de salida
        fi.open(argv[1]);

        if (!fi){   

            cerr << "No se ha podido abrir el fichero " << argv[1] << endl;
            return (2);

        }

        ofstream fo;
        fo.open(argv[2]);

        if (!fo){

            cerr << "No se ha podido abrir el fichero " << argv[2] << endl;
            return (2);

        }

        enumera(fo,fi);

    }

    else
        enumera(cout,cin);



    return (0);
}