#include "stdafx.h"
#include "Player.h"
#include <algorithm>
#include <string>
#include <stdlib.h>
#include "Gameplay.h"

Player::Player(std::string name) : name(name), state(States::IDLE), field(0)
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

bool Player::update(float dt)
{
	if (state == States::ACTIVE)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			state = States::DICE_ROLL;
		}
	}
	else if (state == States::DICE_ROLL)
	{
		//Animacja rzutu koscia
		//...
		//end
		std::cout << "DiceRoll" << std::endl;

		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			std::cout << "Ruch" << std::endl;
			srand(time(NULL));
			int movment = rand() % 6 + 1;
			std::cout << movment << " oczek" << std::endl;
			bool right = false;
			while ( !(right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{ }
			if (right)
			{
				field -= movment;
				if (field < 0) {
					field = Gameplay::LEVEL_1_SIZE + field;
				}
				
			}
			else
			{
				field += movment;
				if (field > Gameplay::LEVEL_1_SIZE)
					field -= Gameplay::LEVEL_1_SIZE;
			}
			std::cout << "teraz stoje na " << field << std::endl;
			state = States::MOVING;
		}
	}
	
	return true;
}
