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

	Player = new Hero(1200, 1200, 6, 12, _xSize, _ySize);

	LayoutMaker = new LayoutGen();
	Headroom = LayoutMaker->getHeadRoom();
	current = Headroom;
	_mainWindow;
	_gameState = MainMenu;

	initSprites();
//	setHero('E', Player, animatedHeroSprite);

}


// Destructor
ZeroGameEngine::~ZeroGameEngine(){
	delete currentHeroAnimation;
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

	ptContinue = true;				// Variable just for the cursor on the pause screen to work properly
	tutorialSwitch = false;
	showCredits = false;
	HeroWon = false;

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

////////////////////////////////////////////////////////////////////////////////
///// Sprite Crap Start

void ZeroGameEngine::initSprites(){
// Hero Animation Crap Start

//    HeroWalkUp;
	if (!HeroBackSprSht.loadFromFile("images/Hero/HeroWalkSpriteSht/HeroBackSprSheet.png"))
		return;
    HeroWalkUp.setSpriteSheet(HeroBackSprSht);
    HeroWalkUp.addFrame(sf::IntRect(0, 0, 88, 91));
    HeroWalkUp.addFrame(sf::IntRect(89, 0, 88, 91));
    HeroWalkUp.addFrame(sf::IntRect(0, 92, 88, 91));
    HeroWalkUp.addFrame(sf::IntRect(89, 92, 88, 91));

//    HeroWalkDown;
	if (!HeroForwardSprSht.loadFromFile("images/Hero/HeroWalkSpriteSht/HeroForwardSprSheet.png"))
		return;
    HeroWalkDown.setSpriteSheet(HeroForwardSprSht);
    HeroWalkDown.addFrame(sf::IntRect(0, 0, 88, 91));
    HeroWalkDown.addFrame(sf::IntRect(89, 0, 88, 91));
    HeroWalkDown.addFrame(sf::IntRect(0, 92, 88, 91));
    HeroWalkDown.addFrame(sf::IntRect(89, 92, 88, 91));

//    HeroWalkLeft;
	if (!HeroLeftSprSht.loadFromFile("images/Hero/HeroWalkSpriteSht/HeroLeftSprSheet.png"))
		return;
    HeroWalkLeft.setSpriteSheet(HeroLeftSprSht);
    HeroWalkLeft.addFrame(sf::IntRect(0, 0, 88, 91));
    HeroWalkLeft.addFrame(sf::IntRect(89, 0, 88, 91));
    HeroWalkLeft.addFrame(sf::IntRect(0, 92, 88, 91));
    HeroWalkLeft.addFrame(sf::IntRect(89, 92, 88, 91));


//    HeroWalkRight;
	if (!HeroRightSprSht.loadFromFile("images/Hero/HeroWalkSpriteSht/HeroRightSprSheet.png"))
		return;
    HeroWalkRight.setSpriteSheet(HeroRightSprSht);
    HeroWalkRight.addFrame(sf::IntRect(0, 0, 88, 91));
    HeroWalkRight.addFrame(sf::IntRect(89, 0, 88, 91));
    HeroWalkRight.addFrame(sf::IntRect(0, 92, 88, 91));
    HeroWalkRight.addFrame(sf::IntRect(89, 92, 88, 91));

//    Hero Walk Diagonal Left Back
    if (!HeroLBSprSht.loadFromFile("images/Hero/HeroWalkSpriteSht/HeroDiagonalWalk_LB.png"))
    	return;
    HeroWalkLB.setSpriteSheet(HeroLBSprSht);
    HeroWalkLB.addFrame(sf::IntRect(0, 0, 88, 91));
    HeroWalkLB.addFrame(sf::IntRect(89, 0, 88, 91));
    HeroWalkLB.addFrame(sf::IntRect(0, 92, 88, 91));
    HeroWalkLB.addFrame(sf::IntRect(89, 92, 88, 91));

//    Hero Walk Diagonal Left Forward
    if (!HeroLFSprSht.loadFromFile("images/Hero/HeroWalkSpriteSht/HeroDiagonalWalk_LF.png"))
    	return;
    HeroWalkLF.setSpriteSheet(HeroLFSprSht);
    HeroWalkLF.addFrame(sf::IntRect(0, 0, 88, 91));
    HeroWalkLF.addFrame(sf::IntRect(89, 0, 88, 91));
    HeroWalkLF.addFrame(sf::IntRect(0, 92, 88, 91));
    HeroWalkLF.addFrame(sf::IntRect(89, 92, 88, 91));

//    Hero Walk Diagonal Right Back
    if (!HeroRBSprSht.loadFromFile("images/Hero/HeroWalkSpriteSht/HeroDiagonalWalk_RB.png"))
    	return;
    HeroWalkRB.setSpriteSheet(HeroRBSprSht);
    HeroWalkRB.addFrame(sf::IntRect(0, 0, 88, 91));
    HeroWalkRB.addFrame(sf::IntRect(89, 0, 88, 91));
    HeroWalkRB.addFrame(sf::IntRect(0, 92, 88, 91));
    HeroWalkRB.addFrame(sf::IntRect(89, 92, 88, 91));

//    Hero Walk Diagonal Right Forward
    if (!HeroRFSprSht.loadFromFile("images/Hero/HeroWalkSpriteSht/HeroDiagonalWalk_RF.png"))
    	return;
    HeroWalkRF.setSpriteSheet(HeroRFSprSht);
    HeroWalkRF.addFrame(sf::IntRect(0, 0, 88, 91));
    HeroWalkRF.addFrame(sf::IntRect(89, 0, 88, 91));
    HeroWalkRF.addFrame(sf::IntRect(0, 92, 88, 91));
    HeroWalkRF.addFrame(sf::IntRect(89, 92, 88, 91));


    currentHeroAnimation = &HeroWalkUp;
//    animatedHeroSprite {sf::seconds(0.05), true, false};
    animatedHeroSprite.setPosition(sf::Vector2f(_xSize/2 - 50, _ySize - (_ySize/5)));

    speed = 80.f;
    noKeyWasPressed = true;
    frameTime = frameClock.restart();

// Hero Animation Crap End


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

//	Menu Cursor
	pauseCursor.setPointCount(3);
//	pauseCursor.setFillColor(sf::Color(0, 228, 255));
	pauseCursor.setFillColor(sf::Color(25, 25, 25));
	pauseCursor.setOutlineThickness(3);
	pauseCursor.setOutlineColor(sf::Color(0, 228, 255));

	pauseCursor.setPoint(0, sf::Vector2f(0,0));
	pauseCursor.setPoint(1, sf::Vector2f(20, 20));
	pauseCursor.setPoint(2, sf::Vector2f(0, 40));
//	pauseCursor.setPosition(415, 405);		// On Continue
//	pauseCursor.setPosition(415, 475);		// On Quit

//	Menu Cursor END

//	Music Crap

//	if (!BGM.openFromFile("sounds/music/ANewDevelopment.wav"))
//		return;
//
//	BGM.setLoop(true);

//	Music Crap END

}

/////////////////////////////////////////////////////////////////////////////////////////

void ZeroGameEngine::MenuLoop(){
	/// Init Event var, background
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
			if (!BGM.openFromFile("sounds/music/GadzooksOpening.wav"))
				return;
			BGM.setLoop(true);
			if (BGM.getStatus()!=sf::Music::Playing)
				BGM.play();

			if (!Background.loadFromFile("images/Backgrounds/titleScreen.png"))
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
			if (currentEvent.type == sf::Event::KeyPressed && currentEvent.key.code == sf::Keyboard::Return){
				//State currentState;
				if (tutorialSwitch)
					_gameState = Playing;
				else
					_gameState = Tutorial;
			}
			//=====================

			break;

		case ZeroGameEngine::Playing:
			//Run GameLoop Here
			GameLoop();
			//GameLoop(currentState);

			//State is a struct with Attributes:
				// vector of units
					// units are all enemies and traps, and hero
						// has current hp, attack
				// state of player stats
				// state / level

			break;


		case ZeroGameEngine::Paused:
			if (!Background.loadFromFile("images/Backgrounds/PauseScreen.png"))
				return;
			BG.setTexture(Background);
			BG.setTextureRect(sf::IntRect(0, 0, _xSize, _ySize));

			if (ptContinue)
				pauseCursor.setPosition(415, 405);		// On Continue
			else
				pauseCursor.setPosition(415, 475); 		// On Quit

			_mainWindow.clear();
			_mainWindow.draw(BG);
			_mainWindow.draw(pauseCursor);
			_mainWindow.display();

			//=====================
			if (currentEvent.type == sf::Event::Closed)
				_gameState = Exiting;
			if (currentEvent.type == sf::Event::KeyPressed && currentEvent.key.code == sf::Keyboard::Escape)
				_gameState = Exiting;
			if (currentEvent.type == sf::Event::KeyPressed && currentEvent.key.code == sf::Keyboard::Return){
				if (ptContinue)
					_gameState = Playing;
				else
					_gameState = Exiting;
			}
			if (currentEvent.type == sf::Event::KeyPressed
					&& (currentEvent.key.code == sf::Keyboard::S || currentEvent.key.code == sf::Keyboard::W)){
				if (ptContinue)
					ptContinue = 0;
				else
					ptContinue = 1;
			}
			//=====================
			if (ptContinue)
				pauseCursor.setPosition(415, 405);		// On Continue
			else
				pauseCursor.setPosition(415, 475); 		// On Quit

			_mainWindow.clear();
			_mainWindow.draw(BG);
			_mainWindow.draw(pauseCursor);
			_mainWindow.display();

			break;

		case ZeroGameEngine::GameOver:
			//
			if (showCredits){
				if (!Background.loadFromFile("images/Backgrounds/CreditScreen.png"))
					return;
			} else if (HeroWon){
				if (!Background.loadFromFile("images/Backgrounds/Player1_WinsScreen.png"))
					return;
			} else{
				if (!Background.loadFromFile("images/Backgrounds/ROGUEAI_WINScreen.png"))
					return;
			}
			BG.setTexture(Background);
			BG.setTextureRect(sf::IntRect(0, 0, _xSize, _ySize));
			_mainWindow.clear();
			_mainWindow.draw(BG);
			_mainWindow.display();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
				if (showCredits)
					_gameState = MainMenu;
				else
					showCredits = true;
				break;
			}

			break;

		case ZeroGameEngine::Tutorial:
			// Just do a simple run through the tutorial screens, then go to _gameState = Playing;
			if (!tutorialSwitch){
				if (!Background.loadFromFile("images/Backgrounds/HowToPlayHero.png"))
					return;
			}
			else {
				if (!Background.loadFromFile("images/Backgrounds/RogueAiHowToPlay.png"))
					return;
			}

			if (currentEvent.type == sf::Event::Closed)
				_gameState = Exiting;

			if (currentEvent.type == sf::Event::KeyPressed && currentEvent.key.code == sf::Keyboard::Return){
				if (tutorialSwitch)
					_gameState = Playing;
				else
					tutorialSwitch = true;
			}

			BG.setTexture(Background);
			BG.setTextureRect(sf::IntRect(0, 0, _xSize, _ySize));
			_mainWindow.clear();
			_mainWindow.draw(BG);
			_mainWindow.display();

			break;

		case ZeroGameEngine::Exiting:
			// Exit the game
			//=====================
//			_mainWindow.close();
			return;
			//=====================
			break;
		}
