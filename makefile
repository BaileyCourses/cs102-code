lab: lab.o Widget.o
	g++ -o lab lab.o Widget.o

lab.o: lab.cc Widget.h
	g++ -c lab.cc

Widget.o: Widget.cc Widget.h
	g++ -c Widget.cc
