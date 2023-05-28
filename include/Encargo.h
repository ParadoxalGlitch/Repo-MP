/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: Encargo.h
//
// Contiene las cabeceras de la clase "Encargo"
//
/***************************************************************************/

#ifndef ENCARGO
#define ENCARGO

#include <string>

#include "utils.h"


using namespace std;

/***************************************************************************/
/***************************************************************************/
// Clase "Encargo"

class Encargo
{

private:

   int categoria;
   double creditos;

public:


/***************************************************************************/
// Constructor por defecto

   Encargo();

/***************************************************************************/
// Constructor de copia

   Encargo(Encargo & otro);

/***************************************************************************/
// Constructor con argumentos

   Encargo(string linea, char delimitador=DELIMITADOR);

/***************************************************************************/
// Métodos get

   int getCategoria() const;
   double getCreditos();

/***************************************************************************/
// Métodos set

   void setCategoria(int cat);
   void setCreditos(double cred);

/***************************************************************************/
// Método ToString

   string ToString();

/***************************************************************************/
// Método clona

   void clona(Encargo & original);

/**************************************************************************/
// Operador << y >>

friend ofstream & operator << (ofstream & fo, Encargo & encargo);

friend ifstream & operator >> (ifstream & fi, Encargo & encargo);


};

#endif

