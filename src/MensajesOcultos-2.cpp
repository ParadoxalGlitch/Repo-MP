/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: MensajesOcultos-2.cpp
//
// Programa que dado un fichero con datos sobre una frase oculta, la 
// encuentra en el fichero de texto proprocionado
//
/***************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char * argv[]){


    // Comprobación de validez de argumentos

    if (argc != 3){

        cerr << "ERROR, número de argumentos incorrecto." << endl;
        cerr << "Uso: " << argv[0] << " <fichero_texto>  <fichero_datos>";
        cerr << endl;

    }


    ifstream fichero_datos;
    fichero_datos.open(argv[2]);

    if (!fichero_datos){

        cerr << "El fichero " << argv[2] << " no ha podido abrirse" << endl;

    }

    ifstream fichero_texto;
    fichero_texto.open(argv[1]);

    if (!fichero_texto){

        cerr << "El fichero " << argv[1] << " no ha podido abrirse" << endl;

    }


    // Guardo el texto completo en un string.

    string flujo;
    string texto;


    while (getline(fichero_texto, flujo)){

        texto += flujo;
        texto += '\n';

    }

    const int MAX_FRASE = 50;
    string frase [MAX_FRASE];
    int tam_frase = 0;
    string linea_aux;
    string palabra_aux;

    int linea = 0;
    int palabra = 0;

    // Lectura adelantada

    fichero_datos >> linea;
    fichero_datos >> palabra;


    while (!fichero_datos.eof()){

        istringstream texto_stream(texto);

        int i = 1;
        while (i<=linea){

            getline(texto_stream, linea_aux);

            if (linea_aux.length() != 0)
                i++;

        }

        //Ahora busco la palabra en la linea que quería

        istringstream linea_stream(linea_aux);

        for (int j=1; j<=palabra; j++){

            linea_stream >> palabra_aux;
            
        }


        frase[tam_frase] = palabra_aux;
        tam_frase++;

        fichero_datos >> linea;
        fichero_datos >> palabra;

    }



    // Imprimo la frase oculta

    cout << "La frase oculta es: ";
    
    for (int i=0; i<tam_frase; i++){

        cout << frase[i] << " ";

    }

    cout << endl;


    fichero_datos.close();
    fichero_texto.close();

    return (0);




}