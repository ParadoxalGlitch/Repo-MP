/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: Fecha.cpp
//
// Contiene las implementaciones de la clase "Matriz2D"
//
/***************************************************************************/


#include "Matriz2D.h"
#include "TipoBase.h"
#include "Secuencia.h"

#include <string>
#include <cstring>
#include <iostream>




using namespace std;


/***************************************************************************/
/***************************************************************************/
// Constructor por defecto

Matriz2D :: Matriz2D()
{
    datos = nullptr;
    fils = 0;
    cols = 0;
}


/***************************************************************************/
// Constructor con 1 argumento, num de filas y columnas

Matriz2D :: Matriz2D(int num)
{

    // Si num es negativo o 0, inicializo todo a 0

    if(num == 0 || num < 0)
    {
        fils = 0;
        cols = 0;
        datos = nullptr;
    }

    // Si no es el caso, inicializo la matriz con los valores pasados por
    // argumento

    else
    {

        fils = num;
        cols = num;
        ReservaMemoria(num, num);

    }

}

/***************************************************************************/
// Constructor con 2 argumentos, num de filas y num de columnas

Matriz2D :: Matriz2D(int f, int c)
{

    // Si f o c son negativos, o alguno es 0, inicializo todo a 0

    if(f == 0 || c == 0 || f < 0 || c < 0)
    {
        fils = 0;
        cols = 0;
        datos = nullptr;
    }

    // Si no es el caso, inicializo la matriz con los valores pasados por
    // argumento

    else
    {

        fils = f;
        cols = c;
        ReservaMemoria(f, c);

    }

}

/***************************************************************************/
// Constructor con 3 argumentos, num de filas, num de columnas y valor a 
// inicializar

Matriz2D :: Matriz2D(int f, int c, int valor)
{

    // Si f o c son negativos, o alguno es 0, inicializo todo a 
    // valor por defecto
   
    if(f == 0 || c == 0 || f < 0 || c < 0)
    {
        fils = 0;
        cols = 0;
        datos = nullptr;
    }
    

    // Si no es el caso, inicializo la matriz con los valores pasados por
    // argumento

    else
    {

        fils = f;
        cols = c;
        ReservaMemoria(f, c, valor);

    }


}

/***************************************************************************/
// Constructor de copia

Matriz2D :: Matriz2D(const Matriz2D & otra)
{
    // Inicializo los atributos
    fils = 0;
    cols = 0;

    // Copio los atributos
    Clona(otra);
}


/***************************************************************************/
// Destructor

Matriz2D :: ~Matriz2D()
{

    if (!EstaVacia())
    {
        // Libero la memoria
        delete [] datos[0];
        delete [] datos;
    }

}



/***************************************************************************/
// Reserva de memoria y ecualización de la matriz

void Matriz2D :: ReservaMemoria(int f, int c, int valor)
{

    // Reservo memoria para la matriz
    datos = new TipoBase * [f];

    datos[0] = new int [f * c];

    fils = f;
    cols = c;


    for (int i = 0; i < f; i++)
    {
        datos[i] = datos[0] + (i * c);
    }

    // Inicializo la matriz con el valor pasado por argumento

    for(int i = 0; i < f; i++)
        for(int j = 0; j < c; j++)
            datos[i][j] = valor;
}



/***************************************************************************/
// Consulta de dimensiones

int Matriz2D :: NumFilas(void) const
{
    return fils;
}


int Matriz2D :: NumColumnas(void) const
{
    return cols;
}


/***************************************************************************/
// Consulta de estado de la matriz (vacia o no)

bool Matriz2D :: EstaVacia(void) const
{
    return (datos == nullptr);
}


/***************************************************************************/
// Metodo de eliminacion de todos los valores de una matriz

void Matriz2D :: EliminaTodos(void)
{

    // Si la matriz no esta vacia, la vacio

    if(!EstaVacia())
    {
        // Libero la memoria
        delete [] datos[0];
        delete [] datos;

        datos = nullptr;
        fils = 0;
        cols = 0;
    }

}


/***************************************************************************/
// Método clona

void  Matriz2D :: Clona (const Matriz2D & origen){
	

	// Volvemos a inicializarla con los datos de origen

	ReservaMemoria(origen.fils, origen.cols);

	//copiamos los valores
    for (int i = 0; i < origen.NumFilas(); i++)
        for (int j = 0; j < origen.NumColumnas(); j++)
            datos[i][j] = origen.datos[i][j];
	
}

/***************************************************************************/
// Metodo ecualiza
// Reemplaza los valores de las casillas por el valor dado como argumento

