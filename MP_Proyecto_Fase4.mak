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
all: presentacion $(BIN)/MP_Proyecto_Fase4
	@echo Terminado


#......................................
# EJECUTABLES

$(BIN)/MP_Proyecto_Fase4 : $(OBJ)/main_MP_Proyecto_Fase4.o \
	                       $(LIB)/libDepartamento.a $(LIB)/libProfesor.a \
                           $(LIB)/libEncargo.a $(LIB)/libAdscripcion.a \
                           $(LIB)/libutils.a $(LIB)/libFecha.a \
                           $(LIB)/libVectorDepartamento.a \
                           $(LIB)/libVectorProfesor.a \
                           $(LIB)/libVectorAdscripcion.a \
                           $(LIB)/libVectorEncargo.a
	g++ -o $(BIN)/MP_Proyecto_Fase4 $(OBJ)/main_MP_Proyecto_Fase4.o \
           -L$(LIB) -lDepartamento -lProfesor -lEncargo -lAdscripcion -lutils \
           -lFecha -lVectorDepartamento -lVectorProfesor -lVectorAdscripcion \
           -lVectorEncargo



#......................................
# OBJETOS
	
$(OBJ)/main_MP_Proyecto_Fase4.o : $(SRC)/main_MP_Proyecto_Fase4.cpp \
                               $(INCLUDE)/Departamento.h $(INCLUDE)/Profesor.h \
                               $(INCLUDE)/Encargo.h \
                               $(INCLUDE)/Adscripcion.h $(INCLUDE)/utils.h
	g++ -c -o $(OBJ)/main_MP_Proyecto_Fase4.o \
	          $(SRC)/main_MP_Proyecto_Fase4.cpp -I$(INCLUDE) -std=c++14
	          
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
	
$(OBJ)/VectorDepartamento.o : $(SRC)/VectorDepartamento.cpp \
                              $(INCLUDE)/VectorDepartamento.h \
                              $(INCLUDE)/utils.h \
                              $(INCLUDE)/Departamento.h
	g++ -c -o $(OBJ)/VectorDepartamento.o $(SRC)/VectorDepartamento.cpp \
	          -I$(INCLUDE) -std=c++14
	          
$(OBJ)/VectorProfesor.o : $(SRC)/VectorProfesor.cpp \
                              $(INCLUDE)/VectorProfesor.h \
                              $(INCLUDE)/utils.h \
                              $(INCLUDE)/Profesor.h
	g++ -c -o $(OBJ)/VectorProfesor.o $(SRC)/VectorProfesor.cpp \
	          -I$(INCLUDE) -std=c++14
	          
$(OBJ)/VectorAdscripcion.o : $(SRC)/VectorAdscripcion.cpp \
                              $(INCLUDE)/VectorAdscripcion.h \
                              $(INCLUDE)/utils.h \
                              $(INCLUDE)/Adscripcion.h
	g++ -c -o $(OBJ)/VectorAdscripcion.o $(SRC)/VectorAdscripcion.cpp \
	          -I$(INCLUDE) -std=c++14
	          
$(OBJ)/VectorEncargo.o : $(SRC)/VectorEncargo.cpp \
                              $(INCLUDE)/VectorEncargo.h \
                              $(INCLUDE)/utils.h \
                              $(INCLUDE)/Encargo.h
	g++ -c -o $(OBJ)/VectorEncargo.o $(SRC)/VectorEncargo.cpp \
	          -I$(INCLUDE) -std=c++14
	          
	          
	          
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
	
$(LIB)/libVectorDepartamento.a : $(OBJ)/VectorDepartamento.o
	ar rvs $(LIB)/libVectorDepartamento.a $(OBJ)/VectorDepartamento.o
	
$(LIB)/libVectorProfesor.a : $(OBJ)/VectorProfesor.o
	ar rvs $(LIB)/libVectorProfesor.a $(OBJ)/VectorProfesor.o
	
$(LIB)/libVectorAdscripcion.a : $(OBJ)/VectorAdscripcion.o
	ar rvs $(LIB)/libVectorAdscripcion.a $(OBJ)/VectorAdscripcion.o
	
$(LIB)/libVectorEncargo.a : $(OBJ)/VectorEncargo.o
	ar rvs $(LIB)/libVectorEncargo.a $(OBJ)/VectorEncargo.o
	          
	         
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



	
	
	
	
	
	

