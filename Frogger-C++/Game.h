#pragma once
#include <math.h>
#include "Player.h"
#include "Enemy.h"
class Game
{
	
	Player * player=nullptr;
	bool player_initialized=false;
	int numOfEnemys = 5;
	bool enemys_alive = false;
	Enemy* enemys[5];
	float base_pos = 615;
	void spownEnemy();
	void checkEnemy();
	bool checkCollision();
	float dxCal(float a, float b);
	
	

public:
	
	void update();
	void draw();
	void init();
	Game();
	~Game();
};
