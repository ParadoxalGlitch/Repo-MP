/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: ParteFicheroPorNumLineas.cpp
//
// Programa que dado una longitud, parte el fichero porporcionado
// en x ficheros de la longitud proporcionada
//
/***************************************************************************/

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

// FUNCIONES

int CuentaLineas (istream fichero)
{
    string linea;
    int total_lineas = 0;

    while(getline(fichero, linea)){

        total_lineas++;

    }

    return total_lineas;
}

string EliminaExtension (string fichero)
{
    int i=0;
    while (fichero.at(i) != '.'){

        i++;

    }

    fichero = fichero.substr(0,i);


    return fichero;


}





int main(int argc, char * argv[]){

    // Compruebo que los argumentos son correctos

    if (argc != 3){

        cerr << "ERROR, numero de argumentos incorrecto." << endl;
        cerr << "Uso: " << argv[0] << " <fichero> <num_lineas_max>" << endl;
        return (1);

    }


    // Creo el flujo de entrada del fichero

    ifstream fi;
    fi.open(argv[1]);

    if (!fi){

        cerr << "No se ha podido abrir el fichero " << argv[1] << endl;

    }

    // Realizo los calculos necesarios y declaro las variables a usar

    string linea;
    string nombre_fichero(argv[1]);
    string nombre_subfichero;
    string fichero_sin_extension = EliminaExtension(nombre_fichero);
    

    int max_lineas = stoi(argv[2]);
    int num_lineas = CuentaLineas(fi);

    double num_ficheros = ceil((num_lineas + max_lineas - 1) / max_lineas);


    fi.seekg(0,ios::beg);   



    // Creo un flujo de salida para los nuevos ficheros 

    ofstream fo;
    int j=0;


    for (int i=1; i <= num_ficheros; i++){

        nombre_subfichero = fichero_sin_extension + '_' + to_string(i) + ".txt";
        fo.open(nombre_subfichero);

        j=0;

        while(j < max_lineas && getline(fi,linea)){

            fo << linea << endl;
            j++;

        }

        fo.close();
    }



    // Creamos el fichero oculto de control

    string nombre_control = '.' + fichero_sin_extension + '.' + "ctrl";

    ofstream control;
    control.open(nombre_control);

    // Añado los datos

    control << argv[1] << endl;
    control << num_ficheros; 

    control.close();
    fi.close();


    return (0);
    
}