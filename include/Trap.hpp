/*
 * Trap.hpp
 *
 *  Created on: Dec 8, 2014
 *      Author: Tony
 */

#ifndef INCLUDE_TRAP_HPP_
#define INCLUDE_TRAP_HPP_

#include <utility>
#include <string>
#include "Item.hpp"

class Trap : public Item
{
private:

	//Trap Base class

	std::string ImageLocation;

	unsigned int HitPoints;
	float Speed;
	unsigned int Attack;
	unsigned int HitPointsMax;
	unsigned int ShieldPoints;
	unsigned int ShieldPointsMax;
//	float MovementSpeed;
	unsigned int AttackDamage;
	unsigned int AttackSpeed;
	unsigned int Armor;
//	float InvulnerablityTime;

	//Space Marine character Variables.

	float AttackCoolDown;

	float AbilityCooldown1Current;
	float AbilityCooldown1Max;
	float AbilityCooldown2Current;
	float AbilityCooldown2Max;
	float AbilityCooldown3Current;
	float AbilityCooldown3Max;
	float AbilityCooldown4Current;
	float AbilityCooldown4Max;

	//AI-specific character variables.

	float Energy;
	float EnergyMaximum;
	float EnergyRechargeRate;


	//Variables that dictate the direction that the Character is facing and moving.
	std::string DirectionFacing;
//	std::string DirectionMoving;



public:
	std::pair<int, int> Coordinates;	// Stores current position (X, Y) of the character

	virtual std::string StandingImage();		// Returns the location of the image

	// This version can take input, first should be preferred
	virtual std::string StandingImage(std::string Direction);

	virtual std::string AttackImage();


	int getX(){
		return Coordinates.first;
	}

	int getY(){
		return Coordinates.second;
	}

	char getDirectionFacing(){
		return DirectionFacing;
	}

//	char getDirectionMoving(){
//		return DirectionMoving;
//	}

	//Take a string from either inputs or from the AI and dictate the directionFacing and directionMoving.
	//Inputs are: 'N', 'E', 'W', 'S', 'NE', 'NW', 'SE', 'SW'
	void setDirectionFacing(std::string Direction){
		DirectionFacing = Direction;
	}

//	void setDirectionMoving(std::string Direction){
//		DirectionMoving = Direction;
//	}




};


#endif /* INCLUDE_TRAP_HPP_ */
