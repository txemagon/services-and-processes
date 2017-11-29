CC=gcc
LIBDIR=./lib
INCDIR=./include
LIB=comm

# Add -DNDEBUG to CFLAGS to get rid of debugging information.
CFLAGS=-g -I$(INCDIR)
LDFLAGS=-L$(LIBDIR)
LDLIB=-l$(LIB)

all: $(LIB) hijo padre clean

$(LIB): $(LIB).o
	$(CC) $(CFLAGS) -o $(LIBDIR)/lib$(LIB).so -fPIC -shared $<

$(LIB).o: $(LIB).cpp
	$(CC) $(CFLAGS) -fPIC -c $<

hijo: hijo.o
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) $(LDLIB)

hijo.o: hijo.cpp
	$(CC) $(CFLAGS) -c $<

padre: padre.o
	$(CC) $(CFLAGS) -o $@ $<

padre.o: padre.cpp
	$(CC) $(CFLAGS) -c $<

.PHONY: clean install uninstall

install:
	cp $(LIBDIR)/lib$(LIB).so /usr/lib

uninstall:
	$(RM) /usr/lib/lib$(LIB).so
clean:
	$(RM) *.o
