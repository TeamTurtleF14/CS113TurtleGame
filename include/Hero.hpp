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

class Hero: public Character, public AnimatedSprite {

private:
	sf::Texture ShieldTexture;
	Animation Shield;
	bool ShieldUP;

public:



	int number;

	Hero() : Character() {
		// Initializes the Hero as facing up
		DirectionFacing = 'N';
	}

	Hero(unsigned int startHP, unsigned int maxHP, unsigned int startSP, unsigned int maxSP, int SizeX, int SizeY)
		: Character(startHP, maxHP, startSP, maxSP, SizeX, SizeY), AnimatedSprite{sf::seconds(.8f), true, false}
	{
		setPosition((SizeX/2 - 50), SizeY - (SizeY/5));

		if (!ShieldTexture.loadFromFile("images/Forcefield/Forcefield1B.png"))
			return;
		Shield.setSpriteSheet(ShieldTexture);
		Shield.addFrame(sf::IntRect(0, 0, 88, 91));

		DirectionFacing = 'N';
		setX(SizeX/2 - 50);
		setY(SizeY - (SizeY/5));
		number = 0;
		setSpeed(40.f);
		ShieldUP = true;
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

	bool isShield(){
		if (getCurrentSP()>0){
			std::cout << "true" << std::endl;
			return true;
		}
		std::cout << "end" << std::endl;
		return false;
	}

	void updateHero(){
		playHero();
	}

	void playHero(){
		if (isShield()){
			setPosition(getXY());
			play(Shield);
		}
		else
			stop();
	}




};



#endif /* SRC_HERO_HPP_ */
