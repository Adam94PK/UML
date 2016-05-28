#pragma once
#include "LibsAndDeclarations.h"
#include "Field.h"

class Beer : public Field
{
	void setDescription();
public:
	void perfomr(Player &player);
};

