/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: Encargos.h
//
// Contiene las cabeceras de la clase "Encargos"
//
/***************************************************************************/

#ifndef ENCARGOS
#define ENCARGOS

#include <string>

#include "utils.h"


using namespace std;

/***************************************************************************/
/***************************************************************************/
// Clase "Encargos"

class Encargos
{

private:

   int categoria;
   double creditos;

public:

/***************************************************************************/
// Constructor por defecto

   Encargos();

/***************************************************************************/
// Constructor con argumentos

   Encargos(string linea, char delimitador=DELIMITADOR);

/***************************************************************************/
// Métodos get

   int getCategoria();
   double getCreditos();

/***************************************************************************/
// Métodos set

   void setCategoria(int cat);
   void setCreditos(double cred);

/***************************************************************************/
// Método ToString

   string ToString();



};

#endif

