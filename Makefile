
all: perfil.o
	gcc main.c perfil.o -o coltegram

perfil.o: perfil.h
	gcc -c perfil.c

clean:
	rm -r *.o 