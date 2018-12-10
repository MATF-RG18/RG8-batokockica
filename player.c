#include "player.h"

Player player = {0, 0, 0, 1, 0, 0, 1};

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

    if (KEY_W && canMoveUp())
    {
        player.posy += d * speed * player.accelerate;
    }
    if (KEY_S && canMoveDown())
    {
        player.posy -= d * speed * player.accelerate;
    }
    if (KEY_A && canMoveLeft())
    {
        player.posx += d * speed * player.accelerate;
    }
    if (KEY_D && canMoveRight())
    {
        player.posx -= d * speed * player.accelerate;
    }

    printf("%f %f\n", player.posx, player.posy);
}

void drawPlayer(void)
{
    setPlayerMaterial();
    glPushMatrix();
    glTranslatef(player.posx, player.posy, player.posz);
    glutSolidCube(player.size);
    glPopMatrix();
}

void setPlayerMaterial()
{
    GLfloat materialWallAmb[] = {1, player.greenColor, player.blueColor, 1};
    GLfloat materialWallDiff[] = {1, player.greenColor, player.blueColor, 1};
    GLfloat materialWallSpec[] = {1, player.greenColor, player.blueColor};

    glMaterialfv(GL_FRONT, GL_AMBIENT, materialWallAmb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialWallDiff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialWallSpec);
    glMaterialf(GL_FRONT, GL_SHININESS, 1);
}
