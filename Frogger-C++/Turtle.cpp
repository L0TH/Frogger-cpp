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
	br.texture = std::string(ASSET_PATH) + "turtle-mid.png";
	br.outline_opacity = 0.f;
	graphics::setOrientation(-diraction*90);
	graphics::drawRect(pos_x, pos_y, size, size, br);
	graphics::setOrientation(-diraction * 90);
	graphics::drawRect(pos_x+35, pos_y, size, size, br);
	graphics::resetPose();
	br.outline_opacity = 1.f;
	br.texture = "";
	br.fill_color[0] = 1.f;
	br.fill_color[1] = 0.3f;
	br.fill_color[2] = 0.3f;
	br.fill_opacity = 0.3f;
	br.gradient = false;

	Disk hull1 = getCollisionHull(20, 0, 3.f);
	graphics::drawDisk(hull1.cx, hull1.cy, hull1.radius, br);
	Disk hull2 = getCollisionHull(-20, 0, 3.f);
	graphics::drawDisk(hull2.cx, hull2.cy, hull2.radius, br);
	Disk hull3 = getCollisionHull(55, 0, 3.f);
	graphics::drawDisk(hull3.cx, hull3.cy, hull3.radius, br);
	

}

void Turtle::init()
{

	speed = 0.08f;
	size = 90;
	active = true;
	diraction = 1.f;
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

Rect Turtle::getRectCollisionHull() const
{
	
	Rect rect;
	rect.rx = pos_x+20;
	rect.ry = pos_y;
	rect.rw = size+25;
	rect.rh = size / 2;
	rect.ontop=pos_x;
	return rect;
}



Disk Turtle::getCollisionHull(int ofset_x, int ofset_y, float red_size) const
{
	Disk disk;
	disk.cx = pos_x + ofset_x;
	disk.cy = pos_y + ofset_y;
	disk.radius = size / red_size;
	return disk;
}
