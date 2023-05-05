/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: VectorProfesor.cpp
//
// Contiene las declaraciones de la clase "VectorProfesor"
//
/***************************************************************************/


#include <iostream>
#include <string>
#include <cstring>

#include "VectorProfesor.h"
#include "utils.h"


using namespace std;





/*****************************************************************************/
/*****************************************************************************/
// Constructor sin argumentos

VectorProfesor::VectorProfesor()
{
    datos = nullptr;
    usados = 0;
    capacidad = 0;
}

/*****************************************************************************/
/*****************************************************************************/
// Constructor con argumentos

VectorProfesor::VectorProfesor(int capacidad)
{
    datos = nullptr;
    reservaMemoria(capacidad);
}

/*****************************************************************************/
/*****************************************************************************/
// Constructor de copia

VectorProfesor::VectorProfesor(const VectorProfesor & otro)
{
    reservaMemoria(otro.capacidad);

    copiaDatos(otro);
    
}

/*****************************************************************************/
/*****************************************************************************/
// Destructor

VectorProfesor::~VectorProfesor()
{
    liberaMemoria();

}

/*****************************************************************************/
/*****************************************************************************/
// Método get

int VectorProfesor::getUsados() const
{
    return usados;
}

int VectorProfesor::getCapacidad() const
{
    return capacidad;
}

/*****************************************************************************/
/*****************************************************************************/
// Método de consulta sobre estado del vector (vacio o no)

bool VectorProfesor::estaVacio() const
{
    return (usados == 0);
}

/*****************************************************************************/
/*****************************************************************************/
// Método de reinicio de un vector (lo deja vacio)

void VectorProfesor::reinicia()
{
    liberaMemoria();
    datos = nullptr;
    usados = 0;
    capacidad = 0;
}

/*****************************************************************************/
/*****************************************************************************/
// Método de inserción de un elemento en el vector en la casilla "pos"

void VectorProfesor::inserta(const Profesor & nuevo, const int pos)
{

    // Compruebo que haya espacio para insertar el nuevo elemento
    // De no haberlo, hago espacio para el nuevo elemento

    if (usados == capacidad)
    {
        redimensiona();
    }


    // Copio los elementos a partir de la posición "pos" una posición a la 
    // derecha
    for (int i = usados; i > pos-1; i--)
    {
        datos[i] = datos[i - 1];
    }

    // Inserto el nuevo elemento en la posición "pos" y actualizo
    // el número de elementos usados

    datos[pos-1] = nuevo;
    usados++;

}


/*****************************************************************************/
/*****************************************************************************/
// Método aniade

void VectorProfesor::aniade(const Profesor & nuevo)
{
    // Compruebo que haya espacio para insertar el nuevo elemento
    // De no haberlo, hago espacio para el nuevo elemento

    if (usados == capacidad)
    {
        redimensiona();
    }
    // Inserto el nuevo elemento en la posición "usados" y actualizo
    // el número de elementos usados
    datos[usados] = nuevo;
    usados++;

}   


/*****************************************************************************/
/*****************************************************************************/
// Método de eliminación de un elemento del vector

void VectorProfesor::elimina(const int pos)
{

    // Copio los elementos a partir de la posición "pos" una posición a la 
    // izquierda
    for (int i = pos-1; i < usados - 1; i++)
    {
        datos[i] = datos[i + 1];
    }

    // Actualizo el número de elementos usados
    usados--;

}

/*****************************************************************************/
/*****************************************************************************/
// Método para ajustar la capacidad del vector al número de elementos usados

void VectorProfesor::ajusta()
{
    // Creo un vector auxiliar con la capacidad del número de elementos usados
    VectorProfesor aux(usados);

    // Copio los elementos del vector original al auxiliar
    aux.copiaDatos(*this);

    // Igualo el vector original al auxiliar
    *this = aux;

}

/*****************************************************************************/
/*****************************************************************************/
// Sobrecarga del operador de asignación

VectorProfesor & VectorProfesor::operator=(const VectorProfesor & otro)
{
    if (this != &otro)
    {
        liberaMemoria();
        reservaMemoria(otro.capacidad);
        copiaDatos(otro);
    }

    return *this;
}


/*****************************************************************************/
/*****************************************************************************/
// Sobre carga del operador de acceso a un elemento del vector

Profesor & VectorProfesor::operator[](const int pos)
{
    return datos[pos-1];
}

const Profesor & VectorProfesor::operator[](const int pos) const
{
    return datos[pos-1];
}

Profesor & VectorProfesor::operator()(const int pos)
{
    return datos[pos-1];
}

const Profesor & VectorProfesor::operator()(const int pos) const
{
    return datos[pos-1];
}

/*****************************************************************************/
/*****************************************************************************/
// Método toString

string VectorProfesor::toString() const
{
    string cadena;

    cadena += "Capacidad: " + to_string(capacidad) + " Usados: " + \
               to_string(usados) + "\n";    

    for (int i = 0; i < usados; i++)
    {
        cadena += datos[i].ToString() + "\n";
    }

    return cadena;
}

/*****************************************************************************/
/*****************************************************************************/
// Método redimensiona

void VectorProfesor::redimensiona()
{
    // Creo un vector auxiliar con el doble de capacidad que el original
    VectorProfesor aux(capacidad + TAM_BLOQUE);

    // Copio los elementos del vector original al auxiliar
    aux.copiaDatos(*this);
 
    // Igualo el vector original al auxiliar
    *this = aux;

}

/*****************************************************************************/
/*****************************************************************************/
// Método reservaMemoria

void VectorProfesor::reservaMemoria(const int capacidad)
{

    // Me deshago de la memoria que pudiera tener reservada el vector
    // y los datos que pudiera contener
    liberaMemoria();

    // Reservo memoria para el vector
    datos = new Profesor[capacidad];

    // Actualizo los datos del vector
    this->capacidad = capacidad;
    usados = 0;

}

/*****************************************************************************/
/*****************************************************************************/
// Método liberaMemoria

void VectorProfesor::liberaMemoria()
{
    if (datos != nullptr)
    {
        delete[] datos;
        datos = nullptr;
    }

    usados = 0;
    capacidad = 0;
}

/*****************************************************************************/
/*****************************************************************************/
// Método copiaDatos. SOlo copiará si hay espacio suficiente en el vector 
// destino

void VectorProfesor::copiaDatos(const VectorProfesor & otro)
{

    // Redimensiono el vector actual hasta que tenga suficiente capacidad
    while (capacidad < otro.usados)
    {
        redimensiona();
    }
    
    // Copio los datos de otro
    for (int i = 0; i < otro.usados; i++)
    {
        datos[i] = otro.datos[i];
    }
    
    usados = otro.usados; // Actualizo el número de elementos usados
}



