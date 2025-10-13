CC=g++
CXX=g++
CFLAGS=-g

lab: lab.o List.o

tests:  tests.o test-driver.o List.o

lab.o: lab.cc List.h

tests.o: tests.cc List.h

List.o: List.cc List.h

test-driver.o: test-driver.cc

valgrind: lab
	valgrind --leak-check=yes lab

clean:
	/bin/rm -f *.o lab tests
