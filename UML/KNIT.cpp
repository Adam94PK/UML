#include "stdafx.h"
#include "KNIT.h"
#include "Player.h"

void KNIT::setDescription()
{
	descriptionText.setString("Trafiasz do kola naukowego IT\nKolo tak naprawde wiele Ci nie daje\nale jesli zechcesz, mozesz je przejac\ni organizowac ciekawe wydarzenia");
}

void KNIT::perform(Player & player)
{
	player.addConnectoins(3);
	player.addFlair(1);
	player.addKnowledge(4);
}
