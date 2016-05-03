#pragma once
#include "LibsAndDeclarations.h"
#include <iostream>
#include <memory>
#include <vector>
#include "GameState.h"

class Gameplay : public GameState
{
	static const int LEVEL_1_SIZE = 24;
	static const int LEVEL_2_SIZE = 20;
	static const int LEVEL_3_SIZE = 16;
	std::vector<std::shared_ptr<Field>> level_1;
	std::vector<std::shared_ptr<Field>> level_2;
	std::vector<std::shared_ptr<Field>> level_3;
	std::vector<std::shared_ptr<Player>> players;
	sf::Texture game_board_texture;
	sf::Sprite game_board_spirte;
public:
	Gameplay(int a);
	Gameplay(int players_count, std::string *names);
	~Gameplay();
	void start();
	bool init();
	bool update(float dt);
	void draw(sf::RenderWindow & window);
	void relase();
};
