CC=g++

all: e dist

e: e.o interfaz.o
	$(CC) -o e e.o interfaz.o

e.o: e.cpp interfaz.h
	$(CC) $(CFLAGS) -c e.cpp

interfaz.o: interfaz.cpp interfaz.h
	$(CC) $(CFLAGS) -c interfaz.cpp

.PHONY: clean dist
clean:
	$(RM) *.o e

dist:
	$(RM) *.o
	mv e dist/
