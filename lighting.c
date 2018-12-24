#include "lighting.h"

int lights[2] = { GL_LIGHT0, GL_LIGHT1 };

Lighting lightingAtPlayer = { 1, 1, 1 };
Lighting ambientLighting = { 0, 8, 0 };

void initAmbientLighting(void){
    GLfloat ambientLight[] = {0.6, 0.6, 0.4, 1};
    GLfloat diffuseLight[] = {0.4, 0.4, 0.4, 1};
    GLfloat specularLight[] = {0.4, 0.4, 0.4, 1};

    glLightfv(lights[AMBIENT_LIGHTING], GL_AMBIENT, ambientLight);
    glLightfv(lights[AMBIENT_LIGHTING], GL_DIFFUSE, diffuseLight);
    glLightfv(lights[AMBIENT_LIGHTING], GL_SPECULAR, specularLight);

    glLightf(lights[AMBIENT_LIGHTING], GL_CONSTANT_ATTENUATION, 1);
}

void setAmbientLightingPosition(void){
    GLfloat lightPosition[] = {
        0, 6, 4, 0
    };

    glLightfv(lights[AMBIENT_LIGHTING], GL_POSITION, lightPosition);
    glEnable(lights[AMBIENT_LIGHTING]);
}

void initPlayerLighting(void){
    GLfloat ambientLight[] = {0, 0, 0, 1};
    GLfloat diffuseLight[] = {0.3, 1, 1, 1};
    GLfloat specularLight[] = {1, 1, 1, 1};

    glLightfv(lights[PLAYER_LIGHTING], GL_AMBIENT, ambientLight);
    glLightfv(lights[PLAYER_LIGHTING], GL_DIFFUSE, diffuseLight);
    glLightfv(lights[PLAYER_LIGHTING], GL_SPECULAR, specularLight);

    glLightf(lights[PLAYER_LIGHTING], GL_CONSTANT_ATTENUATION, 1);
}

void setPlayerLightingPosition(void){
    lightingAtPlayer.posx = player.posx;
    lightingAtPlayer.posy = player.posy;
    //Drzimo lighting na celu playera
    lightingAtPlayer.posz = player.posz + player.size/2;

    GLfloat lightPosition[] = {
        lightingAtPlayer.posx, 
        lightingAtPlayer.posy, 
        lightingAtPlayer.posz,     1
    };

    glLightfv(lights[PLAYER_LIGHTING], GL_POSITION, lightPosition);

    glEnable(lights[PLAYER_LIGHTING]);
}