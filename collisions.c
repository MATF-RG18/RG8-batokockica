#include "collisions.h"

bool canMoveLeft()
{
    if (player.posx < PLAYER_MOVEMENT_WIDTH / 2)
        return true;

    return false;
}

bool canMoveRight()
{
    if (player.posx > -PLAYER_MOVEMENT_WIDTH / 2)
        return true;

    return false;
}

bool canMoveUp()
{
    if (player.posy < PLAYER_MOVEMENT_HEIGHT)
        return true;

    return false;
}

bool canMoveDown()
{
    if (player.posy > 0)
        return true;

    return false;
}

// Dve kocke imaju zajednicku sekciju ako se seku po sve tri ose
bool cubeIntersect(float x1, float y1, float z1, float size1, float x2, float y2, float z2, float size2)
{
    //Udaljenost izmedju centra kocki je manji od zbira njihovih polovina velicina po toj osi
    if (abs(z1 - z2) < size1 / 2 + size2 / 2)
    {
        if (abs(y1 - y2) < size1 / 2 + size2 / 2)
        {
            if (abs(x1 - x2) < size1 / 2 + size2 / 2)
            {
                return true;
            }
        }
    }
    return false;
}

bool playerObstacleCollision()
{
    for (int i = 0; i < MAX_OBSTACLES; i++)
    {
        for (int j = 0; j < obstacles[i].numberOfCubes; j++)
        {
            if (!obstacles[i].cubes[j].fade && cubeIntersect(player.posx, player.posy, player.posz, player.size,
                              obstacles[i].cubes[j].posx, obstacles[i].cubes[j].posy, obstacles[i].cubes[j].posz, obstacles[i].cubes[j].size))
            {
                if(obstacles[i].cubes[j].colorType == COLOR_LIMEGREEN){
                    player.size -= 0.01;
                    player.greenColor -= player.greenColor != 0 ? 0.01 : 0;
                    player.blueColor += player.blueColor != 100 ? 0.01 : 0;    
                    fadeBullets++;
                    gravityBullets++;
                    colorBullets++;
                }else if(obstacles[i].cubes[j].colorType == COLOR_CYAN){
                    player.size += 0.01;
                    player.greenColor += player.greenColor != 0 ? 0.01 : 0;
                    player.blueColor -= player.blueColor != 100 ? 0.01 : 0;
                }
                
                obstacles[i].cubes[j].fade = 1;          
            }                                   
        }                                       
    }                                           
    return false;
}

//bool?
bool bulletObstacleCollision()
{
    for (int z = 0; z < MAX_FIRED_BULLETS; z++)
    {
        if (!firedBullets[z].fired)
            continue;

        for (int i = 0; i < MAX_OBSTACLES; i++)
        {
            for (int j = 0; j < obstacles[i].numberOfCubes; j++)
            {
                if (!obstacles[i].cubes[j].fade && cubeIntersect(firedBullets[z].posx, firedBullets[z].posy, firedBullets[z].posz, 0.3,
                                  obstacles[i].cubes[j].posx, obstacles[i].cubes[j].posy, obstacles[i].cubes[j].posz, obstacles[i].cubes[j].size))
                {
                    if(firedBullets[z].bulletType == FADE_BULLET){   
                        obstacles[i].cubes[j].fade = 1;
                    }else if(firedBullets[z].bulletType == COLOR_BULLET){
                        obstacles[i].cubes[j].colorType = obstacles[i].cubes[j].colorType == COLOR_LIMEGREEN? COLOR_CYAN : COLOR_LIMEGREEN; 
                    }else if(firedBullets[z].bulletType == GRAVITY_BULLET){
                        obstacles[i].cubes[j].vecy = 0.2;
                    }
                    
                    firedBullets[z].fired = 0;
                }
            }
        }
    }
    
    return false;
}