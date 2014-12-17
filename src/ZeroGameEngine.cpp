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
	_mainWindow.setFramerateLimit(60);
	_gameState = MainMenu;

	while (!isExiting()){
//		 While there is no exit signal, go into the game loop
		MenuLoop();
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
void ZeroGameEngine::MenuLoop(){
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

			//=====================
			if (currentEvent.type == sf::Event::Closed)
				_gameState = Exiting;
			if (currentEvent.type == sf::Event::KeyPressed && currentEvent.key.code == sf::Keyboard::Escape)
            	_gameState = Exiting;
			if (currentEvent.type == sf::Event::KeyPressed && currentEvent.key.code == sf::Keyboard::Return)
				//State currentState;
				_gameState = Playing;
			//=====================

			break;

		case ZeroGameEngine::Playing:
			//Run GameLoop Here
			GameLoop();

			//State is a struct with Attributes:
				// vector of units
					// units are all enemies and traps, and hero
						// has current hp, attack
				// state of player stats
				// state / level

			break;


		case ZeroGameEngine::Paused:
			if (!Background.loadFromFile("images/pause.jpg"))
				return;
			BG.setTexture(Background);
			BG.setTextureRect(sf::IntRect(0, 0, _xSize, _ySize));
			_mainWindow.clear();
			_mainWindow.draw(BG);
			_mainWindow.display();

			//=====================
			if (currentEvent.type == sf::Event::Closed)
				_gameState = Exiting;
			if (currentEvent.type == sf::Event::KeyPressed && currentEvent.key.code == sf::Keyboard::Escape)
				_gameState = Exiting;
			if (currentEvent.type == sf::Event::KeyPressed && currentEvent.key.code == sf::Keyboard::Return)
				_gameState = Playing;
			//=====================

			break;

		case ZeroGameEngine::Exiting:
			// Exit the game
			//=====================
			_mainWindow.close();
			//=====================
			break;
		}
		return;
	}
}


// main game loop // meat of the program
void ZeroGameEngine::GameLoop()
{

	sf::RectangleShape mouseDrag;

	sf::Texture Background;
	Background.setRepeated(true);
	sf::Sprite BG;
	if (!Background.loadFromFile("images/Backgrounds/Blue_Background-wall.jpg"))
	{
		std::cout << "Failed to load Background!" << std::endl;
		return;
	}
	BG.setTexture(Background);
	BG.setTextureRect(sf::IntRect(0, 0, _xSize, _ySize));


	sf::Vector2i mouseStart, mouseRelease, mouseRight, mouseRightRelease;


	while(_gameState == Playing)
	{
		sf::Event event;
		while (_mainWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_gameState = Exiting;
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				_gameState = Paused;

//===================== MOUSE PRESSES ===========================================

			//========= LEFT CLICKS =============================================
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				mouseStart.x = event.mouseButton.x;
			    mouseStart.y = event.mouseButton.y;
			}

			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			{
				mouseRelease.x = event.mouseButton.x;
				mouseRelease.y = event.mouseButton.y;

				//select all selectable units within area



			    mouseStart.x = 0;
			    mouseStart.y = 0;
			}

            //======== RIGHT CLICKS =============================================
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
			{
				mouseRight.x = event.mouseButton.x;
			    mouseRight.y = event.mouseButton.y;
			}

			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Right)
			{
				mouseRightRelease.x = event.mouseButton.x;
			    mouseRightRelease.y = event.mouseButton.y;
			}

		}//end while pollevent

        sf::Vector2i mouseEnd;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
      	{
        	mouseEnd = sf::Mouse::getPosition(_mainWindow);
        }
        float widthDrag, heightDrag;
        sf::Vector2f origin;
        widthDrag = mouseEnd.x - mouseStart.x;
        heightDrag = mouseEnd.y - mouseStart.y;

		sf::Vector2f size(widthDrag, heightDrag);
		mouseDrag.setSize(size);


		mouseDrag.setPosition(mouseStart.x, mouseStart.y);

		//255 opacity = 100%
		mouseDrag.setFillColor(sf::Color(0,255,255,50));



		_mainWindow.clear();
		_mainWindow.draw(BG); // always first to be drawn

		_mainWindow.draw(mouseDrag); // drawn right before HUD
		DrawHealthBar();
		// draw energy bar

		// draw health over health bar
		// draw energy over energy bar
		_mainWindow.display();
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


