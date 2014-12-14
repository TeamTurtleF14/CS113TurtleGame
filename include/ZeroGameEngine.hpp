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
#include <SFML/Audio.hpp>
#include "CollisionDet.hpp"


class ZeroGameEngine : public CollisionDet {
public:

	float timetest;

	enum GameState {Uninitialized, Paused, MainMenu, Playing, Exiting, GameOver, Tutorial};
	GameState _gameState;
	sf::RenderWindow _mainWindow;
	float _xSize;
	float _ySize;

	sf::ConvexShape pauseCursor;
	bool ptContinue;
	bool tutorialSwitch;
	bool showCredits;
	bool HeroWon;
///////////////////////////////////////////////////////////////////////////
//	Hero specific items: sprites for movements, attacks etc
//////////
	Hero* Player;

	sf::Texture HeroImage;
	sf::Sprite HeroSpr;

	sf::Texture HeroBackSprSht;
	sf::Texture HeroForwardSprSht;
	sf::Texture HeroRightSprSht;
	sf::Texture HeroLeftSprSht;
	sf::Texture HeroLBSprSht;
	sf::Texture HeroLFSprSht;
	sf::Texture HeroRBSprSht;
	sf::Texture HeroRFSprSht;
	Animation HeroWalkUp;
	Animation HeroWalkLeft;
	Animation HeroWalkRight;
	Animation HeroWalkDown;
	Animation HeroWalkLB;
	Animation HeroWalkLF;
	Animation HeroWalkRB;
	Animation HeroWalkRF;

	sf::Texture HeroShootSprSht;
	Animation HeroShootUp;
	Animation HeroShootLeft;
	Animation HeroShootRight;
	Animation HeroShootDown;
	Animation HeroShootLB;
	Animation HeroShootLF;
	Animation HeroShootRB;
	Animation HeroShootRF;

	sf::Vector2f HeroMovement{0.f, 0.f};
    Animation* currentHeroAnimation;
    AnimatedSprite animatedHeroSprite{sf::seconds(.8f), true, false};
//   AnimatedSprite animatedHeroSprite{sf::seconds(0.05), true, false};

    bool movingbullet;
    float bulletTimer;
    sf::Vector2f BulletMovement{0.f, 0.f};
    sf::Texture blueBulletTexture;
//    Animation* BlueBullet;
    Animation BlueBullet;
    AnimatedSprite animatedBlueBullet{sf::seconds(0.5), true, false};

/////////////////////
//    Hero related variables end
/////////////////////////////////////////////////////////////////////////////
    sf::RectangleShape mouseDrag;
    sf::Vector2i mouseStart, mouseRelease, mouseRight, mouseRightRelease;

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

//////////////////////
////// END TEXTURE/SPRITES
///////////////////////

	sf::Music BGM;

//public:
	ZeroGameEngine();						// Constructor
	~ZeroGameEngine();						// Destructor
	void initSprites();						// Loads up all the starting sprites
	void Start();							// Starts the game and enters the main loop
	bool isExiting();						// Returns bool that signals if game is ending
	void MenuLoop();						// Main Game loop and Menu Loop
	void GameLoop();
	void UpdateFrame();						// Update the gui, will need to take positions from the characters
	void DrawDoors(Room* currentRoom);		// Takes a character, N | E | S | W , does what is necessary to display that door
	void DrawRoom(Room* current);			// Takes a room and displays its content
	void DrawHero(Hero* hero);				// Uses Hero's attributes to draw the Hero's position, attributes
	void ControlMouse(sf::Event event); 	// Controls the mouses' basic controls
	void ControlHero(sf::Event event);						// Controls the Hero's basic movements
	void DrawHealthBar();
	void DrawHealthBar(Hero* player);
	void setHero(char cameFrom, Hero* player, AnimatedSprite& playerSprite); // Set Hero position near the door entered from
	void updateTimer();						// uses the vector of items, updates their timer
	void HeroShoot(std::string direction);

};


#endif /* SRC_ZEROGAMEENGINE_HPP_ */
