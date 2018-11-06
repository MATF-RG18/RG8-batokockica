#include "lighting.h"
#include "camera.h"

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
    glutCreateWindow("Cracking open a cold one with the Bois");

    //init
    initAmbientLighting();
    initPlayerLighting();

    //glutKeyboardFunc(onKeyboard);
    //glutKeyboardFunc(onKeyboardUp);
    //glutMotionFunc(onMousePressedLook);
    //glutSetCursor(GLUT_CURSOR_NONE); 

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

    //skyBoxDraw()
    //update obstacles && render them
    //update player position and render him
    
    //TestStart
    GLfloat materialWallAmb[] = {0.6, 0.6, 0.6, 1};
	GLfloat materialWallDiff[] = {0.8, 0.8, 0.4, 1}; 
	GLfloat materialWallSpec[] = {0.41, 0.3, 0.4}; 

	glMaterialfv(GL_FRONT, GL_AMBIENT, materialWallAmb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialWallDiff);
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialWallSpec);
    glMaterialf(GL_FRONT, GL_SHININESS, 58);
	glutSolidCube(1);
    //TestEnd


    glutSwapBuffers();
}

static void onReshape(int width, int height){
	
	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80, (float) width /height, 1, 150); //Random valeus 
}

static void onTimerUpdate(int id){
    if(TIMER_UPDATE_ID != id){
        return;
    }

    updateDeltaTime();
    
    //Kretanje + collisions

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
