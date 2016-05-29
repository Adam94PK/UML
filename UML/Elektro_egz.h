#pragma once
#include "LibsAndDeclarations.h"
#include "Field.h"

class Elektro_egz : public Field
{
	void setDescription();
public:
	void perform(Player &player);
};

