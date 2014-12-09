/*
 * Hero.hpp
 * Hero class, the character that the keyboard player controls
 * Subclass of Character.hpp
 *  Created on: Nov 17, 2014
 *      Author: Tony
 */

#ifndef SRC_HERO_HPP_
#define SRC_HERO_HPP_

#include "Character.hpp"

class Hero: public Character {

private:


public:

	Hero() : Character() {
		// Initializes the Hero as facing up
		DirectionFacing = 'N';
	}

	Hero(unsigned int HP, int SizeX, int SizeY)
		: Character(HP, SizeX, SizeY)
	{
		DirectionFacing = 'N';
		setX(SizeX/2 - 50);
		setY(SizeY - (SizeY/5));
	}

	// Returns the image location to render the Hero just standing
	std::string StandingImage(){
		switch (DirectionFacing){
		case 'N':
			return "images/Hero/HeroMovement/BackWalk/HeroWalk_1b.png";
		case 'E':
			return "images/Hero/HeroMovement/RightWalk/HeroWalk_1r.png";
		case 'S':
			return "images/Hero/HeroMovement/ForwardWalk/HeroWalk_1l.png";
		case 'W':
			return "images/Hero/HeroMovement/LeftWalk/HeroWalk_1l.png";
		}
	}

};



#endif /* SRC_HERO_HPP_ */
