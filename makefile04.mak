###############################################################################
# 
# Makefile Ejercicios Segunda Entrega
#
# David Pérez Tobarra
#
# makefile04.mak
#
# Ejercicios resueltos de la práctica 04
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

all: presentacion $(BIN)/I_PruebaFunciones $(BIN)/I_EncuentraInicioPalabras \
	 clean
	@echo Terminado


#......................................
# EJECUTABLES

$(BIN)/I_EncuentraInicioPalabras : $(OBJ)/I_EncuentraInicioPalabras.o \
								   $(OBJ)/MiCadenaClasica.o \
								   $(LIB)/libMiCadenaClasica.a
	g++ -o bin/I_EncuentraInicioPalabras obj/I_EncuentraInicioPalabras.o \
	obj/MiCadenaClasica.o -lMiCadenaClasica -L$(LIB)

$(BIN)/I_PruebaFunciones : $(OBJ)/I_PruebaFunciones.o \
						   $(OBJ)/MiCadenaClasica.o \
						   $(LIB)/libMiCadenaClasica.a
	g++ -o bin/I_PruebaFunciones obj/I_PruebaFunciones.o obj/MiCadenaClasica.o \
	-lMiCadenaClasica -L$(LIB)


#......................................
# OBJETOS
	
$(OBJ)/I_PruebaFunciones.o : $(SRC)/I_PruebaFunciones.cpp \
						  	 $(INCLUDE)/MiCadenaClasica.h
	g++ -c -o obj/I_PruebaFunciones.o src/I_PruebaFunciones.cpp \
	-I./include -std=c++11

$(OBJ)/MiCadenaClasica.o : $(SRC)/MiCadenaClasica.cpp \
						   $(INCLUDE)/MiCadenaClasica.h
	g++ -c -o obj/MiCadenaClasica.o src/MiCadenaClasica.cpp \
	-I./include -std=c++11

$(OBJ)/I_EncuentraInicioPalabras.o : $(SRC)/I_EncuentraInicioPalabras.cpp \
								     $(INCLUDE)/MiCadenaClasica.h
	g++ -c -o obj/I_EncuentraInicioPalabras.o src/I_EncuentraInicioPalabras.cpp\
	 -I./include -std=c++11


#......................................
# BIBLIOTECAS

$(LIB)/libMiCadenaClasica.a : $(OBJ)/MiCadenaClasica.o
	ar rvs $(LIB)/libMiCadenaClasica.a $(OBJ)/MiCadenaClasica.o 

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

