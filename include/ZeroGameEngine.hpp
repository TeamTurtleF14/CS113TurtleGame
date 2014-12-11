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

//#include "LayoutGen.hpp"
//#include "Hero.hpp"
//#include <SFML/Graphics.hpp>
//#include "Animation.hpp"
//#include "AnimatedSprite.hpp"
#include "CollisionDet.hpp"


class ZeroGameEngine : public CollisionDet {
public:
	enum GameState {Uninitialized, Paused, MainMenu, Playing, Exiting, GameOver};
	GameState _gameState;
	sf::RenderWindow _mainWindow;
	float _xSize;
	float _ySize;

	Hero* Player;

	sf::Texture HeroImage;
	sf::Sprite HeroSpr;

	sf::Texture HeroBackSprSht;
	sf::Texture HeroForwardSprSht;
	sf::Texture HeroRightSprSht;
	sf::Texture HeroLeftSprSht;

	Animation HeroWalkUp;
	Animation HeroWalkLeft;
	Animation HeroWalkRight;
	Animation HeroWalkDown;

	sf::Vector2f HeroMovement{0.f, 0.f};
    Animation* currentHeroAnimation;
    AnimatedSprite animatedHeroSprite{sf::seconds(0.05), true, false};
//   AnimatedSprite animatedHeroSprite(sf::seconds(0.05), true, false);


    sf::Clock frameClock;
    float speed;
    bool noKeyWasPressed;
    sf::Time frameTime;


	LayoutGen* LayoutMaker;
	Room* Headroom;
	Room* current;
	std::string Doors;
	std::vector<sf::Sprite> SpriteList;

	sf::Texture HealthBar;
	sf::Sprite HealthBarSpr;

	sf::Sprite HealthBarSprC;

	// Door Art Containers
	sf::Texture NorthDoor;
	sf::Texture EastDoor;
	sf::Texture SouthDoor;
	sf::Texture WestDoor;
	sf::Sprite NorthDoorSpr;
	sf::Sprite EastDoorSpr;
	sf::Sprite SouthDoorSpr;
	sf::Sprite WestDoorSpr;

	// First is art for first bit in container, not first is the rest
	sf::Texture HPBitFirst;
	sf::Texture HPBit;
	sf::Sprite HPBitFirstSpr;
	sf::Sprite HPBitSpr;

	sf::Texture SPBitFirst;
	sf::Texture SPBit;
	sf::Sprite SPBitFirstSpr;
	sf::Sprite SPBitSpr;



//public:

	// Constructor
	ZeroGameEngine();

	// Destructor
	~ZeroGameEngine();

	// Loads up all the starting sprites
	void initSprites();

	// Starts the game and enters the main loop
	void Start();

	// Returns bool that signals if game is ending
	bool isExiting();

	// Main Game loop
	void GameLoop();

	// Update the gui, will need to take positions from the characters
	void UpdateFrame();

	// Takes a character, N | E | S | W , does what is necessary to display that door
	void DrawDoors(Room* currentRoom);

	// Takes a room and displays its content
	void DrawRoom(Room* current);

	// Uses Hero's attributes to draw the Hero's position, attributes
	void DrawHero(Hero* hero);

	void ControlHero();		// Controls the Hero's basic movements



	// Display HUD: Health Bar, enemy highlighting, etc. if state is Playing
	//	Full Health Bar is 12 squares
	//  Red = Health
	//	Green = Shield
	void DrawHealthBar();
	void DrawHealthBar(Hero* player);



};


#endif /* SRC_ZEROGAMEENGINE_HPP_ */
