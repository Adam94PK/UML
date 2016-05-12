#pragma once
#include "LibsAndDeclarations.h"
#include<iostream>

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
	sf::Vector2f position;
	sf::Vector2f target_position;
public:
	enum class States { IDLE, ACTIVE, DICE_ROLL, MOVING };
	States state;
	int field;
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
};
