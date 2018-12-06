#include "input.h"

//Flagovi za pritisnute dugmice
int KEY_W = 0;
int KEY_A = 0;
int KEY_S = 0;
int KEY_D = 0;

void onKeyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case ('s'):
    case ('S'):
        KEY_S = 1; // Postavljamo flag na 1 kad je dugme pritisnuto
        break;
    case ('w'):
    case ('W'):
        KEY_W = 1;
        break;
    case ('a'):
    case ('A'):
        KEY_A = 1;
        break;
    case ('d'):
    case ('D'):
        KEY_D = 1;
        break;
    case (ESC): //ESC dugme, TD: napravi define za ovo
        exit(0);
        break;
    }
}

void onKeyboardUp(unsigned char key, int x, int y)
{
    switch (key)
    {
    case ('s'):
    case ('S'):
        KEY_S = 0; // Postavljamo flag na 0 kada je dugme pusteno
        break;
    case ('w'):
    case ('W'):
        KEY_W = 0;
        break;
    case ('a'):
    case ('A'):
        KEY_A = 0;
        break;
    case ('d'):
    case ('D'):
        KEY_D = 0;
        break;
    }
}

void onMousePressed(int button, int state, int x, int y)
{ //Uzeti u obzir sirinu bulleta i poziciju odakle se metak ispaljuje

    if (state == GLUT_UP)
    {
        if (button == GLUT_LEFT_BUTTON)
            fireBullet(GRAVITY_BULLET, player.posx, player.posy, player.posz);
        else if (button == GLUT_MIDDLE_BUTTON)
            fireBullet(COLOR_BULLET, player.posx, player.posy, player.posz);
        else if (button == GLUT_RIGHT_BUTTON)
            fireBullet(FADE_BULLET, player.posx, player.posy, player.posz);
    }
}

//Indikator za dijagonalno kretanje
bool twoButtonsPressed()
{
    if (KEY_W && KEY_A || KEY_W && KEY_D)
        return true;
    else if (KEY_S && KEY_A || KEY_S && KEY_D)
        return true;
    else
        return false;
}