#include <iostream>
#include <fstream>

#include <VectorProfesor.h>
#include <Profesor.h>
#include <utils.h>

using namespace std;





int main(int argc, char * argv[]){



    if (argc != 2){

        cerr << "Numero de argumentos incorrecto";
        return(1);

    }

    VectorProfesor vector_dep (argv[1]);


    cout << vector_dep.toString() << endl;

    vector_dep.GuardarVectorProfesor("vector_dep_out.txt");


}



