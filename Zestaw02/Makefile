# Makefile

CC		:= g++
CFLAGS	:= -Wall -std=c++2a -pedantic -c -o
LDFLAGS	:= -s -o
LDLIBS	:= -L. -lmsgdyn -lrt
DYNLIB	:= -Wl,-rpath ./

.PHONY: all clean cleano cleantxt

all: Queue.x Generator.x Radix.x

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
	
Queue.o: Queue.cpp ArrayQueue.hpp LinkedQueue.hpp
Queue.x: Queue.o ArrayQueue.hpp LinkedQueue.hpp
Radix.o: Radix.cpp ArrayQueue.hpp LinkedQueue.hpp
Radix.x: Radix.o ArrayQueue.hpp LinkedQueue.hpp
Generator.o: Generator.cpp
Generator.x: Generator.o