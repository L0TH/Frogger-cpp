#pragma once
#include "Config.h"
#include "Util.h"
class Collitable
{
public:
	float ontop;
	virtual Disk getCollisionHull() const = 0;
	virtual Disk getCollisionHull(int ofset_x, int ofset_y, float red_size) const = 0;
	

};
class GameObject
{
protected:
	const class  Game& game;

public:
	
	GameObject(const class Game& mygame);
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void init() = 0;
};
