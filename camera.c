#include "camera.h"

Camera camera;

void setCameraPosition(void){
	camera.posx = 0;
	camera.posy = 3;
	camera.posz = -5;

	camera.lookDirectionX = 0; 
	camera.lookDirectionY = 2; 
	camera.lookDirectionZ = 0;
	
    gluLookAt(camera.posx, camera.posy, camera.posz,
              camera.lookDirectionX, camera.lookDirectionY, camera.lookDirectionZ,
              0, 1, 0);
}