#define SDL_MAIN_HANDLED
#include <iostream>
#include <vector>
#include "includes.h"
#include <cstdlib>
#include <SDL.h>
#include <ctime>


int initialize() {
	SDL_Window* main_window;
	SDL_Renderer* main_renderer;
	SDL_CreateWindowAndRenderer(600, 800, 0, &main_window, &main_renderer);
	if (main_window == NULL || main_renderer == NULL || GRAW::SetGRAW(main_window, main_renderer) == -1)
		return -1;
	return 0;
}

void update(std::vector<Enemy> &enemies)  {
	//clear Canvas
	SDL_SetRenderDrawColor(GRAW::R, 0, 0, 0, 0);
	SDL_RenderClear(GRAW::R);

	SDL_SetRenderDrawColor(GRAW::R, 255, 255, 255, 0);
	GRAW::Draw(100, 400, 4, 800);
	GRAW::Draw(500, 400, 4, 800);
	
	GRAW::FramesFromStart++;

	if (GRAW::FramesFromStart % 6000 == 0)
		enemies.push_back(Enemy());

	SDL_SetRenderDrawColor(GRAW::R, 242, 135, 5, 0);
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i].Update();
	}


	Tower::Update();
		
	UI::RenderUi();

	//Render changes
	SDL_RenderPresent(GRAW::R);
}

int main()
{
	srand(time(NULL));
	std::vector<Enemy> enemies;
	for (int i = 0; i < 5; i++) {
		Enemy en(200 + (rand() % 200), 10 + 790 * (rand() % 2));
		enemies.push_back(en);

	}
	std::cout << "Select Difficulty\n1)Easy\n2)Normal\n3)Hard\n";
	int difficulty;
	std::cin >> difficulty;
	while(difficulty != 1 && difficulty != 2 && difficulty != 3) {
		std::cout << "1 or 2 or 3\n";
		std::cin >> difficulty;
	}
	switch (difficulty) {
	case 1:
		Enemy::speed = 70;
	case 2:
		Enemy::speed = 50;
	case 3:
		Enemy::speed = 40;
	}
		

	if (initialize() == -1) {
		std::cout << "Failed to start";
		return 0;
	}

	while (Tower::HP > 0)
	{
		update(enemies);
	}

	std::cout << "GAME OVER\nYou Scored " << Tower::Points << " Points\n";
	system("pause");

}
