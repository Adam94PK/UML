#pragma once
#include "LibsAndDeclarations.h"
#include "PlayerFSM.h"

class Exercise : public PlayerFSM
{
	bool pressed;
	bool executed;
public:
	void init();
	PlayerFSM * execute(Player & player);
	void release();
};

