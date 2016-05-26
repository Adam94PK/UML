#pragma once
#include "LibsAndDeclarations.h"
#include <iostream>
#include "Active.h"
#include "DiceRoll.h"
#include "Idle.h"

class Player
{

	struct statistics
	{
		int hangover;
		int knowledge;
		int flair;
		int connections;
		int ects;
	};
	struct graphics
	{
		sf::Texture texture;
		sf::Sprite sprite;
	};
	struct states
	{
		Idle idle;
		Active active;
		DiceRoll dice_roll;
	};
	struct text
	{
		sf::Text hangover;
		sf::Text knowledge;
		sf::Text flair;
		sf::Text connectoins;
		sf::Text ects;
	};

	friend Active;
	friend DiceRoll;
	friend Idle;
	friend PlayerFSM;


	////////////////////////////////////
	std::string name;
	statistics stats;
	int field;
	graphics graphics;
	states available_states;
	PlayerFSM* state;
	sf::Vector2f position;
	sf::Vector2f target_position;
	GameLevel * actual_level;
	text statisticsText;
	sf::Font font;
	//////////////////////////////////
	void initStatisticsText();
	void updateStatisticsText();
	void drawStatistics(sf::RenderWindow & window);
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
	const GameLevel * getActualLvl();
	void setLvl(GameLevel & game_lvl);
};
