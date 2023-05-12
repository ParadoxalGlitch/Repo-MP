/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: VectorDepartamento.h
//
// Contiene las cabeceras de la clase "VectorDepartamento"
//
/***************************************************************************/

#ifndef VECTORDEPARTAMENTO
#define VECTORDEPARTAMENTO

#include "Departamento.h"

/***************************************************************************/
/***************************************************************************/
// Clase "VectorDepartamento"

class VectorDepartamento
{

private:

    Departamento * datos;
    int usados;
    int capacidad;


public:

    /***********************************************************************/
    // Constructor sin argumentos

    VectorDepartamento();

    /***********************************************************************/
    // Constructor con argumentos

    VectorDepartamento(int capacidad);

    /***********************************************************************/
    // Constructor de copia

    VectorDepartamento(const VectorDepartamento & otro);

    /***********************************************************************/
    // Destructor

    ~VectorDepartamento();

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

    void inserta(const Departamento & nuevo, const int pos);

    /***********************************************************************/
    // Método de inserción de un elemento en el vector al final

    void aniade(const Departamento & nuevo);

    /***********************************************************************/
    // Método de eliminación de un elemento del vector

    void elimina(const int pos);

    /***********************************************************************/
    // Método para ajustar la capacidad del vector al numero de elementos
    // usados

    void ajusta();

    /***********************************************************************/
    // Sobrecarga del operador de asignación

    VectorDepartamento & operator=(const VectorDepartamento & otro);

    /***********************************************************************/
    // Sobrecarga del operador de acceso, tanto [ ] como ( )

    Departamento & operator[](const int pos);

    const Departamento & operator[](const int pos) const;

    Departamento & operator()(const int pos);

    const Departamento & operator()(const int pos) const;

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

    void copiaDatos(const VectorDepartamento & otro);


    /***********************************************************************/
    // Método para buscar si x departamento ya existe en el vector

    bool estaDepartamento (const Departamento & departamento) const;


    /***********************************************************************/
    // Sobrecarga del operador + (Vector + Vector)

    friend VectorDepartamento operator + (const VectorDepartamento & uno, const
                                          VectorDepartamento & otro);
                                          
    /***********************************************************************/
    // Sobrecarga del operador + (Vector + departamento)

    friend VectorDepartamento operator + (const VectorDepartamento & uno, const
                                          Departamento & departamento);

    /***********************************************************************/
    // Sobrecarga del operador + (departamento + Vector)

    friend VectorDepartamento operator + (const Departamento & departamento,
                                          const VectorDepartamento & uno);

    /***********************************************************************/
    // Sobrecarga del operador - (Vector - Vector)

    friend VectorDepartamento operator - (const VectorDepartamento & uno, const
                                          VectorDepartamento & otro);

    /***********************************************************************/
    // Sobrecarga del operador - (Vector - departamento)

    friend VectorDepartamento operator - (const VectorDepartamento & uno, const
                                          Departamento & departamento);


    /***********************************************************************/
    // Sobrecarga del operador - (Vector - string)

    friend VectorDepartamento operator - (const VectorDepartamento & uno, const
                                          string & cadena);

    /***********************************************************************/
    // Sobrecarga del operador * (Vector * Vector)

    friend VectorDepartamento operator * (const VectorDepartamento & uno, const
                                          VectorDepartamento & otro);

    /***********************************************************************/
    // Sobrecarga del operador binario && (vector && vector)

    friend bool operator && (const VectorDepartamento & uno, const
                                           VectorDepartamento & otro);

    /***********************************************************************/
    // Sobrecarga del operador binario && (Vector && departamento)

    friend bool operator && (const VectorDepartamento & uno, const
                                           Departamento & departamento);

    /***********************************************************************/
    // Sobrecarga del operador binario && (departamento && Vector)

    friend bool operator && (const Departamento & departamento,
                                           const VectorDepartamento & uno);

    /***********************************************************************/
    // Sobrecarga del operador binario && (Vector && string)

    friend bool operator && (const VectorDepartamento & uno, const
                                           string & cadena);


    /***********************************************************************/
    // Sobrecarga del operador binario && (string && Vector)

    friend bool operator && (const string & cadena, const
                                           VectorDepartamento & uno);

    /***********************************************************************/
    // Sobrecarga del operador += (vector += vector)

    VectorDepartamento operator += (const VectorDepartamento & otro);

    /***********************************************************************/
    // Sobrecarga del operador += (vector += departamento)

    VectorDepartamento operator += (const Departamento & departamento);

    /***********************************************************************/
    // Sobrecarga del operador -= (vector -= vector)

    VectorDepartamento operator -= (const VectorDepartamento & otro);

    /***********************************************************************/
    // Sobrecarga del operador -= (vector -= departamento)

    VectorDepartamento operator -= (const Departamento & departamento);

    /***********************************************************************/
    // Sobrecarga del operador -= (vector -= string)

    VectorDepartamento operator -= (const string & cadena);




};

#endif
