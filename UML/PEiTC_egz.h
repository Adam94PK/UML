#pragma once
#include "LibsAndDeclarations.h"
#include "Field.h"

class PEiTC_egz : public Field
{
	void setDescription();
public:
	void perform(Player &player);
};

