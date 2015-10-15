calculadora: titulo.o calculadora.o
	g++ -o calculadora titulo.o calculadora.o

calculadora.o: calculadora.cpp titulo.h
	g++ -c calculadora.cpp

titulo.o: titulo.cpp titulo.h
	g++ -c titulo.cpp

clean: 
	rm -f *.o

