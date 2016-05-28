#include "stdafx.h"
#include "Player.h"
#include <algorithm>
#include <string>
#include <stdlib.h>
#include "Gameplay.h"

void Player::initStatisticsText()
{
	if (!font.loadFromFile("resources/sansation.ttf"))
		return;
	sf::Vector2f posistion(850., 20.);
	sf::Vector2f to_next_position(0., 25.);
	statisticsText.connectoins.setFont(font);
	statisticsText.connectoins.setCharacterSize(20);
	statisticsText.connectoins.setPosition(posistion);
	statisticsText.connectoins.setColor(sf::Color::White);

	statisticsText.ects.setFont(font);
	statisticsText.ects.setCharacterSize(20);
	posistion += to_next_position;
	statisticsText.ects.setPosition(posistion);
	
	statisticsText.flair.setFont(font);
	statisticsText.flair.setCharacterSize(20);
	posistion += to_next_position;
	statisticsText.flair.setPosition(posistion);
	
	statisticsText.hangover.setFont(font);
	statisticsText.hangover.setCharacterSize(20);
	posistion += to_next_position;
	statisticsText.hangover.setPosition(posistion);
	
	statisticsText.knowledge.setFont(font);
	statisticsText.knowledge.setCharacterSize(20);
	posistion += to_next_position;
	statisticsText.knowledge.setPosition(posistion);
}

void Player::updateStatisticsText()
{
	statisticsText.connectoins.setString("Connections: " + to_string(stats.connections));
	statisticsText.ects.setString("ECTSL: " + to_string(stats.ects));
	statisticsText.flair.setString("Flair: " + to_string(stats.flair));
	statisticsText.hangover.setString("Hangover: " + to_string(stats.hangover));
	statisticsText.knowledge.setString("Knowladge: " + to_string(stats.knowledge));
}

void Player::drawStatistics(sf::RenderWindow & window)
{
	window.draw(statisticsText.connectoins);
	window.draw(statisticsText.ects);
	window.draw(statisticsText.flair);
	window.draw(statisticsText.hangover);
	window.draw(statisticsText.knowledge);
}

Player::Player(std::string name) : name(name), field(0)
{
	state = &available_states.idle;
	std::cout << "Player konstruktor ";
	std::cout << name; 
	stats.connections = 0;
	stats.ects = 0;
	stats.flair = 0;
	stats.hangover = 0;
	stats.knowledge = 0;
}


Player::~Player()
{
}

std::string Player::getName()
{
	return name;
}

Player::Player(const Player &player): name(player.name)
{
	std::cout << "Konstruktor kopiujacy" << std::endl;
}

Player::Player(const Player && player) : name(player.name)
{
	std::cout << "Konstruktor przenoszenia";
}
void Player::swap(Player &player)
{
	this->name.swap(player.name);
}

bool Player::init()
{
	if (!graphics.texture.loadFromFile("player.jpg"))
	{
		std::cout << "Nie udalo sie zaladowac textury" << std::endl;
		return false;
	}
	graphics.sprite.setTexture(graphics.texture);
	initStatisticsText();
	return true;
}

bool Player::update(float dt)
{
	if ( PlayerFSM *new_state = state->execute(*this) )
	{
		state->release();
		new_state->init();
		state = new_state;
	}
	updateStatisticsText();
	return true;
}

bool Player::draw(sf::RenderWindow & window)
{
	graphics.sprite.setPosition(position);
	window.draw(graphics.sprite);
	//drawStatistics(window);
	return true;
}

void Player::relase()
{
}

void Player::setActive()
{
	state = &available_states.active;
}

GameLevel * Player::getActualLvl()
{
	return actual_level;
}

void Player::setLvl(GameLevel & game_lvl)
{
	actual_level = &game_lvl;
}

int Player::getActualField()
{
	return field;
}
