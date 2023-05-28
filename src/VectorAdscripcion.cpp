/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: VectorAdscripcion.cpp
//
// Contiene las declaraciones de la clase "VectorAdscripcion"
//
/***************************************************************************/


#include <iostream>
#include <string>
#include <cstring>

#include "VectorAdscripcion.h"
#include "utils.h"

using namespace std;





/*****************************************************************************/
/*****************************************************************************/
// Constructor sin argumentos

VectorAdscripcion::VectorAdscripcion()
{
    datos = nullptr;
    usados = 0;
    capacidad = 0;
}

/*****************************************************************************/
/*****************************************************************************/
// Constructor con argumentos

VectorAdscripcion::VectorAdscripcion(int capacidad)
{
    datos = nullptr;
    reservaMemoria(capacidad);
}

/*****************************************************************************/
/*****************************************************************************/
// Constructor con argumentos

VectorAdscripcion :: VectorAdscripcion(const string & nombre)
{

    datos = nullptr;
    usados = 0;
    capacidad = 0;

    RecuperarVectorAdscripcion(nombre);

}

/*****************************************************************************/
/*****************************************************************************/
// Constructor de copia

VectorAdscripcion::VectorAdscripcion(const VectorAdscripcion & otro)
{

    datos = nullptr;

    reservaMemoria(otro.capacidad);

    copiaDatos(otro);
    
}

/*****************************************************************************/
/*****************************************************************************/
// Destructor

VectorAdscripcion::~VectorAdscripcion()
{
    liberaMemoria();

}

/*****************************************************************************/
/*****************************************************************************/
// Método get

int VectorAdscripcion::getUsados() const
{
    return usados;
}

int VectorAdscripcion::getCapacidad() const
{
    return capacidad;
}

/*****************************************************************************/
/*****************************************************************************/
// Método de consulta sobre estado del vector (vacio o no)

bool VectorAdscripcion::estaVacio() const
{
    return (usados == 0);
}

/*****************************************************************************/
/*****************************************************************************/
// Método de reinicio de un vector (lo deja vacio)

void VectorAdscripcion::reinicia()
{
    liberaMemoria();
    datos = nullptr;
    usados = 0;
    capacidad = 0;
}

/*****************************************************************************/
/*****************************************************************************/
// Método de inserción de un elemento en el vector en la casilla "pos"

void VectorAdscripcion::inserta(const Adscripcion & nuevo, const int pos)
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

    datos[pos] = nuevo;
    usados++;

}


/*****************************************************************************/
/*****************************************************************************/
// Método aniade

void VectorAdscripcion::aniade(const Adscripcion & nuevo)
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

void VectorAdscripcion::elimina(const int pos)
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

void VectorAdscripcion::ajusta()
{
    // Creo un vector auxiliar con la capacidad del número de elementos usados
    VectorAdscripcion aux(usados);

    // Copio los elementos del vector original al auxiliar
    aux.copiaDatos(*this);

    // Igualo el vector original al auxiliar
    *this = aux;

}

/*****************************************************************************/
/*****************************************************************************/
// Sobrecarga del operador de asignación

VectorAdscripcion & VectorAdscripcion::operator=(const VectorAdscripcion & otro)
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

Adscripcion & VectorAdscripcion::operator[](const int pos)
{
    return datos[pos-1];
}

const Adscripcion & VectorAdscripcion::operator[](const int pos) const
{
    return datos[pos-1];
}

Adscripcion & VectorAdscripcion::operator()(const int pos)
{
    return datos[pos-1];
}

const Adscripcion & VectorAdscripcion::operator()(const int pos) const
{
    return datos[pos-1];
}

/*****************************************************************************/
/*****************************************************************************/
// Método toString

string VectorAdscripcion::toString() const
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

void VectorAdscripcion::redimensiona()
{
    // Creo un vector auxiliar con el doble de capacidad que el original
    VectorAdscripcion aux(capacidad + TAM_BLOQUE);

    // Copio los elementos del vector original al auxiliar
    aux.copiaDatos(*this);

    // Igualo el vector original al auxiliar
    *this = aux;

}

/*****************************************************************************/
/*****************************************************************************/
// Método reservaMemoria

void VectorAdscripcion::reservaMemoria(const int capacidad)
{

    // Me deshago de la memoria que pudiera tener reservada el vector
    // y los datos que pudiera contener
    liberaMemoria();

    // Reservo memoria para el vector
    datos = new Adscripcion[capacidad];

    // Actualizo los datos del vector
    this->capacidad = capacidad;
    usados = 0;

}

/*****************************************************************************/
/*****************************************************************************/
// Método liberaMemoria

void VectorAdscripcion::liberaMemoria()
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

