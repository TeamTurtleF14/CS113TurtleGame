#include "Unit.hpp"



void Unit::activate()
{
	active = !active;
}

void Unit::update()
{
}

void Unit::setX(float xVal)
{
	x = xVal;
}


void Unit::setY(float yVal)
{
	y = yVal;
}


float Unit::getX()
{
	return x;
}


float Unit::getY()
{
	return y;
}


void Unit::setWidth(float w)
{
	width = w;
}


void Unit::setHeight(float h)
{
	height = h;
}


void Unit::setPosition(sf::Vector2f pos)
{
	position = pos;
}


float Unit::getWidth()
{
	return width;
}


float Unit::getHeight()
{
	return height;
}


sf::Vector2f Unit::getPosition()
{
	return position;
}


float Unit::distance(sf::Vector2f pos)
{
	float d = std::sqrt(std::pow(x - pos.x, 2) + std::pow(y - pos.y, 2));
	return d;
}

//bounding box
float Unit::left()
{
	return x - width/2;
}


float Unit::right()
{
	return x + width/2;
}


float Unit::top()
{
	return y - height/2;
}


float Unit::bottom()
{
	return y + height/2;
}

//checks if other bounding boxes collide with this bounding box
bool Unit::contains(Unit u)
{
	return (left() <= u.left() && right() >= u.left() && top() <= u.top() && bottom() >= u.top())
	||(left() <= u.right() && right() >= u.right() && top() <= u.top() && bottom() >= u.top())
	||(left() <= u.left() && right() >= u.left() && top() <= u.bottom() && bottom() >= u.bottom())
	||(left() <= u.right() && right() >= u.right() && top() <= u.bottom() && bottom() >= u.bottom())
	||contains(u.position);
}

//use for mouse clicks
bool Unit::contains(sf::Vector2f pos)
{
	return left() <= pos.x && right() >= pos.x
			&& top() >= pos.y && bottom() <= pos.y;
}
