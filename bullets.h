#ifndef BULLETS_H
#define BULLETS_H

#include "player.h"

#define MAX_BULLET_SPEED 0.05

//Maximum bulleta iste vrste koji mozemo sakupiti
#define MAX_GRAVITY_BULLETS 15
#define MAX_COLOR_BULLETS 15
#define MAX_FADE_BULLETS 15

#define MAX_FIRED_BULLETS 45

//Bullet types, enum?
#define GRAVITY_BULLET 0
#define COLOR_BULLET 1
#define FADE_BULLET 2

//Broj bulleta odredjene vrste koji trenutno imamo na raspolaganju
extern int gravityBullets;
extern int colorBullets;
extern int fadeBullets;

//Bullet koji je opaljen i koji treba da renderujemo/pomeramo, sudaramo sa objektima
typedef struct {
    float posx;
    float posy;
    float posz;

    float width;
    float height;

    int bulletType; //Bullet type
    int fired;
}Bullet;

//Ovde bi bilo korisnije da smo implementirali listu i isli preko toga, lazy for that :(
extern int firedBulletCounter; // Ide od 0 do MAX_FIRED_BULLETS pa u krug
extern Bullet firedBullets[MAX_FIRED_BULLETS];

void drawBullets(void);
void moveBullets(void);
void fireBullet(int bulletType, float x, float y, float z); //bullet leti prema 

void setBulletMaterial(int type);
void gravityBulletMaterial();
void colorBulletMaterial();
void fadeBulletMaterial();

#endif