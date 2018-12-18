#ifndef TEXTURES_H
#define TEXTURES_H

#include "image.h"
#include <GL/glut.h>
#include <stdio.h>
#include "player.h"

#define SKY_TEXTURE "sky.bmp"
#define SHIP_TEXTURE "spaceShip.bmp"

#define SKYBOX_SIZE 8

void initTextures(void);
void skyBoxDraw(void);
void playerTextureDraw(void);


extern GLuint names[2];
extern Image * image;

#endif