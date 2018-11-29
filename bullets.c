#include "bullets.h"

//Broj raspolozenih metkova, init
int gravityBullets = MAX_GRAVITY_BULLETS;
int colorBullets = MAX_COLOR_BULLETS;
int fadeBullets = MAX_FADE_BULLETS;

int firedBulletCounter = 0; //Ide od 0 do max fired bullets
Bullet firedBullets[MAX_FIRED_BULLETS];

void drawBullets(void){
    
    for(int i = 0; i < MAX_FIRED_BULLETS; i++){
        if(!firedBullets[i].fired)
            break;
        
        float x = firedBullets[i].posx;
        float y = firedBullets[i].posy;
        float z = firedBullets[i].posz; //Pomeramo bullet za mali deo, dt???

        //color u odnosu na tip

        glPushMatrix();
            glTranslated(x, y, z);
            glScalef(1, 1, 6);
            glutSolidCube(0.15);
        glPopMatrix();
    }
}

void moveBullets(void){
    
    for(int i = 0; i < MAX_FIRED_BULLETS; i++){
        if(!firedBullets[i].fired)
            continue;

        firedBullets[i].posz += 0.1;
    }
}

void fireBullet(int bulletType, float x, float y, float z){
    //napraviti novi bullet koji krece od pozicije playuera kad je ispaljen
    // i leti u +z

    firedBullets[firedBulletCounter].posx = x;
    firedBullets[firedBulletCounter].posy = y;
    firedBullets[firedBulletCounter].posz = z;
    firedBullets[firedBulletCounter].bulletType = bulletType;
    firedBullets[firedBulletCounter].fired = 1;

    if(firedBulletCounter < MAX_FIRED_BULLETS)
        firedBulletCounter++;
    else
        firedBulletCounter = 0;
}