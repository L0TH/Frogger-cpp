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
	br.texture = std::string(ASSET_PATH) + "turtle.png";
	br.outline_opacity = 0.f;
	graphics::setOrientation(90);
	graphics::drawRect(pos_x, pos_y, size, size, br);
	graphics::setOrientation(90);
	graphics::drawRect(pos_x+40, pos_y, size, size, br);
	graphics::resetPose();
	br.outline_opacity = 1.f;
	br.texture = "";
	br.fill_color[0] = 1.f;
	br.fill_color[1] = 0.3f;
	br.fill_color[2] = 0.3f;
	br.fill_opacity = 0.3f;
	br.gradient = false;

	Disk hull1 = getCollisionHull(20, 10, 3.5f);
	graphics::drawDisk(hull1.cx, hull1.cy, hull1.radius, br);
	Disk hull2 = getCollisionHull(-20, 10, 3.5f);
	graphics::drawDisk(hull2.cx, hull2.cy, hull2.radius, br);
	Disk hull3 = getCollisionHull(60, 10, 3.5f);
	graphics::drawDisk(hull3.cx, hull3.cy, hull3.radius, br);
	

}

void Turtle::init()
{

	speed = 0.1f;
	size = 100;
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

Disk Turtle::getCollisionHull(int ofset_x, int ofset_y, float red_size) const
{
	Disk disk;
	disk.cx = pos_x + ofset_x;
	disk.cy = pos_y + ofset_y;
	disk.radius = size / red_size;
	return disk;
}
