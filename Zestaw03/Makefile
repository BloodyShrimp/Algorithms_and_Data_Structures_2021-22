# Makefile

CC		:= g++
CFLAGS	:= -Wall -std=c++2a -pedantic -c -o
LDFLAGS	:= -s -o
LDLIBS	:= -L. -lmsgdyn -lrt
DYNLIB	:= -Wl,-rpath ./

.PHONY: all clean cleano cleantxt

all: LinkedList.x Generator.x

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
	
LinkedList.o: LinkedList.cpp LinkedList.hpp
LinkedList.x: LinkedList.o LinkedList.hpp
Generator.o: Generator.cpp
Generator.x: Generator.o