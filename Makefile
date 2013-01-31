CFLAGS=-g -O2 -Wall -Isrc -rdynamic -static $(OPTFLAGS)
LIBS=-ldl $(OPTLIBS)
SOURCES=src

all:
	mkdir -p build
	mkdir -p bin
	cc $(CFLAGS) -I$(SOURCES) -c src/darray.c -o build/darray.o
	ar rcs build/libdarray.a build/darray.o
	cc $(CFLAGS) -I$(SOURCES) -c src/structure.c -Lbuild -ldarray -o build/structure.o
	ar rcs build/libstructure.a build/structure.o

test:
	cc tests/test_darray.c $(CFLAGS) -I$(SOURCES) -Lbuild -ldarray -o bin/test_darray
	cc tests/test_structure.c $(CFLAGS) -I$(SOURCES) -Lbuild -ldarray -lstructure -o bin/test_structure
	bin/test_darray
	bin/test_structure

clean:
	rm -rf bin
	rm -rf build
