#include "stdafx.h"
#include "Exercise.h"
#include "Player.h"
#include "GameLevel.h"
#include "GameplayManager.h"

void Exercise::init()
{
	pressed = executed = false;
}

PlayerFSM * Exercise::execute(Player & player)
{
	if (!executed) {
		executed = true;
		shared_ptr<Field> field = player.actual_level->getField(player.field);
		field->perform(player);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		pressed = true;
	if (pressed && !sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		GameplayManager::get()->setNextActive();
		return &player.available_states.idle;
	}
	return nullptr;
}

void Exercise::release()
{
}
