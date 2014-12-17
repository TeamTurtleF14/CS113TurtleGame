#include <SFML/Graphics.hpp>
#include "ZeroGameEngine.hpp"
#include <iostream>
#include <cmath>
#include <vector>
#include "Unit.hpp"
#include "Animation.hpp"
#include "AnimatedSprite.hpp"
#include "Images.hpp"
#include "AiUnit.hpp"
#include <algorithm>


int wWidth(1080), wHeight(720);
const double pi = std::acos(-1);

float distance(sf::Vector2f start, sf::Vector2f end){
	return std::sqrt(std::pow(end.y - start.y, 2) + std::pow(end.x - start.x, 2));}
float distance(sf::Vector2i start, sf::Vector2f end){
	return std::sqrt(std::pow(end.y - start.y, 2) + std::pow(end.x - start.x, 2));}
float distance(sf::Vector2f start, sf::Vector2i end){
	return std::sqrt(std::pow(end.y - start.y, 2) + std::pow(end.x - start.x, 2));}
float distance(sf::Vector2i start, sf::Vector2i end){
	return std::sqrt(std::pow(end.y - start.y, 2) + std::pow(end.x - start.x, 2));}

bool collision(sf::Vector2f p1, int r1, sf::Vector2f p2, int r2){
	return distance(p1, p2) < (r1 + r2);}
bool collision(sf::Vector2i p1, int r1, sf::Vector2f p2, int r2){
	return distance(p1, p2) < (r1 + r2);}
bool collision(sf::Vector2f p1, int r1, sf::Vector2i p2, int r2){
	return distance(p1, p2) < (r1 + r2);}
bool collision(sf::Vector2i p1, int r1, sf::Vector2i p2, int r2){
	return distance(p1, p2) < (r1 + r2);}

/*
bool drawFirst(AiUnit a, AiUnit b)
{
	return (a.getPosition().y < b.getPosition().y);
}
*/
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



//if(distance(animatedAi2.getPosition(), mouseStart) < 20 && distance(animatedAi2.getPosition(), mouseRelease) < 20)




/*
bool contains(sf::Vector2f pos)
{
	return left() <= pos.x && right() >= pos.x
			&& top() >= pos.y && bottom() <= pos.y;
}
*/


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

    //loads images and sets animations
    Images img(wWidth, wHeight);
    if (img.notLoaded()){return 1;}

    sf::RectangleShape mouseDrag;
    sf::CircleShape mouseClick;



    //initial animations
    Animation* SmAnimation = img.getWalk(Images::SM,Images::S);
    AnimatedSprite animatedSm(sf::seconds(0.1), true, false);
    animatedSm.setPosition(sf::Vector2f(wWidth/ 2, wHeight/2));
    animatedSm.setOrigin(20.f,50.f);

//================== spawners
    Animation* SpAnimation = img.getSpawner(Images::AIr, Images::N);
    AnimatedSprite animatedSp(sf::seconds(0.1), true, false);
    animatedSp.setPosition(sf::Vector2f(wWidth/ 2, 30));

    Animation* SpAnimationb = img.getSpawner(Images::AIb, Images::E);
    AnimatedSprite animatedSpb(sf::seconds(0.1), true, false);
    animatedSpb.setPosition(sf::Vector2f(wWidth - 100, wHeight/2));

    Animation* SpAnimationg = img.getSpawner(Images::AIg, Images::W);
    AnimatedSprite animatedSpg(sf::seconds(0.1), true, false);
    animatedSpg.setPosition(sf::Vector2f(0, wHeight/2));




    std::vector<AiUnit*> aiUnits;
    std::vector<AiUnit*>::iterator it;
    AiUnit Ai(wWidth/3, wHeight/3, Images::AIr, img.getWalk(Images::AIr, Images::S));
    AiUnit Ai2(wWidth/2, wHeight/3, Images::AIb, img.getWalk(Images::AIb, Images::S));
    AiUnit Ai3(wWidth/3, wHeight/2, Images::AIg, img.getWalk(Images::AIg, Images::S));
    aiUnits.push_back(&Ai);
    aiUnits.push_back(&Ai2);
    aiUnits.push_back(&Ai3);

    //add to class
    bool noKeyWasPressed = true;
    bool notSpawning = true;
    bool notSpawningb = true;
    bool notSpawningg = true;
    int spawntime = 0;

    //first click, left release, first right click, right release
	sf::Vector2i mouseStart, mouseRelease, mouseRight, mouseRightRelease;

    sf::Clock frameClock;

    float speed = 90.f;


    while (window.isOpen())	//start game loop
    {

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

            	if(distance(animatedSpg.getPosition(), mouseStart) < 50 && distance(animatedSpg.getPosition(), mouseRelease) < 50)
         	 	{
            		SpAnimationg = img.getSpawner(Images::AIg, Images::W);
         	 		notSpawningg = false;
         	 	}
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

		mouseDrag.setSize(drags(window, mouseStart));
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

//===================== END MOUSE PRESSES =======================================


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
    	SpAnimation = img.getSpawner(Images::AIr, Images::N);
 	 	notSpawning = false;
 	 	SpAnimationb = img.getSpawner(Images::AIb, Images::E);
 	 	notSpawningb = false;

    }

//================= KEY PRESSES =================================================

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
//================= END KEY PRESSES =============================================




//================= PLAY ANIMATIONS =============================================
		for(std::vector<AiUnit*>::size_type i = 0; i != aiUnits.size(); i++)
		{
			aiUnits[i]->setFrameTime(frameTime);
			aiUnits[i]->play();
			aiUnits[i]->update();
		}
//==================spawners///////////////////
		animatedSp.play(*SpAnimation);
		if(notSpawning)
		{
			animatedSp.stop();
		}
		notSpawning = true;
		animatedSp.update(frameTime);

		animatedSpb.play(*SpAnimationb);
		if(notSpawningb)
		{
			animatedSpb.stop();
		}
		notSpawningb = true;
		animatedSpb.update(frameTime);

		animatedSpg.play(*SpAnimationg);
		if(notSpawningg)
		{
			animatedSpg.stop();
		}
		notSpawningg = true;
		animatedSpg.update(frameTime);
//==================================================//////////////////////////
		animatedSm.play(*SmAnimation);
		animatedSm.move(SmMovement * frameTime.asSeconds());
        if (noKeyWasPressed)
        {
        	animatedSm.stop();
        }
        noKeyWasPressed = true;
        animatedSm.update(frameTime);



//================== DISPLAY ====================================================
        window.clear();
        window.draw(img.getBG());
        window.draw(mouseClick);
        //spawners////////////////
        window.draw(animatedSp);
        window.draw(animatedSpb);
        window.draw(animatedSpg);
        /////////////////////////////
        window.draw(animatedSm);
        for(std::vector<AiUnit*>::size_type i = 0; i != aiUnits.size(); i++)
        {
        	window.draw(aiUnits[i]->getAiSprite());
        }

        //Drawing order
        //1) 	BG
        //2)	Doors
        //3)	Units :: Traps, Enemies, Hero
       // 	a)	unit vector
       // 	b)	depends on y-value of unit..
       // 	c)	sort by y-value lowest values first..
       // 4)	Mouse select
       // 5)	HUD (i.e. Hero Life, Ai Energy)



        window.draw(mouseDrag);
        window.display();







    }//end game loop

    return 0;
}

