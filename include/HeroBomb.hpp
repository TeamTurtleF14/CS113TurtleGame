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
	bool blowup;


public:

	HeroBomb(sf::Vector2f position, float damage)
		: Item(10, 5)
	{
		setPosition(position);
		if (!BombTexture.loadFromFile("images/Hero/HeroWeapons/bomb.png"))
			return;
		Bomb.setSpriteSheet(BombTexture);
		Bomb.addFrame(sf::IntRect(0, 0, 88, 91));

//		if (!DetonateBomb.loadFromFile("images/Hero/HeroWeapons/Explosion-Sprite-Sheet.png"))
		if (!DetonateBomb.loadFromFile("images/Hero/HeroWeapons/bomb_explosion.png"))
			return;
		BombBlowUp.setSpriteSheet(DetonateBomb);
		BombBlowUp.addFrame(sf::IntRect(0, 0, 50, 50));
		BombBlowUp.addFrame(sf::IntRect(51, 0, 50, 50));
		BombBlowUp.addFrame(sf::IntRect(0, 51, 50, 50));
		BombBlowUp.addFrame(sf::IntRect(51, 51, 50, 50));

		currentAnimation = &Bomb;

		frameTime = 0;
		switchSignal = false;
		switchTime = 5;
		blowup = false;
		startSound();
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

	void updateTimer(sf::Time frametime){
		frameTime += frametime.asSeconds();
		if (sound.getStatus()!=sound.Playing)
			sound.play();
		if (switchSignal){
			if (!blowup){
				blowup = 1;
				sound.setPlayingOffset(sf::seconds(5.f));
			}
			update(frametime);
			if (sound.getStatus()!=sound.Playing)
				sound.play();
			if (frameTime > switchTime){
				stop();
				sound.stop();
			}
		} else {
			if (frameTime > TimeLimit){
				std::cout << "BLOW UP" << std::endl;
				switchAnimation();
				switchSignal = true;
			}
		}
	}

	void startSound(){
		if (!buffer.loadFromFile("sounds/TimeBomb.wav"))
			return;
		sound.setBuffer(buffer);
		sound.setPlayingOffset(sf::seconds(0.f));
	}

//	void stopSprite(){
//		stop();
//	}

};


#endif /* INCLUDE_HEROBOMB_HPP_ */
