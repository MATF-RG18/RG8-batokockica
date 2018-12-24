#include "obstacle.h"

//Pokazivac na poziciju gde ce se sacuvati prvi sledeci obstacle, ide od 0 do MAX_OBSTACLES pa u krug
int obstacleCounter = 0;
//Niz obstacla koje renderujemo
Obstacle obstacles[MAX_OBSTACLES];


void initObstacles()
{
    for (int i = 0; i < MAX_OBSTACLES; i++)
    {
        generateNextWall(i);
    }
}

//Generisemo obstacleWall na poziciji Z
//Svaki wall ima kocke random velicine i random x, y kordinata na datoj z kordinati
void generateNextWall(int z)
{
    
    if (obstacleCounter < MAX_OBSTACLES)
        obstacleCounter++;
    else
        obstacleCounter = 0;
    
    int numberOfCubes = rand() % (MAX_CUBES_PER_OBSTACLE / MAX_LEVEL * gameLevel);

    obstacles[obstacleCounter].numberOfCubes = numberOfCubes;

    for (int i = 0; i < obstacles[obstacleCounter].numberOfCubes; i++)
    {
        //Init pozicija, mora biti unutar obstacle width i heighta
        obstacles[obstacleCounter].cubes[i].posx = -OBSTACLE_MOVEMENT_WIDTH/2 + rand() % OBSTACLE_MOVEMENT_WIDTH;
        obstacles[obstacleCounter].cubes[i].posy = 0 + rand() % OBSTACLE_MOVEMENT_HEIGHT;
        obstacles[obstacleCounter].cubes[i].posz = z;

        //Vektor 'gravitacije'
        obstacles[obstacleCounter].cubes[i].vecx = 0;
        obstacles[obstacleCounter].cubes[i].vecy = 0;
        obstacles[obstacleCounter].cubes[i].vecz = 0;

        //Generisemo sa psuedo tacnoscu kojeg ce tipa biti obstacle
        obstacles[obstacleCounter].cubes[i].colorType = (rand() % 100 > SPAWN_RATE_OBSTACLE) ? COLOR_CYAN : COLOR_LIMEGREEN;

        obstacles[obstacleCounter].cubes[i].eaten = false;
        obstacles[obstacleCounter].cubes[i].hitByBullet = false;

        obstacles[obstacleCounter].cubes[i].size = MIN_CUBE_SIZE + ((double)rand() / (double)RAND_MAX); //Min je 0.1 a max ~1.1
    }

}

void moveObstacles()
{
    for (int i = 0; i < MAX_OBSTACLES; i++)
    {
        for (int j = 0; j < obstacles[i].numberOfCubes; j++)
        {
            //Pomeramo ka playeru 
            obstacles[i].cubes[j].posz -= OBSTACLE_SPEED * dt * gameLevel;
    
            //Pomeramo po Y osi ukoliko je vektor vecy veci od 0 (odnosno ako je pogodjen sa gravityBulletom)
            obstacles[i].cubes[j].posy += obstacles[i].cubes[j].vecy;
            
            //Ukoliko player jede cube, smanji size
            if (obstacles[i].cubes[j].eaten)
                if (obstacles[i].cubes[j].size > 0)
                    obstacles[i].cubes[j].size -= 0.02 * gameLevel;
                else
                    obstacles[i].cubes[j].size = 0;

            //Smanji kocku ukoliko je pogodjena sa fade bulletom
            if (obstacles[i].cubes[j].hitByBullet)
                if (obstacles[i].cubes[j].size > 0)
                    obstacles[i].cubes[j].size -= 0.02 * gameLevel;
                else
                    obstacles[i].cubes[j].size = 0;

            //Kada cube bude na sredini izmedju playera i camere, pokrecemo njegovo smanjivanje i pomeranje u stranu
            if (obstacles[i].cubes[j].posz < (camera.posz + player.posz) /2 )
            {
                if (obstacles[i].cubes[j].size > 0)
                {  
                    //Smanjujemo size kocke i pomeramo je na levu ili desnu stranu u zavisnosti da da li je u
                    //negativnom ili pozitivnom delu X ose
                    obstacles[i].cubes[j].posx += obstacles[i].cubes[j].posx > 0 ? 0.5 : -0.5;
                    obstacles[i].cubes[j].size -= 0.1; 
                }                                      
            }

            
            // Kada wall obstacla ode iza vidnog polja kamere, generisemo opet ispred playera
            if (obstacles[i].cubes[0].posz <= camera.posz)
            {
                generateNextWall(MAX_OBSTACLES - 1);
            }
        }
    }
}

//Renderujemo kocke obstacl-a
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

//Event kada obstacle bude pogodjen bulletom
void hitByBullet(ObstacleCube *cube, Bullet *bullet)
{
    if (bullet->bulletType == FADE_BULLET)
    {
        //Ovaj indikator koristimo samo kada smanjujemo kocku (odnosno pogodjen fadebulletom)
        cube->hitByBullet = true; 
    }
    else if (bullet->bulletType == COLOR_BULLET)
    { //Menjamo boju
        cube->colorType = cube->colorType == COLOR_LIMEGREEN ? COLOR_CYAN : COLOR_LIMEGREEN;
    }
    else if (bullet->bulletType == GRAVITY_BULLET)
    { //Postavljamo gravitaciju preko vektora (0,y,0)
        cube->vecy = 0.2;
    }

    bullet->fired = false;
}
