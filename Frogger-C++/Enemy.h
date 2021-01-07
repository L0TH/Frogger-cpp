#pragma once
#include"GameObject.h"
class Enemy :public GameObject, public Collitable
{
	
	float pos_x, pos_y;
	float speed;
	float diraction;
	float size;
	bool active = true;
public:
	//make it a getter
	bool alive = false;
	void set_x(float x) { pos_x = x; }
	void set_y(float y) { pos_y = y; }
	void set_diraction(float d) { diraction = d; }
	void update() override;
	void draw() override;
	void init() override;
	bool getState() { return active; }
	Enemy(const class Game& mygame);
	~Enemy();
	Disk getCollisionHull()const override;
	Disk getCollisionHull(int ofset_x, int ofset_y, float red_size) const override;
};