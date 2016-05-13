#pragma once
#include "PlayerFSM.h"
class DiceRoll :public PlayerFSM
{
public:
	DiceRoll();
	~DiceRoll();
	void init();
	PlayerFSM* execute(Player & player);
	void release();
};

