/*
 * ZeroGameEngine.cpp
 *
 *  Created on: Nov 29, 2014
 *      Author: Tony
 */

#include "ZeroGameEngine.hpp"

//ZeroGameEngine::GameState ZeroGameEngine::_gameState = Uninitialized;
//ZeroGameEngine::GameState ZGE::_gameState = MainMenu;
////sf::RenderWindow _mainWindow;

// Constructor
ZeroGameEngine::ZeroGameEngine(){
	_xSize = 1080;
	_ySize = 720;

	Player = new Hero(1000, _xSize, _ySize);

	LayoutMaker = new LayoutGen();
	Headroom = LayoutMaker->getHeadRoom();
	current = Headroom;
	_mainWindow;
	_gameState = MainMenu;


	if (!NorthDoor.loadFromFile("images/Door/North/door.png"))
		return;
	NorthDoorSpr.setTexture(NorthDoor);
	NorthDoorSpr.setPosition(sf::Vector2f(_xSize/2 - 50, _ySize/32));
	// North Door Coordinates = (515 to 565, 22)

	if (!EastDoor.loadFromFile("images/Door/sidedoor.png"))
		return;
	EastDoorSpr.setTexture(EastDoor);
	EastDoorSpr.setTextureRect(sf::IntRect(0, 0, 15, 80));
	EastDoorSpr.setPosition(sf::Vector2f(_xSize - 15, _ySize/2));

	if (!WestDoor.loadFromFile("images/Door/sidedoor.png"))
		return;
	WestDoorSpr.setTexture(WestDoor);
	WestDoorSpr.setTextureRect(sf::IntRect(0, 0, 15, 80));
	WestDoorSpr.setPosition(sf::Vector2f(0, _ySize/2));

	if (!SouthDoor.loadFromFile("images/Door/North/door.png"))
		return;
	SouthDoorSpr.setTexture(SouthDoor);
//	SouthDoorSpr.setTextureRect(sf::IntRect(0, 0, 0, 0));
//	SouthDoorSpr.setPosition(sf::Vector2f(_xSize/2 -50, _ySize));

}


// Destructor
ZeroGameEngine::~ZeroGameEngine(){
	delete Player;
	delete LayoutMaker;
}

// Starts the game
void ZeroGameEngine::Start(){
	// If the game has been Initialized already, return
	if (_gameState != MainMenu)
		return;

	_mainWindow.create(sf::VideoMode(_xSize, _ySize), "The Zeroth Law");
	_gameState = MainMenu;

	while (!isExiting()){
//		 While there is no exit signal, go into the game loop
		GameLoop();
//		break;
	}

	_mainWindow.close();

}

// returns a confirmation that the screen is being closed, or exiting
bool ZeroGameEngine::isExiting(){
	if (_gameState == Exiting)
		return true;
	else
		return false;
}

// The main game loop, called by Start()
void ZeroGameEngine::GameLoop(){
	sf::Event currentEvent;
	sf::Texture Background;

	Background.setRepeated(true);
	sf::Sprite BG;
	while (_mainWindow.pollEvent(currentEvent)){
//		enum GameState {Uninitialized, Paused, MainMenu, Playing, Exiting};
		switch (_gameState){
		case ZeroGameEngine::Uninitialized:
			// Should never be Uninitialized going into the GameLoop
			break;

		case ZeroGameEngine::MainMenu:
			// Display the Main Menu stuff
			if (!Background.loadFromFile("images/titleScreen.png"))
				return;
			BG.setTexture(Background);
			BG.setTextureRect(sf::IntRect(0, 0, _xSize, _ySize));
			_mainWindow.clear(sf::Color::Black);
			_mainWindow.draw(BG);
			_mainWindow.display();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
				_gameState = Exiting;
//				sf::sleep(sf::milliseconds(10));
				break;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
				_gameState = Playing;
//				sf::sleep(sf::milliseconds(10));
				break;
			}

			break;

		case ZeroGameEngine::Playing:
			if (!Background.loadFromFile("images/Backgrounds/Blue_Background-wall.jpg"))
				return;
			BG.setTexture(Background);
			BG.setTextureRect(sf::IntRect(0, 0, _xSize, _ySize));
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
				_gameState = Paused;
				sf::sleep(sf::milliseconds(50));
//				_gameState = Exiting;
				break;
			}
			_mainWindow.clear(sf::Color::Black);
			_mainWindow.draw(BG);
			// Draw other crap here, before display is called
			DrawDoors(current);
			DrawHealthBar();
//			DrawHero();
			DrawHero(Player);
			_mainWindow.display();
			break;


		case ZeroGameEngine::Paused:
			if (!Background.loadFromFile("images/pause.jpg"))
				return;
			BG.setTexture(Background);
			BG.setTextureRect(sf::IntRect(0, 0, _xSize, _ySize));
			_mainWindow.clear();
			_mainWindow.draw(BG);
			_mainWindow.display();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
				_gameState = Exiting;
				sf::sleep(sf::milliseconds(10));
				break;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
				_gameState = Playing;
				sf::sleep(sf::milliseconds(10));
				break;
			}

			break;

		case ZeroGameEngine::Exiting:
			// Exit the game
			if (_gameState==Exiting){
				return;
			}
			break;
		}
		return;
	}
}

// Takes a char direction Does stuff to display the doors
void ZeroGameEngine::DrawDoors(Room* currentRoom){
	if (!current->isAvailable('N')){
		_mainWindow.draw(NorthDoorSpr);
	}
	if (current->isAvailable('E')){
		_mainWindow.draw(EastDoorSpr);
	}
	if (current->isAvailable('W')){
		_mainWindow.draw(WestDoorSpr);
	}
//	if (current->isAvailable('S')){
//		_mainWindow.draw(SouthDoorSpr);
//	}
}

// Updates what is seen in the window
void ZeroGameEngine::UpdateFrame(){
//	_mainWindow.clear();
	for (std::vector<sf::Sprite>::iterator spr = SpriteList.begin(); spr!=SpriteList.end(); spr++){
		; // do stuff here, render the image w/e
	}
//	_mainWindow.display();
}


// For each room, generate objects, monsters, and so forth for each room
void ZeroGameEngine::DrawRoom(Room* current){
//	DrawDoors(current);
}

void ZeroGameEngine::DrawHero(Hero* hero){
	if (!HeroImage.loadFromFile(hero->StandingImage()))
		return;
	HeroSpr.setTexture(HeroImage);
	HeroSpr.setPosition(sf::Vector2f(hero->getX(), hero->getY()));
	_mainWindow.draw(HeroSpr);
}

void ZeroGameEngine::DrawHero() {
	if (!HeroImage.loadFromFile("images/Hero/HeroMovement/BackWalk/HeroWalk_1b.png"))
		return;
	HeroSpr.setTexture(HeroImage);
	HeroSpr.setPosition(sf::Vector2f(_xSize/2, _ySize/2));
	_mainWindow.draw(HeroSpr);
}

// Alters the sprite imaging for HP/MP on the HUD
//void ZeroGameEngine::DrawHealthBar(Hero Player) {
void ZeroGameEngine::DrawHealthBar(){
	// after Hero is ore complete, implement an algorithm to display
	//	based on Hero's current health
//	Full Health Bar is 12 squares
//  Red = Health
//	Green = Shield
	if (!HealthBar.loadFromFile("images/HealthBar/HealthBarContainer.png"))
		return;
	HealthBarSpr.setTexture(HealthBar);
	HealthBarSpr.setPosition(sf::Vector2f(20, 20));
	_mainWindow.draw(HealthBarSpr);
}