//		return;
	}
}

////////////////////////////////////////////////////////////////////////////////////////
///// END MenuLoop Start GameLoop
/////////////////////////////////////////////////////////////////////////////////////



void ZeroGameEngine::GameLoop(){
	sf::Texture Background;
	// When changing rooms, have it reset

	sf::Sprite BG;
//	Background.setRepeated(true);
	if (!Background.loadFromFile("images/Backgrounds/Blue_Background-wall.jpg"))
		return;
	Background.setRepeated(true);
	BG.setTexture(Background);
	BG.setTextureRect(sf::IntRect(0, 0, _xSize, _ySize));

	if (!BGM.openFromFile("sounds/music/ANewDevelopment.wav"))
		return;
	BGM.setLoop(true);
	if (BGM.getStatus()!=sf::Music::Playing){
		BGM.play();
	}

	while (_gameState == Playing){
		sf::Event currentEvent;
		while (_mainWindow.pollEvent(currentEvent)){
			if (currentEvent.type == sf::Event::Closed){
				_gameState = Exiting;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				_gameState = Paused;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
				_gameState = GameOver;

				ControlHero();			// Logic for controlling Hero
				std::cout << animatedHeroSprite.getPosition().x << " " << animatedHeroSprite.getPosition().y << std::endl << std::endl;
				ControlMouse(currentEvent);
//				_mainWindow.clear(sf::Color::Black);
//				_mainWindow.draw(BG);
//				// Draw other crap here, before display is called
//				DrawDoors(current);
//				DrawHealthBar();
////				DrawHealthBar(Player);
////				DrawHero(Player);
//				_mainWindow.draw(animatedHeroSprite);
//				_mainWindow.display();
		}
		_mainWindow.clear(sf::Color::Black);
		_mainWindow.draw(BG);
		// Draw other crap here, before display is called
		DrawDoors(current);
//		DrawHealthBar();
		DrawHealthBar(Player);
//			DrawHero(Player);
		_mainWindow.draw(animatedHeroSprite);
		_mainWindow.draw(mouseDrag);
		_mainWindow.display();
	}
//	return;
}

// Takes a char direction Does stuff to display the doors
void ZeroGameEngine::DrawDoors(Room* currentRoom){
//	std::cout << current->OccupiedRoomString() << std::endl;
	if (!current->isAvailable('N')){
		_mainWindow.draw(NorthDoorSpr);
	}
//	if (!current->isAvailable('E')){
	if (current->isAvailable('E')){		//testing
		_mainWindow.draw(EastDoorSpr);
	}
//	if (!current->isAvailable('W')){
	if (current->isAvailable('W')){		// testing
		_mainWindow.draw(WestDoorSpr);
	}
//	if (!current->isAvailable('S')){
	if (current->isAvailable('S')){		//testing
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


void ZeroGameEngine::ControlMouse(sf::Event event){
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
}

// For each room, generate objects, monsters, and so forth for each room
void ZeroGameEngine::DrawRoom(Room* current){
//	DrawDoors(current);
}

// Deprecated?? As of implementation of Hero animation sprites
void ZeroGameEngine::DrawHero(Hero* hero){
	if (!HeroImage.loadFromFile(hero->StandingImage()))
		return;
	HeroSpr.setTexture(HeroImage);
	HeroSpr.setPosition(sf::Vector2f(hero->getX(), hero->getY()));
	_mainWindow.draw(HeroSpr);
}

void ZeroGameEngine::ControlHero() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		Player->setDirectionFacing('N');
		HeroMovement.y = -Player->getSpeed();
		HeroMovement.x = -Player->getSpeed();
		currentHeroAnimation = &HeroWalkLB;
//		Player->setVX(-1);
//		Player->setVY(-1);
		noKeyWasPressed = false;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		Player->setDirectionFacing('N');
		HeroMovement.y = -Player->getSpeed();
		HeroMovement.x = Player->getSpeed();
		currentHeroAnimation = &HeroWalkRB;
//		Player->setVX(1);
//		Player->setVY(-1);
		noKeyWasPressed = false;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		Player->setDirectionFacing('S');
		HeroMovement.y = Player->getSpeed();
		HeroMovement.x = -Player->getSpeed();
		currentHeroAnimation = &HeroWalkLF;
//		Player->setVX(-1);
//		Player->setVY(1);
		noKeyWasPressed = false;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		Player->setDirectionFacing('S');
		HeroMovement.y = Player->getSpeed();
		HeroMovement.x = Player->getSpeed();
		currentHeroAnimation = &HeroWalkRF;
//		Player->setVX(1);
//		Player->setVY(1);
		noKeyWasPressed = false;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		Player->setDirectionFacing('N');
		HeroMovement.y = -Player->getSpeed();
		HeroMovement.x = 0;
		currentHeroAnimation = &HeroWalkUp;
//		Player->setVX(0);
//		Player->setVY(-1);
		noKeyWasPressed = false;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		Player->setDirectionFacing('S');
		HeroMovement.y = Player->getSpeed();
		HeroMovement.x = 0;
		currentHeroAnimation = &HeroWalkDown;
//		Player->setVX(0);
//		Player->setVY(1);
		noKeyWasPressed = false;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		Player->setDirectionFacing('W');
		HeroMovement.y = 0;
		HeroMovement.x = -Player->getSpeed();
		currentHeroAnimation = &HeroWalkLeft;
//		Player->setVX(-1);
//		Player->setVY(0);
		noKeyWasPressed = false;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		Player->setDirectionFacing('E');
		HeroMovement.y = 0;
		HeroMovement.x = Player->getSpeed();
		currentHeroAnimation = &HeroWalkRight;
//		Player->setVX(1);
//		Player->setVY(0);
		noKeyWasPressed = false;
	} else{
		HeroMovement.x = 0;
		HeroMovement.y = 0;
//		Player->setVX(0);
//		Player->setVY(0);
	}
	WallLimit(animatedHeroSprite);
//	ApproachDoor();
//	EnterRoom(current, Player);
	std::cout << Player->getX() << "  " << Player->getY() << std::endl << std::endl;
	animatedHeroSprite.play(*currentHeroAnimation);
    animatedHeroSprite.move(HeroMovement * frameTime.asSeconds());

    // if no key was pressed stop the animation
    if (noKeyWasPressed)
    {
        animatedHeroSprite.stop();
    }
    noKeyWasPressed = true;
    // update AnimatedSprite
    animatedHeroSprite.update(frameTime);
    Player->setXY(animatedHeroSprite.getPosition());
}

// Alters the sprite imaging for HP/MP on the HUD
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
	unsigned int maxHP = player->getMaxHP();
	int incrementAmt = 8;
	int placementX = 92;
	if (player->getCurrentHP() > 0){
		HPBitFirstSpr.setPosition(sf::Vector2f(placementX, 28));
		_mainWindow.draw(HPBitFirstSpr);
		for (unsigned int HP = maxHP/12; HP <= player->getCurrentHP(); HP += maxHP/12){
			placementX = placementX + incrementAmt;
			HPBitSpr.setPosition(sf::Vector2f(placementX, 28));
			_mainWindow.draw(HPBitSpr);
		}
	}

	unsigned int maxSP = player->getMaxSP();
	placementX = 92;
	if (player->getCurrentSP() > 0) {
		SPBitFirstSpr.setPosition(sf::Vector2f(placementX, 48));
		_mainWindow.draw(SPBitFirstSpr);
		for (unsigned int SP = maxSP/12; SP <= player->getCurrentSP(); SP += maxSP/12){
			placementX = placementX + incrementAmt;
			SPBitSpr.setPosition(sf::Vector2f(placementX, 48));
			_mainWindow.draw(SPBitSpr);
		}
	}

}