void Matriz2D :: Ecualiza(int valor)
{
    // Ecualizo los valores
    for (int i = 0; i < fils; i++)
        for (int j = 0; j < cols; j++)
            datos[i][j] = valor;
    
}


/***************************************************************************/
// Metodo ToString

string Matriz2D :: ToString(void)
{

    string cad;

	string delimitador = "..................................";

	cad = "\n" + delimitador + "\n";
	cad = cad + "Filas = " + to_string(fils) + 
		", Columnas = " + to_string (cols) + "\n\n";

	for (int f=0; f<fils; f++) {
		cad = cad + "Fila " + to_string(f) + " --> ";
		
		for (int c=0; c<cols; c++) 
			cad = cad + to_string(datos[f][c]) + "  ";
		cad = cad + "\n";
	}
	cad = cad + delimitador + "\n\n";

	return (cad);

}


/***************************************************************************/
// Sobrecarga del operador de asignación

Matriz2D & Matriz2D :: operator = (const Matriz2D & otra)
{
    // Compruebo que no sean el mismo objeto
    if (this != &otra)
    {
        // Libero la memoria
        EliminaTodos();

        // Copio los atributos
        Clona(otra);
    }

    return (*this);
}

/***************************************************************************/
// Sobrecarga alternativa del operador de asignación, que recibe como argumento
// un valor de tipo TipoBase y asigna dicho valor a todos los elementos de la
// matriz

Matriz2D & Matriz2D :: operator = (const TipoBase & valor)
{
    // Inicializo la matriz con el valor pasado por argumento

    for(int i = 0; i < fils; i++)
        for(int j = 0; j < cols; j++)
            datos[i][j] = valor;

    return (*this);
}


/***************************************************************************/
// Método get y set
// Devuelve una referencia, para poder leer o modificar el valor a gusto del
// usuario

TipoBase & Matriz2D :: Valor(int f, int c) const
{
    return datos[f][c];
}


/***************************************************************************/
// Método para comparar dos matrices, devuelve true si son iguales

bool Matriz2D :: EsIgualA (const Matriz2D & otra)
{
    bool Iguales = true;

    // Revisa si las columnas son distintas
	if (NumColumnas() != otra.NumColumnas())
		Iguales = false;
    
    // Revisa si las filas son distintas
	if(NumFilas() != otra.NumFilas())
		Iguales = false;

    // Recorre todas las posiciones de la matriz
	for (int f=0; f<NumColumnas() && Iguales; f++)
        for (int c=0; c<NumColumnas() && Iguales; c++)
            // Comprueba si hay algńu valor distinto
            if (Valor(f, c) != otra.Valor(f, c))
                // En ese caso, establece Iguales a falso
                // deteniendo la ejecución del bucle
                Iguales = false;
	
	return (Iguales);
}


/***************************************************************************/
// Método get de filas y columnas, como objetos de la clase Secuencia
// usando la funcion Valor de Secuencia

// Método get de fila

Secuencia Matriz2D :: Fila (int f)
{
    Secuencia fila(cols);

    for (int i = 0; i < cols; i++)
        fila.Valor(i) = datos[f][i];
    

    return fila;
}

// Método get de columna

Secuencia Matriz2D :: Columna (int c)
{
    Secuencia columna(fils);

    for (int i = 0; i < fils; i++)
        columna.Valor(i) = datos[i][c];

    return columna;
}


/***************************************************************************/
// Método para añadir una fila al final de la matriz. Siendo esta fila de
// tipo Secuencia

void Matriz2D :: AniadeFila (Secuencia & fila)
{
    // Creo una matriz auxiliar con una fila mas
    Matriz2D aux(fils + 1, cols);

    // Copio los valores de la matriz original
    for (int i = 0; i < fils; i++)
        for (int j = 0; j < cols; j++)
            aux.datos[i][j] = datos[i][j];

    // Copio los valores de la fila pasada por argumento
    for (int i = 0; i < cols; i++)
        aux.datos[fils][i] = fila.Valor(i);

    // Libero la memoria de la matriz original
    EliminaTodos();

    // Copio los atributos de la matriz auxiliar
    Clona(aux);
}


/***************************************************************************/
// Método para insertar una fila en la matriz. Siendo esta fila de tipo
// Secuencia

