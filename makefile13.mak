#############################################################################
#
# David Pérez Tobarra
#
# makefile13.mak
#
# Clase Matriz2D y otros ejercicios
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
all:  $(BIN)/V_Demo-Matriz2D $(BIN)/NumeraLineas_Ampliacion \
      $(BIN)/VI_Demo-Matriz2D
	  
	  @echo Terminado

#................................................
# EJECUTABLES

$(BIN)/V_Demo-Matriz2D : $(OBJ)/V_Demo-Matriz2D.o $(LIB)/libMatriz2D.a \
                           $(LIB)/libSecuencia.a
	g++ -o $(BIN)/V_Demo-Matriz2D $(OBJ)/V_Demo-Matriz2D.o \
	       -L$(LIB) -lMatriz2D -lSecuencia
	       
$(BIN)/NumeraLineas_Ampliacion : $(OBJ)/NumeraLineas_Ampliacion.o
	g++ -o $(BIN)/NumeraLineas_Ampliacion $(OBJ)/NumeraLineas_Ampliacion.o
	
$(BIN)/VI_Demo-Matriz2D : $(OBJ)/VI_Demo-Matriz2D.o $(LIB)/libMatriz2D.a \
                           $(LIB)/libSecuencia.a
	g++ -o $(BIN)/VI_Demo-Matriz2D $(OBJ)/VI_Demo-Matriz2D.o \
	       -L$(LIB) -lMatriz2D -lSecuencia

#................................................
# OBJETOS 

$(OBJ)/V_Demo-Matriz2D.o : $(SRC)/V_Demo-Matriz2D.cpp \
             $(INCLUDE)/Matriz2D.h $(INCLUDE)/Secuencia.h $(INCLUDE)/TipoBase.h
	g++ -c -o $(OBJ)/V_Demo-Matriz2D.o $(SRC)/V_Demo-Matriz2D.cpp \
            -I$(INCLUDE) -std=c++14
            
$(OBJ)/VI_Demo-Matriz2D.o : $(SRC)/VI_Demo-Matriz2D.cpp \
             $(INCLUDE)/Matriz2D.h $(INCLUDE)/Secuencia.h $(INCLUDE)/TipoBase.h
	g++ -c -o $(OBJ)/VI_Demo-Matriz2D.o $(SRC)/VI_Demo-Matriz2D.cpp \
            -I$(INCLUDE) -std=c++14

$(OBJ)/Matriz2D.o : $(SRC)/Matriz2D.cpp $(INCLUDE)/Matriz2D.h \
					$(INCLUDE)/TipoBase.h
	g++ -c -o $(OBJ)/Matriz2D.o $(SRC)/Matriz2D.cpp -I$(INCLUDE) -std=c++11
	
	          
$(OBJ)/Secuencia.o : $(SRC)/Secuencia.cpp $(INCLUDE)/Secuencia.h \
                     $(INCLUDE)/TipoBase.h
	g++ -c -o $(OBJ)/Secuencia.o $(SRC)/Secuencia.cpp -I$(INCLUDE) -std=c++14
	
$(OBJ)/NumeraLineas_Ampliacion.o : $(SRC)/NumeraLineas_Ampliacion.cpp
	g++ -c -o $(OBJ)/NumeraLineas_Ampliacion.o \
	          $(SRC)/NumeraLineas_Ampliacion.cpp -std=c++14
	          

#................................................
# BIBLIOTECAS
$(LIB)/libMatriz2D.a : $(OBJ)/Matriz2D.o
	ar rvs $(LIB)/libMatriz2D.a $(OBJ)/Matriz2D.o
	
$(LIB)/libSecuencia.a : $(OBJ)/Secuencia.o
	ar rvs $(LIB)/libSecuencia.a $(OBJ)/Secuencia.o

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

