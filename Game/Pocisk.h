#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

class Pocisk : public sf::CircleShape
{
public:
	Pocisk(float r, sf::Vector2f polozenie_posatc, sf::Vector2i polozenie_celownik);
	~Pocisk();
	//	sf::Vector2f runspace(sf::CircleShape pom, sf::Vector2f v_pom);
	 sf::Vector2f select_();
	bool isCollision(sf::CircleShape *circle);

private:
	sf::Vector2f polozenie_posatc_;
	sf::Vector2i polozenie_myszy_;
	float x_;
	float y_;
	float x_myszy;
	float y_myszy;

};

