/*
 * CollisionDet.cpp
 *
 *  Created on: Dec 11, 2014
 *      Author: Tony
 */

#include "CollisionDet.hpp"

CollisionDet::CollisionDet(){
	// Changed this if screen resolution needs to change
	_xSize = 1080;
	_ySize = 720;
}


void CollisionDet::EnterRoom(Room* current, Hero* Player) {
	float posX = Player->getX();
	float posY = Player->getY();

	if (posX > _xSize/2 - 100 && posX < _xSize/2){
		if (posY < _ySize/32 + 32)
			std::cout << "Enter NORTH" << std::endl << std::endl;
		else if (posY > _ySize - 90)
			std::cout << "Enter SOUTH" << std::endl << std::endl;
	}
	if (posY > _ySize/2 - 60 && posY < _ySize/2 + 10 ){
		if (posX < -10)
			std::cout << "Enter WEST" << std::endl << std::endl;
		else if (posX > _xSize - 70)
			std::cout << "Enter EAST" << std::endl << std::endl;
	}

}

// Current Implementaion for Hero
// Implementation for all units, after movements -> check every coord in vector
void CollisionDet::WallLimit(AnimatedSprite& sprite) {
	if (sprite.getPosition().y<48){
		sprite.setPosition(sprite.getPosition().x, 48);
	}
	else if (sprite.getPosition().y>635){
		sprite.setPosition(sprite.getPosition().x, 635);
	}
	if (sprite.getPosition().x<-20) {
		sprite.setPosition(-20, sprite.getPosition().y);
	} else if (sprite.getPosition().x > 1015){
		sprite.setPosition(1015, sprite.getPosition().y);
	}
}

void CollisionDet::ApproachDoor(Room* current, Hero* Player){
	// Operates the opening door animation on the North and the South
//	NorthDoorSpr.setPosition(sf::Vector2f(_xSize/2 - 50, _ySize/32));
	// Currently for North Logic
	float posX = Player->getX();
	float posY = Player->getY();

	if (posX > _xSize/2 - 100 && posX < _xSize/2 && posY < _ySize/32 +100)
		std::cout << "HERO IS NEAR" << std::endl << std::endl;
}