void Matriz2D :: InsertaFila (Secuencia & fila, int pos)
{
    // Creo una matriz auxiliar con una fila mas
    Matriz2D aux(fils + 1, cols);

    cout << "MATRIZ AUX INICIALIZADA: ";
    cout << aux.ToString();

    // Copio los valores de la matriz original hasta la posicion pasada por
    // argumento
    for (int i = 0; i < pos; i++)
        for (int j = 0; j < cols; j++)
            aux.datos[i][j] = datos[i][j];


    cout << "MATRIZ AUX MEDIA MITAD COPIADA: ";
    cout << aux.ToString();


    // Copio los valores de la fila pasada por argumento
    for (int i = 0; i < cols; i++)
        aux.datos[pos][i] = fila.Valor(i);

    cout << "MATRIZ AUX COPIADA LA FILA: ";
    cout << aux.ToString();

    // Copio los valores de la matriz original desde la posicion pasada por
    // argumento
    for (int i = pos; i < fils; i++)
        for (int j = 0; j < cols; j++)
            aux.datos[i+1][j] = datos[i][j];

    cout << "MATRIZ AUX COPIADA LA SEGUNDA MITAD: ";
    cout << aux.ToString();


    // Libero la memoria de la matriz original
    EliminaTodos();

    // Copio los atributos de la matriz auxiliar
    Clona(aux);
}

/***************************************************************************/
// Método para eliminar una fila de la matriz

void Matriz2D :: EliminaFila (int num_fila)
{

    bool Continuar = true;
	
	// Compruebo que la matriz no está vacía
	// en cuyo caso no hago nada


	if (EstaVacia())
		Continuar = false;
	
	// Si la matriz no está vacía y tiene más de una fila
	// procedo a eliminar la fila

	if (Continuar && fils > 1){
		memmove(datos[num_fila], datos[num_fila+1],\
				cols*(fils - num_fila-1) *sizeof(TipoBase));

		
		// Almaceno los datos de la matriz a modificar para
		// tener acceso a ellos tras borrarla

		TipoBase * tmp = new TipoBase [fils*cols];
		memcpy(tmp, datos[0], fils*cols*sizeof(TipoBase));

		int fils_tmp = fils - 1;
		int cols_tmp = cols;


		// Elimino la memoria de la matriz y reservo nueva
		// acorde a las nuevas características

		EliminaTodos();

		ReservaMemoria(fils_tmp, cols_tmp);

		// Copio el contenido en la nueva matriz
		
		memcpy(datos[0], tmp, fils*cols*sizeof(TipoBase));

		// Me deshago del vector temporal

		delete [] tmp;
	}

	// Si la matriz tiene una fila
	
	else if (Continuar && fils == 1){
		EliminaTodos();
	}
}


/***************************************************************************/
// Método para eliminar una columna de la matriz

    void Matriz2D :: EliminaColumna(int num_col){

	bool Continuar = true;


	// Compruebo que la matriz no está vacía
	// en cuyo caso no hago nada

	if (EstaVacia())
		Continuar = false;
	
	// Si la matriz no está vacía y tiene más de una columna

	if (Continuar && cols > 1){

		// Creo Matriz auxiliar con los datos necesarios
		Matriz2D tmp(fils, (cols-1));

		// Voy fila por fila copiando los elementos que quiero 
		// saltandome la columna
		for (int i=0; i < fils; i++){
			memcpy(tmp.datos[i], datos[i], num_col*sizeof(TipoBase));
			memcpy(tmp.datos[i]+num_col, datos[i]+num_col+1, \
			      (cols-num_col-1)*sizeof(TipoBase));
		}

		Clona(tmp);

	}

	// Si la matriz tiene una columna

	else if (Continuar && cols == 1){
		EliminaTodos();
	}

}

/***************************************************************************/
// Método SubMatriz

void Matriz2D :: SubMatriz (const Matriz2D & original, int fila_inic, 
                int col_inic, int num_filas, int num_cols){


	// Compruebo que las casillas elegidas son correctas
	// De no serlo, filas o columnas, o ambas estarán a 0
	// y al crear la submatriz, esta estará vacía

	if (fila_inic < 0 || fila_inic >= original.fils)
		num_filas = 0;

	if (col_inic < 0 || col_inic >= original.cols)
		num_cols = 0;


	// Compruebo que el numero de filas y columnas que se me pide
	// es válido o no, y actualizo de acuerdo a ello

	if (num_filas > original.fils-fila_inic)
		num_filas = original.fils-fila_inic;
	
	if (num_cols > original.cols-col_inic)
		num_cols = original.cols-col_inic;

	

	// Una vez que tengo todos los parámetros comprobados
	// creo la nueva matriz


	// "Reinicio" la matriz

	EliminaTodos();

	// La inicializo con los valores calculados
	// incluso si va a quedarse vacía, la dejo inicializada
	// ya que el usuario querrá seguir usándola

    // Si num_filas o num_cols son 0, la matriz se inicializa vacía
    // y no se reserva memoria

    if (num_filas != 0 && num_cols != 0)
        ReservaMemoria(num_filas, num_cols);

    else{
        datos = nullptr;
        fils = 0;
        cols = 0;
    }


	// Comienzo a copiar los valores


	for (int i=0; i<fils; i++){

		memcpy(datos[i], original.datos[i+fila_inic]+col_inic, 
		      (num_cols)*sizeof(TipoBase));

	}


}

