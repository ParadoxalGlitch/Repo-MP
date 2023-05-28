/***************************************************************************/
//
// David Pérez Tobarra
//
// Fichero: VectorEncargo.cpp
//
// Contiene las declaraciones de la clase "VectorEncargo"
//
/***************************************************************************/


#include <iostream>
#include <string>
#include <cstring>

#include "VectorEncargo.h"
#include "utils.h"

using namespace std;





/*****************************************************************************/
/*****************************************************************************/
// Constructor sin argumentos

VectorEncargo::VectorEncargo()
{
    datos = nullptr;
    usados = 0;
    capacidad = 0;
}

/*****************************************************************************/
/*****************************************************************************/
// Constructor con argumentos

VectorEncargo::VectorEncargo(int capacidad)
{
    datos = nullptr;
    reservaMemoria(capacidad);
}

/*****************************************************************************/
/*****************************************************************************/
// Constructor con argumentos

VectorEncargo :: VectorEncargo(const string & nombre)
{

    datos = nullptr;
    usados = 0;
    capacidad = 0;

    RecuperarVectorEncargo(nombre);

}

/*****************************************************************************/
/*****************************************************************************/
// Constructor de copia

VectorEncargo::VectorEncargo(const VectorEncargo & otro)
{

    datos = nullptr;

    reservaMemoria(otro.capacidad);

    copiaDatos(otro);
    
}

/*****************************************************************************/
/*****************************************************************************/
// Destructor

VectorEncargo::~VectorEncargo()
{
    liberaMemoria();

}

/*****************************************************************************/
/*****************************************************************************/
// Método get

int VectorEncargo::getUsados() const
{
    return usados;
}

int VectorEncargo::getCapacidad() const
{
    return capacidad;
}

/*****************************************************************************/
/*****************************************************************************/
// Método de consulta sobre estado del vector (vacio o no)

bool VectorEncargo::estaVacio() const
{
    return (usados == 0);
}

/*****************************************************************************/
/*****************************************************************************/
// Método de reinicio de un vector (lo deja vacio)

void VectorEncargo::reinicia()
{
    liberaMemoria();
    datos = nullptr;
    usados = 0;
    capacidad = 0;
}

/*****************************************************************************/
/*****************************************************************************/
// Método de inserción de un elemento en el vector en la casilla "pos"

void VectorEncargo::inserta(const Encargo & nuevo, const int pos)
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

void VectorEncargo::aniade(const Encargo & nuevo)
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

void VectorEncargo::elimina(const int pos)
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

void VectorEncargo::ajusta()
{
    // Creo un vector auxiliar con la capacidad del número de elementos usados
    VectorEncargo aux(usados);

    // Copio los elementos del vector original al auxiliar
    aux.copiaDatos(*this);

    // Igualo el vector original al auxiliar
    *this = aux;

}

/*****************************************************************************/
/*****************************************************************************/
// Sobrecarga del operador de asignación

VectorEncargo & VectorEncargo::operator=(const VectorEncargo & otro)
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

Encargo & VectorEncargo::operator[](const int pos)
{
    return datos[pos-1];
}

const Encargo & VectorEncargo::operator[](const int pos) const
{
    return datos[pos-1];
}

Encargo & VectorEncargo::operator()(const int pos)
{
    return datos[pos-1];
}

const Encargo & VectorEncargo::operator()(const int pos) const
{
    return datos[pos-1];
}

/*****************************************************************************/
/*****************************************************************************/
// Método toString

string VectorEncargo::toString() const
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

void VectorEncargo::redimensiona()
{
    // Creo un vector auxiliar con el doble de capacidad que el original
    VectorEncargo aux(capacidad + TAM_BLOQUE);

    // Copio los elementos del vector original al auxiliar
    aux.copiaDatos(*this);

    // Igualo el vector original al auxiliar
    *this = aux;

}

/*****************************************************************************/
/*****************************************************************************/
// Método reservaMemoria

