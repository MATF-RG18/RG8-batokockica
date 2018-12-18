#include "camera.h"
#include "bullets.h"
#include "obstacle.h"
#include "textures.h"
#include "lighting.h"
#include "player.h"
#include "input.h"

#include <time.h>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

#define TIMER_UPDATE_ID (1)
#define UPDATE_TIMER_INTERVAL (10)
#define DT_MAX (100)

int dt;
static int oldDisplayTime;
static int newTime;
static int oldTime = 0;

static void onDisplay(void);
static void onTimerUpdate(int id);
static void updateDeltaTime(void);
static void onReshape(int width, int height);

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutInitWindowSize(900, 600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("The engines don't move the ship at all. The ship stays where it is and the engines move the universe around it");

    //init
    initTextures();
    srand(time(NULL));
    initAmbientLighting();
    initPlayerLighting();
    initObstacles();

    glutKeyboardFunc(onKeyboard);
    glutKeyboardUpFunc(onKeyboardUp);
    
    glutMouseFunc(onMousePressed);
    
    glutSetCursor(GLUT_CURSOR_NONE); 

    glutDisplayFunc(onDisplay);
    glutReshapeFunc(onReshape);

    glClearColor(0, 0, 0, 1);
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_DEPTH);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);
    

    glutTimerFunc(UPDATE_TIMER_INTERVAL, onTimerUpdate, TIMER_UPDATE_ID);

    glutMainLoop();
}

static void onDisplay(void){
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
  	glLoadIdentity();
    setCameraPosition();


    //lightingPositions
    setPlayerLightingPosition();
    setAmbientLightingPosition();

    drawPlayer();
    
    skyBoxDraw();
    
    drawBullets();
    drawObstacles();

    glutSwapBuffers();
}

static void onReshape(int width, int height){
	
	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(105, (float) width /height, 1, 150); 
}

static void onTimerUpdate(int id){
    if(TIMER_UPDATE_ID != id){
        return;
    }

    updateDeltaTime();

    movePlayer();
    moveBullets();
    moveObstacles();

    playerObstacleCollision();
    bulletObstacleCollision();

    glutPostRedisplay();
    glutTimerFunc(UPDATE_TIMER_INTERVAL, onTimerUpdate, TIMER_UPDATE_ID);
}

static void updateDeltaTime(void){
    newTime = glutGet(GLUT_ELAPSED_TIME);
    dt = newTime - oldTime;
    oldTime = newTime;

    if(dt > DT_MAX)
        dt = DT_MAX;
}
