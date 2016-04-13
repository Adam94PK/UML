#pragma once
#include "classes.h"
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
	~Player();
};

