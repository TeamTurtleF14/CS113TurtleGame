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

	// Used to store the strings where the images are located.
	std::string ImageLocation;
	std::string ImageNorth;
	std::string ImageEast;
	std::string ImageSouth;
	std::string ImageWest;

//	Used to help simplify calculations within class, such as starting positions
	int ScreenSizeX;
	int ScreenSizeY;

	unsigned int HitPoints;
	unsigned int HitPointsMax;

	float Speed;
	unsigned int Attack;
	unsigned int ShieldPoints;
	unsigned int ShieldPointsMax;
	float MovementSpeed;
	unsigned int AttackDamage;
	unsigned int AttackSpeed;
	unsigned int Armor;
	float InvulnerablityTime;

	//Space Marine character Variables.
	// ABL = Ability
	float ABLCooldown1Current;
	float ABLCooldown1Max;
	float ABLCooldown2Current;
	float ABLCooldown2Max;
	float ABLCooldown3Current;
	float ABLCooldown3Max;
	float ABLCooldown4Current;
	float ABLCooldown4Max;

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

	Character()
	: HitPoints { 0 }
	{

	}

	Character(int startHP, int ScreenSizeX, int ScreenSizeY)
	: HitPoints {startHP}, ScreenSizeX {ScreenSizeX}, ScreenSizeY {ScreenSizeY}
	{

	}

	Character(int startHP, int startSP, int ScreenSizeX, int ScreenSizeY)
	: HitPoints {startHP}, ShieldPoints {startSP},  ScreenSizeX {ScreenSizeX}, ScreenSizeY {ScreenSizeY}
	{

	}

	std::pair<int, int> Coordinates;	// Stores current position (X, Y) of the character

	std::string StandingImage();		// Returns the location of the image

	// This version can take input, first should be preferred
	std::string StandingImage(std::string Direction);

	//Take a string from either inputs or from the AI and dictate the directionFacing and directionMoving.
	//Inputs are: 'N', 'E', 'W', 'S', 'NE', 'NW', 'SE', 'SW'

	void setDirectionFacing(char Direction){
		DirectionFacing = Direction;
	}

	void setDirectionMoving(char Direction){
		DirectionMoving = Direction;
	}

///////////
//	Character Attributes Below: HP, HP setting etc.
//////////

	unsigned int getCurrentHP() {
		return HitPoints;
	}

	// Change can be either negative or positive, needs checks to ensure current stays within
	// bounds
	// can be used to take damage, gain health, w/e
	void changeCurrentHP(int change) {
		if ((HitPoints + change) <= 0){
			HitPoints = 0;
		} else if ((HitPoints + change) >= HitPointsMax){
			HitPoints = HitPointsMax;
		} else{
			HitPoints = HitPoints + change;
		}
	}

	unsigned int getMaxHP() {
		return HitPointsMax;
	}

	// Change can be negative or positive
	void changeMaxHP(int change) {
		HitPointsMax = HitPointsMax + change;
	}

	unsigned int getCurrentSP() {
		return ShieldPoints;
	}

	void changeCurrentSP(int change) {
		if ((ShieldPoints + change) <= 0){
			ShieldPoints = 0;
		} else if ((ShieldPoints + change) >= ShieldPointsMax){
			ShieldPoints = ShieldPointsMax;
		} else{
			ShieldPoints = ShieldPoints + change;
		}
	}

	unsigned int getMaxSP() {
		return ShieldPointsMax;
	}

	// Change can be negative or positive
	void changeMaxSP(int change) {
		ShieldPointsMax = ShieldPointsMax + change;
	}

///////////////////////////////////////////////
/////////////// HP and SP Crap
////////////////////////////////////////

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


	char getDirectionFacing() {
		return DirectionFacing;
	}

	char getDirectionMoving() {
		return DirectionMoving;
	}




};



#endif /* SRC_CHARACTER_HPP_ */
