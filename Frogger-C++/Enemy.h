#pragma once

#include"GameObject.h"
class Enemy :public GameObject
{
	float pos_x, pos_y;
	float speed;
	float ditaction;
	float size;
	bool active = true;
public:
	void update() override;
	 void draw() override;
	 void init() override;
	 bool getState() { return active; }
	 Enemy(const class Game& mygame);
	 ~Enemy();
};