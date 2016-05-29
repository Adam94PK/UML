#pragma once
#include "LibsAndDeclarations.h"
#include <iostream>
#include <memory>
#include <vector>
#include "GameState.h"
#include "GameLevel.h"

class Gameplay : public GameState
{
	std::vector<std::shared_ptr<Player>> players;
	sf::Texture game_board_texture;
	sf::Sprite game_board_spirte;
	int active_player;
	int players_conut;
public:
	bool init();
	bool init(int players_count, std::string *names);
	bool update(float dt);
	bool draw(sf::RenderWindow & window);
	void relase();
	void setNextActive();
	GameLevel gameLvl1;
	GameLevel gameLvl2;
	GameLevel gameLvl3;
};
