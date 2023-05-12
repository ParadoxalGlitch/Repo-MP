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

#include "utils.h"
#include "Fecha.h"

using namespace std;


/***************************************************************************/
/***************************************************************************/
// Clase "Profesor"

class Profesor
{

private:

    char * dni;
    char * nombre;
    char * apellidos;
    Fecha fechaNacimiento; 
    int categoria; // Valor entre 1 y 4

public:


/***************************************************************************/
// Constructor por defecto

    Profesor();


/***************************************************************************/
// Constructor de copia

    Profesor(const Profesor & otro);

/***************************************************************************/
// Constructor con argumentos

    Profesor(string linea, char delimitador=DELIMITADOR);



/***************************************************************************/
// Destructor
    ~Profesor();

    

/***************************************************************************/
// Métodos get

    string getDni() const;
    string getNombre();
    string getApellidos();
    string getFechaNacimiento();
    int getCategoria();

/***************************************************************************/
// Métodos set

    void setDni(string d);
    void setNombre(string n);
    void setApellidos(string a);
    void setFechaNacimiento(string f);
    void setCategoria(int c);

/***************************************************************************/
// Método ToString

    string ToString();
    

/***************************************************************************/
// Método ReservaMemoria
// Se llama a esta función cuando se va a clonar un objeto
// por lo que se elimina el contenido anterior y se reserva
// para el nuevo

    void ReservaMemoria(const Profesor & objeto);


/************************************************************/
// Libera memoria

    void LiberarMemoria(void);

/************************************************************/
// Copiar datos desde otro objeto de la clase
// Parámetros: otro (referencia), objeto que sirve de modelo.
//
// PRE: Se ha reservado memoria para los datos

    void CopiarDatos (const Profesor & otro);


/***************************************************************************/
// Método clona

    void clona(const Profesor & original);


/**************************************************************************/
// Operador de asignación

    Profesor & operator = (const Profesor & original);

};

#endif