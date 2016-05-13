#include "stdafx.h"
#include "Player.h"
#include <algorithm>
#include <string>
#include <stdlib.h>
#include "Gameplay.h"

Player::Player(std::string name) : name(name), field(0)
{
	state = &state_idle;
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

bool Player::init()
{
	if (!texture.loadFromFile("player.jpg"))
	{
		std::cout << "Nie udalo sie zaladowac textury" << std::endl;
		return false;
	}
	sprite.setTexture(texture);
	return true;
}

bool Player::update(float dt)
{
	if ( PlayerFSM *new_state = state->execute(*this) )
	{
		state = new_state;
	}
	return true;
}

bool Player::draw(sf::RenderWindow & window)
{
	sprite.setPosition(position);
	window.draw(sprite);
	return true;
}

void Player::relase()
{
}

void Player::setActive()
{
	state = &state_active;
}
