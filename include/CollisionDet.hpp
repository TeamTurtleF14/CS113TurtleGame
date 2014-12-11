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

	void WallLimit(AnimatedSprite& sprite);		// Sets the limiting bounds for where the player can move

	void ApproachDoor(Room* current, Hero* Player);	// Detects if the Hero is near the door

	// Logic for what happens when Hero approaches and enters a door
	void EnterRoom(Room* current, Hero* Player);

	// Transitions to next room
	void transitionRoom(Room* current, Hero* Player);
};



#endif /* INCLUDE_COLLISIONDET_HPP_ */
