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
ZeroGameEngine::GameState ZeroGameEngine::_gameState = MainMenu;
sf::RenderWindow ZeroGameEngine::_mainWindow;

// Constructor
ZeroGameEngine::ZeroGameEngine(){
	LayoutMaker = new LayoutGen();
	Headroom = LayoutMaker->getHeadRoom();
	current = Headroom;
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

	_mainWindow.create(sf::VideoMode(1080, 720), "The Zeroth Law");
//	_gameState = ZeroGameEngine::MainMenu;

	while (!isExiting()){
		// While there is no exit signal, go into the game loop
		GameLoop();
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
			// Should never reach this point
			// Should never be Uninitialized going into the GameLoop
			break;
		case ZeroGameEngine::MainMenu:
			// Display the mainmenu stuff
			if (!Background.loadFromFile("Images/titleScreen.png"))
				return;
			BG.setTexture(Background);
			BG.setTextureRect(sf::IntRect(0, 0, 1024, 768));
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
					_gameState = Exiting;
//					break;
//			     	std::cout << "Left" << std::endl;
			}
			break;
		case ZeroGameEngine::Playing:
			// Do game stuff hereeeeee
			break;
		case ZeroGameEngine::Paused:
			// Pause the game. What should we display?
			if (!Background.loadFromFile("Images/pause.jpg"))
				return;
			BG.setTexture(Background);
			BG.setTextureRect(sf::IntRect(0, 0, 1024, 768));

			break;
		case ZeroGameEngine::Exiting:
			// Exit the game here?
			return;

		}
		//_mainWindow.update()?
		_mainWindow.clear();
		_mainWindow.draw(BG);
		_mainWindow.display();
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

// Displays the HUD
void ZeroGameEngine::DisplayHUD(){
	// Link the Hero's HP to the bar that will display on the top left?
	//
}

} //namespace ZGE

