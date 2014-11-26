/*
 * ZeroGameEngine.hpp
 * The game engine
 * Main will call this class, where it will provide the graphics, a function to update,
 * movement, etc.
 *  Created on: Nov 11, 2014
 *      Author: Tony
 */

#ifndef SRC_ZEROGAMEENGINE_HPP_
#define SRC_ZEROGAMEENGINE_HPP_

#include "LayoutGen.hpp"


class ZeroGameEngine {

	// Update the gui, will need to take positions from the characters
	void UpdateFrame();

	// Takes the LayoutGen, produces a layout for the GUI, from LayoutGen
	void GenerateLayout();

	// Takes a room and displays its content
	void DisplayRoom(Room* current);

	// Display HUD: Health Bar, enemy highlighting, etc.
	void DisplayHUD();
};



#endif /* SRC_ZEROGAMEENGINE_HPP_ */
