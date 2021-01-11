#include "Player.h"
#include "graphics.h"
#include "Game.h"


Player::Player(const Game& mygame)
	:GameObject(mygame)
{
	init();
}

void Player::update()
{
	

	if (graphics::getKeyState(graphics::SCANCODE_A))
	{
		
		fly = true;
		pos_x -= speed * graphics::getDeltaTime() / 40.0f;
		orientation = 90.0f;
		


	}
	if (graphics::getKeyState(graphics::SCANCODE_D))
	{
		fly = true;
		pos_x += speed * graphics::getDeltaTime() / 40.0f;
		orientation = -90.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_W))
	{
		fly = true;
		pos_y -= speed * graphics::getDeltaTime() / 40.0f;
		orientation = 0.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_S))
	{
		fly = true;
		pos_y += speed * graphics::getDeltaTime() / 40.0f;
		orientation = 180.0f;
	}
	if (pos_x < 0)pos_x = 0;
	if (pos_x > CANVAS_WIDTH)pos_x = CANVAS_WIDTH;
	if (pos_y < 0)pos_y = 0;
	if (pos_y > CANVAS_HEIGHT)pos_y = CANVAS_HEIGHT;
}

void Player::draw()
{

	graphics::Brush br;

	if (fly)
	{

		br.texture = std::string(ASSET_PATH) + "flying-frog - Copy.png";
		br.outline_opacity = 0.0f;
		br.fill_opacity = 0.5f;
		graphics::setOrientation(orientation);

		graphics::drawRect(pos_x - 10, pos_y + 20, 40, 40, br);

		br.texture = std::string(ASSET_PATH) + "flying-frog.png";
		br.fill_opacity = 1.0f;
		br.outline_opacity = 0.0f;
		graphics::drawRect(pos_x, pos_y, 40, 40, br);
		graphics::resetPose();

	}
	if (!fly)
	{
		br.texture = std::string(ASSET_PATH) + "sitting-frog.png";
		br.outline_opacity = 0.0f;
		graphics::setOrientation(orientation);
		graphics::drawRect(pos_x, pos_y, 40, 40, br);
		graphics::resetPose();

	}
	fly = false;
	//for debuging
	br.outline_opacity = 1.f;
	br.texture = "";
	br.fill_color[0] = 0.3f;
	br.fill_color[1] = 1.f;
	br.fill_color[2] = 0.3f;
	br.fill_opacity = 0.3f;
	br.gradient = false;
	Disk hull = getCollisionHull(0, 0, 1.25);
	graphics::drawDisk(hull.cx, hull.cy, hull.radius, br);


}

void Player::init()
{
	speed = 5.0f;
	pos_x = CANVAS_WIDTH / 2;
	pos_y = CANVAS_HEIGHT - 30;
	fly = false;
	orientation = 0.0f;
}

Disk Player::getCollisionHull() const
{
	Disk disk;
	disk.cx = pos_x;
	disk.cy = pos_y;
	disk.radius = 20.0f;
	return disk;
}

Disk Player::getCollisionHull(int ofset_x, int ofset_y, float red_size) const
{
	Disk disk;
	disk.cx = pos_x;
	disk.cy = pos_y;
	disk.radius = 20.0f/red_size;
	return disk;
}
