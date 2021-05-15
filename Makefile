#
# Universidade Federal do Rio de Janeiro
# Escola Politecnica
# Departamento de Eletronica e de Computacao
# EEL670 - Linguagens de Programação
# Prof. Miguel
# Autor: Leticia Tavares
# Descricao: adaptei para este trabalho a forma como foi ensinado o Makefile na disciplina de Computacao II
#
#
# g++ -Wall main.cpp estadual.cpp nacional.cpp dados.cpp auxiliares.cpp menu.cpp -o  covidBrasil

#Compilar
CC = g++
LD = g++

#Linkeditar
CFLAGS = -Wall
LFLAGS = -Wall

#Dependencias
COVIDBRASILOBJS = main.o estadual.o  auxiliares.o dados.o menu.o nacional.o

COVIDBRASIL = covidBrasil

EXECS = $(COVIDBRASIL)

# ALL pois irei reutilizar este arquivo de Makefile para os proximos trabalhos
ALL = $(EXECS)

#Regra Implicita

.cpp.o:
	$(CC) $(CFLAGS) -c $<

all: $(ALL)

covidBrasil: $(COVIDBRASILOBJS)
	$(LD) $(LFLAGS) -o $@ $(COVIDBRASILOBJS)

clean:
	rm -f *.o $(EXECS)

clean-all:
	rm -f *.o $(EXECS)
