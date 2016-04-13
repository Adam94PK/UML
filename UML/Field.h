#pragma once
#include "classes.h"

class Field
{
public:
	Field();
	virtual ~Field();
	virtual void perfomr(Player &player);
};

