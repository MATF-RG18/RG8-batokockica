
bla: main.c input.c lighting.c camera.c player.c
	gcc -o bla main.c input.c lighting.c camera.c player.c  -lglut -lGLU -lGL -lm

.PHONY: clean

clean:
	-rm *.o 