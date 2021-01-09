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
	bool getState() { return active; }
	void set_diraction(float d) { diraction = d; }
	void set_x(float x) { pos_x = x; }
	void set_y(float y) { pos_y = y; }
	Disk getCollisionHull()const override;
	Disk getCollisionHull(int ofset_x, int ofset_y, float red_size) const override;
};
