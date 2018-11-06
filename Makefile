
batoKockica: main.c lighting.c camera.c 
	gcc -o batoKockica main.c lighting.c camera.c -lglut -lGLU -lGL -lm

.PHONY: clean

clean:
	-rm *.o 
