#include "Pocisk.h"
#include "iostream"

Pocisk::Pocisk(float r,sf::Vector2f polozenie_posatc, sf::Vector2i polozenie_myszu):
CircleShape(r), x_(polozenie_posatc.x), y_(polozenie_posatc.y),y_myszy(polozenie_myszu.y), x_myszy(polozenie_myszu.x), polozenie_posatc_(polozenie_posatc), polozenie_myszy_(polozenie_myszu)
{
}

Pocisk::~Pocisk()
{
}

sf::Vector2f Pocisk::select_()
{
	sf::Vector2f pom_pomozenie_myszy = sf::Vector2f(polozenie_myszy_.x*1.0, polozenie_myszy_.y*1.0);
	sf::Vector2f roznica_polozenia = pom_pomozenie_myszy - polozenie_posatc_;
	sf::Vector2f roznica_polozenia_wersor = roznica_polozenia / sqrt((pow(roznica_polozenia.x, 2) + (pow(roznica_polozenia.y, 2))));
	return sf::Vector2f(roznica_polozenia_wersor.x*5.0, roznica_polozenia_wersor.y*5.0);

}

bool Pocisk::isCollision(sf::CircleShape * circle)
{
	if (this->getRadius() + 3 > sqrt((this->getPosition().x - circle->getPosition().x)*(this->getPosition().x - circle->getPosition().x) + (this->getPosition().y - circle->getPosition().y)*(this->getPosition().y - circle->getPosition().y)))
	{
		return true;
	}
	else
	{
		return false;
	}

}


