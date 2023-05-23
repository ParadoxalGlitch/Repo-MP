/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: Fecha.h
//
// Contiene las cabeceras de la clase "Matriz2D"
//
/***************************************************************************/

#ifndef MATRIZ2D
#define MATRIZ2D

#include <string>
#include <iostream>
#include "TipoBase.h"
#include "Secuencia.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Clase "Matriz2D"

class Matriz2D
{

private:

    TipoBase ** datos;
    int fils;
    int cols;

public:

/***************************************************************************/
// Constructor por defecto

    Matriz2D();

/****************************************************************************/
// Constructor con 1 argumento, nombre de fichero de texto

    Matriz2D (const char * nombre);

/***************************************************************************/
// Constructor con 1 argumento, num de filas y columnas

    Matriz2D(int num);

/***************************************************************************/
// Constructor con 2 argumentos, num de filas y num de columnas

    Matriz2D(int f, int c);

/***************************************************************************/
// Constructor con 3 argumentos, num de filas, num de columnas y valor a 
// inicializar

    Matriz2D(int f, int c, int valor);

/***************************************************************************/
// Constructor de copia

    Matriz2D(const Matriz2D & otra);

/***************************************************************************/
// Destructor

    ~Matriz2D();

/***************************************************************************/
// Reserva de memoria

    void ReservaMemoria(int f, int c, int valor = 0);

/***************************************************************************/
// Consulta de dimensiones

    int NumFilas(void) const;

    int NumColumnas(void) const; 

/***************************************************************************/
// Consulta de estado de la matriz (vacia o no)

    bool EstaVacia(void) const;

/***************************************************************************/
// Metodo de eliminacion de todos los valores de una matriz

    void EliminaTodos(void);


/***************************************************************************/
// Método clona

    void Clona (const Matriz2D & origen);


/***************************************************************************/
// Metodo ecualiza
// Reemplaza los valores de las casillas por el valor dado como argumento

    void Ecualiza(int valor);

/***************************************************************************/
// Metodo ToString

    string ToString(void) const;

/***************************************************************************/
// Sobrecarga del operador de asignación

    Matriz2D & operator = (const Matriz2D & otra);



/***************************************************************************/
// Sobrecarga alternativa del operador de asignación, que recibe como argumento
// un valor de tipo TipoBase y asigna dicho valor a todos los elementos de la
// matriz

    Matriz2D & operator = (const TipoBase & valor);


/***************************************************************************/
// Método get y set
// Devuelve una referencia, para poder leer o modificar el valor a gusto del
// usuario

    TipoBase & Valor(int f, int c) const;
    

/***************************************************************************/
// Método para comparar dos matrices, devuelve true si son iguales

    bool EsIgualA (const Matriz2D & otra);

/***************************************************************************/
// Método get de filas y columnas, como objetos de la clase Secuencia
// usando la funcion Valor de Secuencia

    Secuencia Fila (int f);

    Secuencia Columna (int c);

/***************************************************************************/
// Método para añadir una fila al final de la matriz. Siendo esta fila de
// tipo Secuencia

    void AniadeFila (Secuencia & fila);

/***************************************************************************/
// Método para insertar una fila en la matriz. Siendo esta fila de tipo
// Secuencia

    void InsertaFila (Secuencia & fila, int pos);


/***************************************************************************/
// Método para eliminar una fila de la matriz

    void EliminaFila (int num_fila);

/***************************************************************************/
// Método para eliminar una columna de la matriz

    void EliminaColumna(int num_col);

/***************************************************************************/
// Método SubMatriz

    void SubMatriz (const Matriz2D & original, int fila_inic, 
                int col_inic, int num_filas, int num_cols);


/***************************************************************************/
// Sobrecarga del operador ()

    TipoBase & operator () (int f, int c) const;

    TipoBase & operator () (int f, int c);


/***************************************************************************/
// Sobrecarga del operador == y !=
    
        bool operator == (const Matriz2D & otra);
    
        bool operator != (const Matriz2D & otra);



/***************************************************************************/
// Sobrecarga del operador unario + y -

    Matriz2D operator + ();

    Matriz2D operator - ();

/***************************************************************************/
// Sobrecarga del operador binario + y - (ambos operandos de tipo Matriz2D)

    friend Matriz2D operator + (const Matriz2D & una , const Matriz2D & otra);

    friend Matriz2D operator - (const Matriz2D & una, const Matriz2D & otra);

/***************************************************************************/
// Sobrecarga del operador binario + y - (uno de los operandos es de tipo
// TipoBase y el otro de tipo TipoBaseMatriz2D)

    friend Matriz2D operator + (const Matriz2D & matriz, const TipoBase valor);

    friend Matriz2D operator - (const Matriz2D & matriz, const TipoBase valor);

    friend Matriz2D operator + (const TipoBase valor, const Matriz2D & matriz);

    friend Matriz2D operator - (const TipoBase valor, const Matriz2D & matriz);

/***************************************************************************/
// Sobrecarga del operador combinado += y -= (ambos operandos son de tipo
// Matriz2D)

    Matriz2D & operator += (const Matriz2D & otra);

    Matriz2D & operator -= (const Matriz2D & otra);




/****************************************************************************/
// Sobrecarga del operador << y >>

    friend ostream & operator << (ostream & out, const Matriz2D & matriz);
    friend istream & operator >> (istream & in, Matriz2D & matriz);

/****************************************************************************/
// Funcion de escritura de una matriz en un fichero

    void EscribirMatriz2D (const char * nombre) const;

/****************************************************************************/
// Funcion de lectura de una matriz desde un fichero

    void LeerMatriz2D (const char * nombre);

};




#endif