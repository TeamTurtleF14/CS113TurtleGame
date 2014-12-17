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

class ArrowTrap : public Trap{
private:

//	float frameTime;							// a float that signals how many frames have been updated, keeps track of
//	float TimeLimit;							// Time before taking action e.g: time until blow up
//	float switchTime;							// Time between action (blowing up) and being deleted, stop()
//	bool switchSignal;

	sf::Texture ArrowTrapTexture;
//	sf::Texture DetonateBomb;
	Animation ArrowTrap;
//	Animation BombBlowUp;
	bool blowup;

	Arrow* arrow;
	bool arrowOut;

public:

	ArrowTrap(float Speed, float damage, )
		: Trap("S", Speed, damage)
	{
//		setPosition(position);					// reset within constuctor
		if (!ArrowTrapTexture.loadFromFile("images/Traps/ArrowTrap.jpg"))
			return;
		ArrowTrap.setSpriteSheet(ArrowTrapTexture);
		ArrowTrap.addFrame(sf::IntRect(0, 0, 100, 100));

		currentAnimation = &ArrowTrap;

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
		if (!arrow->isPlaying())
			stop();
		else
			arrow->playSprite();
		if ("clicked"){
//			fire
			if (EnergyCurrent==EnergyMaximum){
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
		arrow = new Arrow(getPosition());
	}



};



#endif /* INCLUDE_ARROWTRAP_HPP_ */
