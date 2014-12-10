#ifndef UNIT_HPP
#define UNIT_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <iostream>

struct Unit
{
//public:
	sf::CircleShape shape;
	float unitRadius{10.f};
	sf::Vector2f velocity{0, 0};
/*
	Unit();

	Unit(const Unit& u);

	~Unit();

	Unit& operator=(const Unit& u);
*/
	Unit(float x, float y)
	{
		shape.setPosition(x,y);
		shape.setRadius(unitRadius);
		shape.setFillColor(sf::Color::Cyan);
		shape.setOrigin(unitRadius, unitRadius);
	}

	void update()
	{
		shape.move(velocity);
	}

	float x()		{return shape.getPosition().x;}
	float y()		{return shape.getPosition().y;}
	float left()	{return x() - shape.getRadius();}
	float right()	{return x() + shape.getRadius();}
	float bottom()	{return y() + shape.getRadius();}
	float top()		{return y() - shape.getRadius();}
};


#endif // UNIT_HPP
