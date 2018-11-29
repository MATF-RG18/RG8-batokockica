#include "player.h"

Player player = {0, 2, 0, 0, 0};

void movePlayer(void)
{

    float d = dt / 15; // deltaTime, hocemo da kretanje playera bude nezavisno od frejmova
    float speed = PLAYER_MAX_SPEED;

    if (twoButtonsPressed())
        speed /= sqrt(2); //Ukoliko je kretanje dijagonalno, brzinu delimo sa korenom iz dva
                          //Time se player nece kretati vecom brzinom nego inace

    //Povecavamo ubrzanje do 1 ukoliko se drzi dugme konstantno
    if (player.accelerate < 1)
        player.accelerate += 0.05;
    

    if(!KEY_A && !KEY_D && !KEY_S && !KEY_W)
        player.accelerate = 0;

    if (KEY_W)
    {
        player.posy += d * speed * player.accelerate;
        printf("%f\n", speed * player.accelerate);
    }
    if (KEY_S)
    {
        player.posy -= d * speed * player.accelerate;
    }
    if (KEY_A)
    {
        player.posx += d * speed * player.accelerate;
        printf("%f\n", speed * player.accelerate);

    }
    if (KEY_D)
    {
        player.posx -= d * speed * player.accelerate;
    }
}

void drawPlayer(void)
{
    glPushMatrix();
    glTranslatef(player.posx, player.posy, player.posz);
    glutSolidCube(1);
    glPopMatrix();
}