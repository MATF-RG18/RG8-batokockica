#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <math.h>
#include <stdbool.h>

#include "player.h"
#include "obstacle.h"
#include "bullets.h"

//Granice po kojoj player moze da se krece
#define PLAYER_MOVEMENT_WIDTH 10
#define PLAYER_MOVEMENT_HEIGHT 5

typedef struct {
    float x;
    float y;
}Point;

//Playera movement
bool canMoveLeft();
bool canMoveRight();
bool canMoveUp();
bool canMoveDown();

bool cubeIntersect(float x1, float y1, float z1, float size1, float x2, float y2, float z2, float size2);

bool playerObstacleCollision();
bool bulletObstacleCollision();
#endif