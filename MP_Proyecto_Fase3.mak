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
all: presentacion $(BIN)/MP_Proyecto_Fase3
	@echo Terminado


#......................................
# EJECUTABLES

$(BIN)/MP_Proyecto_Fase3 : $(OBJ)/main_MP_Proyecto_Fase3.o \
	                       $(LIB)/libDepartamento.a $(LIB)/libProfesor.a \
                           $(LIB)/libEncargo.a $(LIB)/libAdscripcion.a \
                           $(LIB)/libutils.a $(LIB)/libFecha.a     
	g++ -o $(BIN)/MP_Proyecto_Fase3 $(OBJ)/main_MP_Proyecto_Fase3.o \
	-L$(LIB) -lDepartamento -lProfesor -lEncargo -lAdscripcion -lutils \
	-lFecha



#......................................
# OBJETOS
	
$(OBJ)/main_MP_Proyecto_Fase3.o : $(SRC)/main_MP_Proyecto_Fase3.cpp \
                               $(INCLUDE)/Departamento.h $(INCLUDE)/Profesor.h \
                               $(INCLUDE)/Encargo.h \
                               $(INCLUDE)/Adscripcion.h $(INCLUDE)/utils.h
	g++ -c -o $(OBJ)/main_MP_Proyecto_Fase3.o \
	          $(SRC)/main_MP_Proyecto_Fase3.cpp -I$(INCLUDE) -std=c++14
	          
$(OBJ)/Departamento.o : $(SRC)/Departamento.cpp $(INCLUDE)/Departamento.h \
                        $(INCLUDE)/utils.h
	g++ -c -o $(OBJ)/Departamento.o $(SRC)/Departamento.cpp -I$(INCLUDE) \
	          -std=c++14
	          
$(OBJ)/Profesor.o : $(SRC)/Profesor.cpp $(INCLUDE)/Profesor.h $(INCLUDE)/utils.h
	g++ -c -o $(OBJ)/Profesor.o $(SRC)/Profesor.cpp -I$(INCLUDE) -std=c++14

$(OBJ)/Encargo.o : $(SRC)/Encargo.cpp $(INCLUDE)/Encargo.h $(INCLUDE)/utils.h
	g++ -c -o $(OBJ)/Encargo.o $(SRC)/Encargo.cpp -I$(INCLUDE) -std=c++14
	
$(OBJ)/Adscripcion.o : $(SRC)/Adscripcion.cpp $(INCLUDE)/Adscripcion.h \
	                     $(INCLUDE)/utils.h
	g++ -c -o $(OBJ)/Adscripcion.o $(SRC)/Adscripcion.cpp -I$(INCLUDE) \
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
	
$(LIB)/libEncargo.a : $(OBJ)/Encargo.o
	ar rvs $(LIB)/libEncargo.a $(OBJ)/Encargo.o
	
$(LIB)/libAdscripcion.a : $(OBJ)/Adscripcion.o
	ar rvs $(LIB)/libAdscripcion.a $(OBJ)/Adscripcion.o
	
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



	
	
	
	
	
	

