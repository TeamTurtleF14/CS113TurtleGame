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

	Player = new Hero(1000, 0, _xSize, _ySize);

	LayoutMaker = new LayoutGen();
	Headroom = LayoutMaker->getHeadRoom();
	current = Headroom;
	_mainWindow;
	_gameState = MainMenu;

	initSprites();

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

////////////////////////////////////////////////////////////////////////////////
///// Sprite Crap Start

void ZeroGameEngine::initSprites(){
// Health Bar sprite crap, Health and Shield
	if (!HealthBar.loadFromFile("images/HealthBar/HealthBarContainer.png"))
		return;
	HealthBarSpr.setTexture(HealthBar);
	HealthBarSpr.setPosition(sf::Vector2f(20, 20));

	if (!HPBitFirst.loadFromFile("images/HealthBar/FirstRedHealthBarPiece.png"))
		return;
	HPBitFirstSpr.setTexture(HPBitFirst);

	if (!HPBit.loadFromFile("images/HealthBar/RestOfRedHealthBarPieces.png"))
		return;
	HPBitSpr.setTexture(HPBit);

	if (!SPBitFirst.loadFromFile("images/HealthBar/FirstGreenHealthBarPiece.png"))
		return;
	SPBitFirstSpr.setTexture(SPBitFirst);

	if (!SPBit.loadFromFile("images/HealthBar/RestofGreenHealthBarPieces.png"))
		return;
	SPBitSpr.setTexture(SPBit);

	// Reusing the bit sprites, set the positiion as you draw



// Health bar sprite crap end

// Door Sprite
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
	SouthDoorSpr.setPosition(sf::Vector2f(_xSize/2 -50, _ySize - 20));
// Door sprite crap end

}

/////////////////////////////////////////////////////////////////////////////////////////

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
//			DrawHealthBar(Player);
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
	std::cout << current->OccupiedRoomString() << std::endl;
	if (!current->isAvailable('N')){
		_mainWindow.draw(NorthDoorSpr);
	}
	if (!current->isAvailable('E')){
//	if (current->isAvailable('E')){		//testing
		_mainWindow.draw(EastDoorSpr);
	}
	if (!current->isAvailable('W')){
//	if (current->isAvailable('W')){		// testing
		_mainWindow.draw(WestDoorSpr);
	}
	if (!current->isAvailable('S')){
//	if (current->isAvailable('S')){		//testing
		_mainWindow.draw(SouthDoorSpr);
	}
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
	_mainWindow.draw(HealthBarSpr);
	HPBitFirstSpr.setPosition(sf::Vector2f(92, 28));
	_mainWindow.draw(HPBitFirstSpr);
	int incrementAmt = 8;
	int placementX = 92;
	for (unsigned int HP = 0; HP < 12; HP++){
		placementX = placementX + incrementAmt;
		HPBitSpr.setPosition(sf::Vector2f(placementX, 28));
		_mainWindow.draw(HPBitSpr);
	}

	placementX = 92;
	SPBitFirstSpr.setPosition(sf::Vector2f(placementX, 48));
	_mainWindow.draw(SPBitFirstSpr);
	for (int SP = 0; SP < 12; SP++){
		placementX = placementX + incrementAmt;
		SPBitSpr.setPosition(sf::Vector2f(placementX, 48));
		_mainWindow.draw(SPBitSpr);
	}
}

void ZeroGameEngine::DrawHealthBar(Hero* player){
// after Hero is more complete, implement an algorithm to display based on Hero's current health
//	Full Health Bar is 12 squares Red = Health Green = Shield
	// First Draw the Health Bar
	_mainWindow.draw(HealthBarSpr);

// Then Analyze Hero's health to display the bits that show on the Health Bar
//  The single pieces are about 8 bits long, going X direction, 92 is startX, 28 startY
	int currentHP = player->getCurrentHP();
	int incrementAmt = 8;
	int placementX = 92;
	if (currentHP > 0){
		HPBitFirstSpr.setPosition(sf::Vector2f(placementX, 28));
		_mainWindow.draw(HPBitFirstSpr);
		for (int HP = currentHP/12; HP <= currentHP; HP += currentHP/12){
			placementX = placementX + incrementAmt;
			HPBitSpr.setPosition(sf::Vector2f(placementX, 28));
			_mainWindow.draw(HPBitSpr);
		}
	}

	int currentSP = player->getCurrentSP();
	placementX = 92;
	if (currentSP > 0) {
		SPBitFirstSpr.setPosition(sf::Vector2f(placementX, 28));
		_mainWindow.draw(SPBitFirstSpr);
		for (int HP = currentHP/12; HP <= currentHP; HP += currentHP/12){
			placementX = placementX + incrementAmt;
			SPBitSpr.setPosition(sf::Vector2f(placementX, 28));
			_mainWindow.draw(SPBitSpr);
		}
	}

}


