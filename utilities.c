#include "utilities.h"

void drawHealths(){
    char healths[4];
    int size = snprintf(healths, sizeof healths, "%d", (int)(100*player.blueColor));

    for (int i = 0; i < size; i++)
    {
        setRandomMaterial();
        glPushMatrix();
        glTranslatef(-i - 6 , 7, -1);
        glScalef(-0.007, 0.007, 0.007);
        glutStrokeCharacter(GLUT_STROKE_ROMAN, healths[i]);
        glPopMatrix();
    }
}

void drawScore(){
    char score[128];
    int size = snprintf(score, sizeof score, "%.2f", player.score);
    
    int k = 0;
    int tmp = player.score > 1 ? player.score : 1;
    while(tmp != 0){
        tmp /= 10;
        k++;
    }

    for (int i = 0; i < size; i++)
    {
        setRandomMaterial();
        glPushMatrix();
        glTranslatef(-i+k, 7, 0);
        glScalef(-0.007, 0.007, 0.007);
        glutStrokeCharacter(GLUT_STROKE_ROMAN, score[i]);
        glPopMatrix();
    }
}

void gameOver(){
    char healths[10];
    int size = snprintf(healths, sizeof healths, "GAME OVER");

    for (int i = 0; i < size; i++)
    {
        setRandomMaterial();
        glPushMatrix();
        glTranslatef(-i, 6, 0);
        glScalef(-0.007, 0.007, 0.007);
        glutStrokeCharacter(GLUT_STROKE_ROMAN, healths[i]);
        glPopMatrix();
    }
}

void setRandomMaterial(){

    GLfloat materialWallAmb[] = {(double)rand()/RAND_MAX, (double) rand()/RAND_MAX, (double) rand()/RAND_MAX, 1};
    GLfloat materialWallDiff[] = {(double)rand()/RAND_MAX, (double) rand()/RAND_MAX, (double) rand()/RAND_MAX, 1};
    GLfloat materialWallSpec[] = {(double)rand()/RAND_MAX, (double) rand()/RAND_MAX, (double) rand()/RAND_MAX};

    glMaterialfv(GL_FRONT, GL_AMBIENT, materialWallAmb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialWallDiff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialWallSpec);
    glMaterialf(GL_FRONT, GL_SHININESS, 100);
}