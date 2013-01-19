CFLAGS=-g -O2 -Wall -Isrc -rdynamic -static $(OPTFLAGS)
LIBS=-ldl $(OPTLIBS)

all:
	mkdir -p build
	mkdir -p bin
	cc $(CFLAGS) -c src/darray.c -o build/darray.o
	ar rcs build/libdarray.a build/darray.o

test:
	cc tests/test_darray.c $(CFLAGS) -Lbuild -ldarray -o bin/test_darray
	bin/test_darray

clean:
	rm -rf bin
	rm -rf build
