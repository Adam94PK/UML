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
	sf::Vector2f text_position(850., 20.);
	sf::Vector2f to_next_position(0., 25.);

	statisticsText.name.setFont(font);
	statisticsText.name.setCharacterSize(25);
	statisticsText.name.setPosition(text_position);
	statisticsText.name.setColor(sf::Color::Red);

	text_position += to_next_position;
	statisticsText.connectoins.setFont(font);
	statisticsText.connectoins.setCharacterSize(20);
	statisticsText.connectoins.setPosition(text_position);
	statisticsText.connectoins.setColor(sf::Color::White);

	statisticsText.ects.setFont(font);
	statisticsText.ects.setCharacterSize(20);
	text_position += to_next_position;
	statisticsText.ects.setPosition(text_position);
	
	statisticsText.flair.setFont(font);
	statisticsText.flair.setCharacterSize(20);
	text_position += to_next_position;
	statisticsText.flair.setPosition(text_position);
	
	statisticsText.hangover.setFont(font);
	statisticsText.hangover.setCharacterSize(20);
	text_position += to_next_position;
	statisticsText.hangover.setPosition(text_position);
	
	statisticsText.knowledge.setFont(font);
	statisticsText.knowledge.setCharacterSize(20);
	text_position += to_next_position;
	statisticsText.knowledge.setPosition(text_position);

	statisticsText.name.setString(name);
	statisticsText.connectoins.setString("Connections: " + to_string(stats.connections));
	statisticsText.ects.setString("ECTSL: " + to_string(stats.ects));
	statisticsText.flair.setString("Flair: " + to_string(stats.flair));
	statisticsText.hangover.setString("Hangover: " + to_string(stats.hangover));
	statisticsText.knowledge.setString("Knowladge: " + to_string(stats.knowledge));
}

void Player::updateStatisticsText()
{
	
}

void Player::drawStatistics(sf::RenderWindow & window)
{
	window.draw(statisticsText.name);
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
	//updateStatisticsText();
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

bool Player::addHangover(int pts)
{
	stats.hangover += pts;
	statisticsText.hangover.setString("Hangover: " + to_string(stats.hangover));
	return true;
}

bool Player::addKnowledge(int pts)
{
	stats.knowledge += pts;
	statisticsText.knowledge.setString("Knowladge: " + to_string(stats.knowledge));
	return true;
}

bool Player::addFlair(int pts)
{
	stats.flair += pts;
	statisticsText.flair.setString("Flair: " + to_string(stats.flair));
	return true;
}

bool Player::addConnectoins(int pts)
{
	stats.connections += pts;
	statisticsText.connectoins.setString("Connections: " + to_string(stats.connections));
	return true;
}

bool Player::addEcts(int pts)
{
	stats.ects += pts;
	statisticsText.ects.setString("ECTSL: " + to_string(stats.ects));
	return true;
}
