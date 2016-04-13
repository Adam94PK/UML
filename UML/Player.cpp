#include "stdafx.h"
#include "Player.h"
#include <string>

Player::Player(std::string name) : name(name)
{
	std::cout << "Player konstruktor " << std::endl;
	std::cout << name; 
}


Player::~Player()
{
}
