#include "player.h"

Player player = {0, 0, 0, 1, 0, 0, 1, 0};

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

}

void drawPlayer(void)
{
    setPlayerMaterial();
    glPushMatrix();
        glTranslatef(player.posx, player.posy, player.posz);        
        playerTextureDraw();
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

//Ukoliko player jede obstacle, u zavisnosti od boje kocke postoje odredjena desavanja
void eatCube(ObstacleCube *cube)
{
    if (cube->size > 0)
    {
        if (cube->colorType == COLOR_LIMEGREEN)
        {
            player.size -= 0.001;
            player.score -= -0.1;
            //Zelene kocke nam povecavaju helte i samim tim menjaju boju playera ka ljubicastoj
            player.greenColor -= player.greenColor > 0 ? 0.001 : 0;
            player.blueColor += player.blueColor < 1 ? 0.001 : 0;

            if(cube->size < 0.1){//Ukoliko 'core kocke' dobijamo bullete
                fadeBullets++;
                gravityBullets++;
                colorBullets++;
            }
        }
        else if (cube->colorType == COLOR_CYAN)
        {
            player.size += 0.001;
            player.score += 0.15;
            //Plave kocke smanjuju helte i menjaju boju playera ka crvenoj
            player.greenColor += player.greenColor < 1 ? 0.001 : 0;
            player.blueColor -= player.blueColor > 0 ? 0.001 : 0;
        }
        cube->eaten = true;
    }
}

void increasePlayerScore(float d){
    player.score += d;
}