bla: main.c input.c lighting.c camera.c player.c bullets.c collisions.c obstacle.c image.c utilities.c textures.c
	gcc -o bla main.c image.c textures.c input.c lighting.c camera.c player.c bullets.c collisions.c utilities.c obstacle.c -lglut -lGLU -lGL -lm

.PHONY: clean

clean:
	-rm *.o 