#include "Unit.hpp"

Unit::Unit()
{
	_x = 0;
	_y = 0;
	_height = 0;
	_width = 0;
	_position.x = _x;
	_position.y = _y;
	_active = false;
}

Unit::Unit(float x, float y)
{
	_x = x;
	_y = y;
	_height = 0;
	_width = 0;
	_position.x = _x;
	_position.y = _y;

}



void Unit::setX(float xVal)
{
	_x = xVal;
}


void Unit::setY(float yVal)
{
	_y = yVal;
}


float Unit::getX()
{
	return _x;
}


float Unit::getY()
{
	return _y;
}


void Unit::setWidth(float w)
{
	_width = w;
}


void Unit::setHeight(float h)
{
	_height = h;
}


void Unit::setPosition(sf::Vector2f pos)
{
	_position = pos;
}


float Unit::getWidth()
{
	return _width;
}


float Unit::getHeight()
{
	return _height;
}


sf::Vector2f Unit::getPosition()
{
	return _position;
}


float Unit::distance(sf::Vector2f pos)
{
	float d = std::sqrt(std::pow(_x - pos.x, 2) + std::pow(_y - pos.y, 2));
	return d;
}

float Unit::distance(sf::Vector2i pos)
{
	float d = std::sqrt(std::pow(_x - pos.x, 2) + std::pow(_y - pos.y, 2));
	return d;
}

//bounding box
float Unit::left()
{
	return _x - _width/2;
}


float Unit::right()
{
	return _x + _width/2;
}


float Unit::top()
{
	return _y - _height/2;
}


float Unit::bottom()
{
	return _y + _height/2;
}

//checks if other bounding boxes collide with this bounding box
bool Unit::contains(Unit u)
{
	return (left() <= u.left() && right() >= u.left() && top() <= u.top() && bottom() >= u.top())
	||(left() <= u.right() && right() >= u.right() && top() <= u.top() && bottom() >= u.top())
	||(left() <= u.left() && right() >= u.left() && top() <= u.bottom() && bottom() >= u.bottom())
	||(left() <= u.right() && right() >= u.right() && top() <= u.bottom() && bottom() >= u.bottom())
	||contains(u._position);
}

//use for mouse clicks
bool Unit::contains(sf::Vector2f pos)
{
	return left() <= pos.x && right() >= pos.x
			&& top() >= pos.y && bottom() <= pos.y;
}

