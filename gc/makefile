UNAME=$(shell uname -s)

ifeq "$(UNAME)" "Darwin"
INCLUDE=-I/opt/local/include
LIB=-L/opt/local/lib
endif

INCLUDE=
LIB=
CFLAGS=-g

all: libGC.a 

test: libGC.a node.h
	g++ test_simple.cpp node.h -o simple_test -L. -lGC

tests: libGC.a node.h BigNode.h
	g++ tests/test_simple.cpp node.h BigNode.h -L. -lGC

libGC.a: gc.o
	ar r libGC.a gc.o

gc.o: gc.cpp gc.h
	g++ $(INCLUDE) $(CFLAGS) -c -o gc.o gc.cpp

clean: 
	rm *.o
	rm a.out
	rm simple_test
	rm libGC.a
