#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float posx;
    float posy;
    float posz;

    float lookDirectionX;
    float lookDirectionY;
    float lookDirectionZ;
    //Minimalno pomeranje zajedno sa playerom?
}Camera;

extern Camera camera;

void setCameraPosition();

#endif