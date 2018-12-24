#include "player.h"

//Inicijalizujemo strukturu playera
Player player = {0, 0, 0, 1, 0, 0, 1, 0};

void movePlayer(void)
{
    // deltaTime, hocemo da kretanje playera bude nezavisno od frejmova
    float d = dt / 15;
    float speed = PLAYER_MAX_SPEED * gameLevel / 2;

    // Ukoliko je kretanje dijagonalno, brzinu delimo sa korenom iz dva
    // time se player nece kretati vecom brzinom nego inace
    if (twoButtonsPressed())
        speed /= sqrt(2); 

    // Povecavamo ubrzanje do 1 ukoliko se drzi dugme konstantno
    if (player.accelerate < 1)
        player.accelerate += 0.05;
    
    //Ukoliko pustimo sve dugmice za kretanje, postavljamo ubrzanje (zalet) na 0
    if(!KEY_A && !KEY_D && !KEY_S && !KEY_W)
        player.accelerate = 0;

    //Ukoliko je pritisnut key i ukoliko je dozvoljeno kretanje u tom pravcu
    if (KEY_W && canMoveUp())
    {   //d - vreme izmedju frejmova
        //speed - brzina playera
        //accelerate - ubrzanje
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

//Renderujemo playera
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
            player.score += 0.5;
            //Zelene kocke nam povecavaju helte i samim tim menjaju boju playera ka ljubicastoj
            player.greenColor -= player.greenColor > 0 ? 0.001 : 0;
            player.blueColor += player.blueColor < 1 ? 0.001 : 0;

            //Ukoliko pojedemo kocku do neke odredjene 'sredine' dobijamo bullete
            if(cube->size < 0.1 * gameLevel / 2){
                fadeBullets++;
                gravityBullets++;
                colorBullets++;
            }
        }
        else if (cube->colorType == COLOR_CYAN)
        {
            player.score -= 0.05;
            //Plave kocke smanjuju helte i menjaju boju playera ka zutoj
            player.greenColor += player.greenColor < 1 ? 0.001 : 0;
            player.blueColor -= player.blueColor > 0 ? 0.001 : 0;
        }

        cube->eaten = true;
    }
}

//Inkrementiramo score na odredjeni period
void increasePlayerScore(float d){
    player.score += d * gameLevel;
}

//Smanjujemo playeru healthe na odredjeni period
//Sluzi i kao indikator da li je player ziv ili mrtav
bool decayPlayerHealths(float d){
    player.size = 1 + player.greenColor;

    if(player.blueColor > 0){
        player.blueColor -= d;
        return true;
    }else{
        return false;
    }
}

//Pokrecemo animaciju kada player umre (pada u propast hehe)
void killPlayer(){
    player.posy -= PLAYER_MAX_SPEED * dt / 15 * gameLevel;
}