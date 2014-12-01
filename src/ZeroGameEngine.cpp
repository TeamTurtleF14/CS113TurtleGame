/*
 * ZeroGameEngine.cpp
 *
 *  Created on: Nov 29, 2014
 *      Author: Tony
 */

#include "ZeroGameEngine.hpp"


namespace ZGE
{

ZeroGameEngine::GameState ZeroGameEngine::_gameState = Uninitialized;
sf::RenderWindow ZeroGameEngine::_mainWindow;

// Constructor
ZeroGameEngine::ZeroGameEngine(){
	LayoutMaker = new LayoutGen();
	Headroom = LayoutMaker->getHeadRoom();
}


// Destructor
ZeroGameEngine::~ZeroGameEngine(){
	delete LayoutMaker;
}

// Starts the game
void ZeroGameEngine::Start(){
	// If the game has been Initialized already, return
	if (_gameState != Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(1080, 720), "The Zeroth Law");
	_gameState = ZeroGameEngine::Playing;

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
	while (_mainWindow.pollEvent(currentEvent)){

	}
}

// Updates what is seen in the window
void ZeroGameEngine::UpdateFrame(){

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

