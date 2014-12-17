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


bool CollisionDet::willEnterRoom(Room* current, Hero* Player) {
	float posX = Player->getX();
	float posY = Player->getY();

	if (posX > _xSize/2 - 100 && posX < _xSize/2){
		if (posY < _ySize/32 + 32)
			return true;
		else if (posY > _ySize - 90)
			return true;
	}
	if (posY > _ySize/2 - 60 && posY < _ySize/2 + 10 ){
		if (posX < -10)
			return true;
		else if (posX > _xSize - 70)
			return true;
	}
	return false;

}

// Should only be called if the function above returns a 1, signals that he is near a room
char CollisionDet::whichRoom(Room* current, Hero* player){
	float posX = player->getX();
	float posY = player->getY();

	if (posX > _xSize/2 - 100 && posX < _xSize/2){
		if (posY < _ySize/32 + 32)
			return 'N';
		else if (posY > _ySize - 90)
			return 'S';
	}
	if (posY > _ySize/2 - 60 && posY < _ySize/2 + 10 ){
		if (posX < -10)
			return 'W';
		else if (posX > _xSize - 70)
			return 'E';
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

void CollisionDet::GetBounds(AnimatedSprite sprite){

}

void CollisionDet::BulletHit(AnimatedSprite bullet, bool& ismoving) {
//void CollisionDet::BulletHit(AnimatedSprite bullet, std::vector<AnimatedSprite> enemyList}){
	float y = bullet.getPosition().y + (bullet.getGlobalBounds().height)/2;
	float x = bullet.getPosition().x + (bullet.getGlobalBounds().width)/2;
	if (y < 48){
		bullet.stop();
		ismoving = false;
	}
	else if (y > 680){
		bullet.stop();
		ismoving = false;
		std::cout << "stopped" << std::endl;
	}
	if (x < 10) {
		bullet.stop();
		ismoving = false;
		std::cout << "stopped" << std::endl;
	} else if (x > 1055){
		bullet.stop();
		ismoving = false;
		std::cout << "stopped" << std::endl;
	}
//	for (std::vector<AnimatedSprite>::iterator sprite = enemyList.begin(); sprite != enemyList.end(); sprite++){
//
//	}
}
