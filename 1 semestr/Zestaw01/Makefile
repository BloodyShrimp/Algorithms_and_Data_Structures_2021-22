# Makefile

CC		:= g++
CFLAGS	:= -Wall -std=c++2a -pedantic -c -o
LDFLAGS	:= -s -o
LDLIBS	:= -L. -lmsgdyn -lrt
DYNLIB	:= -Wl,-rpath ./

.PHONY: all clean cleano cleantxt

all: Stack.x Generator.x ONP.x

%.x: %.o
	$(CC) $(LDFLAGS) $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) $@ $<

clean:
	$(RM) *.o *.x

cleano:
	$(RM) *.o

cleantxt:
	$(RM) *.txt
	
Stack.o: Stack.cpp ArrayStack.hpp LinkedStack.hpp
Stack.x: Stack.o ArrayStack.hpp LinkedStack.hpp
Generator.o: Generator.cpp
Generator.x: Generator.o
ONP.o: ONP.cpp
ONP.x: ONP.o