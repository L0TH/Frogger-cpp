#pragma once

#include "Player.h"
#include "Enemy.h"
class Game
{
	
	Player * player=nullptr;
	bool player_initialized=false;
	Enemy* enemy1;
	Enemy* enemy2;
	void spownEnemy();
	void checkEnemy();
	bool checkCollision();
	

public:
	
	void update();
	void draw();
	void init();
	Game();
	~Game();
};
