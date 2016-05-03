#pragma once
#include "LibsAndDeclarations.h"
#include<iostream>

class Player
{
	std::string name;
	int hangover;
	int knowledge;
	int flair;
	int connections;
	int ects;

public:
	Player(std::string name);
	Player(const Player &player);
	Player(const Player &&player);
	~Player();
	std::string getName();
	void swap(Player &player);

};

