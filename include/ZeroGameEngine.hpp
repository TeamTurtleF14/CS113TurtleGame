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
#include <SFML/Graphics.hpp>

namespace ZGE
{

class ZeroGameEngine {
public:
	LayoutGen* LayoutMaker;
	Room* Headroom;
	Room* current;
	enum GameState {Uninitialized, Paused, MainMenu, Playing, Exiting};
	GameState _gameState;
	sf::RenderWindow _mainWindow;
	std::string Doors;
	std::vector<sf::Sprite> SpriteList;

//public:

	// Constructor
	ZeroGameEngine();

	// Destructor
	~ZeroGameEngine();

	// Starts the game and enters the main loop
	void Start();

	// Returns bool that signals if game is ending
	bool isExiting();

	// Main Game loop
	void GameLoop();

	// Update the gui, will need to take positions from the characters
	void UpdateFrame();

	// Takes a character, N | E | S | W , does what is necessary to display that door
	void DisplayDoors(char Direction);

	// Takes a room and displays its content
	void DisplayRoom(Room* current);

	// Display HUD: Health Bar, enemy highlighting, etc. if state is Playing
	void DisplayHUD();


};

} // namespace ZGE

#endif /* SRC_ZEROGAMEENGINE_HPP_ */