/***************************************************************************/
// Sobrecarga del operador ()
// PRE: 0 <= fila < fils && 0 <= col < cols

TipoBase & Matriz2D :: operator () (int fila, int col)
{
    return datos[fila][col];
}

TipoBase & Matriz2D :: operator () (int fila, int col) const
{
    return datos[fila][col];
}

/***************************************************************************/
// Sobrecarga del operador == y !=

bool Matriz2D :: operator == (const Matriz2D & otra)
{

    bool esIgual = true;
    // Compruebo que las matrices tienen el mismo tamaño
    // Si no lo tienen, devuelvo false

    if (fils != otra.fils || cols != otra.cols)
        esIgual = false;

    // Si tienen el mismo tamaño, compruebo que todos los elementos
    // son iguales. Si no lo son, devuelvo false

    for (int i=0; i<fils; i++)
        for (int j=0; j<cols; j++)
            if (datos[i][j] != otra.datos[i][j])
                esIgual = false;

    // Si todos los elementos son iguales, devuelvo true

    return esIgual;
}

bool Matriz2D :: operator != (const Matriz2D & otra)
{
    return !(*this == otra);
}

/***************************************************************************/
// Sobrecarga del operador unario + y -

Matriz2D Matriz2D :: operator + ()
{
    return (*this);
}

Matriz2D Matriz2D :: operator - ()
{
    Matriz2D tmp(fils, cols);

    for (int i=0; i < fils; i++)
        for (int j=0; j < cols; j++)
            tmp(i,j) = -Valor(i,j);

    return tmp;

}

/**************************************************************************/
// Sobrecarga del operador binario + y - (ambos operandos de tipo Matriz2D)

Matriz2D operator + (const Matriz2D & una, const Matriz2D & otra)
{


    Matriz2D tmp(una.NumFilas(), una.NumColumnas());

    if (una.NumFilas() == otra.NumFilas() && \
        una.NumColumnas() == otra.NumColumnas()){

        for (int i=0; i < una.NumFilas(); i++)
            for (int j=0; j < una.NumColumnas(); j++)
                tmp.Valor(i,j) = una.Valor(i,j) + otra.Valor(i,j);

    }

    return tmp;

}

Matriz2D operator - (const Matriz2D & una, const Matriz2D & otra)
{

    Matriz2D tmp;

    tmp = otra;

    return (una + -tmp);

}

/**************************************************************************/
// Sobrecarga del operador binario + y - (uno de los operandos es de tipo
// TipoBase y el otro de tipo TipoBaseMatriz2D)

Matriz2D operator + (const Matriz2D & matriz, const TipoBase valor)
{

    return (matriz + Matriz2D(matriz.NumFilas(), matriz.NumColumnas(),valor));

}

Matriz2D operator - (const Matriz2D & matriz, const TipoBase valor)
{

    return (matriz - Matriz2D(matriz.NumFilas(), matriz.NumColumnas(),valor));

}

Matriz2D operator + (const TipoBase valor, const Matriz2D & matriz)
{

    return (matriz + Matriz2D(matriz.NumFilas(), matriz.NumColumnas(),valor));

}

Matriz2D operator - (const TipoBase valor, const Matriz2D & matriz)
{

    return (Matriz2D(matriz.NumFilas(), matriz.NumColumnas(),valor) - matriz);

}


/***************************************************************************/
// Sobrecarga del operador combinado += y -= (ambos operandos son de tipo
// Matriz2D)

Matriz2D & Matriz2D :: operator +=(const Matriz2D & otra) 
{

    if (fils == otra.fils && cols == otra.cols) {
        for (int i = 0; i < fils; i++) {
            for (int j = 0; j < cols; j++) {
                Valor(i, j) += otra.Valor(i, j);
            }
        }
    }
    return (*this);
}

Matriz2D & Matriz2D :: operator -= (const Matriz2D & otra) 
{

    if (fils == otra.fils && cols == otra.cols) {
        for (int i = 0; i < fils; i++) {
            for (int j = 0; j < cols; j++) {
                Valor(i, j) -= otra.Valor(i, j);
            }
        }
    }
    return (*this);
}
