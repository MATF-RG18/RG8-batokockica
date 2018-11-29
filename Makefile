bla: main.c input.c lighting.c camera.c player.c bullets.c
	gcc -o bla main.c input.c lighting.c camera.c player.c bullets.c -lglut -lGLU -lGL -lm

.PHONY: clean

clean:
	-rm *.o 