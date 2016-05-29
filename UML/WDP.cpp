#include "stdafx.h"
#include "WDP.h"
#include "Player.h"

void WDP::setDescription()
{
	descriptionText.setString("Masz egzamin z WDP. Prowadzacy odebral Ci\nwszelka motywacje do nauki, ale ECTSy\nzdobyles bez mrugniecia okiem");
}

void WDP::perform(Player & player)
{
	player.addEcts(10);
	player.addKnowledge(-2);
}
