#ifndef PLAYER_H
#define PLAYER_H

//Potrebno nam je ovo ukoliko hocemo da koristimo type alias iz drugog headera
#ifndef TYPEDEF_OBSTACLECUBE_DECLARED_
#define TYPEDEF_OBSTACLECUBE_DECLARED_
typedef struct _ObstacleCube ObstacleCube;
#endif

#include "input.h"
#include "collisions.h"
#include "obstacle.h"
#include "textures.h"

#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

#define PLAYER_MAX_SPEED (0.1)

typedef struct {
    float posx;
    float posy;
    float posz;

    float size;
    float accelerate;
                       //blue + green = 1;
    float greenColor; //Init vrednost je nula
    float blueColor; //Init vrednost je 1 i predstavlja helte playera
    float score;   
}Player;            

extern Player player;
extern int dt;

void movePlayer(void);
void drawPlayer(void);
void setPlayerMaterial(void);

void eatCube(ObstacleCube* cube);

bool decayPlayerHealths(float d);
void increasePlayerScore(float d);

void killPlayer(void);
#endif