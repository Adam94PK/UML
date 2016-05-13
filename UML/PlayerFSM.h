#pragma once
#include "LibsAndDeclarations.h"
class PlayerFSM
{
public:
	PlayerFSM();
	PlayerFSM(PlayerFSM &) = delete;
	PlayerFSM& operator= (PlayerFSM &) = delete;
	~PlayerFSM();
	virtual void init() = 0;
	virtual PlayerFSM* execute(Player &)=0;
	virtual void release() = 0;
};

