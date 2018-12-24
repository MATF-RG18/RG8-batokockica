#ifndef UTILITIES_H
#define UTILITIES_H

#include "player.h"
#include <GL/glut.h>

#define MAX_LEVEL 5

#define LEVEL_4_LIMIT 500
#define LEVEL_3_LIMIT 400
#define LEVEL_2_LIMIT 200

extern int gameLevel;

void drawScore();
void drawHealths();
void drawGameOver();

void resetGame();

void increaseLevel();

void setRandomMaterial();

#endif