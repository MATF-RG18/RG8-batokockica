#ifndef LIGHTING_H
#define LIGHTING_H

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include "player.h"
#define AMBIENT_LIGHTING (0)
#define PLAYER_LIGHTING (1)

extern int lights[2];

typedef struct{
    float posx;
    float posy;
    float posz;
}Lighting;

extern Lighting lightingAtPlayer; 
extern Lighting ambientLighting;

void initAmbientLighting(void);
void setAmbientLightingPosition(void);

void initPlayerLighting(void);
void setPlayerLightingPosition(void);

#endif