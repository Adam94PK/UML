#include "stdafx.h"
#include "DiceRoll.h"
#include "Player.h"
#include "GameLevelFactory.h"
#include "GameLevel.h"


void DiceRoll::init()
{
}

PlayerFSM* DiceRoll::execute(Player & player)
{
	//Animacja rzutu koscia
	//...
	//end
	std::cout << "DiceRoll" << std::endl;
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		const GameLevel * level = player.getActualLvl();
		std::cout << "Ruch" << std::endl;
		srand(time(NULL));
		int movment = rand() % 6 + 1;
		std::cout << movment << " oczek" << std::endl;
		bool right = false;
		while (!(right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
		}
		if (right)
		{
			player.field -= movment;
			if (player.field < 0) {
				player.field = level->getSize() - 1 + player.field;
			}

		}
		else
		{
			player.field += movment;
			if (player.field > level->getSize())
				player.field -= level->getSize() -1;
		}
		std::cout << "teraz stoje na " << player.field << std::endl;
		//Target position
		int pixel_size = level->level_texture.getSize().x;
		int size = level->getSize();
		if (player.field >= size*(3./4.))
		{
			player.target_position.x = pixel_size - 40;
			player.target_position.y = (player.field - size*(3./4.)) * 80;
		}
		else if (player.field >= size/2)
		{
			player.target_position.x = (player.field - size/2) * 80;
			player.target_position.y = 0;
		}
		else if (player.field >= size/4)
		{
			player.target_position.x = 0;
			player.target_position.y = (size/2 - player.field) * 80;
		}
		else
		{
			player.target_position.x = (size/4 - player.field) * 80;
			player.target_position.y = pixel_size - 40;
		}
		player.position = player.target_position + player.actual_level->getSpritePosition();
		cout << "Target pos = : " << player.position.x << " " << player.position.y;
		return &player.available_states.active;
		//state = States::ACTIVE;
	}
	return nullptr;
}

void DiceRoll::release()
{
}
