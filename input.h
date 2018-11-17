#ifndef INPUT_H
#define INPUT_H

#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ESC (27)

extern int KEY_D, KEY_A, KEY_S, KEY_W;

void onKeyboard(unsigned char key, int x, int y);
void onKeyboardUp(unsigned char key, int x, int y);
void onKeyHold(void);
bool twoButtonsPressed();


#endif