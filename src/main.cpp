#include <SFML/Graphics.hpp>
#include "ZeroGameEngine.hpp"
#include <iostream>
#include "Unit.hpp"
#include "Animation.hpp"
#include "AnimatedSprite.hpp"
#include <cmath>

int wWidth(1080), wHeight(720);
const double pi = std::acos(-1);

/*
int main(){
	ZeroGameEngine* game = new ZeroGameEngine();
	game->Start();
	delete game;
}
*/

//================= Thomas's Main w/ tests

int main()
{
	sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "Zeroth Law");
    window.setFramerateLimit(60);

    sf::Texture Background;
    Background.setRepeated(true);
    sf::Sprite BG;
    if (!Background.loadFromFile("Images/Backgrounds/Blue_Background-wall.jpg"))
    {
    	std::cout << "Failed to load Background!" << std::endl;
    	return 1;
    }
    BG.setTexture(Background);
    BG.setTextureRect(sf::IntRect(0, 0, wWidth, wHeight));

    sf::RectangleShape mouseDrag;
    sf::CircleShape mouseClick;

    sf::Texture AiSprite;
    if (!AiSprite.loadFromFile("AiWalk spritesheet.png"))
    {
    	std::cout << "Failed to load spritesheet!" << std::endl;
    	return 1;
    }

    sf::Texture SmSprite;
    if (!SmSprite.loadFromFile("HeroWalk spritesheet.png"))
    {
    	std::cout << "Failed to load spritesheet!" << std::endl;
        return 1;
    }

    Animation WalkDown;
    WalkDown.setSpriteSheet(SmSprite);
    for(int i = 0; i < 4; i++)
    {
    	WalkDown.addFrame(sf::IntRect(i*40, 70, 40, 70));
    }
    WalkDown.getSpriteSheet();
    Animation* currentAnimation2 = &WalkDown;

    Animation WalkUp;
    WalkUp.setSpriteSheet(SmSprite);
    for(int i = 0; i < 4; i++)
    {
    	WalkUp.addFrame(sf::IntRect(i*40, 0, 40, 70));
    }
    WalkUp.getSpriteSheet();

    Animation WalkLeft;
    WalkLeft.setSpriteSheet(SmSprite);
    for(int i = 0; i < 4; i++)
    {
    	WalkLeft.addFrame(sf::IntRect(i*40, 140, 40, 70));
    }
    WalkLeft.getSpriteSheet();

    Animation WalkRight;
    WalkRight.setSpriteSheet(SmSprite);
    for(int i = 0; i < 4; i++)
    {
        	WalkRight.addFrame(sf::IntRect(i*40, 210, 40, 70));
    }
    WalkRight.getSpriteSheet();


    AnimatedSprite animatedSm(sf::seconds(0.1), true, false);
    animatedSm.setPosition(sf::Vector2f(wWidth/ 2, wHeight/2));
    animatedSm.setOrigin(20.f,35.f);




//======== Setup arrays of textures =============================================
    Animation WalkSouth;
    WalkSouth.setSpriteSheet(AiSprite);
    for(int i = 0; i < 8; i++)
    {
    	WalkSouth.addFrame(sf::IntRect(i*50, 0, 50, 50));
    }
    WalkSouth.getSpriteSheet();
    Animation* currentAnimation = &WalkSouth;

    Animation WalkNorth;
    WalkNorth.setSpriteSheet(AiSprite);
    for(int i = 0; i < 8; i++)
    {
    	WalkNorth.addFrame(sf::IntRect(i*50, 50, 50, 50));
    }
    //WalkNorth.getSpriteSheet();

    Animation WalkWest;
    WalkWest.setSpriteSheet(AiSprite);
    for(int i = 0; i < 8; i++)
    {
    	WalkWest.addFrame(sf::IntRect(i*50, 100, 50, 50));
    }
    //WalkWest.getSpriteSheet();

    Animation WalkEast;
    WalkEast.setSpriteSheet(AiSprite);
    for(int i = 0; i < 8; i++)
    {
        	WalkEast.addFrame(sf::IntRect(i*50, 150, 50, 50));
    }
    //WalkEast.getSpriteSheet();

    Animation WalkNW;
    WalkNW.setSpriteSheet(AiSprite);
    for(int i = 0; i < 8; i++)
    {
        	WalkNW.addFrame(sf::IntRect(i*50, 200, 50, 50));
    }
    //WalkNW.getSpriteSheet();

    Animation WalkNE;
    WalkNE.setSpriteSheet(AiSprite);
    for(int i = 0; i < 8; i++)
    {
    	WalkNE.addFrame(sf::IntRect(i*50, 250, 50, 50));
    }
    //WalkNE.getSpriteSheet();

    Animation WalkSE;
    WalkSE.setSpriteSheet(AiSprite);
    for(int i = 0; i < 8; i++)
        {
            	WalkSE.addFrame(sf::IntRect(i*50, 300, 50, 50));
        }
    //WalkSE.getSpriteSheet();

    Animation WalkSW;
    WalkSW.setSpriteSheet(AiSprite);
    for(int i = 0; i < 8; i++)
    {
    	WalkSW.addFrame(sf::IntRect(i*50, 350, 50, 50));
    }
    WalkSW.getSpriteSheet();

    // initialize frame speed
    AnimatedSprite animatedAi(sf::seconds(0.05), true, false);
    // set initial position
    animatedAi.setPosition(sf::Vector2f(wWidth/ 2, wHeight/2));
    // set center/origin of frame
    animatedAi.setOrigin(25.f,25.f);
