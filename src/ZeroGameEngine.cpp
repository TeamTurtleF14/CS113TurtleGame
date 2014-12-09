/*
 * ZeroGameEngine.cpp
 *
 *  Created on: Nov 29, 2014
 *      Author: Tony
 */

#include "ZeroGameEngine.hpp"


namespace ZGE
{

//ZeroGameEngine::GameState ZeroGameEngine::_gameState = Uninitialized;
//ZeroGameEngine::GameState ZGE::_gameState = MainMenu;
////sf::RenderWindow _mainWindow;

// Constructor
ZeroGameEngine::ZeroGameEngine(){
	LayoutMaker = new LayoutGen();
	Headroom = LayoutMaker->getHeadRoom();
	current = Headroom;
	_mainWindow;
	_gameState = MainMenu;
}


// Destructor
ZeroGameEngine::~ZeroGameEngine(){
	delete LayoutMaker;
}

// Starts the game
void ZeroGameEngine::Start(){
	// If the game has been Initialized already, return
	if (_gameState != MainMenu)
		return;
//	_gameState = Paused;

	_mainWindow.create(sf::VideoMode(1080, 720), "The Zeroth Law");
	_gameState = MainMenu;

//	if (_gameState == MainMenu)
//		std::cout << "MainMenu" << std::endl;
//	if (_gameState == Playing)
//		std::cout << "Playing" << std::endl;
//	if (_gameState == Paused)
//		std::cout << "Paused" << std::endl;

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
			BG.setTextureRect(sf::IntRect(0, 0, 1080, 720));
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
				_gameState = Exiting;
				break;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
				_gameState = Playing;
				break;
			}
			_mainWindow.clear();
			_mainWindow.draw(BG);
			_mainWindow.display();
			break;

		case ZeroGameEngine::Playing:
			if (!Background.loadFromFile("images/Backgrounds/Blue_Background-wall.jpg"))
				return;
			BG.setTexture(Background);
			BG.setTextureRect(sf::IntRect(0, 0, 1080, 720));
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
				_gameState = Paused;
//				_gameState = Exiting;
				break;
			}
			_mainWindow.clear();
			_mainWindow.draw(BG);
			_mainWindow.display();
			break;

		case ZeroGameEngine::Paused:
			if (!Background.loadFromFile("images/pause.jpg"))
				return;
			BG.setTexture(Background);
			BG.setTextureRect(sf::IntRect(0, 0, 1024, 768));
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
				_gameState = Exiting;
				break;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
				_gameState = Playing;
				break;
			}
			_mainWindow.clear();
			_mainWindow.draw(BG);
			_mainWindow.display();
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
void ZeroGameEngine::DisplayDoors(char Direction){

}

// Updates what is seen in the window
void ZeroGameEngine::UpdateFrame(){
	_mainWindow.clear();
	for (std::vector<sf::Sprite>::iterator spr = SpriteList.begin(); spr!=SpriteList.end(); spr++){
		; // do stuff here, render the image w/e
	}
	_mainWindow.display();
}


// For each room, generate objects, monsters, and so forth for each room
void ZeroGameEngine::DisplayRoom(Room* current){

}

// Alters the sprite imaging for HP/MP on the HUD
void ZeroGameEngine::DisplayHUD(){
	// Link the Hero's HP to the bar that will display on the top left?

}


} ///// namespace ZGE

