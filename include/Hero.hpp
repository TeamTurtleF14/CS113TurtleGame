/*
 * Hero.hpp
 * Hero class, the character that the keyboard player controls
 * Subclass of Character.hpp
 *  Created on: Nov 17, 2014
 *      Author: Tony
 */

#ifndef SRC_HERO_HPP_
#define SRC_HERO_HPP_

class Hero: public Character
{
public:

	// Returns the image location to render the Hero just standing
	std::string Hero::StandingImage(){
		switch (DirectionFacing){
		case 'N':
			return "/images/Hero/HeroMovement/BackWalk/HeroWalk_1b.png";
		case 'E':
			return "/images/Hero/HeroMovement/RightWalk/HeroWalk_1r.png";
		case 'S':
			return "/images/Hero/HeroMovement/ForwardWalk/HeroWalk_1l.png";
		case 'W':
			return "/images/Hero/HeroMovement/LeftWalk/HeroWalk_1l.png";
		}
	}


private:

};



#endif /* SRC_HERO_HPP_ */