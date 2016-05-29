#pragma once
#include "LibsAndDeclarations.h"
#include "Field.h"

class Weekend : public Field
{
	void setDescription();
public:
	void perform(Player &player);
};

