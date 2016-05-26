#include "stdafx.h"
#include "Active.h"
#include "Player.h"


Active::Active()
{
}


Active::~Active()
{
}

void Active::init()
{
}

PlayerFSM* Active::execute(Player & player)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		return &player.available_states.dice_roll;
	}
	return nullptr;
}

void Active::release()
{
}
