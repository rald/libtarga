libtarga.a: libtarga.o
	ar rcs libtarga.a libtarga.o

libtarga.o: libtarga.c
	gcc -c libtarga.c

game:	game.o
	gcc game.o -o game -I. -L. -ltarga

game.o: game.c
	gcc -c game.c

.PHONY: clean

clean:
	rm game.o game libtarga.o libtarga.a output.tga
