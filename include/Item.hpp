/*
 * Item.hpp
 *
 *  Created on: Dec 13, 2014
 *      Author: Tony
 */

#ifndef INCLUDE_ITEM_HPP_
#define INCLUDE_ITEM_HPP_

#include "AnimatedSprite.hpp"

// Base class for all objects on field that are stationary.
// Hero's bombs, mines, traps, etc
// Will contain the nesscessary crap to draw the objects as well

class Item : public AnimatedSprite
{
private:
	sf::Vector2f coordinates{0.f, 0.f};			// Items such as Hero's bombs, mines, traps shouldnt change
	float frameTime;							// a float that signals how many frames have been updated, keeps track of

public:

	Item(float setX, float setY)
		: coordinates {setX, setY}
	{

	}


	sf::Vector2f getPosition(){
		return coordinates;
	}

	void setXY(float X, float Y){
		coordinates.x = X;
		coordinates.y = Y;
	}

	bool withinBounds(sf::Vector2f position){

	}

	void updateTime(float time){
		frameTime += time;
	}

	float getTime(){
		return frameTime;
	}

	void resetTimer() {
		frameTime = 0;
	}

};



#endif /* INCLUDE_ITEM_HPP_ */
