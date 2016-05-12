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
					field = Gameplay::LEVEL_1_SIZE -1 + field;
				}
				
			}
			else
			{
				field += movment;
				if (field > Gameplay::LEVEL_1_SIZE)
					field -= Gameplay::LEVEL_1_SIZE;
			}
			std::cout << "teraz stoje na " << field << std::endl;
			//Target position

			if (field >= 27)
			{
				target_position.x = 800 - 40;
				target_position.y = (field - 27) * 80;
			}
			else if (field >= 18)
			{
				target_position.x = (field - 18) * 80;
				target_position.y = 0;
			}
			else if (field >= 9)
			{
				target_position.x = 0;
				target_position.y = (18 - field) * 80;
			}
			else
			{
				target_position.x = (9 - field) * 80;
				target_position.y = 800 - 40;
			}
			/*
			if (field <= 8)
			{
				target_position.x = ((8 - field) * 80) + 40;
				target_position.y = 800 - 40;
			}
			else if (field > 8 &&  field < 16) {
				target_position.x = 40;
				target_position.y = ((8 - (field*0.5)) * 80) - 40;
			}
			else if (field >= 16 && field < 24)
			{
				target_position.x = ((8 - field / 3) * 80) + 40;
				target_position.y = 40;
			}
			else
			{
				target_position.x = 800 - 40;
				target_position.y = ((8 - field / 4) * 80) + 40;
			}*/
			position = target_position;
			//state = States::MOVING;
			state = States::ACTIVE;
		}
	}
	
	return true;
}

bool Player::draw(sf::RenderWindow & window)
{
	sprite.setPosition(position);
	window.draw(sprite);
	return true;
}
