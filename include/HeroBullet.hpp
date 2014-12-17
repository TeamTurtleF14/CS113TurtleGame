/*
 * HeroBullet.hpp
 *
 *  Created on: Dec 16, 2014
 *      Author: Tony
 */

#ifndef INCLUDE_HEROBULLET_HPP_
#define INCLUDE_HEROBULLET_HPP_

#include "Item.hpp"

class HeroBullet : public Item {
private:
	sf::Texture BulletTexture;
	Animation Bullet;
	sf::Vector2f BulletMovement;


public:

	HeroBullet(sf::Vector2f position, float damage, sf::Vector2f movement)
		: Item(4, 0), BulletMovement{movement}
	{
		setPosition(position);
		if (!BulletTexture.loadFromFile("images/Hero/HeroWeapons/spr_bullet_strip.png"))
			return;
		Bullet.setSpriteSheet(BulletTexture);
		Bullet.addFrame(sf::IntRect(0, 0, 39, 39));

		currentAnimation = &Bullet;

		frameTime = 0;
		switchSignal = false;
		switchTime = 1;
	}

//	if (movingbullet) {
//		if (bulletTimer<5){
//			std::cout << "one" << std::endl;
//			animatedBlueBullet.play(BlueBullet);
//			animatedBlueBullet.move(BulletMovement * frameTime.asSeconds());
//			animatedBlueBullet.update(frameTime);
//			bulletTimer += frameTime.asSeconds();
//			_mainWindow.draw(animatedBlueBullet);
//			BulletHit(animatedBlueBullet, movingbullet);
//		} else {
//			animatedBlueBullet.stop();
//			movingbullet = false;
//		}
//	} else {
////			std::cout << "three" << std::endl;
//		bulletTimer = 0;
//		animatedBlueBullet.setPosition(animatedHeroSprite.getPosition());
//	}

	void updateTimer(sf::Time frametime){
		frameTime += frametime.asSeconds();
		if (frameTime > TimeLimit || (!isPlaying())){
			std::cout << "stopping <" << std::endl;
			stop();
		} else if (frameTime < TimeLimit){
//			play();
			move(BulletMovement * frametime.asSeconds());
//			update(frametime);
			CheckWall();
		}
	}

	void CheckWall() {
	//void CollisionDet::BulletHit(AnimatedSprite bullet, std::vector<AnimatedSprite> enemyList}){
		float y = getPosition().y + (getGlobalBounds().height)/2;
		float x = getPosition().x + (getGlobalBounds().width)/2;
		if (y < 48){
			stop();
		}
		else if (y > 680){
			stop();
			std::cout << "stopped" << std::endl;
		}
		if (x < 10) {
			stop();
			std::cout << "stopped" << std::endl;
		} else if (x > 1055){
			stop();

			std::cout << "stopped" << std::endl;
		}
	//	for (std::vector<AnimatedSprite>::iterator sprite = enemyList.begin(); sprite != enemyList.end(); sprite++){
	//
	//	}
	}

};




#endif /* INCLUDE_HEROBULLET_HPP_ */
