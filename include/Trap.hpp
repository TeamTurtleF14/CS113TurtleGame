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

public:
	//Trap Base class

	std::string ImageLocation;

	unsigned int HitPoints;
	unsigned int Attack;
	unsigned int HitPointsMax;
//	unsigned int ShieldPoints;
//	unsigned int ShieldPointsMax;
//	float MovementSpeed;
	float AttackDamage;
	float AttackSpeed;

	//Space Marine character Variables.

	float AttackCoolDown;

	//AI-specific character variables.

	float EnergyCurrent;
	float EnergyMaximum;
	float EnergyRechargeRate;


	//Variables that dictate the direction that the Character is facing and moving.
	std::string DirectionFacing;
//	std::string DirectionMoving;



//public:
	std::pair<int, int> Coordinates;	// Stores current position (X, Y) of the character

	Trap(std::string direction, float Speed, float Damage)
		: DirectionFacing{direction}, AttackSpeed{Speed}, EnergyMaximum{100},
		  EnergyCurrent{EnergyMaximum}, EnergyRechargeRate{1}, AttackDamage{Damage}
	{

	}

	virtual std::string StandingImage(){
		// Returns the location of the image
	}

	// This version can take input, first should be preferred
	virtual std::string StandingImage(std::string Direction){

	}

	virtual std::string AttackImage(){

	}


	int getX(){
		return Coordinates.first;
	}

	int getY(){
		return Coordinates.second;
	}

	std::string getDirectionFacing(){
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

	virtual sf::FloatRect getSettingBounds(){
		// By Default
		return sf::FloatRect(-20, 48, 1015, 635);

	}

	virtual void updateTimer(sf::Time frameTime, Hero* player){
		return;
	}

//	virtual void playSprite() {
//		play(*currentAnimation);
//	}


};


#endif /* INCLUDE_TRAP_HPP_ */
