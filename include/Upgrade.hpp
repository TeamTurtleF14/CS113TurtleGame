/*
 * Upgrade.hpp
 * Upgrades class
 *
 *  Created on: Dec 2, 2014
 *      Author: Sani
 */

#ifndef SRC_UPGRADE_HPP_
#define SRC_UPGRADE_HPP_

#include <utility>
#include <string>
#include <map>

class Upgrade
{
	//Name = Name of the Upgrade.
	//VariableNameModifier1-3 = References the modifier that this upgrade modifies. "NULL" if not used.
	//VariableModifier1-3 = How much this modifier modifies this upgrade. "NULL" if not used.
	//AddOrMult1-3 = Is this modifier and additive or multiplicative modifier. "A" for additive, "M" for multiplicative. "NULL" if not used.
	//ForCharacter = Which character this is for. 0 = SM, 1 = rAI
	//Tier = Which tier this upgrade is. Goes from 1 to 3.
	//PreReqName1-2 = Any prerequisite upgrades needed for this upgrade. "NULL" if no prerequisite.
	//

private:
	std::string Name;
	std::string VariableNameModifier1;
	float VariableModifier1;
	std::string AddOrMult1;
	std::string VariableNameModifier2;
	float VariableModifier2;
	std::string AddOrMult2;
	std::string VariableNameModifier3;
	float VariableModifier3;
	std::string AddOrMult3;

	bool ForCharacter;
	int Tier;

	std::string PreReqName1;
	std::string PreReqName2;

public:

	std::string getName(){
		return Name;
	}

	//Organizes all the modifiers into a <map> to be sent back.

	int getNumberModifiers(){
		if (VariableNameModifier1 == "NULL")
			return 0;
		else if (VariableNameModifier2 == "NULL")
			return 1;
		else if (VariableNameModifier3 == "NULL")
			return 2;
		else
			return 3;
	}


};



#endif /* SRC_UPGRADE_HPP_ */
