#include "stdafx.h"
#include "Beer.h"
#include "Player.h"

void Beer::setDescription()
{
	descriptionText.setString("Jestes pijany. Poznales nowych znajomych,\nale jutro dopadnie Cie kac morderca!");
}

void Beer::perform(Player & player)
{
	player.addConnectoins(2);
	player.addHangover(2);
}
