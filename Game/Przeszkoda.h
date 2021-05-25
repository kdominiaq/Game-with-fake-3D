#pragma once
#include <SFML/Graphics.hpp>

class Przeszkoda : public sf::CircleShape
{
public:
	Przeszkoda(float r, float x, float y,bool axis, bool side, float limit);
	~Przeszkoda();
//	sf::Vector2f runspace(sf::CircleShape pom, sf::Vector2f v_pom);
	sf::Vector2f runspace(sf::Vector2f v_pom);
	sf::Vector2f select_move_();
	bool isCollision(sf::RectangleShape rect);
	
private:
	bool axis_; // x = true, y = false
	bool side_; // right/top = true, left/down = false
	
	float limit_;
	float x_;
	float y_;

};

