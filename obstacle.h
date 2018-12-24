#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "bullets.h"
#include "player.h"
#include "utilities.h"
#include "camera.h"

#include <stdbool.h>
#include <GL/glut.h>

//Definisemo alias za struct Bullet ukoliko nije definisan u ovom header fajlu
#ifndef TYPEDEF_BULLET_DECLARED_
#define TYPEDEF_BULLET_DECLARED_
typedef struct _Bullet Bullet;
#endif

#define MAX_CUBE_SIZE 0 //Nepotrebno
#define MIN_CUBE_SIZE 0.4

#define MAX_OBSTACLES 60          //Maximum obstacla
#define MAX_CUBES_PER_OBSTACLE 15 //Svaki obstacle ima u sebi 0-15
#define OBSTACLE_SPEED 0.002

// % rate po kojim se spawnuju jedni ili drugi obstacli (ima 2 vrste)
#define SPAWN_RATE_OBSTACLE 20 

#define COLOR_CYAN 0
#define COLOR_LIMEGREEN 1

//Sirina i duzina na kojoj se obstacli mogu spawnovati
#define OBSTACLE_MOVEMENT_WIDTH 12
#define OBSTACLE_MOVEMENT_HEIGHT 6

typedef struct _ObstacleCube
{
    float posx;
    float posy;
    float posz;

    float vecx;
    float vecy;
    float vecz;

    int colorType; //Color types;

    float size; 
    bool eaten; //Indikator da li player upravo jede obstacle
    bool hitByBullet; //Indikator da li je obstacle pogodjen bulletom
}ObstacleCube;

//Obstacle se sastoji od kocki koji su na istoj x osi
typedef struct
{
    int numberOfCubes;
    ObstacleCube cubes[MAX_CUBES_PER_OBSTACLE];
}Obstacle;

extern int obstacleCounter;
extern Obstacle obstacles[MAX_OBSTACLES];

void drawObstacles();         // Iscrtava sve prepreke u nizu obstacles
void initObstacles();         // Init vrednosti obstacla
void generateNextWall(int z); // Generise sledece obstacle na poziciji z kada ove na pocetku odu iza playera
void moveObstacles();

void obstacleMaterial(int colorType);
void setObstacleCyanMaterial();
void setObstacleLimeGreenMaterial();

void hitByBullet(ObstacleCube *cube, Bullet* bullet);

#endif