#############################################################################
#
# METODOLOGIA DE LA PROGRAMACION
#
# (C) FRANCISCO JOSE CORTIJO BON
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
#
# basico_Matriz2D.mak
#
# Generacion del proyecto descrito en los videos 
# "Gestión de matrices dinámicas"
#
#############################################################################

HOME = .
HOME_CLASES_UTILS = .

BIN = $(HOME)/bin
SRC = $(HOME)/src
OBJ = $(HOME)/obj
LIB = $(HOME)/lib
INCLUDE = $(HOME)/include

SRC_CLASES_UTILS =  $(HOME_CLASES_UTILS)/src
OBJ_CLASES_UTILS =  $(HOME_CLASES_UTILS)/obj
LIB_CLASES_UTILS =  $(HOME_CLASES_UTILS)/lib
INCLUDE_CLASES_UTILS = $(HOME_CLASES_UTILS)/include

#................................................
all:  preambulo \
      $(BIN)/II_Demo-Matriz2D $(BIN)/II_Viajante-Comercio \
      final

#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Proyecto descrito en el video: \"Gestión de matrices dinámicas\"
	@echo
	@echo METODOLOGÍA DE LA PROGRAMACIÓN
	@echo
	@echo "("c")" Francisco José CORTIJO BON
	@echo Depto. Ciencias de la Computación e Inteligencia Artificial
	@echo Universidad de Granada
	@echo ------------------------------------------------------------
	@echo

#................................................
final: 
	@echo

#................................................
# EJECUTABLES

$(BIN)/II_Demo-Matriz2D : $(OBJ)/II_Demo-Matriz2D.o \
             $(OBJ)/Matriz2D.o 
	g++ -o $(BIN)/II_Demo-Matriz2D $(OBJ)/II_Demo-Matriz2D.o \
           $(OBJ)/Matriz2D.o 
           
$(BIN)/II_Viajante-Comercio : $(OBJ)/II_Viajante-Comercio.o $(OBJ)/Matriz2D.o \
                              $(OBJ)/FuncsVectorDinamico.o
	g++ -o $(BIN)/II_Viajante-Comercio $(OBJ)/II_Viajante-Comercio.o \
	       $(OBJ)/Matriz2D.o $(OBJ)/FuncsVectorDinamico.o

#................................................
# OBJETOS 

$(OBJ)/II_Demo-Matriz2D.o : $(SRC)/II_Demo-Matriz2D.cpp \
             $(INCLUDE)/Matriz2D.h $(INCLUDE)/FuncsVectorDinamico.h \
             $(INCLUDE)/TipoBase.h
	g++ -c -o $(OBJ)/II_Demo-Matriz2D.o $(SRC)/II_Demo-Matriz2D.cpp \
            -I$(INCLUDE) -std=c++11

$(OBJ)/Matriz2D.o : $(SRC)/Matriz2D.cpp $(INCLUDE)/Matriz2D.h \
					$(INCLUDE)/TipoBase.h
	g++ -c -o $(OBJ)/Matriz2D.o $(SRC)/Matriz2D.cpp -I$(INCLUDE) -std=c++11
	
$(OBJ)/II_Viajante-Comercio.o : $(SRC)/II_Viajante-Comercio.cpp \
                                $(INCLUDE)/Matriz2D.h $(INCLUDE)/TipoBase.h
	g++ -c -o $(OBJ)/II_Viajante-Comercio.o $(SRC)/II_Viajante-Comercio.cpp \
	          -I$(INCLUDE) -std=c++11
	          
$(OBJ)/FuncsVectorDinamico.o : $(SRC)/FuncsVectorDinamico.cpp \
                               $(INCLUDE)/FuncsVectorDinamico.h
	g++ -c -o $(OBJ)/FuncsVectorDinamico.o $(SRC)/FuncsVectorDinamico.cpp \
	          -I$(INCLUDE) -std=c++14
	          

#................................................
# BIBLIOTECAS


#................................................
# LIMPEZA

clean: clean-objs 

clean-objs: 

	@echo Borrando objetos...

	-rm $(OBJ)/II_Demo-Matriz2D.o
	-rm $(OBJ)/Matriz2D.o

	@echo ...Borrados objetos
	@echo 

clean-bins : 
	@echo Borrando ejecutables...

	-rm $(BIN)/II_Demo-Matriz2D

	@echo ...Borrados ejecutables

mr.proper:  clean-objs clean-bins

