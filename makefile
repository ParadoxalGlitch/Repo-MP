#Primer makefile
#David Pérez Tobarra

AUTOR = David

HOME = .
SRC = $(HOME)/src
INCLUDE = $(HOME)/include
LIB = $(HOME)/lib
OBJ = $(HOME)/obj
BIN = $(HOME)/bin

all: presentacion $(BIN)/saludo $(BIN)/saludo_en_dos_pasos clean
	@echo Terminado

bin/saludo : $(SRC)/saludo.cpp
	g++ -o $(BIN)/saludo $(SRC)/saludo.cpp
	
obj/saludo.o : $(SRC)/saludo.cpp
	g++ -c -o $(OBJ)/saludo.o $(SRC)/saludo.cpp
	
bin/saludo_en_dos_pasos : $(OBJ)/saludo.o
	g++ -o $(BIN)/saludo_en_dos_pasos $(OBJ)/saludo.o
	
clean:
	rm $(OBJ)/*
	@echo objetos eliminados
		
mr.proper: clean
	-rm $(BIN)/*
	@echo ejecutables eliminados
	-rm $(LIB)/*
	@echo librerias eliminadas

presentacion:
	@echo El autor de este software es: $(AUTOR)

