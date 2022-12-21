#include "GlobalRendererAndWindow.h"

int GRAW::SetGRAW(SDL_Window*& main_window, SDL_Renderer*& main_renderer) {
	W = main_window;
	R = main_renderer;
	if (W == NULL || R == NULL)
		return -1;
	return 0;
}
SDL_Window* GRAW::W;
SDL_Renderer* GRAW::R;

void GRAW::Draw(int xMid, int yMid, int xSize, int ySize, bool is_filled) {
	SDL_Rect r;
	r.x = xMid - xSize / 2;
	r.y = yMid - ySize / 2;
	r.w = xSize;
	r.h = ySize;
	if(!is_filled)
		SDL_RenderDrawRect(R, &r);
	else 
		SDL_RenderFillRect(R, &r);
}
int GRAW::FramesFromStart = 0;