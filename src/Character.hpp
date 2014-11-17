/*
 * Character.hpp
 * Character class, base class for Hero, enemies, so on
 *
 *  Created on: Nov 17, 2014
 *      Author: Tony
 */

#ifndef SRC_CHARACTER_HPP_
#define SRC_CHARACTER_HPP_

#include <utility>

class Character
{
private:
	unsigned int HitPoints;
	float Speed;
	unsigned int Attack;

public:
	std::pair<int, int> Coordinates;	// Stores current position (X, Y) of the character

	int getX(){
		return Coordinates.first;
	}

	int getY(){
		return Coordinates.second;
	}
};



#endif /* SRC_CHARACTER_HPP_ */
