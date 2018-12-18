#include "textures.h"

GLuint names[2];
Image *image;

void skyBoxDraw(void)
{

	glEnable(GL_TEXTURE_2D);
	glDepthMask(GL_FALSE);  // Isklucujemo upis u buffer dubine, tako nam quadovi skyboxa nece zaklanjati nijedan polygon
	glDisable(GL_LIGHTING); // Isklucujemo lighting

	glColor4f(1, 1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, names[0]); // Uzimamo texturu neba

	glPushMatrix();
	glBegin(GL_QUADS);
	//pod
	glNormal3f(0, 1, 0);
	glTexCoord2f(2, 2);
	glVertex3f(SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE);
	glTexCoord2f(2, 0);
	glVertex3f(SKYBOX_SIZE, -SKYBOX_SIZE, -SKYBOX_SIZE);
	glTexCoord2f(0, 0);
	glVertex3f(-SKYBOX_SIZE, -SKYBOX_SIZE, -SKYBOX_SIZE);
	glTexCoord2f(0, 2);
	glVertex3f(-SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE);

	//Levi Zid
	glNormal3f(1, 0, 0);
	glTexCoord2f(2, 2);
	glVertex3f(SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE);
	glTexCoord2f(0, 2);
	glVertex3f(SKYBOX_SIZE, SKYBOX_SIZE, -SKYBOX_SIZE);
	glTexCoord2f(0, 0);
	glVertex3f(SKYBOX_SIZE, -SKYBOX_SIZE, -SKYBOX_SIZE);
	glTexCoord2f(2, 0);
	glVertex3f(SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE);

	//Prednji zid
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 0);
	glVertex3f(-SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE);
	glTexCoord2f(2, 0);
	glVertex3f(SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE);
	glTexCoord2f(2, 2);
	glVertex3f(SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE);
	glTexCoord2f(0, 2);
	glVertex3f(-SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE);

	//Plafon
	glNormal3f(0, -1, 0);
	glTexCoord2f(0, 0);
	glVertex3f(-SKYBOX_SIZE, SKYBOX_SIZE, -SKYBOX_SIZE);
	glTexCoord2f(0, 2);
	glVertex3f(SKYBOX_SIZE, SKYBOX_SIZE, -SKYBOX_SIZE);
	glTexCoord2f(2, 2);
	glVertex3f(SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE);
	glTexCoord2f(2, 0);
	glVertex3f(-SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE);

	//Desni zid
	glNormal3f(-1, 0, 0);
	glTexCoord2f(2, 0);
	glVertex3f(-SKYBOX_SIZE, -SKYBOX_SIZE, -SKYBOX_SIZE);
	glTexCoord2f(0, 2);
	glVertex3f(-SKYBOX_SIZE, SKYBOX_SIZE, -SKYBOX_SIZE);
	glTexCoord2f(2, 2);
	glVertex3f(-SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE);
	glTexCoord2f(0, 0);
	glVertex3f(-SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE);

	glEnd();
	glPopMatrix();

	glDepthMask(GL_TRUE);	 // Uklucujemo upis u buffer dubine
	glEnable(GL_LIGHTING);	// i Lighting
	glDisable(GL_TEXTURE_2D); // Iskljucujemo texture
}

void playerTextureDraw(void)
{

	glEnable(GL_TEXTURE_2D);
	//glDisable(GL_LIGHTING);
	glColor4f(1, 1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, names[1]); // Uzimamo texturu neba

	float size = player.size / 2;

	glBegin(GL_QUADS);
	//pod
	glNormal3f(0, 1, 0);
	glTexCoord2f(0, 0);
	glVertex3f(-size, -size, -size);
	glTexCoord2f(1, 0);
	glVertex3f(size, -size, -size);
	glTexCoord2f(1, 1);
	glVertex3f(size, -size, size);
	glTexCoord2f(0, 1);
	glVertex3f(-size, -size, size);

	//Levi Zid
	glNormal3f(1, 0, 0);
	glTexCoord2f(0, 0);
	glVertex3f(size, -size, -size);
	glTexCoord2f(0, 1);
	glVertex3f(size, size, -size);
	glTexCoord2f(1, 1);
	glVertex3f(size, size, size);
	glTexCoord2f(1, 0);
	glVertex3f(size, -size, size);

	//Prednji zid
	glNormal3f(0, 0, 1);
	glTexCoord2f(0, 0);
	glVertex3f(-size, size, size);
	glTexCoord2f(1, 0);
	glVertex3f(size, size, size);
	glTexCoord2f(1, 1);
	glVertex3f(size, -size, size);
	glTexCoord2f(0, 1);
	glVertex3f(-size, -size, size);

	//Plafon
	glNormal3f(0, -1, 0);
	glTexCoord2f(0, 1);
	glVertex3f(size, size, -size);
	glTexCoord2f(0, 0);
	glVertex3f(-size, size, -size);
	glTexCoord2f(1, 0);
	glVertex3f(-size, size, size);
	glTexCoord2f(1, 1);
	glVertex3f(size, size, size);

	//Desni zid
	glNormal3f(1, 0, 0);
	glTexCoord2f(0, 1);
	glVertex3f(-size, size, -size);
	glTexCoord2f(1, 0);
	glVertex3f(-size, -size, -size);
	glTexCoord2f(0, 0);
	glVertex3f(-size, -size, size);
	glTexCoord2f(1, 1);
	glVertex3f(-size, size, size);

	//Zid pozadi
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 1);
	glVertex3f(size, -size, -size);
	glTexCoord2f(1, 0);
	glVertex3f(-size, -size, -size);
	glTexCoord2f(0, 0);
	glVertex3f(-size, size, -size);
	glTexCoord2f(1, 1);
	glVertex3f(size, size, -size);

	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D); // Iskljucujemo texture
	//
}

void initTextures(void)
{

	image = image_init(0, 0);

	image_read(image, SKY_TEXTURE);
	glGenTextures(2, names);

	glBindTexture(GL_TEXTURE_2D, names[0]);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
				 image->width, image->width, 0,
				 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

	image_read(image, SHIP_TEXTURE);
	glBindTexture(GL_TEXTURE_2D, names[1]);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
				 image->width, image->width, 0,
				 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

	glBindTexture(GL_TEXTURE_2D, 0);
	image_done(image);
}