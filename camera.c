#include "camera.h"

Camera camera;

void setCameraPosition(void){
	camera.posx = 3;
	camera.posy = 6;
	camera.posz = -10;

	camera.lookDirectionX = 0; 
	camera.lookDirectionY = 0; 
	camera.lookDirectionZ = 0;
	
    gluLookAt(camera.posx, camera.posy, camera.posz,
              camera.lookDirectionX, camera.lookDirectionY, camera.lookDirectionZ,
              0, 1, 0);
}