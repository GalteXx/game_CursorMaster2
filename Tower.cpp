#include "Tower.h"
#include <iostream>
#include "GlobalRendererAndWindow.h"
void Tower::Update() {

	SDL_SetRenderDrawColor(GRAW::R, 255, 255, 255, 0);
	GRAW::Draw(300, 400, 50, 50, 1);
}


void Tower::Hit() {
	Tower::HP--;
}

int Tower::HP = 3;
int Tower::Points = 0;