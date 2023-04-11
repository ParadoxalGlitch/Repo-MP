#############################################################################
#
# METODOLOGIA DE LA PROGRAMACION
#
# (C) FRANCISCO JOSE CORTIJO BON
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
#
# basico_Matriz2D.mak
#
# Generacion del proyecto descrito en los videos 
# "Gestión de matrices dinámicas"
#
#############################################################################

HOME = .
HOME_CLASES_UTILS = .

BIN = $(HOME)/bin
SRC = $(HOME)/src
OBJ = $(HOME)/obj
LIB = $(HOME)/lib
INCLUDE = $(HOME)/include

#................................................
all:  $(BIN)/II_Demo-Matriz2D $(BIN)/II_Viajante-Comercio 
	  
	  @echo Terminado

#................................................
# EJECUTABLES

$(BIN)/II_Demo-Matriz2D : $(OBJ)/II_Demo-Matriz2D.o \
             $(LIB)/libMatriz2D.a
	g++ -o $(BIN)/II_Demo-Matriz2D $(OBJ)/II_Demo-Matriz2D.o \
	       -L$(LIB) -lMatriz2D
           
$(BIN)/II_Viajante-Comercio : $(OBJ)/II_Viajante-Comercio.o \
                              $(LIB)/libMatriz2D.a \
                              $(LIB)/libVectorDinamico.a
	g++ -o $(BIN)/II_Viajante-Comercio $(OBJ)/II_Viajante-Comercio.o \
	       -L$(LIB) -lMatriz2D -lVectorDinamico

#................................................
# OBJETOS 

$(OBJ)/II_Demo-Matriz2D.o : $(SRC)/II_Demo-Matriz2D.cpp \
             $(INCLUDE)/Matriz2D.h $(INCLUDE)/FuncsVectorDinamico.h \
             $(INCLUDE)/TipoBase.h
	g++ -c -o $(OBJ)/II_Demo-Matriz2D.o $(SRC)/II_Demo-Matriz2D.cpp \
            -I$(INCLUDE) -std=c++14

$(OBJ)/Matriz2D.o : $(SRC)/Matriz2D.cpp $(INCLUDE)/Matriz2D.h \
					$(INCLUDE)/TipoBase.h
	g++ -c -o $(OBJ)/Matriz2D.o $(SRC)/Matriz2D.cpp -I$(INCLUDE) -std=c++11
	
$(OBJ)/II_Viajante-Comercio.o : $(SRC)/II_Viajante-Comercio.cpp \
                                $(INCLUDE)/Matriz2D.h $(INCLUDE)/TipoBase.h
	g++ -c -o $(OBJ)/II_Viajante-Comercio.o $(SRC)/II_Viajante-Comercio.cpp \
	          -I$(INCLUDE) -std=c++14
	          
$(OBJ)/FuncsVectorDinamico.o : $(SRC)/FuncsVectorDinamico.cpp \
                               $(INCLUDE)/FuncsVectorDinamico.h
	g++ -c -o $(OBJ)/FuncsVectorDinamico.o $(SRC)/FuncsVectorDinamico.cpp \
	          -I$(INCLUDE) -std=c++14
	          

#................................................
# BIBLIOTECAS
$(LIB)/libMatriz2D.a : $(OBJ)/Matriz2D.o
	ar rvs $(LIB)/libMatriz2D.a $(OBJ)/Matriz2D.o
	
$(LIB)/libVectorDinamico.a : $(OBJ)/FuncsVectorDinamico.o
	ar rvs $(LIB)/libVectorDinamico.a $(OBJ)/FuncsVectorDinamico.o

#................................................
# LIMPEZA

clean:
	-rm $(OBJ)/*
	@echo objetos eliminados
		
mr.proper: clean
	-rm $(BIN)/*
	@echo ejecutables eliminados
	-rm $(LIB)/*
	@echo librerias eliminadas

presentacion:
	@echo El autor de este software es: $(AUTOR)

