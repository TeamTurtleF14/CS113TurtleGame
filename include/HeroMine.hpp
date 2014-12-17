/*
 * HeroMine.hpp
 *
 *  Created on: Dec 16, 2014
 *      Author: Tony
 */

#ifndef INCLUDE_HEROMINE_HPP_
#define INCLUDE_HEROMINE_HPP_

#include "Item.hpp"
#include "Unit.hpp"

class HeroMine : public Item {
private:
	sf::Texture MineTexture;
	sf::Texture DetonateMine;
	Animation Mine;
	Animation MineBlowUp;

public:

	HeroMine(sf::Vector2f position, float damage)
			: Item(10, 5)
		{
			setPosition(position);
			if (!MineTexture.loadFromFile("images/Hero/HeroWeapons/mine.png"))
				return;
			Mine.setSpriteSheet(MineTexture);
			Mine.addFrame(sf::IntRect(0, 0, 88, 91));

			if (!DetonateMine.loadFromFile("images/Hero/HeroWeapons/mine_explosion.png"))
				return;
			MineBlowUp.setSpriteSheet(DetonateMine);
			MineBlowUp.addFrame(sf::IntRect(0, 0, 88, 91));
			MineBlowUp.addFrame(sf::IntRect(89, 0, 88, 91));
			MineBlowUp.addFrame(sf::IntRect(0, 92, 88, 91));
			MineBlowUp.addFrame(sf::IntRect(89, 92, 88, 91));

			currentAnimation = &Mine;

			frameTime = 0;
			switchSignal = false;
			switchTime = 1;
		}

	//	Animation* getAnimation(){
	//		return currentAnimation;
	//	}

	void switchAnimation(){
		if (currentAnimation==&Mine)
			currentAnimation = &MineBlowUp;
		frameTime = 0;
	//		else
	//			currentAnimation = &Bomb;
	}

	void playSprite(){
		play(*currentAnimation);
	}

	void checkDetonate(std::vector<Unit> spritelist){
		float x = getPosition().x + (getGlobalBounds().width)/2;
		float y = getPosition().y + (getGlobalBounds().height)/2;
		if (switchSignal){
			stop();
		}
		for (std::vector<Unit>::iterator sprite = spritelist.begin(); sprite!=spritelist.end(); sprite++){
			if ((*sprite).distance(sf::Vector2f(x, y)) < 20){
				switchAnimation();
				switchSignal = true;
			}
		}
	}

};




#endif /* INCLUDE_HEROMINE_HPP_ */
