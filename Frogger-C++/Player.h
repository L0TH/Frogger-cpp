#pragma once
#include "GameObject.h"
#include "Config.h"
class Player : public GameObject, public Collitable
{
	
	float orientation = 0.0f;
	bool fly = false;
	float speed = 5.0f;
	float pos_x = CANVAS_WIDTH / 2, pos_y = CANVAS_HEIGHT - 30;
	
public: 
	Player(const class Game& mygame);
	 void update() override;
	 void draw() override;
	 void draw(bool a);
	 void init() override;
	 float getPosY(){return pos_y;}
	 float getPosX() { return pos_x; }
	 Disk getCollisionHull() const override;
	 Disk getCollisionHull(int ofset_x, int ofset_y, float red_size) const override;
};