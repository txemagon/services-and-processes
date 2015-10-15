calculadora: calculadora.o titulo.o funciones.o
	g++ -o calculadora calculadora.o titulo.o funciones.o


calculadora.o: calculadora.cpp titulo.h funciones.h
	g++ -c calculadora.cpp

titulo.o: titulo.cpp titulo.h
	g++ -c titulo.cpp

funciones.o: funciones.h funciones.cpp
	g++ -c funciones.cpp

.PHONY: clean

clean:
	rm -f *.o calculadora
