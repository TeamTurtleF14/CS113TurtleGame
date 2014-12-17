#ifndef UNIT_HPP
#define UNIT_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <iostream>
#include <cmath>

// base class for:
// monster
// spawner
// bullets
// character?

class Unit
{
public:

	Unit(float x, float y, float width, float height)
		:x{x}, y{y}, width{width}, height{height}
	{
		position.x = x;
		position.y = y;
		active = false;
	}

	virtual ~Unit() = default;
	virtual void activate();
	virtual void update();

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

	//boundaries
	float left();
	float right();
	float top();
	float bottom();

	bool contains(Unit u);
	bool contains(sf::Vector2f pos);

private:
	float x;
	float y;
	float width;
	float height;
	sf::Vector2f position;
	bool active;

};


#endif // UNIT_HPP
