#include "utilities.h"

int gameLevel = 2;

//Povecava level kada se predju odredjene granice scora
void increaseLevel()
{
    if (player.score >= LEVEL_4_LIMIT)
        gameLevel = 5;
    else if (player.score >= LEVEL_3_LIMIT)
        gameLevel = 4;
    else if (player.score >= LEVEL_2_LIMIT)
        gameLevel = 3;
}

//Resetuje igru tako sto postavi
void resetGame()
{
    gameLevel = 2;
    player.score = 0;
    player.blueColor = 1;
    player.greenColor = 0;

    player.posy = 0;
}

void drawHealths()
{
    char healths[5];
    int size = snprintf(healths, sizeof healths, "%dhp", (int)(100 * player.blueColor));

    for (int i = 0; i < size; i++)
    {   //Brojeve helta renderujemo sa vecim skaliranjem
        if (i == 1 || i == 0){
            setRandomMaterial();
            glPushMatrix();
                glTranslatef(-i - 4.5, 7, -1);
                glScalef(-0.007, 0.007, 0);
                glutStrokeCharacter(GLUT_STROKE_ROMAN, healths[i]);
            glPopMatrix();
 }      else{
            //Slova 'hp' sa manjim
            glPushMatrix();
                glTranslatef(- (float)i/3 - 5.6, 7, -1);
                glScalef(-0.003, 0.003, 0);
                glutStrokeCharacter(GLUT_STROKE_ROMAN, healths[i]);
        glPopMatrix();
        }
    }
}

//Renderujemo score points na sredini ekrana
void drawScore()
{
    char score[128];
    int size = snprintf(score, sizeof score, "%.2f", player.score);

    //Nalazimo broj cifara sa leve strane tacke i koristimo tu informaciju za transliranje
    //Ne zelimo da nam se tacka uopste pomera kada se pojavi nova cifra sa leve strane
    //vec da tacka ostane fiksna a da se cifre samo dopisuju sa leva na desno
    int k = 0;
    int tmp = player.score > 1 ? player.score : 1;
    
    while (tmp != 0)
    {
        tmp /= 10;
        k++;
    }

    for (int i = 0; i < size; i++)
    {
        setRandomMaterial();
            glPushMatrix();
            glTranslatef(-i + k, 7, 0);
        //Smanjujemo razmak izmedju takce i brojeva sa desne strane tacke
            if(i > size - 3)
                glTranslatef(0.5, 0 ,0);
            glScalef(-0.007, 0.007, 0.007);
            glutStrokeCharacter(GLUT_STROKE_ROMAN, score[i]);
        glPopMatrix();
    }
}

//Poruka koja se ispisuje kada player ostane bez healtha
void drawGameOver()
{
    char text[10];
    int size = snprintf(text, sizeof text, "GAME OVER");

    for (int i = 0; i < size; i++)
    {
        setRandomMaterial();
        glPushMatrix();
            glTranslatef(-i + 4.5, 7, -1);
            glScalef(-0.007, 0.007, 0.007);
            glutStrokeCharacter(GLUT_STROKE_ROMAN, text[i]);
        glPopMatrix();
    }
}

//Random boja za slova :)
void setRandomMaterial()
{
    
    GLfloat materialWallAmb[] = { 0.5 + (double)rand() / RAND_MAX /2,
                                  0.2 + (double)rand() / RAND_MAX /2,
                                  0.5 + (double)rand() / RAND_MAX /2, 1};
    
    GLfloat materialWallDiff[] = { 0.5 + (double)rand() / RAND_MAX /2,
                                  0.2 + (double)rand() / RAND_MAX /2,
                                  0.5 + (double)rand() / RAND_MAX /2, 1};
    
    GLfloat materialWallSpec[] = { 0.5 + (double)rand() / RAND_MAX /2,
                                  0.2 + (double)rand() / RAND_MAX /2,
                                  0.5 + (double)rand() / RAND_MAX /2, 1};

    glMaterialfv(GL_FRONT, GL_AMBIENT, materialWallAmb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialWallDiff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialWallSpec);
    glMaterialf(GL_FRONT, GL_SHININESS, 40);
}