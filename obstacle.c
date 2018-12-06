#include "obstacle.h"

int obstacleCounter = 0;
Obstacle obstacles[MAX_OBSTACLES];

int gameLevel = 2; // od 1 do 4

void initObstacles()
{
    for (int i = 0; i < MAX_OBSTACLES; i++)
    {
        generateNextWall(i);
    }
}

void generateNextWall(int z)
{

    int numberOfCubes = rand() % (4 * gameLevel); // Ovo treba da budem random i vece kako level raste

    obstacles[obstacleCounter].numberOfCubes = numberOfCubes;

    for (int i = 0; i < obstacles[obstacleCounter].numberOfCubes; i++)
    {
        //Init pozicija, mora biti unutar obstacle iwdth i heighta
        obstacles[obstacleCounter].cubes[i].posx = -6 + rand() % OBSTACLE_MOVEMENT_WIDTH;
        obstacles[obstacleCounter].cubes[i].posy = 0 + rand() % OBSTACLE_MOVEMENT_HEIGHT;
        obstacles[obstacleCounter].cubes[i].posz = z; //Generisemo na kraju i pomeramo ka playeru
        //Neki se krecu, neki ne
        obstacles[obstacleCounter].cubes[i].vecx = 0;
        obstacles[obstacleCounter].cubes[i].vecy = 0;
        obstacles[obstacleCounter].cubes[i].vecz = 0;

        obstacles[obstacleCounter].cubes[i].speed = 0;

        obstacles[obstacleCounter].cubes[i].color = 0;
        obstacles[obstacleCounter].cubes[i].fade = 0;
        obstacles[obstacleCounter].cubes[i].size = 0.1 + (double)rand()/(double)RAND_MAX;
    }

    if (obstacleCounter < MAX_OBSTACLES)
        obstacleCounter++;
    else
        obstacleCounter = 0;
}

void moveObstacles()
{
    for (int i = 0; i < MAX_OBSTACLES; i++)
    {
        for (int j = 0; j < obstacles[i].numberOfCubes; j++)
        {
            obstacles[i].cubes[j].posz -= OBSTACLE_SPEED * gameLevel; 
            
            if (obstacles[i].cubes[j].posz < player.posz - player.size * 2){ //Umesto 1 player size
                if(obstacles[i].cubes[j].size > 0){            //TD:Minimizing speed
                    obstacles[i].cubes[j].posx += obstacles[i].cubes[j].posx > 0 ? 0.5 : -0.5;
                    obstacles[i].cubes[j].size -= 0.1; //Kada prepreke odu iza playera, smanjujemo ih i sklanjamo
                }                       //Levo ili desno u zavisnosti sa koje strane su y ose
            }
            if (obstacles[i].cubes[0].posz < -6){
                generateNextWall(40); // Kada wall obstacla ode iza vidnog polja kamere, generisemo opet ispred playera
            }
        }
    }
}

void drawObstacles()
{
    for (int i = 0; i < MAX_OBSTACLES; i++)
    {
        for (int j = 0; j < obstacles[i].numberOfCubes; j++)
        {
            glPushMatrix();
            glTranslatef(obstacles[i].cubes[j].posx, obstacles[i].cubes[j].posy, obstacles[i].cubes[j].posz);
            glutSolidCube(obstacles[i].cubes[j].size);
            glPopMatrix();
        }
    }
}