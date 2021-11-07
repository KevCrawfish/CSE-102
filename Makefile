#------------------------------------------------------------------------------
#  Makefile for Graph ADT
#
#  make                makes MWST
#  make clean          removes binary files
#------------------------------------------------------------------------------

MWST : Mwst.o Graph.o
	g++ -std=c++11 -Wall -o MWST Mwst.o Graph.o

Mwst.o : Graph.h Mwst.cpp
	g++ -std=c++11 -Wall -c Mwst.cpp

Graph.o : Graph.h Graph.cpp
	g++ -g -std=c++11 -Wall -c Graph.cpp

clean :
	rm -f MWST Mwst.o Graph.o
