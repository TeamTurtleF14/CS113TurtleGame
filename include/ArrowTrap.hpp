/*
 * ArrowTrap.hpp
 *
 *  Created on: Dec 17, 2014
 *      Author: Tony
 */

#ifndef INCLUDE_ARROWTRAP_HPP_
#define INCLUDE_ARROWTRAP_HPP_

#include "Arrow.hpp"
#include "Item.hpp"

class ArrowTrap : public Trap {
private:

//	float frameTime;							// a float that signals how many frames have been updated, keeps track of
//	float TimeLimit;							// Time before taking action e.g: time until blow up
//	float switchTime;							// Time between action (blowing up) and being deleted, stop()
//	bool switchSignal;

	sf::Texture ArrowTrapTexture;
//	sf::Texture DetonateBomb;
	Animation ArrowTrapAnimated;
//	Animation BombBlowUp;
	bool blowup;

	Arrow* arrow;
	bool arrowOut;

public:

	ArrowTrap(float x, float y)
		: Trap("S", 100, 80)
	{
//		setPosition(position);					// reset within constuctor
		if (!ArrowTrapTexture.loadFromFile("images/Traps/ArrowTrap.png"))
			return;
		ArrowTrapAnimated.setSpriteSheet(ArrowTrapTexture);
		ArrowTrapAnimated.addFrame(sf::IntRect(0, 0, 100, 100));

		currentAnimation = &ArrowTrapAnimated;

		float random = (rand() % 800) + 100;

		setPosition(random, 10);

		frameTime = 0;
	}

	~ArrowTrap(){
		stop();
		if (arrowOut)
			delete arrow;
	}

	void playSprite(){
		play(*currentAnimation);
	}

	void updateTimer(sf::Time frametime){
		if (arrowOut){
			arrow->playSprite();
		}
		if ("clicked"){
//			fire
//			if (EnergyCurrent==EnergyMaximum){
			if (EnergyCurrent > EnergyMaximum){
				fireArrow();
			}
		} else {
			if (EnergyCurrent < EnergyMaximum){
				EnergyCurrent += frametime.asSeconds()*EnergyRechargeRate;
			}
			if (EnergyCurrent > EnergyMaximum)
				EnergyCurrent = EnergyMaximum;
		}
	}

	void fireArrow(){
		arrowOut = true;
		float x = getPosition().x + getGlobalBounds().width/2;
		float y = getPosition().y + getGlobalBounds().height;
		arrow = new Arrow(x, y, AttackDamage, AttackSpeed);
	}

	sf::FloatRect getSettingBounds(){
		return sf::FloatRect(0, 0, 100, 950);
	}


};



#endif /* INCLUDE_ARROWTRAP_HPP_ */
