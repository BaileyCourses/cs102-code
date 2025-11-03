CC=g++
CXX=g++
CXXFLAGS=-g

run: tests
	./tests

tests: tests.o test-driver.o List.o

test-driver.o: test-driver.cc

tests.o: tests.cc List.h

valgrind:
	valgrind --leak-check=yes driver

clean:
	/bin/rm -f *.o *~ tests
