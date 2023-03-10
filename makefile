#Makefile Ejercicios Primera Entrega
#David Pérez Tobarra

AUTOR = David

HOME = .
SRC = $(HOME)/src
INCLUDE = $(HOME)/include
LIB = $(HOME)/lib
OBJ = $(HOME)/obj
BIN = $(HOME)/bin

all: presentacion $(BIN)/I_PosMayor_Basico $(BIN)/I_OrdenaVector $(BIN)/I_OrdenayMezclaVectores clean
	@echo Terminado
		
obj/ProcesamientoArrayInt.o : $(SRC)/ProcesamientoArrayInt.cpp $(INCLUDE)/ProcesamientoArrayInt.h
	g++ -c -o obj/ProcesamientoArrayInt.o src/ProcesamientoArrayInt.cpp -I./include -std=c++11
		
	
obj/I_PosMayor_Basico.o : $(SRC)/I_PosMayor_Basico.cpp $(INCLUDE)/ProcesamientoArrayInt.h
	g++ -c -o obj/I_PosMayor_Basico.o  src/I_PosMayor_Basico.cpp -I./include -std=c++11
	
bin/I_PosMayor_Basico : $(OBJ)/I_PosMayor_Basico.o $(OBJ)/ProcesamientoArrayInt.o
	g++ -o bin/I_PosMayor_Basico obj/ProcesamientoArrayInt.o obj/I_PosMayor_Basico.o
	
obj/I_OrdenaVector.o : $(SRC)/I_OrdenaVector.cpp $(INCLUDE)/ProcesamientoArrayInt.h
	g++ -c -o obj/I_OrdenaVector.o  src/I_OrdenaVector.cpp -I./include -std=c++11
	
bin/I_OrdenaVector : $(OBJ)/I_OrdenaVector.o $(OBJ)/ProcesamientoArrayInt.o
	g++ -o bin/I_OrdenaVector obj/ProcesamientoArrayInt.o obj/I_OrdenaVector.o
	
obj/I_OrdenayMezclaVectores.o : $(SRC)/I_OrdenayMezclaVectores.cpp $(INCLUDE)/ProcesamientoArrayInt.h
	g++ -c -o obj/I_OrdenayMezclaVectores.o  src/I_OrdenayMezclaVectores.cpp -I./include -std=c++11
	
bin/I_OrdenayMezclaVectores : $(OBJ)/I_OrdenayMezclaVectores.o $(OBJ)/ProcesamientoArrayInt.o
	g++ -o bin/I_OrdenayMezclaVectores obj/ProcesamientoArrayInt.o obj/I_OrdenayMezclaVectores.o
	
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

