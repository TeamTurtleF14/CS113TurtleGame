/*
 * Item.hpp
 *
 *  Created on: Dec 13, 2014
 *      Author: Tony
 */

#ifndef INCLUDE_ITEM_HPP_
#define INCLUDE_ITEM_HPP_

#include "AnimatedSprite.hpp"
#include "Animation.hpp"

// Base class for all objects on field that are stationary.
// Hero's bombs, mines, traps, etc
// Will contain the nesscessary crap to draw the objects as well

class Item : public AnimatedSprite
{
private:

public:
//	sf::Vector2f coordinates{0.f, 0.f};			// Items such as Hero's bombs, mines, traps shouldnt change
	float frameTime;							// a float that signals how many frames have been updated, keeps track of
	float TimeLimit;							// Time before taking action e.g: time until blow up
	float switchTime;							// Time between action (blowing up) and being deleted, stop()
	bool switchSignal;

//public:
	Animation* currentAnimation;

//public:

	Item(float TimeLimit, float switchTime)
		:TimeLimit{TimeLimit}, switchTime{switchTime}, AnimatedSprite(sf::seconds(.8f), true, false)
	{
		frameTime = 0;
	}


	Animation* getAnimation(){
		return currentAnimation;
	}



	bool withinBounds(){

	}


	virtual void updateTimer(float time){
		frameTime += time;
	}

	virtual void checkDetonate(std::vector<AnimatedSprite> enemy){

	}

	virtual void playSprite() {

	}

	float getTime(){
		return frameTime;
	}

	void resetTimer() {
		frameTime = 0;
	}

	bool sendDamage(){
		if (switchSignal)
			return true;
		return false;
	}

};



#endif /* INCLUDE_ITEM_HPP_ */