void VectorEncargo::reservaMemoria(const int capacidad)
{

    // Me deshago de la memoria que pudiera tener reservada el vector
    // y los datos que pudiera contener
    liberaMemoria();

    // Reservo memoria para el vector
    datos = new Encargo[capacidad];

    // Actualizo los datos del vector
    this->capacidad = capacidad;
    usados = 0;

}

/*****************************************************************************/
/*****************************************************************************/
// Método liberaMemoria

void VectorEncargo::liberaMemoria()
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

void VectorEncargo::copiaDatos(const VectorEncargo & otro)
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
// Método para buscar si x encargo ya existe en el vector

bool VectorEncargo::estaEncargo (const Encargo & encargo) 
const
{

    bool encontrado = false;
    int i=0;

    while (i < getUsados() && !encontrado){
        if (datos[i].getCategoria() == encargo.getCategoria())
            encontrado = true;

        i++;
    }

    return (encontrado);

}


/***********************************************************************/
// Sobrecarga del operador + (Vector + Vector)

VectorEncargo operator + (const VectorEncargo & uno, const
                          VectorEncargo & otro)
{

    // Creo un vector temporal donde guardaré los datos concatenados

    VectorEncargo tmp(uno);

    // Guardo los datos de otro en tmp

    for (int i = 0; i < otro.getUsados(); i++)
        if (!tmp.estaEncargo(otro[i+1]))
            tmp.aniade(otro[i+1]);

    // Devuelvo tmp
    return tmp;
    
}


/***********************************************************************/
// Sobrecarga del operador + (Vector + Encargo)

VectorEncargo operator + (const VectorEncargo & uno, const
                          Encargo & encargo)
{

    // Creo un vector con el departamento dentro

    VectorEncargo tmp;
    tmp.aniade(encargo);

    return(uno + tmp);

}


/***********************************************************************/
// Sobrecarga del operador + (Encargo + Vector)

VectorEncargo operator + (const Encargo & encargo,
                          const VectorEncargo & uno)
{
    // Creo un vector con el departamento dentro

    VectorEncargo tmp;
    tmp.aniade(encargo);

    return(tmp + uno);

}


/***********************************************************************/
// Sobrecarga del operador += (vector += vector)

VectorEncargo VectorEncargo :: operator += (const VectorEncargo & otro)
{
    for (int i=0; i<otro.getUsados(); i++)
        if (!estaEncargo(otro[i+1]))
            aniade(otro[i+1]);

    return (*this);

}

/***********************************************************************/
// Sobrecarga del operador += (vector += encargo)

VectorEncargo VectorEncargo :: operator += (const Encargo & encargo)
{
 
    VectorEncargo tmp;
    tmp.aniade(encargo);

    return (*this += tmp);   

}

/***********************************************************************/
// Función de escritura de un vector en un fichero

void VectorEncargo :: GuardarVectorEncargo(const string & nombre) 
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

void VectorEncargo :: RecuperarVectorEncargo 
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

ofstream & operator << (ofstream & fo, const VectorEncargo & vector)
{
    if (vector.datos != nullptr){

        // Escribo la cabecera

        fo << "ENCARGOS" << endl;

        // Escribo un comentario explicativo

        fo << "# Colección de encargos" << endl;

        // Voy escribiendo el contenido del vector en el fichero

        for (int i=0; i<vector.getUsados(); i++){


            fo << vector.datos[i] << endl;


        }

    }

    return fo;

}

ifstream & operator >> (ifstream & fi, VectorEncargo & vector)
{
    // Reinicio el Vector

    vector.reinicia();

    // Compruebo que la cabecera es correcta

    string linea;

    getline(fi,linea);


    if (linea == "ENCARGOS"){

        // Leo lineas hasta que no queden mas

        getline(fi,linea); // Lectura adelantada
        Encargo aux;

        while (!fi.eof()){

            while (linea.at(0) == '#'){
                getline(fi,linea);
            }
               

            if (!fi.eof()){

                Encargo aux(linea);

                vector.aniade(aux);


            }

            getline(fi,linea);

        }

    }

    return fi;
}
