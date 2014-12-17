#ifndef UNIT_HPP
#define UNIT_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include "Animation.hpp"
#include "AnimatedSprite.hpp"

// base class for:
// monster
// spawner
// bullets
// character?

class Unit
{
public:
	Unit();
	Unit(float x, float y);

	void activate();
	bool isActive() const;


	void setX(float xVal);
	void setY(float yVal);
	float getX();
	float getY();

	void setWidth(float w);
	void setHeight(float h);
	float getWidth();
	float getHeight();

	void setPosition(sf::Vector2f pos);
	sf::Vector2f getPosition();

	float distance(sf::Vector2f pos);
	float distance(sf::Vector2i pos);

	//boundaries
	float left();
	float right();
	float top();
	float bottom();

	bool contains(Unit u);
	bool contains(sf::Vector2f pos);

private:
	float _x;
	float _y;
	sf::Vector2f _position;
	bool _active;
	float _width;
	float _height;
};


#endif // UNIT_HPP