//===============================================================================


    //first click, left release, first right click, right release
	sf::Vector2i mouseStart, mouseRelease, mouseRight, mouseRightRelease;


    sf::Clock frameClock;

    float speed = 80.f;
    bool noKeyWasPressed = true;
    bool robotMoving = true;

    while (window.isOpen())	//start game loop
    {
        sf::Vector2f AiMovement(0.f, 0.f);
        sf::Vector2f SmMovement(0.f, 0.f);
        sf::Time frameTime = frameClock.restart();

    	sf::Event event;
        while (window.pollEvent(event))
        {
        	//======= CLOSE WINDOW ==============================================
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            	window.close();
            //======= END CLOSE WINDOW ==========================================

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
        }

        //============= LEFT CLICKED / DRAGS ====================================

        sf::Vector2i mouseEnd;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
      	{
        	mouseEnd = sf::Mouse::getPosition(window);
        }
        float widthDrag, heightDrag;
        sf::Vector2f origin;
        widthDrag = mouseEnd.x - mouseStart.x;
        heightDrag = mouseEnd.y - mouseStart.y;

		sf::Vector2f size(widthDrag, heightDrag);
		mouseDrag.setSize(size);



		mouseDrag.setPosition(mouseStart.x, mouseStart.y);

		//255 opacity = 100%
		mouseDrag.setFillColor(sf::Color(0,255,255,20));

		mouseClick.setOrigin(10, 10);
    	mouseClick.setRadius(10);
    	mouseClick.setPosition(mouseRightRelease.x, mouseRightRelease.y);
    	//mouseClick.setFillColor(sf::Color(255,0,0,200));


	//make enemy chase after mouse click
        float angle = pi + std::atan((mouseRightRelease.y - animatedAi.getPosition().y)
        						/(mouseRightRelease.x - animatedAi.getPosition().x));


        float distance = std::sqrt(std::pow(mouseRightRelease.x - animatedAi.getPosition().x, 2) + std::pow(mouseRightRelease.y - animatedAi.getPosition().y, 2));
        if ( distance > mouseClick.getRadius())
        {
        			if(mouseRightRelease.x > animatedAi.getPosition().x)
        			{
        				if(mouseRightRelease.y > animatedAi.getPosition().y)
        				{
        					currentAnimation = &WalkSE;
        					AiMovement.x -= std::cos(angle) * speed;
        					AiMovement.y -= std::sin(angle) * speed;
        					robotMoving = false;
        				}
        				else
        				{
        					currentAnimation = &WalkNE;
        					AiMovement.x -= std::cos(angle) * speed;
        					AiMovement.y -= std::sin(angle) * speed;
        					robotMoving = false;
        				}
        			}
        			else
        			{
        				if(mouseRightRelease.y > animatedAi.getPosition().y)
        				{
        					currentAnimation = &WalkSW;
        					AiMovement.x += std::cos(angle) * speed;
        					AiMovement.y += std::sin(angle) * speed;
        					robotMoving = false;
        				}
        				else
        				{
        					currentAnimation = &WalkNW;
        					AiMovement.x += std::cos(angle) * speed;
        					AiMovement.y += std::sin(angle) * speed;
        					robotMoving = false;
        				}
        			}
        }
        else
        {
        	robotMoving = true;
  			AiMovement.x = 0;
        	AiMovement.y = 0;
        }

//===================== END MOUSE PRESSES =======================================




//================= KEY PRESSES =================================================

    //============= NORTHWEST ===================================================
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
			&& sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			currentAnimation2 = &WalkLeft;
			SmMovement.x = std::cos(5*pi/4) * speed;
			SmMovement.y = std::sin(5*pi/4) * speed;
			noKeyWasPressed = false;
		}

	//============= NORTHEAST ===================================================
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
			&& sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			currentAnimation2 = &WalkRight;
			SmMovement.x = std::cos(7*pi/4) * speed;
			SmMovement.y = std::sin(7*pi/4) * speed;
			noKeyWasPressed = false;
		}

	//============= SOUTHEAST ===================================================
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
			&& sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			currentAnimation2 = &WalkRight;
			SmMovement.x = std::cos(pi/4) * speed;
			SmMovement.y = std::sin(pi/4) * speed;
			noKeyWasPressed = false;
		}

	//============= SOUTHWEST ===================================================
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
			&& sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			currentAnimation2 = &WalkLeft;
			SmMovement.x = std::cos(3*pi/4) * speed;
			SmMovement.y = std::sin(3*pi/4) * speed;
			noKeyWasPressed = false;
		}

	//============= SOUTH =======================================================
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
			&& !sf::Keyboard::isKeyPressed(sf::Keyboard::W)
			&& !sf::Keyboard::isKeyPressed(sf::Keyboard::A)
			&& !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			currentAnimation2 = &WalkDown;
			SmMovement.x = std::cos(pi/2) * speed;
			SmMovement.y = std::sin(pi/2) * speed;
			noKeyWasPressed = false;
		}

	//============= NORTH =======================================================
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
			&& !sf::Keyboard::isKeyPressed(sf::Keyboard::S)
			&& !sf::Keyboard::isKeyPressed(sf::Keyboard::A)
			&& !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			currentAnimation2 = &WalkUp;
			SmMovement.x = std::cos(3*pi/2) * speed;
			SmMovement.y = std::sin(3*pi/2) * speed;
			noKeyWasPressed = false;
		}

	//============= WEST ========================================================
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
			&& !sf::Keyboard::isKeyPressed(sf::Keyboard::W)
			&& !sf::Keyboard::isKeyPressed(sf::Keyboard::S)
			&& !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			currentAnimation2 = &WalkLeft;
			SmMovement.x = std::cos(pi) * speed;
			SmMovement.y = std::sin(pi) * speed;
			noKeyWasPressed = false;
		}

	//============= EAST ========================================================
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
			&& !sf::Keyboard::isKeyPressed(sf::Keyboard::W)
			&& !sf::Keyboard::isKeyPressed(sf::Keyboard::S)
			&& !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			currentAnimation2 = &WalkRight;
			SmMovement.x = std::cos(2*pi) * speed;
			SmMovement.y = std::sin(2*pi) * speed;
			noKeyWasPressed = false;
		}

