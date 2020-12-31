#include "Game.h"
#include "graphics.h"
#include "Config.h"

void Game::update()
{
}

void Game::draw()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "frogger-background.png";
	graphics::drawRect(CANVAS_WIDTH/2,CANVAS_HEIGHT/2,CANVAS_WIDTH,CANVAS_HEIGHT,br);
}

void Game::init()
{
}

Game::Game()
{
}

Game::~Game()
{
}
