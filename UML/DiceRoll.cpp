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
				player.field = level->getSize() + player.field;
			}

		}
		else
		{
			player.field += movment;
			if (player.field >= level->getSize())
				player.field -= level->getSize();
		}
		std::cout << "teraz stoje na " << player.field << std::endl;
		return &player.available_states.move;
	}
	return nullptr;
}

void DiceRoll::release()
{
}
