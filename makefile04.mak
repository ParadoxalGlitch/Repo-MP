#Makefile Ejercicios Segunda Entrega
#David Pérez Tobarra

AUTOR = David

HOME = .
SRC = $(HOME)/src
INCLUDE = $(HOME)/include
LIB = $(HOME)/lib
OBJ = $(HOME)/obj
BIN = $(HOME)/bin

all: presentacion $(BIN)/I_PruebaFunciones $(BIN)/I_EncuentraInicioPalabras clean
	@echo Terminado
		
obj/I_PruebaFunciones.o : $(SRC)/I_PruebaFunciones.cpp $(INCLUDE)/MiCadenaClasica.h
	g++ -c -o obj/I_PruebaFunciones.o src/I_PruebaFunciones.cpp -I./include -std=c++11
		
bin/I_PruebaFunciones : $(OBJ)/I_PruebaFunciones.o $(OBJ)/MiCadenaClasica.o
	g++ -o bin/I_PruebaFunciones obj/I_PruebaFunciones.o obj/MiCadenaClasica.o

obj/MiCadenaClasica.o : $(SRC)/MiCadenaClasica.cpp $(INCLUDE)/MiCadenaClasica.h
	g++ -c -o obj/MiCadenaClasica.o src/MiCadenaClasica.cpp -I./include -std=c++11

obj/I_EncuentraInicioPalabras.o : $(SRC)/I_EncuentraInicioPalabras.cpp $(INCLUDE)/MiCadenaClasica.h
	g++ -c -o obj/I_EncuentraInicioPalabras.o src/I_EncuentraInicioPalabras.cpp -I./include -std=c++11

bin/I_EncuentraInicioPalabras : $(OBJ)/I_EncuentraInicioPalabras.o $(OBJ)/MiCadenaClasica.o
	g++ -o bin/I_EncuentraInicioPalabras obj/I_EncuentraInicioPalabras.o obj/MiCadenaClasica.o

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

