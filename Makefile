main:
	gcc -I/usr/include/SDL/ stdutils.c entities.c SDLKiwiUtils.c main.c -o prueba.bin -L/usr/lib -lSDL -ggdb
