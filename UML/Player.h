#pragma once
#include "LibsAndDeclarations.h"
#include<iostream>
#include "Active.h"
#include "DiceRoll.h"
#include "Idle.h"

class Player
{
	std::string name;
	int hangover;
	int knowledge;
	int flair;
	int connections;
	int ects;
	sf::Texture texture;
	sf::Sprite sprite;

public:
	Player(std::string name);
	Player(const Player &player);
	Player(const Player &&player);
	~Player();
	std::string getName();
	void swap(Player &player);
	bool init();
	bool update(float dt);
	bool draw(sf::RenderWindow & window);
	void relase();
	void setActive();
	int field;
	PlayerFSM* state;
	Idle state_idle;
	Active state_active;
	DiceRoll state_dice_roll;
	sf::Vector2f position;
	sf::Vector2f target_position;
};
