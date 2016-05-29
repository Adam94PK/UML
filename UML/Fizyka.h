#pragma once
#include "LibsAndDeclarations.h"
#include "Field.h"

class Fizyka : public Field
{
	void setDescription();
public:
	void perform(Player &player);
};

