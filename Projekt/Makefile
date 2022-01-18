# Makefile

CC		:= g++
CFLAGS	:= -Wall -g -std=c++2a -pedantic -c -o
LDFLAGS	:= -s -o
LDLIBS	:= -L. -lmsgdyn -lrt
DYNLIB	:= -Wl,-rpath ./

.PHONY: all clean cleano cleantxt

all: main.x

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
	
main.o: main.cpp Block.hpp Block.cpp BlockChain.hpp BlockChain.cpp
main.x: main.o Block.hpp Block.cpp BlockChain.hpp BlockChain.cpp