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

all: presentacion $(BIN)/I_MezclaArrays $(BIN)/I_MezclaArrays_ref clean
	@echo Terminado


#......................................
# EJECUTABLES

$(BIN)/I_MezclaArrays : $(OBJ)/I_MezclaArrays.o $(OBJ)/ProcesamientoArrayInt.o \
			$(INCLUDE)/ProcesamientoArrayInt.h
	g++ -o $(BIN)/I_MezclaArrays $(OBJ)/I_MezclaArrays.o \
	       $(OBJ)/ProcesamientoArrayInt.o -I./include
	
$(BIN)/I_MezclaArrays_ref : $(OBJ)/I_MezclaArrays_ref.o \
			    $(OBJ)/ProcesamientoArrayInt.o \
			    $(INCLUDE)/ProcesamientoArrayInt.h
	g++ -o $(BIN)/I_MezclaArrays_ref $(OBJ)/I_MezclaArrays_ref.o \
	       $(OBJ)/ProcesamientoArrayInt.o -I./include


#......................................
# OBJETOS
	
$(OBJ)/I_MezclaArrays.o : $(SRC)/I_MezclaArrays.cpp \
			  $(INCLUDE)/ProcesamientoArrayInt.h
	g++ -c -o $(OBJ)/I_MezclaArrays.o $(SRC)/I_MezclaArrays.cpp \
		  -I./include -std=c++11

$(OBJ)/ProcesamientoArrayInt.o : $(SRC)/ProcesamientoArrayInt.cpp \
				 $(INCLUDE)/ProcesamientoArrayInt.h
	g++ -c -o $(OBJ)/ProcesamientoArrayInt.o \
		  $(SRC)/ProcesamientoArrayInt.cpp -I./include -std=c++11
		  
$(OBJ)/I_MezclaArrays_ref.o : $(SRC)/I_MezclaArrays_ref.cpp \
			      $(INCLUDE)/ProcesamientoArrayInt.h
	g++ -c -o $(OBJ)/I_MezclaArrays_ref.o $(SRC)/I_MezclaArrays_ref.cpp \
		  -I./include -std=c++11


#......................................
# BIBLIOTECAS

#$(LIB)/libMiCadenaClasica.a : $(OBJ)/MiCadenaClasica.o
#	ar rvs $(LIB)/libMiCadenaClasica.a $(OBJ)/MiCadenaClasica.o 

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

