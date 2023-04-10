###############################################################################
# 
# Makefile Proyecto
#
# David Pérez Tobarra
#
# MP_Proyecto_Fase1.mak
#
# Makefile de la fase 1 del proyecto
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
all: presentacion $(BIN)/main_MP_Proyecto_Fase1
	@echo Terminado


#......................................
# EJECUTABLES

$(BIN)/main_MP_Proyecto_Fase1 : $(OBJ)/main_MP_Proyecto_Fase1.o \
	                            $(LIB)/libDepartamento.a $(LIB)/libProfesor.a \
	                            $(LIB)/libEncargos.a $(LIB)/libAdscripciones.a \
	                            $(LIB)/libutils.a $(LIB)/libFecha.a     
	g++ -o $(BIN)/main_MP_Proyecto_Fase1 $(OBJ)/main_MP_Proyecto_Fase1.o \
	-L$(LIB) -lDepartamento -lProfesor -lEncargos -lAdscripciones -lutils \
	-lFecha



#......................................
# OBJETOS
	
$(OBJ)/main_MP_Proyecto_Fase1.o : $(SRC)/main_MP_Proyecto_Fase1.cpp \
                               $(INCLUDE)/Departamento.h $(INCLUDE)/Profesor.h \
                               $(INCLUDE)/Encargos.h \
                               $(INCLUDE)/Adscripciones.h $(INCLUDE)/utils.h
	g++ -c -o $(OBJ)/main_MP_Proyecto_Fase1.o \
	          $(SRC)/main_MP_Proyecto_Fase1.cpp -I$(INCLUDE) -std=c++14
	          
$(OBJ)/Departamento.o : $(SRC)/Departamento.cpp $(INCLUDE)/Departamento.h \
                        $(INCLUDE)/utils.h
	g++ -c -o $(OBJ)/Departamento.o $(SRC)/Departamento.cpp -I$(INCLUDE) \
	          -std=c++14
	          
$(OBJ)/Profesor.o : $(SRC)/Profesor.cpp $(INCLUDE)/Profesor.h $(INCLUDE)/utils.h
	g++ -c -o $(OBJ)/Profesor.o $(SRC)/Profesor.cpp -I$(INCLUDE) -std=c++14

$(OBJ)/Encargos.o : $(SRC)/Encargos.cpp $(INCLUDE)/Encargos.h $(INCLUDE)/utils.h
	g++ -c -o $(OBJ)/Encargos.o $(SRC)/Encargos.cpp -I$(INCLUDE) -std=c++14
	
$(OBJ)/Adscripciones.o : $(SRC)/Adscripciones.cpp $(INCLUDE)/Adscripciones.h \
	                     $(INCLUDE)/utils.h
	g++ -c -o $(OBJ)/Adscripciones.o $(SRC)/Adscripciones.cpp -I$(INCLUDE) \
	          -std=c++14

$(OBJ)/utils.o : $(SRC)/utils.cpp $(INCLUDE)/utils.h
	g++ -c -o $(OBJ)/utils.o $(SRC)/utils.cpp -I$(INCLUDE) -std=c++14
	
$(OBJ)/Fecha.o : $(SRC)/Fecha.cpp $(INCLUDE)/Fecha.h $(INCLUDE)/utils.h
	g++ -c -o $(OBJ)/Fecha.o $(SRC)/Fecha.cpp -I$(INCLUDE) -std=c++14
	          
#......................................
# BIBLIOTECAS

$(LIB)/libDepartamento.a : $(OBJ)/Departamento.o
	ar rvs $(LIB)/libDepartamento.a $(OBJ)/Departamento.o
	
$(LIB)/libProfesor.a : $(OBJ)/Profesor.o
	ar rvs $(LIB)/libProfesor.a $(OBJ)/Profesor.o
	
$(LIB)/libEncargos.a : $(OBJ)/Encargos.o
	ar rvs $(LIB)/libEncargos.a $(OBJ)/Encargos.o
	
$(LIB)/libAdscripciones.a : $(OBJ)/Adscripciones.o
	ar rvs $(LIB)/libAdscripciones.a $(OBJ)/Adscripciones.o
	
$(LIB)/libutils.a : $(OBJ)/utils.o
	ar rvs $(LIB)/libutils.a $(OBJ)/utils.o
	
$(LIB)/libFecha.a : $(OBJ)/Fecha.o
	ar rvs $(LIB)/libFecha.a $(OBJ)/Fecha.o
	          
	         
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



	
	
	
	
	
	

