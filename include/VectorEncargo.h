/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: VectorEncargo.h
//
// Contiene las cabeceras de la clase "VectorEncargo"
//
/***************************************************************************/

#ifndef VECTORENCARGO
#define VECTORENCARGO

#include <cstring>

#include "Encargo.h"


/***************************************************************************/
/***************************************************************************/
// Clase "VectorEncargo"

class VectorEncargo
{

private:

    Encargo * datos;
    int usados;
    int capacidad;


public:

    /***********************************************************************/
    // Constructor sin argumentos

    VectorEncargo();

    /***********************************************************************/
    // Constructor con argumentos

    VectorEncargo(int capacidad);

    /***********************************************************************/
    // Constructor de copia

    VectorEncargo(const VectorEncargo & otro);

    /***********************************************************************/
    // Destructor

    ~VectorEncargo();

    /***********************************************************************/
    // Método get

    int getUsados() const;

    int getCapacidad() const;

    /***********************************************************************/
    // Método de consulta sobre estado del vector (vacio o no)

    bool estaVacio() const;

    /***********************************************************************/
    // Método de reinicio de un vector (lo deja vacio)

    void reinicia();

    /***********************************************************************/
    // Método de inserción de un elemento en el vector en la casilla "pos"

    void inserta(const Encargo & nuevo, const int pos);

    /***********************************************************************/
    // Método de inserción de un elemento en el vector al final

    void aniade(const Encargo & nuevo);

    /***********************************************************************/
    // Método de eliminación de un elemento del vector

    void elimina(const int pos);

    /***********************************************************************/
    // Método para ajustar la capacidad del vector al numero de elementos
    // usados

    void ajusta();

    /***********************************************************************/
    // Sobrecarga del operador de asignación

    VectorEncargo & operator=(const VectorEncargo & otro);

    /***********************************************************************/
    // Sobrecarga del operador de acceso, tanto [ ] como ( )

    Encargo & operator[](const int pos);

    const Encargo & operator[](const int pos) const;

    Encargo & operator()(const int pos);

    const Encargo & operator()(const int pos) const;

    /***********************************************************************/
    // Método toString

    string toString() const;

    /***********************************************************************/
    // Método de redimensionamiento del vector por bloques de tamaño fijo

    void redimensiona();

    /***********************************************************************/
    // Reserva de memoria

    void reservaMemoria(int capacidad);

    /***********************************************************************/
    // liberación de memoria

    void liberaMemoria();

    /***********************************************************************/
    // Método de copia de datos

    void copiaDatos(const VectorEncargo & otro);

};

#endif