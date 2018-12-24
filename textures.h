#ifndef TEXTURES_H
#define TEXTURES_H

#include "image.h"
#include "player.h"

#include <GL/glut.h>
#include <stdio.h>

#define SKYBOX_SIZE 8

#define SKY_TEXTURE "sky.bmp"
#define SHIP_TEXTURE "spaceShip.bmp"

void initTextures(void);
void skyBoxDraw(void);
void playerTextureDraw(void);

extern GLuint names[2];
extern Image * image;

#endif