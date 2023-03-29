###############################################################################
# 
# Makefile Ejercicios Segunda Entrega
#
# David Pérez Tobarra
#
# makefile05.mak
#
# Ejercicios resueltos de la práctica 05
#
###############################################################################

AUTOR = David

HOME = .
SRC = $(HOME)/src
INCLUDE = $(HOME)/include
LIB = $(HOME)/lib
OBJ = $(HOME)/obj
BIN = $(HOME)/bin

#......................................

all: presentacion $(BIN)/II_Demo_VectorDinamico \
                  $(BIN)/II_Demo-VectorDinamicoCadenas
	@echo Terminado


#......................................
# EJECUTABLES

$(BIN)/II_Demo_VectorDinamico : $(OBJ)/II_Demo_VectorDinamico.o \
	                            $(LIB)/libFuncsVectorDinamico.a      
	g++ -o $(BIN)/II_Demo_VectorDinamico $(OBJ)/II_Demo_VectorDinamico.o \
	       $(OBJ)/FuncsVectorDinamico.o -lFuncsVectorDinamico -L$(LIB)
	       
$(BIN)/II_Demo-VectorDinamicoCadenas : $(OBJ)/II_Demo-VectorDinamicoCadenas.o \
                                       $(LIB)/libFuncsVectorDinamicoCadenas.a
	g++ -o $(BIN)/II_Demo-VectorDinamicoCadenas \
	       $(OBJ)/II_Demo-VectorDinamicoCadenas.o \
	       $(OBJ)/FuncsVectorDinamicoCadenas.o -lFuncsVectorDinamicoCadenas \
	       -L$(LIB)


#......................................
# OBJETOS
	
$(OBJ)/FuncsVectorDinamico.o : $(SRC)/FuncsVectorDinamico.cpp \
                               $(INCLUDE)/FuncsVectorDinamico.h
	g++ -c -o $(OBJ)/FuncsVectorDinamico.o $(SRC)/FuncsVectorDinamico.cpp \
	          -I$(INCLUDE) -std=c++14
	          
$(OBJ)/FuncsVectorDinamicoCadenas.o : $(SRC)/FuncsVectorDinamicoCadenas.cpp \
                               $(INCLUDE)/FuncsVectorDinamicoCadenas.h
	g++ -c -o $(OBJ)/FuncsVectorDinamicoCadenas.o \
	          $(SRC)/FuncsVectorDinamicoCadenas.cpp -I$(INCLUDE) -std=c++14	          
	                

$(OBJ)/II_Demo_VectorDinamico.o : $(SRC)/II_Demo_VectorDinamico.cpp \
                                  $(INCLUDE)/FuncsVectorDinamico.h
	g++ -c -o $(OBJ)/II_Demo_VectorDinamico.o \
	          $(SRC)/II_Demo_VectorDinamico.cpp \
	          -I$(INCLUDE) -std=c++14
$(OBJ)/II_Demo-VectorDinamicoCadenas.o : \
                                    $(SRC)/II_Demo-VectorDinamicoCadenas.cpp \
                                    $(INCLUDE)/FuncsVectorDinamicoCadenas.h
	g++ -c -o $(OBJ)/II_Demo-VectorDinamicoCadenas.o \
	          $(SRC)/II_Demo-VectorDinamicoCadenas.cpp \
	          -I$(INCLUDE) -std=c++14





#......................................
# BIBLIOTECAS

$(LIB)/libFuncsVectorDinamico.a : $(OBJ)/FuncsVectorDinamico.o
	ar rvs $(LIB)/libFuncsVectorDinamico.a $(OBJ)/FuncsVectorDinamico.o
	
$(LIB)/libFuncsVectorDinamicoCadenas.a : $(OBJ)/FuncsVectorDinamicoCadenas.o
	ar rvs $(LIB)/libFuncsVectorDinamicoCadenas.a \
	       $(OBJ)/FuncsVectorDinamicoCadenas.o
	
#......................................
# LIMPIEZA


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

