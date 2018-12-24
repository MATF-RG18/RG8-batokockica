#include "bullets.h"

int gravityBullets = INIT_GRAVITY_BULLETS;
int colorBullets = INIT_COLOR_BULLETS;
int fadeBullets = INIT_FADE_BULLETS;

//Krece se u krug od 0 do MAX_FIRED_BULLETS, pokazivac na poziciju 
//gde cemo upisati sledeci ispaljen bullet
int firedBulletCounter = 0;                            

Bullet firedBullets[MAX_FIRED_BULLETS];                   

void drawBullets(void){

    for(int i = 0; i < MAX_FIRED_BULLETS; i++){
        //Renderujemo bullet ukoliko je ispaljen
        if(!firedBullets[i].fired) 
            continue;
        
        float x = firedBullets[i].posx;
        float y = firedBullets[i].posy;
        float z = firedBullets[i].posz;

        float width = firedBullets[i].width;
        float height = firedBullets[i].height;

        //Menjamo material koji je specifican za tip bulleta
        setBulletMaterial(firedBullets[i].bulletType);

        glPushMatrix();
            glTranslated(x, y, z);
            glScalef(width, width, height);
            glutSolidCube(0.15);
        glPopMatrix();
    }
}

void moveBullets(void){
    
    for(int i = 0; i < MAX_FIRED_BULLETS; i++){
        //Pomeramo sve ispaljene bullete
        if(!firedBullets[i].fired) 
            continue;

        firedBullets[i].posz += MAX_BULLET_SPEED * dt;
    }
}

//Ispaljujemo bullet koji krece od pozicije (x,y,z) zadatog tipa i smanjujemo zalihe odredjenog bulleta
void fireBullet(int bulletType, float x, float y, float z){
    
    if(bulletType == FADE_BULLET)
        if(fadeBullets > 0)
            fadeBullets--;
        else
            return;

    if(bulletType == GRAVITY_BULLET)
        if(gravityBullets > 0)
            gravityBullets--;
        else
            return;

    if(bulletType == COLOR_BULLET)
        if(colorBullets > 0)
            colorBullets--;
        else
            return;

    firedBullets[firedBulletCounter].posx = x;
    firedBullets[firedBulletCounter].posy = y;
    firedBullets[firedBulletCounter].posz = z;

    firedBullets[firedBulletCounter].bulletType = bulletType;
    firedBullets[firedBulletCounter].fired = true;

    firedBullets[firedBulletCounter].width = 1;
    firedBullets[firedBulletCounter].height = 12;

    //Pomeramo pokazivac na sledece slobodno mesto za sledeci bullet koji je ispaljen
    if(firedBulletCounter < MAX_FIRED_BULLETS)
        firedBulletCounter++;
    else
        firedBulletCounter = 0;
}

void setBulletMaterial(int type){
    if (type == GRAVITY_BULLET)
        gravityBulletMaterial();
    else if(type == COLOR_BULLET)
        colorBulletMaterial();
    else if(type == FADE_BULLET)
        fadeBulletMaterial();
    else
        exit(-1);
}

void gravityBulletMaterial(){
    GLfloat materialWallAmb[] = {0.6, 0, 0.6, 1};
	GLfloat materialWallDiff[] = {0.8, 0, 0.8, 1}; 
	GLfloat materialWallSpec[] = {0.41, 0, 0.4}; 

	glMaterialfv(GL_FRONT, GL_AMBIENT, materialWallAmb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialWallDiff);
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialWallSpec);
    glMaterialf(GL_FRONT, GL_SHININESS, 90);
}

void colorBulletMaterial(){
    GLfloat materialWallAmb[] = {0, 0.6, 0.6, 1};
	GLfloat materialWallDiff[] = {0, 0.4, 0.4, 1}; 
	GLfloat materialWallSpec[] = {0, 0.4, 0.4}; 

	glMaterialfv(GL_FRONT, GL_AMBIENT, materialWallAmb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialWallDiff);
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialWallSpec);
    glMaterialf(GL_FRONT, GL_SHININESS, 60);
}

void fadeBulletMaterial(){
    GLfloat materialWallAmb[] = {0.6, 0, 0, 1};
	GLfloat materialWallDiff[] = {0.8, 0, 0, 1}; 
	GLfloat materialWallSpec[] = {0.41, 0, 0}; 

	glMaterialfv(GL_FRONT, GL_AMBIENT, materialWallAmb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialWallDiff);
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialWallSpec);
    glMaterialf(GL_FRONT, GL_SHININESS, 58);
}

