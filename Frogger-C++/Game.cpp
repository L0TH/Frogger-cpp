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
	
	checkEnemy();
	spownEnemy(0);
	if (graphics::getGlobalTime() > 2500 )
	{
		spownEnemy(5);
	}
	if (graphics::getGlobalTime() > 5000)
	{
		spownEnemy(10);
	}
	for (int i = 0; i < numOfEnemys; ++i)
	{
		if (enemys[i])
		{
			enemys[i]->update();
		}
	}

	

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
	for (int i = 0; i < numOfEnemys; ++i)
	{
		if (enemys[i])
		{
			enemys[i]->draw();

		}
	}
	
	

}


//mabe must go to the ~Game
void Game::spownEnemy(int start)
{
	//maybe if must leave an numOfEnemys become static 
	int depos_y = -1;
	float directionSeter = -1.f;
	for (int i =start; i <start+5 ; ++i)
	{
		if (!loc_enemy[i])
		{
				enemys[i] = new Enemy(*this);
				loc_enemy[i] = true;
				enemys[i]->set_diraction(directionSeter);
				if (directionSeter == 1.f)
				{
					enemys[i]->set_x(0);
				}
				else
				{
					enemys[i]->set_x(CANVAS_WIDTH + 50);
				}
				enemys[i]->set_y(base_pos - (i-start) * 60);
					
			
		}
		directionSeter *= -1.f;
	}
	base_pos = 615;
	directionSeter = -1.f;
}
void Game::checkEnemy()
{
	
		for (int i = 0; i < numOfEnemys; ++i)
		{
			if (enemys[i] && !enemys[i]->getState())
			{	
				delete enemys[i];
				enemys[i] = nullptr;
				loc_enemy[i] = false;
			}
		}
	
	
}
bool Game::checkCollision()
{
	
	for (int i = 0; i < numOfEnemys; ++i)
	{
		if (!player||!enemys[i])
		{
			return false;
		}

		Disk d1 = player->getCollisionHull();
		//de=disk x of enemy 
		Disk de[2];
		de[0] = enemys[i]->getCollisionHull(10, -3, 4.5f);
		de[1] = enemys[i]->getCollisionHull(10, -3, 4.5f);
		float dx1;
		float dx2;
		dx1 = dxCal(d1.cx, de[0].cx);
		dx2 = dxCal(d1.cx, de[1].cx);
		float dy1;
		float dy2;
		dy1 = dxCal(d1.cy, de[0].cy);
		dy2 = dxCal(d1.cy, de[1].cy);


		if (sqrt(dx1*dx1+dy1*dy1) < d1.radius+ de[0].radius || sqrt(dx2*dx2+ dy2*dy2) < d1.radius+de[1].radius)
			return true;
		
	}
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

float  Game::dxCal(float a, float b)
{
	return a - b;
};
