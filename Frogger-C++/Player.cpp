#include "Player.h"
#include "graphics.h"


void Player::update()
{
	
	if (graphics::getKeyState(graphics::SCANCODE_A))
	{
		fly = true;
		pos_x -= speed * graphics::getDeltaTime() / 40.0f;
		
	}
	if (graphics::getKeyState(graphics::SCANCODE_D))
	{
		fly = true;
		pos_x += speed * graphics::getDeltaTime() / 40.0f;
		
	}
	if (graphics::getKeyState(graphics::SCANCODE_W))
	{
		fly = true;
		pos_y -= speed * graphics::getDeltaTime() / 40.0f;
		
	}
	if (graphics::getKeyState(graphics::SCANCODE_S))
	{
		fly = true;
		pos_y += speed * graphics::getDeltaTime() / 40.0f;
		
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
		br.texture = std::string(ASSET_PATH) + "flying-frog.png";
		br.outline_opacity = 0.0f;
		graphics::drawRect(pos_x, pos_y, 40, 40, br);
		
	}
	if (fly==false)
	{
		
		graphics::Brush br;
		br.texture = std::string(ASSET_PATH) + "sitting-frog.png";
		br.outline_opacity = 0.0f;
		graphics::drawRect(pos_x, pos_y, 40, 40, br);
		
	}
	fly = false;
}

void Player::init()
{
}
