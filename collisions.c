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

// Axis aligned bounding box
bool cubeIntersect(float x1, float y1, float z1, float size1, float x2, float y2, float z2, float size2)
{

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

            if (cubeIntersect(player.posx, player.posy, player.posz, player.size,
                              obstacles[i].cubes[j].posx, obstacles[i].cubes[j].posy, obstacles[i].cubes[j].posz, obstacles[i].cubes[j].size))
                printf("Collision detected\n"); // Return true;
        }
    }
    return false;
}

bool bulletObstacleCollision()
{
    for (int z = 0; z < MAX_FIRED_BULLETS; z++)
    {
        if(!firedBullets[z].fired)
            continue;
       
        for (int i = 0; i < MAX_OBSTACLES; i++)
        {
            for (int j = 0; j < obstacles[i].numberOfCubes; j++)
            {
                if (cubeIntersect(firedBullets[z].posx, firedBullets[z].posy, firedBullets[z].posz, 0.3,
                                  obstacles[i].cubes[j].posx, obstacles[i].cubes[j].posy, obstacles[i].cubes[j].posz, obstacles[i].cubes[j].size))
                   printf("Bullet hit the target\n"); //obstacles[i].cubes[j].size = 0;
            }
        }
    }
    return false;
}