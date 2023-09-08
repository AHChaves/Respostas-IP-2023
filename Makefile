coltegram: 
	gcc main.o perfil.o -o coltegram

main.o: main.c
	gcc -c main.c

perfil.o: perfil.c perfil.h
	gcc  -c perfil.c

clean:
	rm *.o coltegram