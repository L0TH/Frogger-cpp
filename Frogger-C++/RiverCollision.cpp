#include "RiverCollision.h"
#include "graphics.h"

void RiverCollision::update()
{

}

void RiverCollision::draw()
{
	graphics::Brush br;
	br.outline_opacity = 1.f;
	br.texture = "";
	br.fill_color[0] = 0.f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 1.f;
	br.fill_opacity = 0.3f;
	br.gradient = false;
	for (int j = 0; j < 5; ++j)
	{
		for (int i = 0; i < 13; i++)
		{
			//Disk hull1 = getCollisionHull(0, 0, 3.5f);
			graphics::drawDisk(hull[i][j].cx, hull[i][j].cy, hull[i][j].radius, br);
		}
	}
	
}

void RiverCollision::init()
{
	//delete
	for (int j = 0; j < 5; ++j)
	{
		for (int i = 0; i < 13; i++)
		{
			hull[i][j] = getCollisionHull(i*60, -j * 45, 3.f);
		}
	}
}

RiverCollision::RiverCollision(const Game& mygame)
	:GameObject(mygame)
{
	init();
}
RiverCollision::~RiverCollision()
{
}

Disk RiverCollision::getCollisionHull() const
{
	Disk disk;
	disk.cx = pos_x;
	disk.cy = pos_y;
	disk.radius = size;
	return disk;
}

Disk RiverCollision::getCollisionHull(int ofset_x, int ofset_y, float red_size) const
{
	Disk disk;
	disk.cx = pos_x + ofset_x;
	disk.cy = pos_y + ofset_y;
	disk.radius = size / red_size;
	return disk;
}
Rect RiverCollision::getRectCollisionHull() const
{
	Rect rect;
	rect.rx = pos_x;
	rect.ry = pos_y;
	rect.rw = size;
	rect.rh = size / 2;
	return rect;
}



