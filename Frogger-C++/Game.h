#pragma once
#include <math.h>
#include "Player.h"
#include "Enemy.h"
#include "Turtle.h"
#include "RiverCollision.h"
class Game
{
	//general
	
	
	float dxCal(float a, float b);
	//player
	Player* player = nullptr;
	bool player_initialized = false;
	//enemy
	bool checkEnemyCollision();
	float base_pos = 615;
	bool loc_enemy[15];
	int numOfEnemys = 15;
	Enemy* enemys[15];
	void spownEnemy(int start);
	void checkEnemy(bool kill);
	bool carhit;
	bool drowing;
	float time;
	//turtle
	float base_t_pos= 255;
	bool loc_turtle[15];
	int numOfTurtles = 15;
	Turtle* turtle[15];
	void spownTurtles(int start);
	void checkTurtles(bool kill);
	//collision
	RiverCollision* river;
	bool checkRiverTurtleCollision(int i, int j);
	bool checkRiverPlayerCollision();
	bool checkTurtlePlayerCollision();
	bool checkFinishCollision();
	//UI
	float score = 0;
	float startTime;
	bool musicPlaying=false;
	typedef enum {STATUS_START,STATUS_PLAYING,STATUS_END} status_t;
	status_t status = STATUS_START;
	void updateStartScreen();
	void updatePlayingScreen();
	void updateEndScreen();
	void drawStartScreen();
	void drawPlayingScreen();
	void drawEndScreen();
public:

	void update();
	void draw();
	void init();
	Game();
	~Game();
};
