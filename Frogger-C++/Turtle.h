#pragma once
#include "GameObject.h"
class Turtle : public GameObject, public Collitable
{
	float pos_x, pos_y;
	float speed;
	float diraction;
	float size;
	bool active;
public:
	void update() override;
	void draw() override;
	void init() override;
	Turtle(const class Game& mygame);
	~Turtle();
	Disk getCollisionHull()const override;
	Disk getCollisionHull(int ofset_x, int ofset_y, float red_size) const override;
};