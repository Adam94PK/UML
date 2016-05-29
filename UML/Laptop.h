#pragma once
#include "LibsAndDeclarations.h"
#include "Field.h"

class Laptop : public Field
{
	void setDescription();
public:
	void perform(Player &player);
};

