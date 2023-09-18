
all: perfil.o
	gcc main.c perfil.o -o coltegram

debugger: debperfil.o
	gcc main.c perfil.o -o coltegram -g

debperfil.o: perfil.h
	gcc -c perfil.c -g

perfil.o: perfil.h
	gcc -c perfil.c

clean:
	rm -r *.o 