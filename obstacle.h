#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <stdbool.h>
#include <GL/glut.h>
#include "player.h"

#define MAX_OBSTACLES 60          //Maximum obstacla
#define MAX_CUBES_PER_OBSTACLE 17 //Svaki obstacle ima u sebi 0-20 kockica
#define OBSTACLE_SPEED 0.02


#define OBSTACLE_MOVEMENT_WIDTH 12
#define OBSTACLE_MOVEMENT_HEIGHT 6

typedef struct
{
    float posx;
    float posy;
    float posz;

    float vecx;
    float vecy;
    float vecz;

    float speed;
    float size; //size ce biti 1 i cim ode iza playa, da se smanji na 0.1
    bool fade;  // 0 1 TD: macroi, da li crtati ili ne
    bool color; // TD: macroi
} ObstacleCube;

typedef struct
{
    int numberOfCubes;
    ObstacleCube cubes[MAX_CUBES_PER_OBSTACLE];
} Obstacle;

extern int obstacleCounter;
extern Obstacle obstacles[MAX_OBSTACLES];

void drawObstacles();         // Iscrtava sve prepreke u nizu obstacles
void initObstacles();         // Init vrednosti obstacla
void generateNextWall(int z); // Generise sledece obstacle kada ove na pocetku odu iza playera
void moveObstacles();

#endif