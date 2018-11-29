#ifndef INPUT_H
#define INPUT_H

#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "bullets.h"

#define ESC (27)

extern int KEY_D, KEY_A, KEY_S, KEY_W;

void onKeyboard(unsigned char key, int x, int y);
void onKeyboardUp(unsigned char key, int x, int y);
void onKeyHold(void);
bool twoButtonsPressed();

//LUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON, or GLUT_RIGHT_BUTTON. state je da l je za pustanje ili sitskanje
void onMousePressed(int button, int state, int x, int y);

#endif