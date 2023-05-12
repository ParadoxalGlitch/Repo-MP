/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: VectorAdscripcion.h
//
// Contiene las cabeceras de la clase "VectorAdscripcion"
//
/***************************************************************************/

#ifndef VECTORADSCRIPCION
#define VECTORADSCRIPCION

#include <cstring>

#include "Adscripcion.h"


/***************************************************************************/
/***************************************************************************/
// Clase "VectorAdscripcion"

class VectorAdscripcion
{

private:

    Adscripcion * datos;
    int usados;
    int capacidad;


public:

    /***********************************************************************/
    // Constructor sin argumentos

    VectorAdscripcion();

    /***********************************************************************/
    // Constructor con argumentos

    VectorAdscripcion(int capacidad);

    /***********************************************************************/
    // Constructor de copia

    VectorAdscripcion(const VectorAdscripcion & otro);

    /***********************************************************************/
    // Destructor

    ~VectorAdscripcion();

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

    void inserta(const Adscripcion & nuevo, const int pos);

    /***********************************************************************/
    // Método de inserción de un elemento en el vector al final

    void aniade(const Adscripcion & nuevo);

    /***********************************************************************/
    // Método de eliminación de un elemento del vector

    void elimina(const int pos);

    /***********************************************************************/
    // Método para ajustar la capacidad del vector al numero de elementos
    // usados

    void ajusta();

    /***********************************************************************/
    // Sobrecarga del operador de asignación

    VectorAdscripcion & operator=(const VectorAdscripcion & otro);

    /***********************************************************************/
    // Sobrecarga del operador de acceso, tanto [ ] como ( )

    Adscripcion & operator[](const int pos);

    const Adscripcion & operator[](const int pos) const;

    Adscripcion & operator()(const int pos);

    const Adscripcion & operator()(const int pos) const;

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

    void copiaDatos(const VectorAdscripcion & otro);

    /***********************************************************************/
    // Método para buscar si x adscripcion ya existe en el vector

    bool estaAdscripcion (const Adscripcion & adscripcion) const;

    /***********************************************************************/
    // Sobrecarga del operador + (Vector + Vector)

    friend VectorAdscripcion operator + (const VectorAdscripcion & uno, const
                                          VectorAdscripcion & otro);

    /***********************************************************************/
    // Sobrecarga del operador + (Vector + adscripcion)

    friend VectorAdscripcion operator + (const VectorAdscripcion & uno, const
                                          Adscripcion & adscripcion);

    /***********************************************************************/
    // Sobrecarga del operador + (adscripcion + Vector)

    friend VectorAdscripcion operator + (const Adscripcion & adscripcion,
                                          const VectorAdscripcion & uno);

    /***********************************************************************/
    // Sobrecarga del operador += (vector += vector)

    VectorAdscripcion operator += (const VectorAdscripcion & otro);

    /***********************************************************************/
    // Sobrecarga del operador += (vector += adscripcion)

    VectorAdscripcion operator += (const Adscripcion & adscripcion);

};

#endif