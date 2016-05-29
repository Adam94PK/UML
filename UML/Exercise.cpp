#include "stdafx.h"
#include "Exercise.h"
#include "Player.h"
#include "GameLevel.h"
#include "GameplayManager.h"

void Exercise::init()
{
}

PlayerFSM * Exercise::execute(Player & player)
{
	cout << "exercise" << endl;
	shared_ptr<Field> field = player.actual_level->getField(player.field);
	field->perform(player);
	GameplayManager::get()->setNextActive();
	return &player.available_states.idle;
}

void Exercise::release()
{
}
