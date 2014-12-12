/*
 * Hero.hpp
 * Hero class, the character that the keyboard player controls
 * Subclass of Character.hpp
 *  Created on: Nov 17, 2014
 *      Author: Tony
 */

#ifndef SRC_HERO_HPP_
#define SRC_HERO_HPP_
#include <iostream>
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
	std::string StandingImage()
	{
		std::string img;
		switch (DirectionFacing){
		case 'N':
			img = "images/Hero/HeroMovement/BackWalk/HeroWalk_1b.png";
			break;
		case 'E':
			img = "images/Hero/HeroMovement/RightWalk/HeroWalk_1r.png";
			break;
		case 'S':
			img = "images/Hero/HeroMovement/ForwardWalk/HeroWalk_1l.png";
			break;
		case 'W':
			img = "images/Hero/HeroMovement/LeftWalk/HeroWalk_1l.png";
			break;
		default:
			img = "images/Hero/HeroMovement/BackWalk/HeroWalk_1b.png";
			break;
		}
		return img;
	}

};



#endif /* SRC_HERO_HPP_ */
