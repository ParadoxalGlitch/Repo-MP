/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: VectorDepartamento.cpp
//
// Contiene las declaraciones de la clase "VectorDepartamento"
//
/***************************************************************************/


#include <iostream>
#include <string>
#include <cstring>

#include "VectorDepartamento.h"
#include "utils.h"

using namespace std;





/*****************************************************************************/
/*****************************************************************************/
// Constructor sin argumentos

VectorDepartamento::VectorDepartamento()
{
    datos = nullptr;
    usados = 0;
    capacidad = 0;
}

/*****************************************************************************/
/*****************************************************************************/
// Constructor con argumentos

VectorDepartamento::VectorDepartamento(int capacidad)
{
    datos = nullptr;
    reservaMemoria(capacidad);
}

/*****************************************************************************/
/*****************************************************************************/
// Constructor de copia

VectorDepartamento::VectorDepartamento(const VectorDepartamento & otro)
{
    reservaMemoria(otro.capacidad);

    copiaDatos(otro);
    
}

/*****************************************************************************/
/*****************************************************************************/
// Destructor

VectorDepartamento::~VectorDepartamento()
{
    liberaMemoria();

}

/*****************************************************************************/
/*****************************************************************************/
// Método get

int VectorDepartamento::getUsados() const
{
    return usados;
}

int VectorDepartamento::getCapacidad() const
{
    return capacidad;
}

/*****************************************************************************/
/*****************************************************************************/
// Método de consulta sobre estado del vector (vacio o no)

bool VectorDepartamento::estaVacio() const
{
    return (usados == 0);
}

/*****************************************************************************/
/*****************************************************************************/
// Método de reinicio de un vector (lo deja vacio)

void VectorDepartamento::reinicia()
{
    liberaMemoria();
    datos = nullptr;
    usados = 0;
    capacidad = 0;
}

/*****************************************************************************/
/*****************************************************************************/
// Método de inserción de un elemento en el vector en la casilla "pos"

void VectorDepartamento::inserta(const Departamento & nuevo, const int pos)
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

void VectorDepartamento::aniade(const Departamento & nuevo)
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

void VectorDepartamento::elimina(const int pos)
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

void VectorDepartamento::ajusta()
{
    // Creo un vector auxiliar con la capacidad del número de elementos usados
    VectorDepartamento aux(usados);

    // Copio los elementos del vector original al auxiliar
    aux.copiaDatos(*this);

    // Igualo el vector original al auxiliar
    *this = aux;

}

/*****************************************************************************/
/*****************************************************************************/
// Sobrecarga del operador de asignación

VectorDepartamento & VectorDepartamento::operator=(const VectorDepartamento & \
                                                   otro)
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

Departamento & VectorDepartamento::operator[](const int pos)
{
    return datos[pos-1];
}

const Departamento & VectorDepartamento::operator[](const int pos) const
{
    return datos[pos-1];
}

Departamento & VectorDepartamento::operator()(const int pos)
{
    return datos[pos-1];
}

const Departamento & VectorDepartamento::operator()(const int pos) const
{
    return datos[pos-1];
}

/*****************************************************************************/
/*****************************************************************************/
// Método toString

string VectorDepartamento::toString() const
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

void VectorDepartamento::redimensiona()
{
    // Creo un vector auxiliar con el doble de capacidad que el original
    VectorDepartamento aux(capacidad + TAM_BLOQUE);
    
    // Copio los elementos del vector original al auxiliar
    aux.copiaDatos(*this);

    // Igualo el vector original al auxiliar
    *this = aux;

}

/*****************************************************************************/
/*****************************************************************************/
// Método reservaMemoria

void VectorDepartamento::reservaMemoria(const int capacidad)
{

    // Me deshago de la memoria que pudiera tener reservada el vector
    // y los datos que pudiera contener
    liberaMemoria();

    // Reservo memoria para el vector
    datos = new Departamento[capacidad];

    // Actualizo los datos del vector
    this->capacidad = capacidad;
    usados = 0;

}

/*****************************************************************************/
/*****************************************************************************/
// Método liberaMemoria

void VectorDepartamento::liberaMemoria()
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

void VectorDepartamento::copiaDatos(const VectorDepartamento & otro)
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


/***********************************************************************/
// Método para buscar si x departamento ya existe en el vector

bool VectorDepartamento::estaDepartamento (const Departamento & departamento) 
const
{

    bool encontrado = false;
    int i=0;

    while (i < getUsados() && !encontrado){

        if (datos[i].getId() == departamento.getId())
            encontrado = true;

    }

    return (encontrado);

}



/***********************************************************************/
// Sobrecarga del operador + (Vector + Vector)

VectorDepartamento operator + (const VectorDepartamento & uno, const
                                          VectorDepartamento & otro)
{

        // Creo un vector temporal donde guardaré los datos concatenados

        VectorDepartamento tmp(uno);

        // Guardo los datos de otro en tmp

        for (int i = 0; i < otro.getUsados(); i++)
            if (!tmp.estaDepartamento(otro[i+1]))
                tmp.aniade(otro[i+1]);

        // Devuelvo tmp
        return tmp;
        
}

/***********************************************************************/
// Sobrecarga del operador + (Vector + departamento)

