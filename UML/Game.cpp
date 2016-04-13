#include "stdafx.h"
#include "Game.h"
#include "Field.h"
#include "Player.h"
#include <memory>

Game::Game(int players_count, std::string *names)
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
Game::Game(int a) {

}

Game::~Game()
{
}


void Game::start() {

}