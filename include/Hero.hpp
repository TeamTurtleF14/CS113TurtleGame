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

	int number;

	Hero() : Character() {
		// Initializes the Hero as facing up
		DirectionFacing = 'N';
	}

	Hero(unsigned int startHP, unsigned int maxHP, unsigned int startSP, unsigned int maxSP, int SizeX, int SizeY)
		: Character(startHP, maxHP, startSP, maxSP, SizeX, SizeY)
	{
		DirectionFacing = 'N';
		setX(SizeX/2 - 50);
		setY(SizeY - (SizeY/5));
		number = 0;
		setSpeed(40.f);
	}

	// Returns the image location to render the Hero just standing
	std::string StandingImage(){
		switch (DirectionFacing){
		case 'N':
			return "images/Hero/HeroMovement/BackWalk/HeroWalk_1b.png";
		case 'E':
			return "images/Hero/HeroMovement/RightWalk/HeroWalk_1r.png";
		case 'S':
			return "images/Hero/HeroMovement/ForwardWalk/HeroWalk_1f.png";
		case 'W':
			return "images/Hero/HeroMovement/LeftWalk/HeroWalk_1l.png";
		}
	}



//	std::string StandingImage(){
//		switch (DirectionFacing){
//		case 'N':
//			switch (number){
//			case 0:
//				changeAnimationLevel();
//				return "images/Hero/HeroMovement/BackWalk/HeroWalk_1b.png";
//			case 1:
//				changeAnimationLevel();
//				return "images/Hero/HeroMovement/BackWalk/HeroWalk_2b.png";
//			case 2:
//				changeAnimationLevel();
//				return "images/Hero/HeroMovement/BackWalk/HeroWalk_3b.png";
//			case 3:
//				changeAnimationLevel();
//				return "images/Hero/HeroMovement/BackWalk/HeroWalk_4b.png";
//			default:
//				return "images/Hero/HeroMovement/BackWalk/HeroWalk_1b.png";
//			}
//		case 'S':
//			switch (number){
//			case 0:
//				changeAnimationLevel();
//				return "images/Hero/HeroMovement/ForwardWalk/HeroWalk_1f.png";
//			case 1:
//				changeAnimationLevel();
//				return "images/Hero/HeroMovement/ForwardWalk/HeroWalk_2f.png";
//			case 2:
//				changeAnimationLevel();
//				return "images/Hero/HeroMovement/ForwardWalk/HeroWalk_3f.png";
//			case 3:
//				changeAnimationLevel();
//				return "images/Hero/HeroMovement/ForwardWalk/HeroWalk_4f.png";
//			default:
//				return "images/Hero/HeroMovement/ForwardWalk/HeroWalk_1f.png";
//			}
//		case 'W':
//			switch (number){
//			case 0:
//				changeAnimationLevel();
//				return "images/Hero/HeroMovement/LeftWalk/HeroWalk_1l.png";
//			case 1:
//				changeAnimationLevel();
//				return "images/Hero/HeroMovement/LeftWalk/HeroWalk_2l.png";
//			case 2:
//				changeAnimationLevel();
//				return "images/Hero/HeroMovement/LeftWalk/HeroWalk_3l.png";
//			case 3:
//				changeAnimationLevel();
//				return "images/Hero/HeroMovement/LeftWalk/HeroWalk_4l.png";
//			default:
//				return "images/Hero/HeroMovement/LeftWalk/HeroWalk_1l.png";
//			}
//		case 'E':
//			changeAnimationLevel();
//			switch (number){
//			case 0:
//				return "images/Hero/HeroMovement/RightWalk/HeroWalk_1r.png";
//			case 1:
//				return "images/Hero/HeroMovement/RightWalk/HeroWalk_2r.png";
//			case 2:
//				return "images/Hero/HeroMovement/RightWalk/HeroWalk_3r.png";
//			case 3:
//				return "images/Hero/HeroMovement/RightWalk/HeroWalk_4r.png";
//			default:
//				return "images/Hero/HeroMovement/RightWalk/HeroWalk_1r.png";
//			}
//		}
//	}


};



#endif /* SRC_HERO_HPP_ */