// Should only be called when transition into a different room
void ZeroGameEngine::setHero(char cameFrom, Hero* player, AnimatedSprite& playerSprite) {
	switch (cameFrom){
	case 'N':	// Should have come from S, near S
		player->setDirectionFacing('N');
		player->setXY(sf::Vector2f(_xSize/2 - 50, _ySize - (_ySize/5)));
		playerSprite.setPosition(_xSize/2 - 50, _ySize - (_ySize/5));
		break;
	case 'E':	// Come from the East Door
		player->setDirectionFacing('E');
		player->setXY(sf::Vector2f(984, 352));
		playerSprite.setPosition(984, 352);
		break;
	case 'S': 	// Should have from the North Door
		player->setDirectionFacing('S');
		player->setXY(sf::Vector2f(490, 95));
		playerSprite.setPosition(490, 95);
		break;
	case 'W':	// Come from the West door
		player->setDirectionFacing('W');
		player->setXY(sf::Vector2f(9, 352));
		playerSprite.setPosition(9, 352);
		break;
	}
}

//// Current Implementaion for Hero
//// Implementation for all units, after movements -> check every coord in vector
//void ZeroGameEngine::WallLimit() {
//	if (animatedHeroSprite.getPosition().y<48){
//		animatedHeroSprite.setPosition(animatedHeroSprite.getPosition().x, 48);
//	}
//	else if (animatedHeroSprite.getPosition().y>635){
//		animatedHeroSprite.setPosition(animatedHeroSprite.getPosition().x, 635);
//	}
//	if (animatedHeroSprite.getPosition().x<-20) {
//		animatedHeroSprite.setPosition(-20, animatedHeroSprite.getPosition().y);
//	} else if (animatedHeroSprite.getPosition().x > 1015){
//		animatedHeroSprite.setPosition(1015, animatedHeroSprite.getPosition().y);
//	}
//}
//
//void ZeroGameEngine::ApproachDoor(){
//	// Operates the opening door animation on the North and the South
////	NorthDoorSpr.setPosition(sf::Vector2f(_xSize/2 - 50, _ySize/32));
//	// Currently for North Logic
//	float posX = Player->getX();
//	float posY = Player->getY();
//
//	if (posX > _xSize/2 - 100 && posX < _xSize/2 && posY < _ySize/32 +100)
//		std::cout << "HERO IS NEAR" << std::endl << std::endl;
//}

//void ZeroGameEngine::EnterRoom() {
//	float posX = Player->getX();
//	float posY = Player->getY();
//
//	if (posX > _xSize/2 - 100 && posX < _xSize/2){
//		if (posY < _ySize/32 + 32)
//			std::cout << "Enter NORTH" << std::endl << std::endl;
//		else if (posY > _ySize - 90)
//			std::cout << "Enter SOUTH" << std::endl << std::endl;
//	}
//	if (posY > _ySize/2 - 60 && posY < _ySize/2 + 10 ){
//		if (posX < -10)
//			std::cout << "Enter WEST" << std::endl << std::endl;
//		else if (posX > _xSize - 70)
//			std::cout << "Enter EAST" << std::endl << std::endl;
//	}
//
//}

