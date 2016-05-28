#pragma once
#include "PlayerFSM.h"

class Move : public PlayerFSM
{
public:
	void init();
	PlayerFSM * execute(Player & player);
	void release();
};

