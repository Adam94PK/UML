#include "stdafx.h"
#include "Move.h"
#include "Player.h"
#include "GameLevel.h"

void Move::init()
{
}

PlayerFSM * Move::execute(Player & player)
{
	GameLevel * level = player.getActualLvl();
	int pixel_size = level->level_texture.getSize().x;
	int size = level->getSize();
	if (player.field >= size*(3. / 4.))
	{
		player.target_position.x = pixel_size - 40;
		player.target_position.y = (player.field - size*(3. / 4.)) * 80;
	}
	else if (player.field >= size / 2)
	{
		player.target_position.x = (player.field - size / 2) * 80;
		player.target_position.y = 0;
	}
	else if (player.field >= size / 4)
	{
		player.target_position.x = 0;
		player.target_position.y = (size / 2 - player.field) * 80;
	}
	else
	{
		player.target_position.x = (size / 4 - player.field) * 80;
		player.target_position.y = pixel_size - 40;
	}
	player.position = player.target_position + player.actual_level->getSpritePosition();
	cout << "Target pos = : " << player.position.x << " " << player.position.y;
	return &player.available_states.exercise;
}

void Move::release()
{
}
