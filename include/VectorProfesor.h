/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: VectorProfesor.h
//
// Contiene las cabeceras de la clase "VectorProfesor"
//
/***************************************************************************/

#ifndef VECTORPROFESOR
#define VECTORPROFESOR

#include <cstring>

#include "Profesor.h"

/***************************************************************************/
/***************************************************************************/
// Clase "VectorProfesor"

class VectorProfesor
{

private:

    Profesor * datos;
    int usados;
    int capacidad;


public:

    /***********************************************************************/
    // Constructor sin argumentos

    VectorProfesor();

    /***********************************************************************/
    // Constructor con argumentos

    VectorProfesor(int capacidad);

    /***********************************************************************/
    // Constructor de copia

    VectorProfesor(const VectorProfesor & otro);

    /***********************************************************************/
    // Destructor

    ~VectorProfesor();

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

    void inserta(const Profesor & nuevo, const int pos);

    /***********************************************************************/
    // Método de inserción de un elemento en el vector al final

    void aniade(const Profesor & nuevo);

    /***********************************************************************/
    // Método de eliminación de un elemento del vector

    void elimina(const int pos);

    /***********************************************************************/
    // Método para ajustar la capacidad del vector al numero de elementos
    // usados

    void ajusta();

    /***********************************************************************/
    // Sobrecarga del operador de asignación

    VectorProfesor & operator=(const VectorProfesor & otro);

    /***********************************************************************/
    // Sobrecarga del operador de acceso, tanto [ ] como ( )

    Profesor & operator[](const int pos);

    const Profesor & operator[](const int pos) const;

    Profesor & operator()(const int pos);

    const Profesor & operator()(const int pos) const;

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

    void copiaDatos(const VectorProfesor & otro);

    /***********************************************************************/
    // Método para buscar si x profesor ya existe en el vector

    bool estaProfesor (const Profesor & profesor) const;


    /***********************************************************************/
    // Sobrecarga del operador + (Vector + Vector)

    friend VectorProfesor operator + (const VectorProfesor & uno, const
                                      VectorProfesor & otro);

    /***********************************************************************/
    // Sobrecarga del operador + (Vector + profesor)

    friend VectorProfesor operator + (const VectorProfesor & uno, const
                                      Profesor & profesor);

    /***********************************************************************/
    // Sobrecarga del operador + (profesor + Vector)

    friend VectorProfesor operator + (const Profesor & profesor,
                                      const VectorProfesor & uno);

    /***********************************************************************/
    // Sobrecarga del operador += (vector += vector)

    VectorProfesor operator += (const VectorProfesor & otro);
    
    /***********************************************************************/
    // Sobrecarga del operador += (vector += departamento)

    VectorProfesor operator += (const Profesor & profesor);













};

#endif