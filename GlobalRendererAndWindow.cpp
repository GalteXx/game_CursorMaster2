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

void GRAW::Draw(int xMid, int yMid, int xSize, int ySize) {
	for (int i = yMid - ySize / 2; i < yMid + ySize / 2; i++) {
		for (int j = xMid - xSize / 2; j < xMid + xSize / 2; j++) {
			SDL_RenderDrawPoint(R, j, i);
		}
	}
}
int GRAW::FramesFromStart = 0;