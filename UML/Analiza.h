#pragma once
#include "LibsAndDeclarations.h"
#include "Field.h"
class Analiza : public Field
{
	void setDescription();
public:
	void perform(Player &player);
};

