/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: Profesor.h
//
// Contiene las cabeceras de la clase "Profesor"
//
/***************************************************************************/

#ifndef PROFESOR
#define PROFESOR

#include <string>

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Clase "Profesor"

class Profesor
{

private:

    string dni;
    string nombre;
    string apellidos;
    string fechaNacimiento; // Esto mas tarde será un objeto de la clase "Fecha"

public:

/***************************************************************************/
// Constructor por defecto

    Profesor();

/***************************************************************************/
// Constructor con argumentos

    Profesor(string d, string n, string a, string f);

/***************************************************************************/
// Métodos get

    string getDni();
    string getNombre();
    string getApellidos();
    string getFechaNacimiento();

/***************************************************************************/
// Métodos set

    void setDni(string d);
    void setNombre(string n);
    void setApellidos(string a);
    void setFechaNacimiento(string f);

/***************************************************************************/
// Método ToString

    string ToString();


};

#endif