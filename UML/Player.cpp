#include "stdafx.h"
#include "Player.h"
#include <algorithm>
#include <string>

Player::Player(std::string name) : name(name)
{
	std::cout << "Player konstruktor ";
	std::cout << name; 
}


Player::~Player()
{
}

std::string Player::getName()
{
	return name;
}

Player::Player(const Player &player): name(player.name)
{
	std::cout << "Konstruktor kopiujacy" << std::endl;
}

Player::Player(const Player && player) : name(player.name)
{
	std::cout << "Konstruktor przenoszenia";
}
void Player::swap(Player &player)
{
	this->name.swap(player.name);
}