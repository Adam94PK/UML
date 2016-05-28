#include "stdafx.h"
#include "Beer.h"
#include "Player.h"

void Beer::setDescription()
{
	descriptionText.setString("Now you are drinking. Y meet new friedns(connections + 1) \n but in the next day you have hangover(hangover + 1");
}

void Beer::perfomr(Player & player)
{
	player.stats.connections += 1;
	player.stats.hangover += 1;
}
