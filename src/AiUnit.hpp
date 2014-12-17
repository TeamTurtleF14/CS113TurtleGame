#ifndef AIUNIT_HPP
#define AIUNIT_HPP

#include "Unit.hpp"
#include "Images.hpp"

class AiUnit : public Unit
{
public:
	AiUnit(float x, float y,Images::UnitType type, Animation* initAnimation);

	void activate();


	bool isActive() const;

	void setFrameTime(sf::Time frameTime);

	void update();

	void play();

	void setVelocity(float x, float y);

	void keyPressed();
	void notPressed();

	AnimatedSprite getAiSprite();

	Images::Direction getDir();
	Images::UnitType getType();
	float getRadius();
	sf::Vector2f getVelocity();
	float getSpeed();
	float angle(sf::Vector2f end);
	float angle(sf::Vector2i end);

	unsigned int getHP() const;
	unsigned int getMax() const;

	float distance(sf::Vector2f end);
	float distance(sf::Vector2i end);

	sf::Vector2f getPosition();

	void setAiAnimation(Animation* animation);


	void Move(sf::Vector2i target, sf::CircleShape& targetArea, Animation* animation);

	void DetectSm(const AnimatedSprite& Sm, const std::vector<AiUnit*>& units, Animation* walkAnimation, Animation* attackAnimation);

	bool isContained(sf::Vector2i start, sf::Vector2i end);



	//bool contains()






private:
	unsigned int _HP = 3;
	unsigned int _MaxHP = 3;
	float _speed;
	float _radius;
	Images::Direction _dir;
	Images::UnitType _type;
	sf::Vector2f _velocity;
	Animation* _Ai;
	AnimatedSprite _AiSprite;
	sf::Time _frameTime;
    bool _NoKeyPressed;
    bool _active;

};

#endif // AIUNIT_HPP
