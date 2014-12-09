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
#include <string>

class Character
{
private:

	//Space Marine, Monster character variables.

	std::string ImageLocation;
	std::string ImageNorth;
	std::string ImageEast;
	std::string ImageSouth;
	std::string ImageWest;

//	Used to help simplify calculations within class, such as starting positions
	int SizeX;
	int SizeY;

	unsigned int HitPoints;
	float Speed;
	unsigned int Attack;
	unsigned int HitPointsMax;
	unsigned int ShieldPoints;
	unsigned int ShieldPointsMax;
	float MovementSpeed;
	unsigned int AttackDamage;
	unsigned int AttackSpeed;
	unsigned int Armor;
	float InvulnerablityTime;

	//Space Marine character Variables.

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


public:

	//Variables that dictate the direction that the Character is facing and moving.
//	std::string DirectionFacing;
//	std::string DirectionMoving;

	char DirectionFacing;
	char DirectionMoving;

	Character(){

	}

	Character(int HP, int SizeX, int SizeY)
	: HitPoints {HP}, SizeX {SizeX}, SizeY {SizeY}
	{

	}

	std::pair<int, int> Coordinates;	// Stores current position (X, Y) of the character

	std::string StandingImage();		// Returns the location of the image

	// This version can take input, first should be preferred
	std::string StandingImage(std::string Direction);

	void setX(int x){
		Coordinates.first = x;
	}

	void setY(int y){
		Coordinates.second = y;
	}

	int getX(){
		return Coordinates.first;
	}

	int getY(){
		return Coordinates.second;
	}

//	std::string getDirectionFacing(){
//		return DirectionFacing;
//	}
//
//	std::string getDirectionMoving(){
//		return DirectionMoving;
//	}

	char getDirectionFacing() {
		return DirectionFacing;
	}

	char getDirectionMoving() {
		return DirectionMoving;
	}

	//Take a string from either inputs or from the AI and dictate the directionFacing and directionMoving.
	//Inputs are: 'N', 'E', 'W', 'S', 'NE', 'NW', 'SE', 'SW'
//	void setDirectionFacing(std::string Direction){
//		DirectionFacing = Direction;
//	}

	void setDirectionFacing(char Direction){
		DirectionFacing = Direction;
	}

//	void setDirectionMoving(std::string Direction){
//		DirectionMoving = Direction;
//	}

	void setDirectionMoving(char Direction){
		DirectionMoving = Direction;
	}


};



#endif /* SRC_CHARACTER_HPP_ */
