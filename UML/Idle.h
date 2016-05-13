#pragma once
#include "LibsAndDeclarations.h"
#include "PlayerFSM.h"

class Idle :public PlayerFSM
{
public:
	Idle();
	~Idle();
	void init();
	PlayerFSM* execute(Player &player);
	void release();
};

