# Makefile

CC		:= g++
CFLAGS	:= -std=c++14 -pedantic -Wall -o
LDFLAGS	:= -s -o
LDLIBS	:= -L. -lmsgdyn -lrt
DYNLIB	:= -Wl,-rpath ./

.PHONY: all clean cleano cleantxt

all: main.x

%.x: %.o
	$(CC) $(LDFLAGS) $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) $@ $<

%.x: %.cpp
	$(CC) $(CFLAGS) $@ $^

clean:
	$(RM) *.o *.x

cleano:
	$(RM) *.o

cleantxt:
	$(RM) *.txt
	
main.x: main.cpp pqueue.hpp