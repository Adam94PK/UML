#include "stdafx.h"
#include "Player.h"
#include <algorithm>
#include <string>
#include <stdlib.h>
#include "Gameplay.h"

Player::Player(std::string name) : name(name), field(0)
{
	state = &available_states.idle;
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
	if (!graphics.texture.loadFromFile("player.jpg"))
	{
		std::cout << "Nie udalo sie zaladowac textury" << std::endl;
		return false;
	}
	graphics.sprite.setTexture(graphics.texture);
	return true;
}

bool Player::update(float dt)
{
	if ( PlayerFSM *new_state = state->execute(*this) )
	{
		state->release();
		new_state->init();
		state = new_state;
	}
	return true;
}

bool Player::draw(sf::RenderWindow & window)
{
	graphics.sprite.setPosition(position);
	window.draw(graphics.sprite);
	return true;
}

void Player::relase()
{
}

void Player::setActive()
{
	state = &available_states.active;
}