void VectorAdscripcion::copiaDatos(const VectorAdscripcion & otro)
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
// Método para buscar si x adscripcion ya existe en el vector

bool VectorAdscripcion::estaAdscripcion (const Adscripcion & adscripcion) 
const
{

    bool encontrado = false;
    int i=0;

    while (i < getUsados() && !encontrado){
        if (datos[i].getDni() == adscripcion.getDni())
            encontrado = true;

        i++;
    }

    return (encontrado);

}


/***********************************************************************/
// Sobrecarga del operador + (Vector + Vector)

VectorAdscripcion operator + (const VectorAdscripcion & uno, const
                              VectorAdscripcion & otro)
{

    // Creo un vector temporal donde guardaré los datos concatenados

    VectorAdscripcion tmp(uno);

    // Guardo los datos de otro en tmp

    for (int i = 0; i < otro.getUsados(); i++)
        if (!tmp.estaAdscripcion(otro[i+1]))
            tmp.aniade(otro[i+1]);

    // Devuelvo tmp
    return tmp;

}

/***********************************************************************/
// Sobrecarga del operador + (Vector + adscripcion)

VectorAdscripcion operator + (const VectorAdscripcion & uno, const
                              Adscripcion & adscripcion)
{

    // Creo un vector con el departamento dentro

    VectorAdscripcion tmp;
    tmp.aniade(adscripcion);

    return(uno + tmp);
   
}

/***********************************************************************/
// Sobrecarga del operador + (adscripcion + Vector)

VectorAdscripcion operator + (const Adscripcion & adscripcion,
                              const VectorAdscripcion & uno)
{
    // Creo un vector con el departamento dentro

    VectorAdscripcion tmp;
    tmp.aniade(adscripcion);

    return(tmp + uno);
   
}

/***********************************************************************/
// Sobrecarga del operador += (vector += vector)

VectorAdscripcion VectorAdscripcion :: operator += 
                                        (const VectorAdscripcion & otro)
{

    for (int i=0; i<otro.getUsados(); i++)
        if (!estaAdscripcion(otro[i+1]))
            aniade(otro[i+1]);

    return (*this);

}

/***********************************************************************/
// Sobrecarga del operador += (vector += departamento)

VectorAdscripcion VectorAdscripcion :: operator += 
                                         (const Adscripcion & adscripcion)
{

    VectorAdscripcion tmp;
    tmp.aniade(adscripcion);

    

    return (*this += tmp);

}

/***********************************************************************/
// Función de escritura de un vector en un fichero

void VectorAdscripcion :: GuardarVectorAdscripcion(const string & nombre) 
const
{

    if (datos != 0){

        // Abro el archivo

        ofstream fo;
        fo.open(nombre);

        if (!fo)
        {

            cerr << "No se ha podido abrir el fichero " << nombre;
            exit(1);

        }

        // Guardo los datos

        fo << *this;

        // Cierro el archivo

        fo.close();

    }
    
}

/***********************************************************************/
// Función de lectura de un vector de un fichero    

void VectorAdscripcion :: RecuperarVectorAdscripcion 
                            (const string & nombre)
{

    // Primero abro el fichero

    ifstream fi;
    fi.open(nombre);

    if (!fi){

        cerr << "No se ha podido abrir el fichero " << nombre << endl;
        exit(1);

    }

    fi >> *this;

    // En este punto el vector ya debería estar relleno
    // asi que cierro el fichero

    fi.close();


}


/***********************************************************************/
// Operadores >> y <<

ofstream & operator << (ofstream & fo, const VectorAdscripcion & vector)
{
    if (vector.datos != nullptr){

        // Escribo la cabecera

        fo << "ADSCRIPCIONES" << endl;

        // Escribo un comentario explicativo

        fo << "# Colección de adscripciones" << endl;

        // Voy escribiendo el contenido del vector en el fichero

        for (int i=0; i<vector.getUsados(); i++){


            fo << vector.datos[i] << endl;


        }

    }

    return fo;

}

ifstream & operator >> (ifstream & fi, VectorAdscripcion & vector)
{
    // Reinicio el Vector

    vector.reinicia();

    // Compruebo que la cabecera es correcta

    string linea;

    getline(fi,linea);


    if (linea == "ADSCRIPCIONES"){

        // Leo lineas hasta que no queden mas

        getline(fi,linea); // Lectura adelantada
        Adscripcion aux;

        while (!fi.eof()){

            while (linea.at(0) == '#'){
                getline(fi,linea);
            }
               

            if (!fi.eof()){

                Adscripcion aux(linea);

                vector.aniade(aux);


            }

            getline(fi,linea);

        }

    }

    return fi;
}
