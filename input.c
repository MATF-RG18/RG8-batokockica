#include "input.h"

//Flagovi za pritisnute dugmice
bool KEY_W = false;
bool KEY_A = false;
bool KEY_S = false;
bool KEY_D = false;
bool fullScreen = false;

void onKeyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case ('s'):
    case ('S'):
        //Postavljamo flag na 1 kad je dugme pritisnuto
        KEY_S = true;
        break;
    case ('w'):
    case ('W'):
        KEY_W = true;
        break;
    case ('a'):
    case ('A'):
        KEY_A = true;
        break;
    case ('d'):
    case ('D'):
        KEY_D = true;
        break;
    case ('f'):
    case ('F'):
        fullScreen = fullScreen ? false : true;
        if(fullScreen)
            glutFullScreen();
        else
            glutReshapeWindow(1700, 800);
        break;
    case ('r'):
    case ('R'):
        resetGame();
        break;
    case (ESC): 
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
        // Postavljamo flag na 0 kada je dugme pusteno
        KEY_S = 0; 
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
{   //Klikom misa, TEK kada pustimo klik ispalicemo bullet
    if (state == GLUT_UP)
    {                 
        //Svaki od 3 klika ispaljuje razliciti bullet
        if (button == GLUT_RIGHT_BUTTON) 
            fireBullet(GRAVITY_BULLET, player.posx, player.posy, player.posz);
        else if (button == GLUT_MIDDLE_BUTTON)
            fireBullet(COLOR_BULLET, player.posx, player.posy, player.posz);
        else if (button == GLUT_LEFT_BUTTON)
            fireBullet(FADE_BULLET, player.posx, player.posy, player.posz);
    }
}

//Vraca tacno ukoliko su aktivni dugmici za dijagonalno kretanje
bool twoButtonsPressed()
{
    if (KEY_W && KEY_A || KEY_W && KEY_D)
        return true;
    else if (KEY_S && KEY_A || KEY_S && KEY_D)
        return true;
    else
        return false;
}