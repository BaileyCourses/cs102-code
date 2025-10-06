lab: lab.o Queue.o
	g++ -g -o lab lab.o Queue.o

Queue.o: Queue.cc Queue.h
	g++ -g -c Queue.cc

lab.o: lab.cc Queue.h
	g++ -g -c lab.cc

valgrind: lab
	valgrind --leak-check=yes lab
