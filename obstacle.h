#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "bullets.h"
#include "player.h"

#include <stdbool.h>
#include <GL/glut.h>

//Definisemo alias za struct Bullet ukoliko nije definisan u ovom header fajlu
//Cini mi se da #include ".h" ne ukljucuje i header??? Nece svakako da ga prepozna
#ifndef TYPEDEF_BULLET_DECLARED_
#define TYPEDEF_BULLET_DECLARED_
typedef struct _Bullet Bullet;
#endif

#define MAX_CUBE_SIZE 0 //Nepotrebno
#define MIN_CUBE_SIZE 0.4

#define MAX_OBSTACLES 60          //Maximum obstacla
#define MAX_CUBES_PER_OBSTACLE 15 //Svaki obstacle ima u sebi 0-15
#define OBSTACLE_SPEED 0.002
#define MAX_LEVEL 5

#define SPAWN_RATE_OBSTACLE 20 // % rate po kojim se spawnuju jedni ili drugi obstacli (ima 2 vrste)

#define COLOR_CYAN 0
#define COLOR_LIMEGREEN 1

//Sirina i duzina na kojoj se obstacli spawnuju
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

    float size; //size ce biti 1 i cim ode iza playa, da se smanji na 0.1
    bool eaten; //Indikator da li player upravo jede obstacle
    bool hitByBullet; //Indikator da li je obstacle pogodjen bulletom
}ObstacleCube;

typedef struct
{
    int numberOfCubes;
    ObstacleCube cubes[MAX_CUBES_PER_OBSTACLE];
}Obstacle;

extern int obstacleCounter;
extern Obstacle obstacles[MAX_OBSTACLES];

void drawObstacles();         // Iscrtava sve prepreke u nizu obstacles
void initObstacles();         // Init vrednosti obstacla
void generateNextWall(int z); // Generise sledece obstacle kada ove na pocetku odu iza playera
void moveObstacles();

void obstacleMaterial(int colorType);
void setObstacleCyanMaterial();
void setObstacleLimeGreenMaterial();

void hitByBullet(ObstacleCube *cube, Bullet* bullet);
#endif