#include "Player.h"
#include "graphics.h"
#include "Game.h"

Player::Player(const Game& mygame)
	:GameObject(mygame)
{

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
	
	if (fly)
	{
		graphics::Brush br;
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

		graphics::Brush br;
		br.texture = std::string(ASSET_PATH) + "sitting-frog.png";
		br.outline_opacity = 0.0f;
		graphics::setOrientation(orientation);
		graphics::drawRect(pos_x, pos_y, 40, 40, br);
		
	}
	fly = false;
	
}

void Player::init()
{
}
