#pragma once
#include <math.h>
#include "Player.h"
#include "Enemy.h"
#include "Turtle.h"
#include "RiverCollision.h"
class Game
{
	//general
	void spawn(int start,float base_pos,int type,bool alivestate[]);
	float base_pos = 615;
	bool onetime = true;
	float dxCal(float a, float b);
	//player
	Player* player = nullptr;
	bool player_initialized = false;
	//enemy
	bool checkEnemyCollision();
	bool loc_enemy[15];
	int numOfEnemys = 15;
	bool enemys_alive = false;
	Enemy* enemys[15];
	void spownEnemy(int start);
	void checkEnemy();
	//turtle
	bool checkRiverTurtleCollision(int i, int j);
	float base_t_pos= 255;
	bool loc_turtle[15];
	int numOfTurtles = 15;
	Turtle* turtle[15];
	void spownTurtles(int start);
	void checkTurtles();
	RiverCollision* river;
	bool checkRiverPlayerCollision();
	bool checkTurtlePlayerCollision();
public:

	void update();
	void draw();
	void init();
	Game();
	~Game();
};
