#define SDL_MAIN_HANDLED
#include <iostream>
#include <vector>
#include "includes.h"
#include <cstdlib>
#include <SDL.h>
#include <fstream>
#include <ctime>

	int difficulty;

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
	GRAW::Draw(100, 400, 4, 800, 1);
	GRAW::Draw(500, 400, 4, 800, 1);
	
	GRAW::FramesFromStart++;

	if (GRAW::FramesFromStart % ((6000 - Enemy::speed) * 6) == 0)
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

void readFromSaves(int &n) {
	std::ifstream bestResult("C:\\Users\\maxim\\source\\repos\\game_CursorMaster2\\bestRes.txt");
	if (!bestResult.is_open()) {
		throw new std::exception("File could not be opened");
	}
	bestResult >> n;
	bestResult.close();
}

void writeToSaves(int n) {
	std::ofstream bestResult("C:\\Users\\maxim\\source\\repos\\game_CursorMaster2\\bestRes.txt");
	bestResult << Tower::Points;
	bestResult.close();
}

int main()
{
	int n;
	readFromSaves(n);
	srand(time(NULL));
	std::vector<Enemy> enemies;
	for (int i = 0; i < 5; i++) {
		Enemy en(200 + (rand() % 200), 10 + 790 * (rand() % 2));
		enemies.push_back(en);

	}
	std::cout << "Select Difficulty\n1)Easy\n2)Normal\n3)Hard\n";
	std::cin >> difficulty;
	while(difficulty != 1 && difficulty != 2 && difficulty != 3) {
		std::cout << "1 or 2 or 3\n";
		std::cin >> difficulty;
	}
	std::cout << difficulty;
	switch (difficulty) {
	case 1:
		Enemy::speed = 500;
		break;
	case 2:
		Enemy::speed = 200;
		break;
	case 3:
		Enemy::speed = 80;
		break;
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

	if (n < Tower::Points) {
		std::cout << "NEW RECORD " << Tower::Points << '\n' << "Old Record " << n << '\n';
		writeToSaves(n);
	}
	else {
		std::cout << "Old Recotrd " << n << '\n';
	}
	system("pause");
	
}
