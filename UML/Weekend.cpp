#include "stdafx.h"
#include "Weekend.h"
#include "Player.h"

void Weekend::setDescription()
{
	descriptionText.setString("Trudny weekend. Kac++");
}

void Weekend::perform(Player & player)
{
	player.addHangover(5);
}
