#ifndef PLAYER_H
#define PLAYER_H

#include "input.h"
#include "collisions.h"

#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

#define PLAYER_MAX_SPEED (0.1)

typedef struct {
    float posx;
    float posy;
    float posz;

    float size;
    float accelerate; //Vrednost izmedju 0-1, ubrzavanje do maksimalne brzine

    float lives;
}Player;

extern Player player;
extern int dt;

void movePlayer(void);
void drawPlayer(void);

#endif