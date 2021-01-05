#include "Game.h"
#include "graphics.h"
#include "Config.h"
void Game::update()
{
	if (!player_initialized && graphics::getGlobalTime() > 1000)
	{
		player = new Player(*this);
		player_initialized = true;
		
	}
	if (player)
		player->update();
	//@TODO Only 1 enemy will be spowned this must change after test
	checkEnemy();
	spownEnemy();
	if (enemy1)
		enemy1->update();
	if (enemy2)
		enemy2->update();
	if (checkCollision())
	{
		delete player;
		player = nullptr;
		player = new Player(*this);
		player_initialized = true;
	}
	
}

void Game::draw()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "frogger-background.png";
	br.outline_opacity = 0.0f;

	//draw background
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_WIDTH, br);

	//draw player
	if (player)
		player->draw();
	//UI INFO for debug
	if (player)
	{
		char info[40];
		sprintf_s(info, "(%f,%f)", player->getPosX(), player->getPosY());
		graphics::drawText(50, 50, 20, info, br);
		graphics::resetPose();
	}

	if (enemy1)
		enemy1->draw();
	if (enemy2)
		enemy2->draw();
	

}

//mabe must go to the ~Game
void Game::spownEnemy()
{
	if (!enemy1)
	{
		enemy1 = new Enemy(*this);
		
	}
	if (!enemy2)
	{
		enemy2 = new Enemy(*this);
		enemy2->set_x(CANVAS_WIDTH + 50);
		enemy2->set_y(555);
	}
}
void Game::checkEnemy()
{
	if (enemy1 && !enemy1->getState())
	{
		delete enemy1;
		enemy1 = nullptr;
	}
	if (enemy2 && !enemy2->getState())
	{
		delete enemy2;
		enemy2 = nullptr;
	}
}
bool Game::checkCollision()
{
	//collision for enemy2 must be added here 
	if (!player || !enemy1)
	{
		return false;
	}
	
	Disk d1 = player->getCollisionHull();
	//de=disk x of enemy 
	Disk de1 = enemy1->getCollisionHull(10, -3, 4.5f);
	Disk de2 = enemy1->getCollisionHull(10, -3, 4.5f);
	float dx = d1.cx - de1.cx;
	float dy = d1.cy - de1.cy;
	float dx2 = d1.cx - de2.cx;
	float dy2 = d1.cy - de2.cy;
	if (sqrt(dx * dx + dy * dy) < d1.radius + de1.radius || sqrt(dx2 * dx2 + dy2 * dy2) < d1.radius + de2.radius)
		return true;
	else
		return false;
}
void Game::init()
{
	graphics::setFont(std::string(ASSET_PATH) + "font.ttf");
}
Game::Game()
{
}



Game::~Game()
{
	if (player)
	{
		delete player;
	}
}