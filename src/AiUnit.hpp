#ifndef AIUNIT_HPP
#define AIUNIT_HPP

#include "Unit.hpp"

class AiUnit : public Unit
{
public:
	AiUnit(float x, float y, float width, float height, unsigned int HP, unsigned int MaxHP, float speed)
		:Unit{x, y, width, height}, HP{HP}, MaxHP{MaxHP}, speed{speed}
	{
	}

virtual void activate();

virtual void update();

private:
	unsigned int HP;
	unsigned int MaxHP;
	float speed;
	sf::Vector2f velocity;
	sf::Texture texture;
};

#endif // AIUNIT_HPP
