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
	//@TODO Only 1 enemy eill be spowned this must change after test
	checkEnemy();
	spownEnemy();
	if (enemy)
		enemy->update();
	
}
//mabe must go to the ~Game
void Game::spownEnemy()
{
	if (!enemy)
	{
	enemy = new Enemy(*this);
	}
}
void Game::checkEnemy()
{
	if (enemy && !enemy->getState())
	{
		delete enemy;
		enemy = nullptr;
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
	//UI INFO
	if (player)
	{
		char info[40];
		sprintf_s(info, "(%f,%f)", player->getPosX(), player->getPosY());
		graphics::drawText(50, 50, 20, info, br);
		graphics::resetPose();
	}

	if (enemy)
		enemy->draw();
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