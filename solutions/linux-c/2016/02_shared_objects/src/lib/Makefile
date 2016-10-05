.PHONY: dist clean

all: ticket dist clean

ticket: ticket.cpp
	g++ -c -I ../../include -fPIC ticket.cpp
	g++ -shared -fPIC -o libticket.so ticket.o

dist:
	mv libticket.so ../../lib

clean:
	$(RM) *.o


