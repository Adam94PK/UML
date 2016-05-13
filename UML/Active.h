#pragma once
#include "PlayerFSM.h"
class Active : public PlayerFSM
{
public:
	Active();
	~Active();
	void init();
	PlayerFSM* execute(Player& player);
	void release();
};

