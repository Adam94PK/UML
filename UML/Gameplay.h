#pragma once
#include "LibsAndDeclarations.h"
#include <iostream>
#include <memory>
#include <vector>
#include "GameState.h"
#include "GameLevel.h"

class Gameplay : public GameState
{
	GameLevel level_1;
	std::vector<std::shared_ptr<Player>> players;
	sf::Texture game_board_texture;
	sf::Sprite game_board_spirte;
	int active_player;
	GameLevel gameLvl;
public:
	Gameplay();
	Gameplay(int players_count, std::string *names);
	void start();
	bool init();
	bool init(int players_count, std::string *names);
	bool update(float dt);
	bool draw(sf::RenderWindow & window);
	void relase();
};
