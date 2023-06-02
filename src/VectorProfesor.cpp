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
    // Constructor con argumentos

    VectorProfesor :: VectorProfesor(const string & nombre)
    {

        datos = nullptr;
        usados = 0;
        capacidad = 0;

        RecuperarVectorProfesor(nombre);

    }

    /*****************************************************************************/
    /*****************************************************************************/
    // Constructor de copia

    VectorProfesor::VectorProfesor(const VectorProfesor & otro)
    {

        datos = nullptr;
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
            reservaMemoria(otro.getCapacidad());
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
        if (datos){

            cadena += "Capacidad: " + to_string(capacidad) + " Usados: " + \
                    to_string(usados) + "\n";    

            for (int i = 0; i < usados; i++)
            {
                cadena += datos[i].ToString() + "\n";
            }

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

        //Reservo memoria para el vector
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

        if (datos)
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

        // Copio los datos de otro
        for (int i = 0; i < otro.usados; i++)
        {
            datos[i] = otro.datos[i];
        }
        
        usados = otro.usados; // Actualizo el número de elementos usados
    }

    /***********************************************************************/
    // Método para buscar si x profesor ya existe en el vector

    bool VectorProfesor::estaProfesor (const Profesor & profesor) const
    {

        bool encontrado = false;
        int i=0;

        while (i < getUsados() && !encontrado){
            if (datos[i].getDni() == profesor.getDni())
                encontrado = true;

            i++;
        }

        return (encontrado);

    }


    /***********************************************************************/
    // Sobrecarga del operador + (Vector + Vector)

    VectorProfesor operator + (const VectorProfesor & uno, const
                            VectorProfesor & otro)
    {

        // Creo un vector temporal donde guardaré los datos concatenados

        VectorProfesor tmp(uno);

        // Guardo los datos de otro en tmp

        for (int i = 0; i < otro.getUsados(); i++)
            if (!tmp.estaProfesor(otro[i+1]))
                tmp.aniade(otro[i+1]);

        // Devuelvo tmp
        return tmp;
    }

    /***********************************************************************/
    // Sobrecarga del operador + (Vector + profesor)

    VectorProfesor operator + (const VectorProfesor & uno, const
                            Profesor & profesor)
    {
        // Creo un vector con el departamento dentro

        VectorProfesor tmp;
        tmp.aniade(profesor);

        return(uno + tmp);
    }

    /***********************************************************************/
    // Sobrecarga del operador + (profesor + Vector)

    VectorProfesor operator + (const Profesor & profesor,
                            const VectorProfesor & uno)
    {
        // Creo un vector con el departamento dentro

        VectorProfesor tmp;
        tmp.aniade(profesor);

        return(tmp + uno);
    }

    /***********************************************************************/
    // Sobrecarga del operador += (vector += vector)

    VectorProfesor VectorProfesor :: operator += (const VectorProfesor & otro)
    {

        for (int i=0; i<otro.getUsados(); i++)
            if (!estaProfesor(otro[i+1]))
                aniade(otro[i+1]);

        return (*this);

    }

    /***********************************************************************/
    // Sobrecarga del operador += (vector += departamento)

    VectorProfesor VectorProfesor :: operator += (const Profesor & profesor)
    {

        VectorProfesor tmp;
        tmp.aniade(profesor);

        return (*this += tmp);

    }

    /***********************************************************************/
    // Función de escritura de un vector en un fichero

    void VectorProfesor :: GuardarVectorProfesor(const string & nombre) 
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

    void VectorProfesor :: RecuperarVectorProfesor 
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

    ofstream & operator << (ofstream & fo, const VectorProfesor & vector)
    {
        if (vector.datos != nullptr){

            // Escribo la cabecera

            fo << "PROFESORES" << endl;

            // Escribo un comentario explicativo

            fo << "# Colección de profesores" << endl;

            // Voy escribiendo el contenido del vector en el fichero

            for (int i=0; i<vector.getUsados(); i++){


                fo << vector.datos[i] << endl;


            }

        }

        return fo;

    }

    ifstream & operator >> (ifstream & fi, VectorProfesor & vector)
    {
        // Reinicio el Vector

        vector.reinicia();

        // Compruebo que la cabecera es correcta

        string linea;

        getline(fi,linea);


        if (linea == "PROFESORES"){

            // Leo lineas hasta que no queden mas

            getline(fi,linea); // Lectura adelantada
            Profesor aux;

            while (!fi.eof()){

                while (linea.at(0) == '#'){
                    getline(fi,linea);
                }

                if (!fi.eof()){

                    Profesor aux(linea);

                    vector.aniade(aux);

                }   

                getline(fi,linea);

            }

        }

        return fi;
    }
