#include "UI.h"
#include "Tower.h"
#include "GlobalRendererAndWindow.h"

void UI::RenderUi() {
	SDL_SetRenderDrawColor(GRAW::R, 255, 0, 0, 0);
	for (int i = 0; i < Tower::HP; i++)
		GRAW::Draw(500 + 30 * i, 30, 20, 20, 1);
	SDL_SetRenderDrawColor(GRAW::R, 255, 255, 255, 0);
}
