/***************************************************************************/
// David Pérez Tobarra
//
// Pruebas sobre el tipo Matriz2D
//
// Fichero: II_Demo-BasicoMatriz2D.cpp 
//
/***************************************************************************/

#include <iostream>

#include "Matriz2D.h"
#include "TipoBase.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	// .....................................................................
	// Creación de matrices vacias  

	Matriz2D vacia1;

	cout << endl;	
	cout << "Se ha creado una matriz \"()\" de dimensiones: " 
	     << vacia1.NumFilas() << " x " << vacia1.NumColumnas() << endl;
	cout << "Vacia = " << (vacia1.EstaVacia() ? "SI": "NO") << endl;	
	cout << endl;	

	Matriz2D vacia2(-1, 3);

	cout << "Se ha creado una matriz \"(-1, 3)\" de dimensiones: " 
	     << vacia2.NumFilas() << " x " << vacia2.NumColumnas() << endl;
	cout << "Vacia = " << (vacia2.EstaVacia() ? "SI": "NO") << endl;	
	cout << endl;	

	Matriz2D vacia3(1, -3);

	cout << "Se ha creado una matriz \"(1, -3)\" de dimensiones: " 
	     << vacia3.NumFilas() << " x " << vacia3.NumColumnas() << endl;
	cout << "Vacia = " << (vacia3.EstaVacia() ? "SI": "NO") << endl;	
	cout << endl;	


	// .....................................................................
	// Creación de una matriz (todas las casillas a cero) y mostrala 

	Matriz2D m0(3, 5);

	cout << "Se ha creado la matriz m0 \"(3,5)\" de dimensiones: " 
	     << m0.NumFilas() << " x " << m0.NumColumnas() << endl;
	cout << "Vacia = " << (m0.EstaVacia() ? "SI": "NO") << endl;	
	cout << endl;	

	cout << "Matriz m0 -con todos 0-: ";
	cout << m0.ToString();


	// .....................................................................
	// Creación de una matriz (todas las casillas a 9) 

	Matriz2D m9(4, 7, 9);

	cout << "Se ha creado la matriz m9 \"(4,7,9)\" de dimensiones: " 
	     << m9.NumFilas() << " x " << m9.NumColumnas() << endl;
	cout << "Vacia = " << (m9.EstaVacia() ? "SI": "NO") << endl;	
	cout << endl;	

	cout << "Matriz m9 -con todos 9-: ";
	cout << m9.ToString();

	cout << "Iguales m0 y m9 = " << (m0.EsIgualA(m9) ? "SI": "NO") << endl;	


	// .....................................................................
	// Submatriz  

	cout << endl;	
	cout << "================================================" << endl;
	cout << endl;	

	Matriz2D grande(5, 5);

	for (int f=0; f<grande.NumFilas(); f++) 
		for (int c=0; c<grande.NumColumnas(); c++) 
			grande.Valor(f, c) = ((10*(f+1))+c+1);
		
	cout << "Matriz \"grande\": ";
	cout << grande.ToString();

	Matriz2D sub;


	// Copia exacta 

	cout << "Creando submatriz de \"grande\" desde (0, 0) y con " 
	     << grande.NumFilas() << " filas y " 
	     << grande.NumColumnas()<< " cols" << endl; 
	
	sub.SubMatriz(grande, 0, 0, grande.NumFilas(), grande.NumColumnas());

	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << sub.NumFilas() << " x " << sub.NumColumnas() << endl;
	cout << "Matriz \"sub\": ";
	cout << sub.ToString();


	// Posición inicial incorrecta

	cout << "Creando submatriz 2x3 de \"grande\" desde (-2, 2)" << endl; 
	
	sub.SubMatriz(grande, -2, 2, 2, 3);

	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << sub.NumFilas() << " x " << sub.NumColumnas() << endl;
	cout << "Vacia = " << (sub.EstaVacia() ? "SI": "NO") << endl;	
	cout << "Matriz \"sub\": ";
	cout << sub.ToString();


	cout << "Creando submatriz 2x3 de \"grande\" desde (2, -2)" << endl; 
	
	sub.SubMatriz(grande, 2, -2, 2, 3);

	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << sub.NumFilas() << " x " << sub.NumColumnas() << endl;
	cout << "Vacia = " << (sub.EstaVacia() ? "SI": "NO") << endl;	
	cout << "Matriz \"sub\": ";
	cout << sub.ToString();


	cout << "Creando submatriz 2x3 de \"grande\" desde (-3, -3)" << endl; 
	
	sub.SubMatriz(grande, -3, -3, 2, 3);

	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << sub.NumFilas() << " x " << sub.NumColumnas() << endl;
	cout << "Vacia = " << (sub.EstaVacia() ? "SI": "NO") << endl;	
	cout << "Matriz \"sub\": ";
	cout << sub.ToString();


	// Exceso de filas

	cout << "Creando submatriz de \"grande\" desde (0, 0) y con " 
	     << grande.NumFilas()+5 << " filas y " 
	     << grande.NumColumnas()<< " cols" << endl; 
	
	sub.SubMatriz(grande, 0, 0, grande.NumFilas()+5, grande.NumColumnas());

	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << sub.NumFilas() << " x " << sub.NumColumnas() << endl;
	cout << "Matriz \"sub\": ";
	cout << sub.ToString();


	// Demasiado grande desde (0,0) 

	// Exceso de filas

	cout << "Creando submatriz de \"grande\" desde (0, 0) y con " 
	     << grande.NumFilas()+5 << " filas y " 
	     << grande.NumColumnas()<< " cols" << endl; 
	
	sub.SubMatriz(grande, 0, 0, grande.NumFilas()+5, grande.NumColumnas());

	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << sub.NumFilas() << " x " << sub.NumColumnas() << endl;
	cout << "Matriz \"sub\": ";
	cout << sub.ToString();

	// Exceso de columnas
	
	cout << "Creando submatriz de \"grande\" desde (0, 0) y con " 
	     << grande.NumFilas() << " filas y " 
	     << grande.NumColumnas()+5<< " cols" << endl; 
	
	sub.SubMatriz(grande, 0, 0, grande.NumFilas(), grande.NumColumnas()+5);

	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << sub.NumFilas() << " x " << sub.NumColumnas() << endl;
	cout << "Matriz \"sub\": ";
	cout << sub.ToString();

	// Exceso de filas y columnas

	cout << "Creando submatriz de \"grande\" desde (0, 0) y con " 
	     << grande.NumFilas()+5 << " filas y " 
	     << grande.NumColumnas()+5<< " cols" << endl; 
	
	sub.SubMatriz(grande, 0, 0, grande.NumFilas()+5, grande.NumColumnas()+5);

	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << sub.NumFilas() << " x " << sub.NumColumnas() << endl;
	cout << "Matriz \"sub\": ";
	cout << sub.ToString();


	// Submatriz contenida desde (1,1) y tamaño 2x3

	cout << "Creando submatriz 2x3 de \"grande\" desde (1, 1)" << endl; 
	
	sub.SubMatriz(grande, 1, 1, 2, 3);

	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << sub.NumFilas() << " x " << sub.NumColumnas() << endl;
	cout << "Matriz \"sub\": ";
	cout << sub.ToString();


	// Demasiado grande desde (2,2) 

	cout << "Creando submatriz de \"grande\" desde (2, 2) y con " 
	     << grande.NumFilas()+5 << " filas y " 
	     << grande.NumColumnas()+5<< " cols" << endl; 
	
	sub.SubMatriz(grande, 2, 2, grande.NumFilas()+5, grande.NumColumnas()+5);

	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << sub.NumFilas() << " x " << sub.NumColumnas() << endl;
	cout << "Matriz \"sub\": ";
	cout << sub.ToString();


	sub.EliminaTodos();
	grande.EliminaTodos();


	// .....................................................................
	// Lectura de las dimensiones de la matriz

	cout << endl;	
	cout << "================================================" << endl;
	cout << endl;	

	int num_filas, num_cols; 

	do  {
		cout << endl;
		cout << "Introduzca num. filas de la matriz: ";
		cin >> num_filas; 
	} while (num_filas <= 0);	

	do  {
		cout << endl;
		cout << "Introduzca num. columnas de la matriz: ";
		cin >> num_cols; 
	} while (num_cols <= 0);	

	cout << endl << endl;

	// .....................................................................
	// Creación de una matriz y rellenar sus casillas, clones y eliminación 
	// de filas y columnas  

	Matriz2D m(num_filas, num_cols);

	// Consultar num. de filas y columnas

	cout << "Se ha creado una matriz \"m\" de dimensiones: " 
	     << m.NumFilas() << " x " << m.NumColumnas() << endl;
	cout << "Vacia = " << (m.EstaVacia() ? "SI": "NO") << endl;	
	cout << endl;	

	for (int f=0; f<m.NumFilas(); f++) 
		for (int c=0; c<m.NumColumnas(); c++) 
			m.Valor(f, c) = ((10*(f+1))+c+1);
		
	cout << "Matriz rellena: ";
	cout << m.ToString();

	// Clonar la matriz "m" en "clon_m"

	Matriz2D clon_m;

	clon_m.Clona(m);

	cout << "Se ha clonado la matriz \"m\" en \"clon_m\": " 
	     << clon_m.NumFilas() << " x " << clon_m.NumColumnas() << endl;
	cout << "Vacia = " << (clon_m.EstaVacia() ? "SI": "NO") << endl;	
	cout << "Iguales = " << (clon_m.EsIgualA(m) ? "SI": "NO") << endl;	
	cout << endl;	
		
	cout << "Matriz \"clon_m\": ";
	cout << clon_m.ToString();


	// Ecualizar matriz m

	m.Ecualiza(99);

	cout << "Matriz ecualizada a 99: ";
	cout << m.ToString();

	// Volver a clonar la matriz "m" en "clon_m"

	clon_m.Clona(m);

	cout << "Se ha vuelto a clonar la matriz \"m\" en \"clon_m\": " 
	     << clon_m.NumFilas() << " x " << clon_m.NumColumnas() << endl;
	cout << "Vacia = " << (clon_m.EstaVacia() ? "SI": "NO") << endl;	
	cout << endl;	
		
	cout << "Matriz \"clon_m\": ";
	cout << clon_m.ToString();


	// Modificar la diagonal principal de "m" (Escribir un 0) y guardar 
	// una copia (clon) en "diagonal" y "otra_diagonal"

	int min_filas_cols = (m.NumFilas() < m.NumColumnas()) ? 
		                  m.NumFilas() : m.NumColumnas(); 
		                  
	for (int d=0; d<min_filas_cols; d++) 
			m.Valor(d, d) = 0;

	cout << "Matriz \"m\" con diagonal a 0: ";
	cout << m.ToString();

	Matriz2D diagonal;
	diagonal.Clona(m);

	Matriz2D otra_diagonal;
	otra_diagonal.Clona(m);


	// Eliminar fila 0

	m.EliminaFila(0);

	cout << "Eliminada fila 0 de \"m\": " 
	     << m.NumFilas() << " x " << m.NumColumnas() << endl;
	cout << "Vacia = " << (m.EstaVacia() ? "SI": "NO") << endl;	
	cout << endl;	
		
	cout << "Matriz \"m\": ";
	cout << m.ToString();

	// Eliminar filas hasta dejar la matriz vacía. 
	// Basta con ir borrando la fila 0 repetidamente

	while (!m.EstaVacia()) {

		m.EliminaFila(0);

		cout << "Eliminada fila 0 de \"m\": " 
		     << m.NumFilas() << " x " << m.NumColumnas() << endl;
		cout << "Vacia = " << (m.EstaVacia() ? "SI": "NO") << endl;	
		cout << endl;	
			
		cout << "Matriz \"m\": ";
		cout << m.ToString();
	}


	// Eliminar columnas hasta dejar la matriz "diagonal" vacía. 
	// Basta con ir borrando la columna 0 repetidamente

	cout << "Matriz \"diagonal\". Vamos a borrar columna a columna: ";
	cout << diagonal.ToString();

	while (!diagonal.EstaVacia()) {

		diagonal.EliminaColumna (diagonal.NumColumnas()-1);

		cout << "Eliminada ultima columna de \"diagonal\": " 
		     << diagonal.NumFilas() << " x " << diagonal.NumColumnas() << endl;
		cout << "Vacia = " << (diagonal.EstaVacia() ? "SI": "NO") << endl;	
		cout << endl;	

		cout << "Matriz \"diagonal\": ";
		cout << diagonal.ToString();
	}

	// Prueba del operador de asignación
	Matriz2D matriz1 (5,5,9);
	Matriz2D matriz2;


	matriz2 = matriz1;

	cout << "Matriz 1: " << endl << matriz1.ToString();
	cout << "Matriz 2: " << endl << matriz2.ToString();

	matriz1.Valor(0,0) = 0;
	matriz1.Valor(0,1) = 1;
	matriz1.Valor(0,2) = 2;
	matriz1.Valor(0,3) = 3;
	matriz1.Valor(0,4) = 4;
	matriz1.Valor(1,0) = 1;
	matriz1.Valor(2,0) = 2;
	matriz1.Valor(3,0) = 3;
	matriz1.Valor(4,0) = 4;



	cout << "Matriz 1: " << endl << matriz1.ToString();
	cout << "Matriz 2: " << endl << matriz2.ToString();

	// Pruebas de la clase Secuencia


	Secuencia secuencia1;
	Secuencia secuencia2;

	secuencia1 = matriz1.Fila(0);
	cout << secuencia1.ToString();

	secuencia2 = matriz1.Columna(0);
	cout << secuencia2.ToString();

	matriz1.AniadeFila(secuencia2);
	cout << matriz1.ToString();

	matriz1.InsertaFila(secuencia2, 2);
	cout << matriz1.ToString();



	// pruebas de los operadores () y == y !=

	Matriz2D matriz3;

	matriz3 = matriz1;

	cout << "Matriz 3: " << endl << matriz3.ToString();





	cout << "Es matriz 3 igual a matriz 1?:" << endl;

	if (matriz3 == matriz1) 
		cout << "SI" << endl;
	else
		cout << "NO" << endl;

	cout << "Es matriz 3 distinta a matriz 1?:" << endl;

	if (matriz3 != matriz1) 
		cout << "SI" << endl << endl;
	else
		cout << "NO" << endl << endl;



	matriz3(0,0) = 99;
	cout << matriz3(0,0) << " es el valor que he editado en matriz3" << endl;
	cout << endl;

	cout << "Es matriz 3 igual a matriz 1?:" << endl;

	if (matriz3 == matriz1) 
		cout << "SI" << endl;
	else
		cout << "NO" << endl;

	cout << "Es matriz 3 distinta a matriz 1?:" << endl;

	if (matriz3 != matriz1) 
		cout << "SI" << endl << endl;
	else
		cout << "NO" << endl << endl;




	// PRUEBAS OPERADORES + - += Y -=


	Matriz2D todo9 (5,5,9);

	Matriz2D todo5 (5,5,5);

	Matriz2D prueba1 (5);
	Matriz2D prueba2 (5);


	//prueba operador + y - unario

	cout << "Matriz todo9: " << endl;
	cout << todo9.ToString();

	todo9 = +todo9;

	cout << "Matriz todo9 positiva: " << endl;
	cout << todo9.ToString();

	cout << "Matriz todo5: " << endl;
	cout << todo5.ToString();
	
	todo5 = -todo5;

	cout << "Matriz todo5 negativa: " << endl;
	cout << todo5.ToString();

	todo5 = -todo5;

	cout << "Matriz todo5 normal de nuevo: " << endl;
	cout << todo5.ToString();

	//prueba operador + y - binario

	prueba1 = todo9 + todo5;

	cout << "Matriz todo9 + matriz todo5: " << endl;
	cout << prueba1.ToString();

	prueba2 = todo5 - todo9;

	cout << "Matriz todo5 - matriz todo9: " << endl;
	cout << prueba2.ToString();

	prueba2 = prueba2 + 5;

	cout << "Matriz prueba2 (todo5-todo9) + 5: " << endl;
	cout << prueba2.ToString();

	prueba1 = prueba1 - 4;

	cout << "Matriz prueba1 (todo9+todo5) - 4 :" << endl;
	cout << prueba1.ToString();

	//prueba operador += y -=

	cout << "Matriz prueba1: " << endl;
	cout << prueba1.ToString();


	cout << "Matriz prueba2: " << endl;
	cout << prueba2.ToString();

	prueba1 += prueba2;

	cout << "Matriz prueba1 (prueba1 += prueba2): " << endl;
	cout << prueba1.ToString();

	prueba1 -= prueba2;

	cout << "Matriz prueba1 (prueba1 -= prueba2): " << endl;
	cout << prueba1.ToString();

	

	return 0; 
}

/***************************************************************************/
/***************************************************************************/
