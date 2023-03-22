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

all: presentacion $(BIN)/I_MezclaArrays $(BIN)/I_MezclaArrays_ref \
     $(BIN)/I_DemoSecuenciaEnteros $(BIN)/I_Inflacion_Matriz clean
	@echo Terminado


#......................................
# EJECUTABLES

$(BIN)/I_MezclaArrays : $(OBJ)/I_MezclaArrays.o	\
                    	$(OBJ)/ProcesamientoArrayInt.o \
						$(OBJ)/GeneradorAleatorioEnteros.o \
						$(LIB)/libProcesamientoArrayInt.a         
	g++ -o $(BIN)/I_MezclaArrays $(OBJ)/I_MezclaArrays.o \
	       $(OBJ)/ProcesamientoArrayInt.o \
	       $(OBJ)/GeneradorAleatorioEnteros.o -lProcesamientoArrayInt -L$(LIB)

$(BIN)/I_MezclaArrays_ref : $(OBJ)/I_MezclaArrays_ref.o	\
                    		$(OBJ)/ProcesamientoArrayInt.o \
		    				$(OBJ)/GeneradorAleatorioEnteros.o \
		    				$(LIB)/libProcesamientoArrayInt.a      
	g++ -o $(BIN)/I_MezclaArrays_ref $(OBJ)/I_MezclaArrays_ref.o \
	       $(OBJ)/ProcesamientoArrayInt.o \
	       $(OBJ)/GeneradorAleatorioEnteros.o -lProcesamientoArrayInt -L$(LIB)

$(BIN)/I_DemoSecuenciaEnteros : $(OBJ)/I_DemoSecuenciaEnteros.o	\
                    			$(OBJ)/SecuenciaEnteros.o \
								$(OBJ)/GeneradorAleatorioEnteros.o \
								$(LIB)/libGeneradorAleatorioEnteros.a    
	g++ -o $(BIN)/I_DemoSecuenciaEnteros $(OBJ)/I_DemoSecuenciaEnteros.o \
	       $(OBJ)/SecuenciaEnteros.o \
		   $(OBJ)/GeneradorAleatorioEnteros.o \
		   -lGeneradorAleatorioEnteros -L$(LIB)
		   
$(BIN)/I_Inflacion_Matriz : $(OBJ)/I_Inflacion_Matriz.o
	g++ -o $(BIN)/I_Inflacion_Matriz $(OBJ)/I_Inflacion_Matriz.o


#......................................
# OBJETOS
	
$(OBJ)/I_MezclaArrays.o : $(SRC)/I_MezclaArrays.cpp \
                      	  $(INCLUDE)/GeneradorAleatorioEnteros.h \
                      	  $(INCLUDE)/ProcesamientoArrayInt.h
	g++ -c -o $(OBJ)/I_MezclaArrays.o $(SRC)/I_MezclaArrays.cpp \
	          -I$(INCLUDE) -std=c++14

$(OBJ)/I_MezclaArrays_ref.o : $(SRC)/I_MezclaArrays_ref.cpp \
                      $(INCLUDE)/GeneradorAleatorioEnteros.h \
                      $(INCLUDE)/ProcesamientoArrayInt.h
	g++ -c -o $(OBJ)/I_MezclaArrays_ref.o $(SRC)/I_MezclaArrays_ref.cpp \
	          -I$(INCLUDE) -std=c++14

$(OBJ)/ProcesamientoArrayInt.o : $(SRC)/ProcesamientoArrayInt.cpp \
                  				 $(INCLUDE)/ProcesamientoArrayInt.h \
                       		     $(INCLUDE)/GeneradorAleatorioEnteros.h 
	g++ -c -o $(OBJ)/ProcesamientoArrayInt.o $(SRC)/ProcesamientoArrayInt.cpp \
	    	  -I$(INCLUDE) -std=c++14

$(OBJ)/GeneradorAleatorioEnteros.o : $(SRC)/GeneradorAleatorioEnteros.cpp \
									 $(INCLUDE)/GeneradorAleatorioEnteros.h
	g++ -c -o $(OBJ)/GeneradorAleatorioEnteros.o \
	          $(SRC)/GeneradorAleatorioEnteros.cpp \
	          -I$(INCLUDE) -std=c++14

$(OBJ)/I_DemoSecuenciaEnteros.o : $(SRC)/I_DemoSecuenciaEnteros.cpp	\
								  $(INCLUDE)/SecuenciaEnteros.h
	g++ -c -o $(OBJ)/I_DemoSecuenciaEnteros.o \
	    	  $(SRC)/I_DemoSecuenciaEnteros.cpp -I$(INCLUDE) -std=c++14

$(OBJ)/SecuenciaEnteros.o : $(SRC)/SecuenciaEnteros.cpp \
    						$(INCLUDE)/SecuenciaEnteros.h \
							$(INCLUDE)/GeneradorAleatorioEnteros.h
	g++ -c -o $(OBJ)/SecuenciaEnteros.o \
			  $(SRC)/SecuenciaEnteros.cpp -I$(INCLUDE) -std=c++14
			  
$(OBJ)/I_Inflacion_Matriz.o : $(SRC)/I_Inflacion_Matriz.cpp
	g++ -c -o $(OBJ)/I_Inflacion_Matriz.o $(SRC)/I_Inflacion_Matriz.cpp \
			  -std=c++14

#......................................
# BIBLIOTECAS

$(LIB)/libSecuenciaEnteros.a : $(OBJ)/SecuenciaEnteros.o
	ar rvs $(LIB)/libSecuenciaEnteros.a $(OBJ)/SecuenciaEnteros.o
	
$(LIB)/libProcesamientoArrayInt.a : $(OBJ)/ProcesamientoArrayInt.o
	ar rvs $(LIB)/libProcesamientoArrayInt.a $(OBJ)/ProcesamientoArrayInt.o
	
$(LIB)/libGeneradorAleatorioEnteros.a : $(OBJ)/GeneradorAleatorioEnteros.o
	ar rvs $(LIB)/libGeneradorAleatorioEnteros.a \
	       $(OBJ)/GeneradorAleatorioEnteros.o

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

