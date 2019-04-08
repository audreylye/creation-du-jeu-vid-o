prog:main.o enigme.o getpixel.o collision.o scroll.o sous.o
	gcc   main.o enigme.o getpixel.o collision.o scroll.o sous.o -o khalil -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
main.o:main.c
	gcc -c main.c

enigme.o:enigme.c
	gcc -c enigme.c

collision.o:collision.c
	gcc -c collision.c

scroll.o:scroll.c
	gcc -c scroll.c

getpixel.o:getpixel.c
	gcc -c getpixel.c

sous.o:sous.c
	gcc -c sous.c
