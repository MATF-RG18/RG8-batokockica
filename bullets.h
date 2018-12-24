#ifndef BULLETS_H
#define BULLETS_H

#include "player.h"

#define MAX_BULLET_SPEED 0.05

//Init vrednosti bulleta
#define INIT_GRAVITY_BULLETS 15
#define INIT_COLOR_BULLETS 15
#define INIT_FADE_BULLETS 15

//Max bulleta koje mozemo istovremeno renderovati
#define MAX_FIRED_BULLETS 45

//Tipovi bulleta
//Salje obstacle po Y osi ka gore
#define GRAVITY_BULLET 0
//Menja boju bulleta
#define COLOR_BULLET 1
//Smanjuje size bulleta dok ne nestane 
#define FADE_BULLET 2 

//Broj bulleta odredjene vrste koji trenutno imamo na raspolaganju
extern int gravityBullets;
extern int colorBullets;
extern int fadeBullets;

//Bullet koji je opaljen i koji treba da renderujemo/pomeramo, sudaramo sa objektima
typedef struct _Bullet{
    float posx;
    float posy;
    float posz;

    float width;
    float height;

    int bulletType; 
    //Indikator da li je bullet opaljen i da li leti
    bool fired; 
}Bullet;

//Ovde bi bilo korisnije da smo implementirali listu i isli preko toga, lazy for that :(
extern Bullet firedBullets[MAX_FIRED_BULLETS];
//Ide od 0 do MAX_FIRED_BULLETS pa u krug
extern int firedBulletCounter; 

void drawBullets(void);
void moveBullets(void);
//Ispaljujemo bullet sa pozicije x,y,z
void fireBullet(int bulletType, float x, float y, float z);

void setBulletMaterial(int type);
void gravityBulletMaterial();
void colorBulletMaterial();
void fadeBulletMaterial();

#endif