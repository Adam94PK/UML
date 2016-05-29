#include "stdafx.h"
#include "Gameplay.h"
#include "Field.h"
#include "Player.h"
#include "GameLevelFactory.h"

bool Gameplay::init()
{
	std::cout << "init" << std::endl;
	players[0]->setActive();
	for (auto p : players)
		p->init();
	active_player = 0;
	return true;
}

bool Gameplay::init(int players_count, std::string * names)
{
	players_conut = players_count;
	players.reserve(players_count);
	for (int i = 0; i < players_count; i++)
		players.emplace_back(make_shared<Player>(names[i]));
	gameLvl1 = GameLevelFactory::getLvl_1();
	gameLvl2 = GameLevelFactory::getLvl_2();
	gameLvl3 = GameLevelFactory::getLvl_3();
	for (auto & p : players)
		p->setLvl(gameLvl1);
	return true;
}

bool Gameplay::update(float dt)
{	
	for (auto player : players)
		player->update(dt);
	return true;
}

bool Gameplay::draw(sf::RenderWindow & window)
{
	window.clear(sf::Color::Blue);
	//window.setView(window.getDefaultView());
	gameLvl1.draw(window);
	gameLvl2.draw(window);
	gameLvl3.draw(window);
	for (auto p : players)
		p->draw(window);
	players[active_player]->drawStatistics(window);
	int actual_filed = players[active_player]->getActualField();
	players[active_player]->getActualLvl()->getField(actual_filed)->drawDescription(window);
	return true;
}

void Gameplay::relase()
{
}

void Gameplay::setNextActive()
{
	active_player += 1;
	active_player %= players_conut;
	players[active_player]->setActive();
}
