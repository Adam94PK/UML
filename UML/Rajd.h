#pragma once
#include "LibsAndDeclarations.h"
#include "Field.h"

class Rajd : public Field
{
	void setDescription();
public:
	void perform(Player &player);
};

