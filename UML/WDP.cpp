#include "stdafx.h"
#include "WDP.h"
#include "Player.h"

void WDP::setDescription()
{
	descriptionText.setString("You went to the exam from C++\n Roll the dice to pass the exam and get some ets");
}

void WDP::perform(Player & player)
{
	player.addEcts(10);
	player.addKnowledge(-2);
}
