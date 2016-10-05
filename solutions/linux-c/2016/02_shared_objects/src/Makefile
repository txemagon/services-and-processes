.PHONY: dist clean

all: rm am dist clean

rm: rm.o
	g++ -o rm rm.o -L../lib -lticket

rm.o: rm.cpp
	g++ -c rm.cpp -I../include

am: am.o
	g++ -o am am.o -L../lib -lticket

am.o: am.cpp
	g++ -c am.cpp -I../include

dist:
	mv ?m ../bin

clean:
	$(RM) *.o


