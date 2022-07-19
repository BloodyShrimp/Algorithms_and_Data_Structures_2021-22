# Makefile

CC		:= g++
CFLAGS	:= -std=c++14 -pedantic -Wall -lcppunit -o
LDFLAGS	:= -s -o
LDLIBS	:= -L. -lmsgdyn -lrt
DYNLIB	:= -Wl,-rpath ./

.PHONY: all clean cleano cleantxt

all: 2_problem.x

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
	
2_problem.x: 2_problem.cpp graph.cpp graph.hpp