#pragma once
#include "GameObject.h"
#include "Config.h"
class Player : public GameObject, public Collitable
{

	float orientation;
	bool fly;
	float speed;
	float pos_x, pos_y;

public:
	Player(const class Game& mygame);
	void update() override;
	void draw() override;
	void init() override;
	float getPosY() { return pos_y; }
	float getPosX() { return pos_x; }
	Disk getCollisionHull() const override;
	Disk getCollisionHull(int ofset_x, int ofset_y, float red_size) const override;
};
