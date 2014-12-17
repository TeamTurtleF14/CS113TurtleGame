/*
 * CollisionDet.hpp
 *
 *  Created on: Dec 11, 2014
 *      Author: Tony
 */

#ifndef INCLUDE_COLLISIONDET_HPP_
#define INCLUDE_COLLISIONDET_HPP_

#include "LayoutGen.hpp"
#include "Hero.hpp"
#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "AnimatedSprite.hpp"

// Serves the purpose of containing functions used for detecting collisions
// E.G. Entering rooms, not going through walls, possibly attacks

class CollisionDet {
private:
	float _xSize;
	float _ySize;
public:

	CollisionDet();

	void WallLimit(AnimatedSprite& sprite);				// Sets the limiting bounds for where the player can move
	void ApproachDoor(Room* current, Hero* Player);		// Detects if the Hero is near the door
	bool willEnterRoom(Room* current, Hero* Player);	// Logic for what happens when Hero approaches and enters a door
	void transitionRoom(Room* current, Hero* Player);	// Transitions into the next room
	char whichRoom(Room* current, Hero* player);
	void GetBounds(AnimatedSprite sprite);				// Gets a sprite's bounds in a box
	void BulletHit(AnimatedSprite bullet, std::vector<AnimatedSprite> enemyList);
	void BulletHit(AnimatedSprite bullet, bool& isMoving);

};



#endif /* INCLUDE_COLLISIONDET_HPP_ */
