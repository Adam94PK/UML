#pragma once
#include "LibsAndDeclarations.h"

class Field
{
public:
	Field();
	virtual ~Field();
	virtual void perfomr(Player &player);
};