VectorDepartamento operator + (const VectorDepartamento & uno, const 
                               Departamento & departamento)
{

    // Creo un vector con el departamento dentro

    VectorDepartamento tmp;
    tmp.aniade(departamento);

    return(uno + tmp);

}



/***********************************************************************/
// Sobrecarga del operador + (departamento + Vector)

VectorDepartamento operator + (const Departamento & departamento,
                               const VectorDepartamento & uno)
{
    // Creo un vector con el departamento dentro

    VectorDepartamento tmp;
    tmp.aniade(departamento);

    return(tmp + uno);

}


/***********************************************************************/
// Sobrecarga del operador - (Vector - Vector)

VectorDepartamento operator - (const VectorDepartamento & uno, const
                                        VectorDepartamento & otro)
{

    //Creo un vector temporal donde guardo los datos de uno

    VectorDepartamento tmp(uno);

    //Elimino los datos que coinciden de tmp

    for (int i=0; i<otro.getUsados(); i++)
        if (tmp.estaDepartamento(otro[i]))
            tmp.elimina(i);

    // Devuelvo tmp

    return (tmp);

}

/***********************************************************************/
// Sobrecarga del operador - (Vector - departamento)

VectorDepartamento operator - (const VectorDepartamento & uno, const
                               Departamento & departamento)
{

    // Creo un vector donde guardo el departamento

    VectorDepartamento tmp;

    return (uno - tmp);

}

/***********************************************************************/
// Sobrecarga del operador - (Vector - string)

VectorDepartamento operator - (const VectorDepartamento & uno, const
                               string & cadena)
{

    // Creo un departamento con la cadena dada establecida como Id_depto

    Departamento dep;
    dep.setId(cadena);

    return (uno - dep);

}

/***********************************************************************/
// Sobrecarga del operador * (Vector * Vector)

VectorDepartamento operator * (const VectorDepartamento & uno, const
                                        VectorDepartamento & otro)
{

    // Creo un departamento temporal donde almacenaré los datos coincidentes

    VectorDepartamento tmp;

    // Busco y almaceno los datos coincidentes en tmp

    for (int i=0; i<otro.getUsados(); i++)
        if (uno.estaDepartamento(otro[i]))
            tmp.aniade(otro[i]);

    return (tmp);

}


/***********************************************************************/
// Sobrecarga del operador binario && (vector && vector)

VectorDepartamento operator && (const VectorDepartamento & uno, const
                                VectorDepartamento & otro)
{
    int i=0;
    bool continuar = true;

    // Compruebo si todos los dep. del segundo vector están en el primero

    while (i < otro.getUsados() && continuar)
        if (!uno.estaDepartamento(otro[i]))
            continuar = false;

    return (continuar);

}


/***********************************************************************/
// Sobrecarga del operador binario && (Vector && departamento)

VectorDepartamento operator && (const VectorDepartamento & uno, const
                                Departamento & departamento)
{

    // Almaceno el departamento en un vector

    VectorDepartamento tmp;
    tmp.aniade(departamento);

    return (uno && tmp);

}

/***********************************************************************/
// Sobrecarga del operador binario && (departamento && Vector)

VectorDepartamento operator && (const Departamento & departamento,
                                const VectorDepartamento & uno)
{
    
    return (uno && departamento);

}


/***********************************************************************/
// Sobrecarga del operador binario && (Vector && string)

VectorDepartamento operator && (const VectorDepartamento & uno, const
                                string & cadena)
{

    Departamento dep;
    dep.setId(cadena);

    return (uno && dep);

}

/***********************************************************************/
// Sobrecarga del operador binario && (string && Vector)

VectorDepartamento operator && (const string & cadena, const
                                VectorDepartamento & uno)
{

    Departamento dep;
    dep.setId(cadena);

    return (uno && dep);

}

/***********************************************************************/
// Sobrecarga del operador += (vector += vector)

VectorDepartamento operator += (const VectorDepartamento & uno, const
                                VectorDepartamento & otro)
{

    VectorDepartamento tmp1(uno);
    VectorDepartamento tmp2(otro);

    return (tmp1 + tmp2);

}

/***********************************************************************/
// Sobrecarga del operador += (vector += departamento)

VectorDepartamento operator += (const VectorDepartamento & uno, const
                                Departamento & departamento)
{

    VectorDepartamento tmp(uno);

    return (tmp + departamento);

}

/***********************************************************************/
// Sobrecarga del operador -= (vector -= vector)

VectorDepartamento operator -= (const VectorDepartamento & uno, const
                                VectorDepartamento & otro)
{

    VectorDepartamento tmp1(uno);
    VectorDepartamento tmp2(otro);

    return (tmp1 - tmp2);

}

/***********************************************************************/
// Sobrecarga del operador -= (vector -= departamento)

VectorDepartamento operator -= (const VectorDepartamento & uno, const
                                Departamento & departamento)
{

    VectorDepartamento tmp(uno);

    return (tmp - departamento);

}


/***********************************************************************/
// Sobrecarga del operador -= (vector -= string)

VectorDepartamento operator -= (const VectorDepartamento & uno, const
                                string & cadena)
{

    VectorDepartamento tmp(uno);

    Departamento dep;
    dep.setId(cadena);

    return (tmp - dep);

}