//================= END KEY PRESSES =============================================




//================= PLAY ANIMATIONS =============================================
		animatedAi.play(*currentAnimation);
		animatedAi.move(AiMovement * frameTime.asSeconds());
		animatedSm.play(*currentAnimation2);
		animatedSm.move(SmMovement * frameTime.asSeconds());

        // if no key was pressed stop the animation
        if (noKeyWasPressed)
        {
        	animatedSm.stop();
        }
        noKeyWasPressed = true;


        if (robotMoving)
        {
        	animatedAi.stop();
        }
        robotMoving = true;
//================== PERFORM UPDATES ============================================
        //update AnimatedSprite
        animatedAi.update(frameTime);
        animatedSm.update(frameTime);


//================== DISPLAY ====================================================
        window.clear();
        window.draw(BG);
        //window.draw(mouseClick);
        window.draw(animatedSm);
        window.draw(animatedAi);

        /*//Drawing order
        1) 	BG
        2)	Doors
        3)	Units :: Traps, Enemies, Hero
        	a)	unit vector
        	b)	depends on y-value of unit..
        	c)	sort by y-value lowest values first..
        4)	Mouse select
        5)	HUD (i.e. Hero Life, Ai Energy)
		*/


        window.draw(mouseDrag);
        window.display();







    }//end game loop

    return 0;
}
