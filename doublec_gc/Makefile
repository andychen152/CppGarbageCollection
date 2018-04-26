UNAME=$(shell uname -s)

ifeq "$(UNAME)" "Darwin"
INCLUDE=-I/opt/local/include
LIB=-L/opt/local/lib
endif

INCLUDE=
LIB=
CFLAGS=-g

all: libGC.a

tests: libGC.a node.h
	g++ tests/test_simple.cpp node.h -L. -lGC -o simple_tests

libGC.a: gc.o
	ar r libGC.a gc.o

gc.o: gc.cpp gc.h
	g++ $(INCLUDE) $(CFLAGS) -c -o gc.o gc.cpp

clean: 
	rm *.o simple_tests libGC.a *.gch
