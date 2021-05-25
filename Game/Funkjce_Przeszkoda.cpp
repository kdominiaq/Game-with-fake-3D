#include "Przeszkoda.h"


Przeszkoda::Przeszkoda(float r, float x, float y, bool axis, bool side, float limit) :
	CircleShape(r), x_(x), y_(y), axis_(axis), side_(side), limit_(limit)
{
}

Przeszkoda::~Przeszkoda()
{

}

 sf::Vector2f Przeszkoda::select_move_() // nadanie
{
	if (axis_ == true and side_ == true)
	{
		return sf::Vector2f(.5, 0); // prawo
	}
	else if (axis_ == true and side_ == false)
	{
		return sf::Vector2f(-.5, 0); //  lewo
	}
	else if (axis_ == false and side_ == true)
	{
		return sf::Vector2f(0, -.5); //gora
	}
	else if (axis_ == false and side_ == false)
	{
		return sf::Vector2f(0, .5); //dol
	}
}



 bool Przeszkoda::isCollision(sf::RectangleShape rect)
{
	sf::Vector2f wielkosc_rect(18, 18);
	float radius = 9.1;
	sf::Vector2f pom(9, 9);
	sf::Vector2f bP = rect.getPosition() + pom;
	// Sprawdzanie kolizji
	sf::Vector2f circleDistance;

	circleDistance.x = abs(this->getPosition().x - bP.x + (wielkosc_rect.x / 2));
	circleDistance.y = abs(this->getPosition().y - bP.y + (wielkosc_rect.y / 2));

	if (circleDistance.x > (wielkosc_rect.x / 2 + radius))
	{
		return false;
	}
	if (circleDistance.y > (wielkosc_rect.y / 2 + radius))
	{
		return false;
	}

	if (circleDistance.x <= (wielkosc_rect.x / 2))
	{
		return true;
	}
	if (circleDistance.y <= (wielkosc_rect.y / 2))
	{
		return true;
	}

	float cornerDistance_sq = (circleDistance.x - wielkosc_rect.x / 2) *(circleDistance.x - wielkosc_rect.x / 2) +
		(circleDistance.y - wielkosc_rect.y / 2) *(circleDistance.y - wielkosc_rect.y / 2);

	return(cornerDistance_sq <= (radius * radius));
}


 sf::Vector2f Przeszkoda::runspace(sf::Vector2f v_pom)
 {
	 if (axis_ == true and side_ == true) // x prawo
	 {
		 if (this->getPosition().x >= (limit_ + x_))
		 {
			 return sf::Vector2f(-.5, 0);
		 }
		 else if (this->getPosition().x <= (x_ - limit_))
		 {
			 return sf::Vector2f(.5, 0);
		 }
		 else
		 {
			 return v_pom;
		 }
	 }
	 else if (axis_ == true and side_ == false) // x lewo
	 {
		 if (this->getPosition().x <= x_ - limit_)
		 {
			 return sf::Vector2f(.5, 0);
		 }
		 else if (this->getPosition().x >= limit_ + x_)
		 {
			 return sf::Vector2f(-.5, 0);
		 }
		 else
		 {
			 return v_pom;
		 }
	 }
	 else if (axis_ == false and side_ == true) // y gora
	 {
		 if (this->getPosition().y <= y_ - limit_)
		 {
			 return sf::Vector2f(0, .5);
		 }
		 else if (this->getPosition().y >= y_ + limit_)
		 {
			 return sf::Vector2f(0, -.5);
		 }
		 else
		 {
			 return v_pom;
		 }
	 }
	 else if (axis_ == false and side_ == false) // y dol
	 {
		 if (this->getPosition().y >= y_ + limit_)
		 {
			 return sf::Vector2f(0, -.5);
		 }
		 else if (this->getPosition().y <= y_ - limit_)
		 {
			 return sf::Vector2f(0, .5);
		 }
		 else
		 {
			 return v_pom;
		 }
	 }
 }