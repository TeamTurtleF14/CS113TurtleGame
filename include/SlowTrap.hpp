/*
 * SlowTrap.hpp
 *
 *  Created on: Dec 17, 2014
 *      Author: Tony
 */

#ifndef INCLUDE_SLOWTRAP_HPP_
#define INCLUDE_SLOWTRAP_HPP_

#include "Item.hpp"
#include "Hero.hpp"

class SlowTrap: public Trap {
private:
	sf::Texture SlowTrapTexture;
//	sf::Texture DetonateBomb;
	Animation SlowTrapAnimated;

public:

	SlowTrap(float x, float y)
		: Trap("S", 100, 80)
	{
		setPosition(x, y);
		if (!SlowTrapTexture.loadFromFile("images/Traps/SlowTrap.jpg"))
			return;
		SlowTrapAnimated.setSpriteSheet(SlowTrapTexture);
		SlowTrapAnimated.addFrame(sf::IntRect(0, 0, 50, 50));

		currentAnimation = &SlowTrapAnimated;

		frameTime = 0;
		TimeLimit = 20;
		switchSignal = false;
	}

	void playSprite(){
		play(*currentAnimation);
	}

	void updateTimer(sf::Time frametime, Hero* player){
		if (!switchSignal){
			if (player->distance(getPosition()) < 80){
				switchSignal = true;
			}
		} else {
			frameTime += frametime.asSeconds();
			if (frameTime >= TimeLimit){
				switchSignal = false;
				player->setVelocity(player->getSpeed());
			} else {
				player->setVelocity(player->getSpeed()-45);
			}
		}
//		float frameTime;							// a float that signals how many frames have been updated, keeps track of
//		float TimeLimit;							// Time before taking action e.g: time until blow up
//		float switchTime;							// Time between action (blowing up) and being deleted, stop()
//		bool switchSignal;
	}

};



#endif /* INCLUDE_SLOWTRAP_HPP_ */
