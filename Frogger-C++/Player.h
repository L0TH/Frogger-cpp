#pragma once
#include "Frog.h"
#include "Config.h"
class Player : public Frog
{
	bool fly = false;
	float speed = 5.0f;
	float pos_x = CANVAS_WIDTH / 2, pos_y = CANVAS_HEIGHT - 30;
public: 
	 void update() override;
	 void draw() override;
	 void draw(bool a);
	 void init() override;
};