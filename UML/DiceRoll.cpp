#include "stdafx.h"
#include "DiceRoll.h"
#include "Player.h"
#include "GameLevelFactory.h"


DiceRoll::DiceRoll()
{
}


DiceRoll::~DiceRoll()
{
}

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
				player.field = GameLevelFactory::LEVEL_1_SIZE - 1 + player.field;
			}

		}
		else
		{
			player.field += movment;
			if (player.field > GameLevelFactory::LEVEL_1_SIZE)
				player.field -= GameLevelFactory::LEVEL_1_SIZE -1;
		}
		std::cout << "teraz stoje na " << player.field << std::endl;
		//Target position

		if (player.field >= 27)
		{
			player.target_position.x = 800 - 40;
			player.target_position.y = (player.field - 27) * 80;
		}
		else if (player.field >= 18)
		{
			player.target_position.x = (player.field - 18) * 80;
			player.target_position.y = 0;
		}
		else if (player.field >= 9)
		{
			player.target_position.x = 0;
			player.target_position.y = (18 - player.field) * 80;
		}
		else
		{
			player.target_position.x = (9 - player.field) * 80;
			player.target_position.y = 800 - 40;
		}
		player.position = player.target_position;
		return &player.state_active;
		//state = States::ACTIVE;
	}
	return nullptr;
}

void DiceRoll::release()
{
}
