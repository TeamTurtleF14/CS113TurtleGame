/*
 * Arrow.hpp
 *
 *  Created on: Dec 17, 2014
 *      Author: Tony
 */

#ifndef INCLUDE_ARROW_HPP_
#define INCLUDE_ARROW_HPP_

#include "Item.hpp"

class Arrow: public Item {
private:

	sf::Texture ArrowTexture;
	Animation Arrow;
	sf::Vector2f ArrowMovement;

public:

	Arrow(sf::Vector2f position, float damage, float speed)
		: ArrowMovement{0, 100.f}								// for now assume that arrows will only go south
	{
	}

	void updateTimer(sf::Time frametime){
//		frameTime += frametime.asSeconds();
//		if (frameTime > TimeLimit || (!isPlaying())){
////			std::cout << "stopping <" << std::endl;
//			stop();
//		} else if (frameTime < TimeLimit){
//			play();
			move(ArrowMovement * frametime.asSeconds());
//			update(frametime);
			CheckWall();
//		}
	}


	void CheckWall() {
		float y = getPosition().y + (getGlobalBounds().height)/2;
		float x = getPosition().x + (getGlobalBounds().width)/2;
		if (y < 48){
			stop();
		}
		else if (y > 680){
			stop();
			std::cout << "Arrow stopped" << std::endl;
		}
		if (x < 10) {
			stop();
			std::cout << "Arrow stopped" << std::endl;
		} else if (x > 1055){
			stop();
		}
	}

};



#endif /* INCLUDE_ARROW_HPP_ */
