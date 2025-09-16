lab:	lab.o SafeArray.o
	g++ -o lab lab.o SafeArray.o

SafeArray.o:	SafeArray.cc SafeArray.h
	g++ -c SafeArray.cc

lab.o:	lab.cc SafeArray.h
	g++ -c lab.cc

clean:
	/bin/rm -f *.o lab *~
