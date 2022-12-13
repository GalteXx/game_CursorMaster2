#pragma once
#include "Mouse.h"
#define enemy_h
#ifdef enemy_h

class Enemy {
public:
	void Update();
	Enemy(int Cx, int Cy);
	Enemy();
	int* GetCoords();
	void SetCoords(int xx, int yy);
	static int speed;
private:
	int x = 0, y = 0, targetX, targetY;
	void Move();
	void GetPushed();
	void Die();
	void Attack();
	void MoveTowards(int _targetX, int _targetY);
};

#endif // global_update_h