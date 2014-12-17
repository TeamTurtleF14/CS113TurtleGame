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
const double pi = std::acos(-1);

sf::Vector2f drags(const sf::Window& window, sf::Vector2i mouseStart)
{
	sf::Vector2i mouseEnd;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		mouseEnd = sf::Mouse::getPosition(window);
	}
	float widthDrag, heightDrag;
	widthDrag = mouseEnd.x - mouseStart.x;
	heightDrag = mouseEnd.y - mouseStart.y;

	sf::Vector2f size(widthDrag, heightDrag);
	return size;
}
float distance(sf::Vector2f start, sf::Vector2i end){
	return std::sqrt(std::pow(end.y - start.y, 2) + std::pow(end.x - start.x, 2));}

// main game loop // meat of the program
void ZeroGameEngine::GameLoop()
{
    Images img(_xSize, _ySize);
    if (img.notLoaded()){return;}

    sf::RectangleShape mouseDrag;
    sf::CircleShape mouseClick;

    Animation* SmAnimation = img.getWalk(Images::SM,Images::S);
    AnimatedSprite animatedSm(sf::seconds(0.1), true, false);
    animatedSm.setPosition(sf::Vector2f(_xSize/ 2, _ySize/2));
    animatedSm.setOrigin(20.f,50.f);


    std::vector<AiUnit*> aiUnits;

    bool noKeyWasPressed = true;

	sf::Vector2i mouseStart, mouseRelease, mouseRight, mouseRightRelease;

    sf::Clock frameClock;
    float speed = 90.f;
    while (_mainWindow.isOpen())	//start game loop
       {

           sf::Vector2f SmMovement(0.f, 0.f);

           sf::Time frameTime = frameClock.restart();

       	sf::Event event;
           while (_mainWindow.pollEvent(event))
           {
           	//======= CLOSE WINDOW ==============================================
               if (event.type == sf::Event::Closed)
                   _mainWindow.close();

               if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
               	_mainWindow.close();

               //========== MOUSE PRESSES ===========================================

               if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
               {
               	mouseStart.x = event.mouseButton.x;
               	mouseStart.y = event.mouseButton.y;
               }

               if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
               {
               	mouseRelease.x = event.mouseButton.x;
               	mouseRelease.y = event.mouseButton.y;

   //==================================== loop through to check if in box ======================================
               	for(std::vector<AiUnit*>::size_type i = 0; i != aiUnits.size(); i++){
               		if(aiUnits[i]->getPosition().y > mouseRelease.y && aiUnits[i]->getPosition().y < mouseStart.y){
               			if(aiUnits[i]->getPosition().x > mouseRelease.x && aiUnits[i]->getPosition().x < mouseStart.x){
               				if(!aiUnits[i]->isActive()){
   								aiUnits[i]->activate();}
   							else{
   								aiUnits[i]->setVelocity(0,0);
   								aiUnits[i]->activate();}
               			}
               		}

               		if(aiUnits[i]->getPosition().y < mouseRelease.y && aiUnits[i]->getPosition().y > mouseStart.y){
               			if(aiUnits[i]->getPosition().x > mouseRelease.x && aiUnits[i]->getPosition().x < mouseStart.x){
               				if(!aiUnits[i]->isActive()){
   								aiUnits[i]->activate();}
   							else{
   								aiUnits[i]->setVelocity(0,0);
   								aiUnits[i]->activate();}
               			}
               		}
               		if(aiUnits[i]->getPosition().y > mouseRelease.y && aiUnits[i]->getPosition().y < mouseStart.y){
               			if(aiUnits[i]->getPosition().x < mouseRelease.x && aiUnits[i]->getPosition().x > mouseStart.x){
               				if(!aiUnits[i]->isActive()){
   								aiUnits[i]->activate();}
   							else{
   								aiUnits[i]->setVelocity(0,0);
   								aiUnits[i]->activate();}
               			}
               		}

               		if(aiUnits[i]->getPosition().y < mouseRelease.y && aiUnits[i]->getPosition().y > mouseStart.y){
               			if(aiUnits[i]->getPosition().x < mouseRelease.x && aiUnits[i]->getPosition().x > mouseStart.x){
               				if(!aiUnits[i]->isActive()){
   								aiUnits[i]->activate();}
   							else{
   								aiUnits[i]->setVelocity(0,0);
   								aiUnits[i]->activate();}
               			}
               		}

               		if(distance(aiUnits[i]->getPosition(), mouseStart) < 20 && distance(aiUnits[i]->getPosition(), mouseRelease) < 20){
   						if(!aiUnits[i]->isActive()){
   							aiUnits[i]->activate();}
   						else{
   							aiUnits[i]->setVelocity(0,0);
   							aiUnits[i]->activate();}
   					}
               	}

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


           }

           //============= LEFT DRAGS =============================================

   		mouseDrag.setSize(drags(_mainWindow, mouseStart));
   		mouseDrag.setPosition(mouseStart.x, mouseStart.y);
   		mouseDrag.setFillColor(sf::Color(0,255,255,50)); //255 opacity = 100%

   		//============== END LEFT DRAG ==============================================

   		//============== RIGHT CLICK ================================================
   		if(aiUnits.size() <= 7){
   			mouseClick.setRadius(50);
   			mouseClick.setOrigin(10, 10);
   			mouseClick.setFillColor(sf::Color(255,0,0,50));

   		}
       	mouseClick.setPosition(mouseRightRelease.x, mouseRightRelease.y); //mouseClick.setFillColor(sf::Color(255,0,0,200));


       	float shortest_d = 1080;
       	for(std::vector<AiUnit>::size_type i = 0; i != aiUnits.size(); i++)
       	{

       	}


   		for(std::vector<AiUnit>::size_type i = 0; i != aiUnits.size(); i++)
   		{
   			if(aiUnits[i]->isActive())
   			{
   				aiUnits[i]->Move(mouseRightRelease, mouseClick, img.getWalk(aiUnits[i]->getType(), aiUnits[i]->getDir()));
   			}
   			else
   			{
   				aiUnits[i]->DetectSm(animatedSm, aiUnits, img.getWalk(aiUnits[i]->getType(), aiUnits[i]->getDir()), img.getAiAttack(aiUnits[i]->getDir()));
   			}
   		}





       //============= NORTHWEST ===================================================
   		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
   			&& sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
   			SmAnimation = img.getWalk(Images::SM,Images::NW);
   			SmMovement.x = std::cos(5*pi/4) * speed;
   			SmMovement.y = std::sin(5*pi/4) * speed;
   			noKeyWasPressed = false;}
   	//============= NORTHEAST ===================================================
   		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
   			&& sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
   			SmAnimation = img.getWalk(Images::SM,Images::NE);
   			SmMovement.x = std::cos(7*pi/4) * speed;
   			SmMovement.y = std::sin(7*pi/4) * speed;
   			noKeyWasPressed = false;}
   	//============= SOUTHEAST ===================================================
   		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
   			&& sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
   			SmAnimation = img.getWalk(Images::SM,Images::SE);
   			SmMovement.x = std::cos(pi/4) * speed;
   			SmMovement.y = std::sin(pi/4) * speed;
   			noKeyWasPressed = false;}
   	//============= SOUTHWEST ===================================================
   		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
   			&& sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
   			SmAnimation = img.getWalk(Images::SM,Images::SW);
   			SmMovement.x = std::cos(3*pi/4) * speed;
   			SmMovement.y = std::sin(3*pi/4) * speed;
   			noKeyWasPressed = false;}
   	//============= SOUTH =======================================================
   		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
   			&& !sf::Keyboard::isKeyPressed(sf::Keyboard::W)
   			&& !sf::Keyboard::isKeyPressed(sf::Keyboard::A)
   			&& !sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
   			SmAnimation = img.getWalk(Images::SM,Images::S);
   			SmMovement.x = std::cos(pi/2) * speed;
   			SmMovement.y = std::sin(pi/2) * speed;
   			noKeyWasPressed = false;}
   	//============= NORTH =======================================================
   		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
   			&& !sf::Keyboard::isKeyPressed(sf::Keyboard::S)
   			&& !sf::Keyboard::isKeyPressed(sf::Keyboard::A)
   			&& !sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
   			SmAnimation = img.getWalk(Images::SM,Images::N);
   			SmMovement.x = std::cos(3*pi/2) * speed;
   			SmMovement.y = std::sin(3*pi/2) * speed;
   			noKeyWasPressed = false;}
   	//============= WEST ========================================================
   		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
   			&& !sf::Keyboard::isKeyPressed(sf::Keyboard::W)
   			&& !sf::Keyboard::isKeyPressed(sf::Keyboard::S)
   			&& !sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
   			SmAnimation = img.getWalk(Images::SM,Images::W);
   			SmMovement.x = std::cos(pi) * speed;
   			SmMovement.y = std::sin(pi) * speed;
   			noKeyWasPressed = false;}
   	//============= EAST ========================================================
   		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
   			&& !sf::Keyboard::isKeyPressed(sf::Keyboard::W)
   			&& !sf::Keyboard::isKeyPressed(sf::Keyboard::S)
   			&& !sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
   			SmAnimation = img.getWalk(Images::SM,Images::E);
   			SmMovement.x = std::cos(2*pi) * speed;
   			SmMovement.y = std::sin(2*pi) * speed;
   			noKeyWasPressed = false;}





   		for(std::vector<AiUnit*>::size_type i = 0; i != aiUnits.size(); i++)
   		{
   			aiUnits[i]->setFrameTime(frameTime);
   			aiUnits[i]->play();
   			aiUnits[i]->update();
   		}


   		animatedSm.play(*SmAnimation);
   		animatedSm.move(SmMovement * frameTime.asSeconds());
           if (noKeyWasPressed)
           {
           	animatedSm.stop();
           }
           noKeyWasPressed = true;
           animatedSm.update(frameTime);






   //================== DISPLAY ====================================================
           _mainWindow.clear();
           _mainWindow.draw(img.getBG());
           _mainWindow.draw(mouseClick);
           _mainWindow.draw(animatedSm);
           for(std::vector<AiUnit*>::size_type i = 0; i != aiUnits.size(); i++)
           {
           	_mainWindow.draw(aiUnits[i]->getAiSprite());
           }
            // always first to be drawn

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


