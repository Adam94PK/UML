#include "stdafx.h"
#include "Exercise.h"
#include "Player.h"
#include "GameLevel.h"

void Exercise::init()
{
}

PlayerFSM * Exercise::execute(Player & player)
{
	cout << "exercise" << endl;
	shared_ptr<Field> field = player.actual_level->getField(player.field);
	field->perfomr(player);
	return &player.available_states.active;
}

void Exercise::release()
{
}
