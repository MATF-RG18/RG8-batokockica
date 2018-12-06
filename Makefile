bla: main.c input.c lighting.c camera.c player.c bullets.c collisions.c obstacle.c
	gcc -o bla main.c input.c lighting.c camera.c player.c bullets.c collisions.c obstacle.c -lglut -lGLU -lGL -lm

.PHONY: clean

clean:
	-rm *.o 