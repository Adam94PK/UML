#include "stdafx.h"
#include "WF.h"
#include "Player.h"

void WF::setDescription()
{
	descriptionText.setString("Trafiles na wf! Schodza z Ciebie wszelkie\nweekendowe opary...");
}

void WF::perform(Player & player)
{
	player.addFlair(5);
	player.addHangover(-3);
}
