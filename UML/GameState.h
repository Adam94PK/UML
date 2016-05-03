#pragma once
#include "LibsAndDeclarations.h"

class GameState
{
public:
	GameState();
	GameState(const GameState&) = delete;
	GameState & operator=(const GameState&) = delete;
	~GameState();
	virtual bool init() = 0;
	virtual bool update(float dt) = 0;
	virtual void draw(sf::RenderWindow & window) = 0;
	virtual void relase() = 0;
};

