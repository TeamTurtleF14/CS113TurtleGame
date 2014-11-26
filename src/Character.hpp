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
<<<<<<< HEAD
=======
#include <string>
>>>>>>> origin/sani

class Character
{
private:
	unsigned int HitPoints;
<<<<<<< HEAD
	float Speed;
	unsigned int Attack;
=======
	unsigned int HitPointsMax;
	unsigned int ShieldPoints;
	unsigned int ShieldPointsMax;
	float MovementSpeed;
	unsigned int AttackDamage;
	unsigned int AttackSpeed;
	unsigned int Armor;
	float InvulnerablityTime;

	float AbilityCooldown1Current;
	float AbilityCooldown1Max;
	float AbilityCooldown2Current;
	float AbilityCooldown2Max;
	float AbilityCooldown3Current;
	float AbilityCooldown3Max;
	float AbilityCooldown4Current;
	float AbilityCooldown4Max;
>>>>>>> origin/sani

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
