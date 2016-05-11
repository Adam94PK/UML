#include "stdafx.h"
#include "Gameplay.h"
#include "Field.h"
#include "Player.h"
#include <memory>
#include <string>

Gameplay::Gameplay(int players_count, std::string *names)
{
	std::cout << "Game konstruktor" << std::endl;
	players.reserve(players_count);
	for (int i = 0; i < players_count; i++)
		players.push_back(std::make_shared<Player>(names[i]));

	level_1.reserve(LEVEL_1_SIZE);
	level_2.reserve(LEVEL_2_SIZE);
	level_3.reserve(LEVEL_3_SIZE);

	
	for (int i = 0; i < LEVEL_1_SIZE; i++)
		level_1.push_back(std::make_shared<Field>());
	for (int i = 0; i < LEVEL_2_SIZE; i++)
		level_1.push_back(std::make_shared<Field>());
	for (int i = 0; i < LEVEL_3_SIZE; i++)
		level_1.push_back(std::make_shared<Field>());

}
Gameplay::Gameplay(int a) {

}

Gameplay::~Gameplay()
{
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
	players[0]->state = Player::States::ACTIVE;
	active_player = 0;
	if ( !game_board_texture.loadFromFile("game_board.jpg") )
	{
		std::cout << "blad przy ladowaniu tekstury" << std::endl;
		return false;
	}
	game_board_spirte.setTexture(game_board_texture);
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
	return true;
}

void Gameplay::relase()
{
}
