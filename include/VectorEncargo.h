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
#include <fstream>

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
    // Constructor con argumentos (fichero)

    VectorEncargo(const string & nombre);

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


    /***********************************************************************/
    // Método para buscar si x encargo ya existe en el vector

    bool estaEncargo (const Encargo & encargo) const;

    /***********************************************************************/
    // Sobrecarga del operador + (Vector + Vector)

    friend VectorEncargo operator + (const VectorEncargo & uno, const
                                          VectorEncargo & otro);

    /***********************************************************************/
    // Sobrecarga del operador + (Vector + Encargo)

    friend VectorEncargo operator + (const VectorEncargo & uno, const
                                     Encargo & encargo);

    /***********************************************************************/
    // Sobrecarga del operador + (Encargo + Vector)

    friend VectorEncargo operator + (const Encargo & encargo,
                                     const VectorEncargo & uno);

    /***********************************************************************/
    // Sobrecarga del operador += (vector += vector)

    VectorEncargo operator += (const VectorEncargo & otro);

    /***********************************************************************/
    // Sobrecarga del operador += (vector += encargo)

    VectorEncargo operator += (const Encargo & encargo);


    /***********************************************************************/
    // Función de escritura de un vector en un fichero

    void GuardarVectorEncargo (const string & nombre) const;

    /***********************************************************************/
    // Función de lectura de un vector de un fichero    

    void RecuperarVectorEncargo (const string & nombre);

    /***********************************************************************/
    // Operadores >> y <<

    friend ofstream & operator << (ofstream & fo, 
                             const VectorEncargo & vector);
    
    friend ifstream & operator >> (ifstream & fi, VectorEncargo & vector);

};

#endif