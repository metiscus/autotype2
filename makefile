CC=gcc
CXX=g++
CFLAGS=-g -Wall -Wextra -MD
CXXFLAGS= -g -Wall -Wextra -MD

RAPIDXML_CXXFLAGS=-Irapidxml-1.13
CXXFLAGS+=$(RAPIDXML_CXXFLAGS)

SRC=\
	config.cc\
	main.cc\
	log.cc\
	compile.cc\

OBJ=$(SRC:.cc=.o)

default: tcc

libgetopt.a: getopt.o
	ar -rcs libgetopt.a getopt.o

tcc: $(OBJ) libgetopt.a
	$(CXX) $(CXXFLAGS) -o tcc $(OBJ) libgetopt.a

clean:
	- rm -f tcc *.o *.d
	- rm -f libgetopt.a getopt.o

-include *.d