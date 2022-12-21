#include "Enemy.h"
#include "GlobalRendererAndWindow.h"
#include "Tower.h"
#include <cstdlib>
#include <iostream>

Enemy::Enemy(int Cx, int Cy) {
	x = Cx;
	y = Cy;
    targetX = 300;
    targetY = 400;
}

void Enemy::Update() {
    GetPushed();
    if (GRAW::FramesFromStart % speed == 0) {
        Move();
    }
    Attack();
    if (x < 100 || x > 500) {
        Tower::Points += 4 * (120 - speed);
        Die();
    }
    GRAW::Draw(x, y, 20, 20, 0);
}

int* Enemy::GetCoords() {
    int a[2] = { x, y };
    return a;
}

void Enemy::Attack() {
    if (abs(300 - x) < 25 && abs(400 - y) < 25) {
        Tower::Hit();
        Die();
    }

}

void Enemy::Die() {
    x = 200 + (rand() % 200);
    y = 5 +  790 * (rand() % 2);
}

void Enemy::GetPushed() {
    SDL_Event event;
    bool GameRunning = true;
    SDL_PollEvent(&event);
    if (event.type == SDL_MOUSEMOTION)
    {
        int xe, ye;
        SDL_GetMouseState(&xe, &ye);
        mouse::X = xe;
        mouse::Y = ye;

        int difx = mouse::X - x;
        int dify = mouse::Y - y;

        if (difx * difx + dify * dify > 900) {
            return;
        }
        MoveTowards(x + difx * ((30.0 - (difx * difx + dify * dify)) / (difx * difx + dify * dify)),
            y + dify * ((30.0 - (difx * difx + dify * dify)) / (difx * difx + dify * dify)));
    }
}

void Enemy::Move() {
    int deltaX = abs(targetX - x);
    int deltaY = abs(targetY - y);
    int signX = x < targetX ? 1 : -1;
    int signY = y < targetY ? 1 : -1;
    int error = deltaX - deltaY;
    int error2 = error * 2;
    if (error2 > -deltaY)
    {
        error -= deltaY;
        x += signX;
    }
    if (error2 < deltaX)
    {
        error += deltaX;
        y += signY;
    }
    
}
void Enemy::MoveTowards(int _targetX, int _targetY) {
    int deltaX = abs(_targetX - x);
    int deltaY = abs(_targetY - y);
    int signX = x < _targetX ? 1 : -1;
    int signY = y < _targetY ? 1 : -1;
    int error = deltaX - deltaY;
    int error2 = error * 2;
    if (error2 > -deltaY)
    {
        error -= deltaY;
        x += signX * 3;
    }
    if (error2 < deltaX)
    {
        error += deltaX;
        y += signY * 3;
    }

}

void Enemy::SetCoords(int xx, int yy) {
    x = xx;
    y = yy;
}
Enemy::Enemy() {
    targetX = 300;
    targetY = 400;
}

int Enemy::speed;