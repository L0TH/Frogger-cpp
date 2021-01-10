#pragma once
#include "GameObject.h"
#include "Turtle.h"
class RiverCollision :public GameObject,public Collitable
{
	
	Disk hull[13][5];
	
	float pos_x=0, pos_y=265;
	float speed;
	float diraction;
	float size=85;
	bool active;
public:
	void update() override;
	void draw() override;
	void init() override;
	RiverCollision(const class Game& mygame);
	~RiverCollision();
	Disk getCollisionHull()const override;
	Disk getCollisionHull(int ofset_x, int ofset_y, float red_size) const override;

	Rect getRectCollisionHull() const;
	
};