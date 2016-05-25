#include "stdafx.h"
#include "Gameplay.h"
#include "Field.h"
#include "Player.h"
#include "GameLevelFactory.h"

Gameplay::Gameplay()
{
}

Gameplay::Gameplay(int players_count, std::string *names)
{
	std::cout << "Game konstruktor" << std::endl;
	players.reserve(players_count);
	for (int i = 0; i < players_count; i++)
		players.push_back(std::make_shared<Player>(names[i]));
	level_1 = GameLevelFactory::getLvl_1();
}

void Gameplay::start() {
	std::cout << std::endl << "Game::start()" << std::endl;
	for (auto player : players)
		std::cout << player->getName() << std::endl;

	std::vector<Player> gracze;
	gracze.reserve(2);
	Player a("kuba");
	Player b("adam");
	gracze.push_back(std::move(*new Player("adam")));
	gracze.push_back(*new Player("Kuba"));
}

bool Gameplay::init()
{
	std::cout << "init" << std::endl;
	players[0]->setActive();
	for (auto p : players)
		p->init();
	active_player = 0;
	if ( !game_board_texture.loadFromFile("game_board.jpg") )
	{
		std::cout << "blad przy ladowaniu tekstury" << std::endl;
		return false;
	}
	game_board_spirte.setTexture(game_board_texture);
	return true;
}

bool Gameplay::init(int players_count, std::string * names)
{
	players.reserve(players_count);
	for (int i = 0; i < players_count; i++)
		players.push_back(std::make_shared<Player>(names[i]));
	level_1 = GameLevelFactory::getLvl_1();
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
	window.draw(game_board_spirte);
	for (auto p : players)
		p->draw(window);
	return true;
}

void Gameplay::relase()
{
}
