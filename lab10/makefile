CC=g++
CXX=g++
CXXFLAGS=-g

run: lab
	make lab 2>&1 | head -15
	./lab

lab: lab.o

lab.o: lab.cc Stack.h

clean:
	/bin/rm -f lab *.o *~
