#pragma once
#include "PlayerFSM.h"
class DiceRoll :public PlayerFSM
{
public:
	void init();
	PlayerFSM* execute(Player & player);
	void release();
};

