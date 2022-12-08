#pragma once
#include<SDL.h>
#define GRAW_h
#ifdef GRAW_h
class GRAW {
public:
	static int SetGRAW(SDL_Window*& main_window, SDL_Renderer*& main_renderer);
	static SDL_Window* W;
	static SDL_Renderer* R;
	static void Draw(int xMid, int yMid, int xSize, int ySize);
};
#endif // GRAW_h
