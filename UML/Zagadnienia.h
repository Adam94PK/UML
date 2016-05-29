#pragma once
#include "LibsAndDeclarations.h"
#include "Field.h"

class Zagadnienia : public Field
{
	void setDescription();
public:
	void perform(Player & player);
};

