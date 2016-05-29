#pragma once
#include "LibsAndDeclarations.h"
#include "Field.h"

class Metodyka : public Field
{
	void setDescription();
public:
	void perform(Player &player);
};

