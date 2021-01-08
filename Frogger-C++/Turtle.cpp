#include "Turtle.h"
#include "graphics.h"
#include "Config.h"

void Turtle::update()
{
	pos_x += speed * graphics::getDeltaTime() * diraction;
	if (pos_x<-size || pos_x>CANVAS_WIDTH + size)
	{
		active = false;
	}
}

void Turtle::draw()
{
	graphics::Brush br;
	br.texture=std::string(ASSET_PATH) + "turtle.png";
	br.outline_opacity = 0.f;
	graphics::drawRect(pos_x, pos_y, size, size, br);
}

void Turtle::init()
{
	pos_x = CANVAS_HEIGHT/2;
	pos_y = CANVAS_WIDTH/2;
	speed = 0.1f;
	size = 100;
	active = true;
	diraction = 1;
}

Turtle::Turtle(const Game& mygame)
	:GameObject(mygame)
{
	init();
}


Turtle::~Turtle()
{
}
Disk Turtle::getCollisionHull() const
{
	Disk disk;
	disk.cx = pos_x;
	disk.cy = pos_y;
	disk.radius = size;
	return disk;
}

Disk Turtle::getCollisionHull(int ofset_x, int ofset_y, float red_size) const
{
	Disk disk;
	disk.cx = pos_x + ofset_x;
	disk.cy = pos_y + ofset_y;
	disk.radius = size / red_size;
	return disk;
}