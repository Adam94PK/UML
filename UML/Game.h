#pragma once
#include "classes.h"
#include <iostream>
#include <memory>
#include <vector>

class Game
{
	static const int LEVEL_1_SIZE = 24;
	static const int LEVEL_2_SIZE = 20;
	static const int LEVEL_3_SIZE = 16;
	std::vector<std::shared_ptr<Field>> level_1;
	std::vector<std::shared_ptr<Field>> level_2;
	std::vector<std::shared_ptr<Field>> level_3;
	std::vector<std::shared_ptr<Player>> players;
public:
	Game(int a);
	Game(int players_count, std::string *names);
	~Game();
	void start();
};
