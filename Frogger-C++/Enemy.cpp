#include"graphics.h"
#include "Enemy.h"
#include "Config.h"
#include "Game.h"

void Enemy::update()
{
	pos_x += speed * graphics::getDeltaTime() * ditaction;
	if (pos_x < -size)
	{
		active = false;
	}
}


void Enemy::draw()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "pixil-frame-0.png";
	br.outline_opacity = 0.f;
	graphics::drawRect(pos_x, pos_y, size, size, br);
	//second taxi
	//graphics::drawRect(pos_x, pos_y-60, size, size, br);
	graphics::resetPose();

}

void Enemy::init()
{
	
	speed = 0.1f;
	pos_x = CANVAS_WIDTH+40 ;
	pos_y=615 ;
	size = 100;
	ditaction = -1.f;
}

Enemy::Enemy(const class Game& mygame)
	:GameObject(mygame)
{
	init();
}

Enemy::~Enemy()
{
}
