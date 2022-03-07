# Makefile

CC		:= g++
CFLAGS	:= -Wall -O3 -std=c++2a -pedantic -c -o
LDFLAGS	:= -s -o
LDLIBS	:= -L. -lmsgdyn -lrt
DYNLIB	:= -Wl,-rpath ./

.PHONY: all clean cleano cleantxt

all: BubbleSort.x SelectionSort.x InsertionSort.x CountingSort.x Generator.x GeneratorCS.x

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
	
BubbleSort.o: BubbleSort.cpp
BubbleSort.x: BubbleSort.o
SelectionSort.o: SelectionSort.cpp
SelectionSort.x: SelectionSort.o
InsertionSort.o: InsertionSort.cpp
InsertionSort.x: InsertionSort.o
CountingSort.o: CountingSort.cpp
CountingSort.x: CountingSort.o
Generator.o: Generator.cpp
Generator.x: Generator.o
GeneratorCS.o: GeneratorCS.cpp
GeneratorCS.x: GeneratorCS.o