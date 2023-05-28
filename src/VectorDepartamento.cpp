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
// Constructor con argumentos

VectorDepartamento :: VectorDepartamento(const string & nombre)
{

    datos = nullptr;
    usados = 0;
    capacidad = 0;

    RecuperarVectorDepartamento(nombre);

}

/*****************************************************************************/
/*****************************************************************************/
// Constructor de copia

VectorDepartamento::VectorDepartamento(const VectorDepartamento & otro)
{

    datos = nullptr;

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
    
    datos[getUsados()] = nuevo;
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

string VectorDepartamento::toString()
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

        i++;
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
        if (tmp.estaDepartamento(otro[i+1]))
            tmp.elimina(i+1);

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

    tmp.aniade(departamento);

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
    dep.setNombre("placeholder");    

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
        if (uno.estaDepartamento(otro[i+1]))
            tmp.aniade(otro[i+1]);

    return (tmp);

}


/***********************************************************************/
// Sobrecarga del operador binario && (vector && vector)

bool operator && (const VectorDepartamento & uno, const
                                VectorDepartamento & otro)
{
    int i=0;
    bool continuar = true;

    // Compruebo si todos los dep. del segundo vector están en el primero

    while (i < otro.getUsados() && continuar){
        if (!uno.estaDepartamento(otro[i+1]))
            continuar = false;

        i++;

    }

    return (continuar);

}


/***********************************************************************/
// Sobrecarga del operador binario && (Vector && departamento)

bool operator && (const VectorDepartamento & uno, const
                                Departamento & departamento)
{

    // Almaceno el departamento en un vector

    VectorDepartamento tmp;
    tmp.aniade(departamento);

    return (uno && tmp);

}

/***********************************************************************/
// Sobrecarga del operador binario && (departamento && Vector)

bool operator && (const Departamento & departamento,
                                const VectorDepartamento & uno)
{
    
    return (uno && departamento);

}


/***********************************************************************/
// Sobrecarga del operador binario && (Vector && string)

bool operator && (const VectorDepartamento & uno, const
                                string & cadena)
{

    Departamento dep;
    dep.setId(cadena);
    dep.setNombre("placeholder");

    return (uno && dep);

}

/***********************************************************************/
// Sobrecarga del operador binario && (string && Vector)

bool operator && (const string & cadena, const
                                VectorDepartamento & uno)
{

    Departamento dep;
    dep.setId(cadena);

    return (uno && dep);

}

/***********************************************************************/
// Sobrecarga del operador += (vector += vector)

VectorDepartamento VectorDepartamento :: operator += 
                                      (const VectorDepartamento & otro)
{

    for (int i=0; i<otro.getUsados(); i++)
        if (!estaDepartamento(otro[i+1]))
            aniade(otro[i+1]);

    return (*this);

}

/***********************************************************************/
// Sobrecarga del operador += (vector += departamento)

VectorDepartamento VectorDepartamento :: operator += 
                                         (const Departamento & departamento)
{

    VectorDepartamento tmp;
    tmp.aniade(departamento);

    

    return (*this += tmp);

}

/***********************************************************************/
// Sobrecarga del operador -= (vector -= vector)

VectorDepartamento VectorDepartamento :: operator -= 
                                         (const VectorDepartamento & otro)
{
    for (int i=0; i<getUsados(); i++)
        if (otro.estaDepartamento((*this)[i+1]))
            elimina(i+1);

    return *this;
}

/***********************************************************************/
// Sobrecarga del operador -= (vector -= departamento)

VectorDepartamento VectorDepartamento :: operator -= 
                                        (const Departamento & departamento)
{

    VectorDepartamento tmp;
    tmp.aniade(departamento);

    return (*this -= tmp);

}


/***********************************************************************/
// Sobrecarga del operador -= (vector -= string)

VectorDepartamento VectorDepartamento :: operator -= (const string & cadena)
{

    Departamento dep;
    dep.setId(cadena);
    dep.setNombre("placeholder");

    return (*this -= dep);

}

/***********************************************************************/
// Función de escritura de un vector en un fichero

void VectorDepartamento :: GuardarVectorDepartamento(const string & nombre) 
const
{

    // Abro el archivo
    if (usados != 0){


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

void VectorDepartamento :: RecuperarVectorDepartamento 
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

ofstream & operator << (ofstream & fo, const VectorDepartamento & vector)
{
    if (vector.datos != nullptr){

        // Escribo la cabecera

        fo << "DEPARTAMENTOS" << endl;

        // Escribo un comentario explicativo

        fo << "# Colección de departamentos" << endl;

        // Voy escribiendo el contenido del vector en el fichero

        for (int i=0; i<vector.getUsados(); i++){


            fo << vector.datos[i] << endl;


        }

    }

    return fo;

}

ifstream & operator >> (ifstream & fi, VectorDepartamento & vector)
{
    // Reinicio el Vector

    vector.reinicia();

    // Compruebo que la cabecera es correcta

    string linea;

    getline(fi,linea);


    if (linea == "DEPARTAMENTOS"){

        // Leo lineas hasta que no queden mas

        getline(fi,linea); // Lectura adelantada
        Departamento aux;

        while (!fi.eof()){

            while (linea.at(0) == '#'){
                getline(fi,linea);
            }
               

            if (!fi.eof()){

                Departamento aux(linea);

                vector.aniade(aux);


            }

            getline(fi,linea);

        }

    }

    return fi;
}
