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
#include "Hero.hpp"
#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "AnimatedSprite.hpp"
#include <cmath>
#include "Images.hpp"

class ZeroGameEngine {
public:
	enum GameState {Uninitialized, Paused, MainMenu, Playing, Exiting};
	GameState _gameState;
	sf::RenderWindow _mainWindow;
	int _xSize;
	int _ySize;

	Hero* Player;

	LayoutGen* LayoutMaker;
	Room* Headroom;
	Room* current;
	std::string Doors;
	std::vector<sf::Sprite> SpriteList;

	sf::Texture HeroImage;
	sf::Sprite HeroSpr;

	sf::Texture HealthBar;
	sf::Sprite HealthBarSpr;

	sf::Texture NorthDoor;
	sf::Texture EastDoor;
	sf::Texture SouthDoor;
	sf::Texture WestDoor;
	sf::Sprite NorthDoorSpr;
	sf::Sprite EastDoorSpr;
	sf::Sprite SouthDoorSpr;
	sf::Sprite WestDoorSpr;

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
	void MenuLoop();

	void GameLoop();

	// Update the gui, will need to take positions from the characters
	void UpdateFrame();

	// Takes a character, N | E | S | W , does what is necessary to display that door
	void DrawDoors(Room* currentRoom);

	// Takes a room and displays its content
	void DrawRoom(Room* current);

	// Uses Hero's attributes to draw the Hero's position, attributes
	void DrawHero(Hero* hero);

	void DrawHero();		// For Testing

	// Display HUD: Health Bar, enemy highlighting, etc. if state is Playing
	//	Full Health Bar is 12 squares
	//  Red = Health
	//	Green = Shield
	void DrawHealthBar();
//	void DrawHealthBar(Hero player);


};


#endif /* SRC_ZEROGAMEENGINE_HPP_ */
