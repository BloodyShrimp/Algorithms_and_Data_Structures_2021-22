# Makefile

CC		:= g++
CFLAGS	:= -std=c++14 -pedantic -Wall -o
LDFLAGS	:= -s -o
LDLIBS	:= -L. -lmsgdyn -lrt
DYNLIB	:= -Wl,-rpath ./

.PHONY: all clean cleano cleantxt

all: main_klasa.x main_szablon.x main_float.x

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
	
main_klasa.x: main_klasa.cpp stos_klasa.cpp stos_klasa.hpp
main_szablon.x: stos_szablon.cpp stos_szablon.hpp
main_float.x: main_float.cpp stos_szablon.hpp