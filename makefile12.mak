#############################################################################
#
# David Pérez Tobarra
#
# makefile12.mak
#
# ejercicios E/S
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
all:  $(BIN)/CuentaLineas $(BIN)/CopiaLineasSinAlmohadilla \
	  $(BIN)/CuentaCaracteresConcretos $(BIN)/CuentaPalabrasLongitudConcreta \
	  $(BIN)/Cuenta_palabras_por_linea $(BIN)/VerificaDatosMatriz2D
	  @echo Terminado

#................................................
# EJECUTABLES

$(BIN)/CuentaLineas : $(OBJ)/CuentaLineas.o
	g++ -o $(BIN)/CuentaLineas $(OBJ)/CuentaLineas.o
	
$(BIN)/CopiaLineasSinAlmohadilla : $(OBJ)/CopiaLineasSinAlmohadilla.o
	g++ -o $(BIN)/CopiaLineasSinAlmohadilla $(OBJ)/CopiaLineasSinAlmohadilla.o

$(BIN)/CuentaCaracteresConcretos : $(OBJ)/CuentaCaracteresConcretos.o
	g++ -o $(BIN)/CuentaCaracteresConcretos $(OBJ)/CuentaCaracteresConcretos.o
	
$(BIN)/CuentaPalabrasLongitudConcreta : $(OBJ)/CuentaPalabrasLongitudConcreta.o
	g++ -o $(BIN)/CuentaPalabrasLongitudConcreta \
	       $(OBJ)/CuentaPalabrasLongitudConcreta.o
	       
$(BIN)/Cuenta_palabras_por_linea : $(OBJ)/Cuenta_palabras_por_linea.o
	g++ -o $(BIN)/Cuenta_palabras_por_linea $(OBJ)/Cuenta_palabras_por_linea.o
	
$(BIN)/VerificaDatosMatriz2D : $(OBJ)/VerificaDatosMatriz2D.o
	g++ -o $(BIN)/VerificaDatosMatriz2D $(OBJ)/VerificaDatosMatriz2D.o
	
#................................................
# OBJETOS 

$(OBJ)/CuentaLineas.o : $(SRC)/CuentaLineas.cpp
	g++ -c -o $(OBJ)/CuentaLineas.o $(SRC)/CuentaLineas.cpp -std=c++14
	
$(OBJ)/CopiaLineasSinAlmohadilla.o : $(SRC)/CopiaLineasSinAlmohadilla.cpp
	g++ -c -o $(OBJ)/CopiaLineasSinAlmohadilla.o \
	          $(SRC)/CopiaLineasSinAlmohadilla.cpp -std=c++14
	          
$(OBJ)/CuentaCaracteresConcretos.o : $(SRC)/CuentaCaracteresConcretos.cpp
	g++ -c -o $(OBJ)/CuentaCaracteresConcretos.o \
	          $(SRC)/CuentaCaracteresConcretos.cpp -std=c++14	  
	          
$(OBJ)/CuentaPalabrasLongitudConcreta.o : \
                                     $(SRC)/CuentaPalabrasLongitudConcreta.cpp
	g++ -c -o $(OBJ)/CuentaPalabrasLongitudConcreta.o \
	          $(SRC)/CuentaPalabrasLongitudConcreta.cpp -std=c++14	 
	          
$(OBJ)/Cuenta_palabras_por_linea.o : $(SRC)/Cuenta_palabras_por_linea.cpp
	g++ -c -o $(OBJ)/Cuenta_palabras_por_linea.o \
	          $(SRC)/Cuenta_palabras_por_linea.cpp -std=c++14	 
	          
$(OBJ)/VerificaDatosMatriz2D.o : $(SRC)/VerificaDatosMatriz2D.cpp
	g++ -c -o $(OBJ)/VerificaDatosMatriz2D.o \
	          $(SRC)/VerificaDatosMatriz2D.cpp -std=c++14	

#................................................
# BIBLIOTECAS

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

