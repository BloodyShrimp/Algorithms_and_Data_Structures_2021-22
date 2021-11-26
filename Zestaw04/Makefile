# Makefile

CC		:= g++
CFLAGS	:= -Wall -std=c++2a -pedantic -c -o
LDFLAGS	:= -s -o
LDLIBS	:= -L. -lmsgdyn -lrt
DYNLIB	:= -Wl,-rpath ./

.PHONY: all clean cleano cleantxt

all: ArrayList.x CursorList.x

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
	
ArrayList.o: ArrayList.cpp ArrayList.hpp
ArrayList.x: ArrayList.o ArrayList.hpp
CursorList.o: CursorList.cpp CursorList.hpp
CursorList.x: CursorList.o CursorList.hpp