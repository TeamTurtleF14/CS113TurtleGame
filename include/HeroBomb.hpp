/*
 * HeroBomb.hpp
 *
 *  Created on: Dec 16, 2014
 *      Author: Tony
 */

#ifndef INCLUDE_HEROBOMB_HPP_
#define INCLUDE_HEROBOMB_HPP_

#include "Item.hpp"

class HeroBomb : public Item {

private:
	sf::Texture BombTexture;
	sf::Texture DetonateBomb;
	Animation Bomb;
	Animation BombBlowUp;


public:

	HeroBomb(float positionX, float positionY, float damage)
		: Item(10, 5)
	{
		setPosition(positionX, positionY);
		if (!BombTexture.loadFromFile("images/Hero/HeroWeapons/bomb.png"))
			return;
		Bomb.setSpriteSheet(BombTexture);
		Bomb.addFrame(sf::IntRect(0, 0, 88, 91));

		if (!DetonateBomb.loadFromFile("images/Hero/HeroWeapons/Explosion-Sprite-Sheet.png"))
			return;
		BombBlowUp.setSpriteSheet(DetonateBomb);
		BombBlowUp.addFrame(sf::IntRect(0, 0, 119, 118));
		BombBlowUp.addFrame(sf::IntRect(119, 0, 119, 118));
		BombBlowUp.addFrame(sf::IntRect(238, 0, 119, 118));
		BombBlowUp.addFrame(sf::IntRect(357, 0, 119, 118));
		BombBlowUp.addFrame(sf::IntRect(476, 0, 119, 118));

		currentAnimation = &Bomb;

		frameTime = 0;
		switchSignal = false;
		switchTime = 1;
	}

//	Animation* getAnimation(){
//		return currentAnimation;
//	}

	void switchAnimation(){
		if (currentAnimation==&Bomb)
			currentAnimation = &BombBlowUp;
		frameTime = 0;
//		else
//			currentAnimation = &Bomb;
	}

	void playSprite(){
		play(*currentAnimation);
	}

	void updateTimer(float frametime){
//		std::cout << "asasdasdasdadaasdadsdassdasdkadqwkdhiawfiuahfilefhiewwehf" << std::endl;
		frameTime += frametime;
		std::cout << frameTime << std::endl;
		if (switchSignal){
			if (frameTime > switchTime){
//				std::cout << "STOPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP" << std::endl;
				stop();
			}
		} else {
			if (frameTime > TimeLimit){
				std::cout << "BLOW UP" << std::endl;
				switchAnimation();
				switchSignal = true;
			}
		}
	}

//	void stopSprite(){
//		stop();
//	}

};


#endif /* INCLUDE_HEROBOMB_HPP_ */
