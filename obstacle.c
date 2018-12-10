#include "obstacle.h"

int obstacleCounter = 0;
Obstacle obstacles[MAX_OBSTACLES];

int gameLevel = 2; // od 1 do 5

void initObstacles()
{
    for (int i = 0; i < MAX_OBSTACLES; i++)
    {
        generateNextWall(i);
    }
}

void generateNextWall(int z)
{
    int numberOfCubes = rand() % (MAX_CUBES_PER_OBSTACLE / MAX_LEVEL * gameLevel); // Ovo treba da budem random i vece kako level raste

    obstacles[obstacleCounter].numberOfCubes = numberOfCubes;

    for (int i = 0; i < obstacles[obstacleCounter].numberOfCubes; i++)
    {
        //Init pozicija, mora biti unutar obstacle width i heighta
        obstacles[obstacleCounter].cubes[i].posx = -6 + rand() % OBSTACLE_MOVEMENT_WIDTH;
        obstacles[obstacleCounter].cubes[i].posy = 0 + rand() % OBSTACLE_MOVEMENT_HEIGHT;
        obstacles[obstacleCounter].cubes[i].posz = z; //Generisemo na kraju i pomeramo ka playeru

        obstacles[obstacleCounter].cubes[i].vecx = 0;
        obstacles[obstacleCounter].cubes[i].vecy = 0;
        obstacles[obstacleCounter].cubes[i].vecz = 0;

        obstacles[obstacleCounter].cubes[i].colorType = (rand() % 100 > SPAWN_RATE_OBSTACLE) ? COLOR_CYAN : COLOR_LIMEGREEN;
        obstacles[obstacleCounter].cubes[i].fade = 0;
        obstacles[obstacleCounter].cubes[i].size = 0.4 + ((double)rand() / (double)RAND_MAX); //Min je 0.1 a max ~1.1
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
            obstacles[i].cubes[j].posy += obstacles[i].cubes[j].vecy;
            obstacles[i].cubes[j].posz -= OBSTACLE_SPEED;
            //Indikator fade je 1 kada je npr metak pogodio obstacle
            //Postepeno je smanjujemo i postavljamo za 0
            if (obstacles[i].cubes[j].fade)
                if (obstacles[i].cubes[j].size > 0)
                    obstacles[i].cubes[j].size -= 0.1;
                else
                    obstacles[i].cubes[j].size = 0;

            if (obstacles[i].cubes[j].posz < player.posz - player.size * 2)
            { 
                if (obstacles[i].cubes[j].size > 0)
                { 
                    obstacles[i].cubes[j].posx += obstacles[i].cubes[j].posx > 0 ? 0.5 : -0.5;
                    obstacles[i].cubes[j].size -= 0.1; //Kada prepreke odu iza playera, smanjujemo ih i sklanjamo
                }                                      //Levo ili desno u zavisnosti sa koje strane su y ose
            }
            if (obstacles[i].cubes[0].posz < -6)
            {
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
            obstacleMaterial(obstacles[i].cubes[j].colorType);

            glPushMatrix();
            glTranslatef(obstacles[i].cubes[j].posx, obstacles[i].cubes[j].posy, obstacles[i].cubes[j].posz);
            glutSolidCube(obstacles[i].cubes[j].size);
            glPopMatrix();
        }
    }
}

void obstacleMaterial(int type)
{
    if (type == COLOR_CYAN)
        setObstacleCyanMaterial();
    else if (type == COLOR_LIMEGREEN)
        setObstacleLimeGreenMaterial();
    //more colors inc
}

void setObstacleLimeGreenMaterial()
{
    GLfloat materialWallAmb[] = {0, 0.6, 0.4, 1};
    GLfloat materialWallDiff[] = {0, 0.6, 0.4, 1};
    GLfloat materialWallSpec[] = {0, 0.6, 0.4};

    glMaterialfv(GL_FRONT, GL_AMBIENT, materialWallAmb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialWallDiff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialWallSpec);
    glMaterialf(GL_FRONT, GL_SHININESS, 128);
}

void setObstacleCyanMaterial()
{
    GLfloat materialWallAmb[] = {0, 0.6, 0.6, 1};
    GLfloat materialWallDiff[] = {0, 0.4, 0.4, 1};
    GLfloat materialWallSpec[] = {0.3, 0.4, 0.4};

    glMaterialfv(GL_FRONT, GL_AMBIENT, materialWallAmb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialWallDiff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialWallSpec);
    glMaterialf(GL_FRONT, GL_SHININESS, 1);
}