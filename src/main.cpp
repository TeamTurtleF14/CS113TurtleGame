#include <SFML/Graphics.hpp>
#include "ZeroGameEngine.hpp"
#include <iostream>
#include <cmath>
#include "Unit.hpp"
#include "Animation.hpp"
#include "AnimatedSprite.hpp"
#include "Images.hpp"


int wWidth(1080), wHeight(720);
const double pi = std::acos(-1);

//DISTANCE
float distance(sf::Vector2f start, sf::Vector2f end){
	return std::sqrt(std::pow(end.x - start.x, 2) + std::pow(end.y - start.y, 2));}
float distance(sf::Vector2f start, sf::Vector2i end){
	return std::sqrt(std::pow(end.x - start.x, 2) + std::pow(end.y - start.y, 2));}
float distance(sf::Vector2i start, sf::Vector2i end){
	return std::sqrt(std::pow(end.x - start.x, 2) + std::pow(end.y - start.y, 2));}
float distance(sf::Vector2i start, sf::Vector2f end){
	return std::sqrt(std::pow(end.x - start.x, 2) + std::pow(end.y - start.y, 2));}

//ANGLE
float angle(sf::Vector2f start, sf::Vector2f end){
	return std::atan((end.y - start.y)/(end.x - start.x));}
float angle(sf::Vector2f start, sf::Vector2i end){
	return std::atan((end.y - start.y)/(end.x - start.x));}
float angle(sf::Vector2i start, sf::Vector2f end){
	return std::atan((end.y - start.y)/(end.x - start.x));}
float angle(sf::Vector2i start, sf::Vector2i end){
	return std::atan((end.y - start.y)/(end.x - start.x));}

bool collision(sf::Vector2f p1, int r1, sf::Vector2f p2, int r2){
	return distance(p1, p2) < (r1 + r2);}
bool collision(sf::Vector2i p1, int r1, sf::Vector2f p2, int r2){
	return distance(p1, p2) < (r1 + r2);}
bool collision(sf::Vector2f p1, int r1, sf::Vector2i p2, int r2){
	return distance(p1, p2) < (r1 + r2);}
bool collision(sf::Vector2i p1, int r1, sf::Vector2i p2, int r2){
	return distance(p1, p2) < (r1 + r2);}


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
    Animation* SpAnimation = img.getSpawner(Images::AIr,Images::N);
    AnimatedSprite animatedSp(sf::seconds(0.1), true, false);
    animatedSp.setPosition(sf::Vector2f(wWidth-90, 35));
    animatedSp.setOrigin(0,0);

    Animation* SmAnimation = img.getWalk(Images::SM,Images::S);
    AnimatedSprite animatedSm(sf::seconds(0.1), true, false);
    animatedSm.setPosition(sf::Vector2f(wWidth/ 2, wHeight/2));
    animatedSm.setOrigin(20.f,35.f);

    //add to class
    Animation* AiAnimation2 = img.getWalk(Images::AIb, Images::S);
    Images::Direction dir2 = Images::S;
    AnimatedSprite animatedAi2(sf::seconds(0.05), true, false);
    animatedAi2.setPosition(sf::Vector2f(wWidth/ 3, wHeight/3));
    animatedAi2.setOrigin(25.f,25.f);

    Animation* AiAnimation = img.getWalk(Images::AIr, Images::S);
    Images::Direction dir = Images::S;
    AnimatedSprite animatedAi(sf::seconds(0.05), true, false);
    animatedAi.setPosition(sf::Vector2f(wWidth/ 2, wHeight/2));
    animatedAi.setOrigin(25.f,25.f);

    //add to class
    bool noKeyWasPressed = true;
    bool robotMoving = true;
    bool robotMoving2 = true;
    bool spawning = true;

    sf::Vector2f target = animatedAi.getPosition();
    sf::Vector2f target2 = animatedAi2.getPosition();
    //first click, left release, first right click, right release
	sf::Vector2i mouseStart, mouseRelease, mouseRight, mouseRightRelease;

    sf::Clock frameClock;

    float speed = 80.f;


//add to class
    bool is_clicked  = false;
    bool is_clicked2  = false;

    while (window.isOpen())	//start game loop
    {

        sf::Vector2f SmMovement(0.f, 0.f);
        sf::Vector2f AiMovement(0.f, 0.f);
        sf::Vector2f AiMovement2(0.f, 0.f);

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


            	if(animatedAi2.getPosition().y < mouseRelease.y && animatedAi2.getPosition().y > mouseRelease.y ){
            		//for(units in unitVector) if (unit.
            	}
            	//for(units in unitVector) if(unit.contains(mouseStart) && unit.contains(mouseRelease)

            	if(distance(animatedAi2.getPosition(), mouseStart) < 20 && distance(animatedAi2.getPosition(), mouseRelease) < 20){
            		if(is_clicked2)
            			is_clicked2 = false;
            		else
            			is_clicked2 = true;
            	}
            	//else
            	//{   is_clicked2 = false; mouseRelease.x = animatedAi2.getPosition().x; mouseRelease.y = animatedAi2.getPosition().y;}

            	if(distance(animatedAi.getPosition(), mouseStart) < 20 && distance(animatedAi.getPosition(), mouseRelease) < 20){
            		if(is_clicked)
            			is_clicked = false;
            		else
            			is_clicked = true;
            	}
            	//else
            	//{   is_clicked = false; mouseRelease.x = animatedAi.getPosition().x; mouseRelease.y = animatedAi.getPosition().y;}


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
		mouseDrag.setFillColor(sf::Color(0,255,255,20)); //255 opacity = 100%

		//============== END LEFT DRAG ==============================================

		//============== RIGHT CLICK ================================================
		mouseClick.setOrigin(10, 10);
    	mouseClick.setRadius(10);
    	mouseClick.setPosition(mouseRightRelease.x, mouseRightRelease.y); //mouseClick.setFillColor(sf::Color(255,0,0,200));


	//make enemy chase after mouse click
    //add to ai class
    if(is_clicked)
    {
    	target.x = mouseRightRelease.x;
    	target.y = mouseRightRelease.y;
        float a = angle(animatedAi.getPosition(), target);
        float d = distance(animatedAi.getPosition(), target);


        if (d > mouseClick.getRadius())
        {
        			if(target.x > animatedAi.getPosition().x)
        			{
        				if(target.y > animatedAi.getPosition().y)
        				{
        					if(a < (pi/8)){
        						AiAnimation = img.getWalk(Images::AIr, Images::E);
        						dir = Images::E;}
        					else if(a < (3*pi/8)){
        						AiAnimation = img.getWalk(Images::AIr, Images::SE);
        						dir = Images::SE;}
        					else{
        						AiAnimation = img.getWalk(Images::AIr, Images::S);
        						dir = Images::S;}
        					AiMovement.x = std::cos(a) * speed;
        					AiMovement.y = std::sin(a) * speed;
        					robotMoving = false;
        				}
        				else
        				{
        					a += 2*pi;
        					if(a > (15*pi/8)){
        						AiAnimation = img.getWalk(Images::AIr, Images::E);
        						dir = Images::E;}
        					else if(a > (13*pi/8)){
        						AiAnimation = img.getWalk(Images::AIr, Images::NE);
        						dir = Images::NE;}
        					else{
        						AiAnimation = img.getWalk(Images::AIr, Images::N);
        						dir = Images::N;}

        					AiMovement.x = std::cos(a) * speed;
        					AiMovement.y = std::sin(a) * speed;
        					robotMoving = false;
        				}
        			}
        			else
        			{
        				a += pi;
        				if(mouseRightRelease.y > animatedAi.getPosition().y)
        				{
        					if(a > (7*pi/8)){
								AiAnimation = img.getWalk(Images::AIr, Images::W);
								dir = Images::W;}
							else if(a > (5*pi/8)){
								AiAnimation = img.getWalk(Images::AIr, Images::SW);
								dir = Images::SW;}
							else{
								AiAnimation = img.getWalk(Images::AIr, Images::S);
        						dir = Images::S;}
        					AiMovement.x = std::cos(a) * speed;
        					AiMovement.y = std::sin(a) * speed;
        					robotMoving = false;
        				}
        				else
        				{
        					if(a < (9*pi/8)){
								AiAnimation = img.getWalk(Images::AIr, Images::W);
								dir = Images::W;}
							else if(a < (11*pi/8)){
								AiAnimation = img.getWalk(Images::AIr, Images::NW);
								dir = Images::NW;}
							else{
								AiAnimation = img.getWalk(Images::AIr, Images::N);
        						dir = Images::N;}
							AiMovement.x = std::cos(a) * speed;
        					AiMovement.y = std::sin(a) * speed;
        					robotMoving = false;
        				}
        			}
        }
        else
        {
        	robotMoving = true;
  			AiMovement.x = 0;
        	AiMovement.y = 0;
        	target = animatedAi.getPosition();
        }
    }

    if(is_clicked2)
    {
    	target2.x = mouseRightRelease.x;
    	target2.y = mouseRightRelease.y;
        float a2 = angle(animatedAi2.getPosition(), target2);
        float d2 = distance(animatedAi2.getPosition(), target2);


        if (d2 > mouseClick.getRadius())
        {
        			if(target2.x > animatedAi2.getPosition().x)
        			{
        				if(target2.y > animatedAi2.getPosition().y)
        				{
        					if(a2 < (pi/8)){
        						AiAnimation2 = img.getWalk(Images::AIb, Images::E);
        						dir2 = Images::E;}
        					else if(a2 < (3*pi/8)){
        						AiAnimation2 = img.getWalk(Images::AIb, Images::SE);
        						dir2 = Images::SE;}
        					else{
        						AiAnimation2 = img.getWalk(Images::AIb, Images::S);
        						dir2 = Images::S;}
        					AiMovement2.x = std::cos(a2) * speed;
        					AiMovement2.y = std::sin(a2) * speed;
        					robotMoving2 = false;
        				}
        				else
        				{
        					a2 += 2*pi;
        					if(a2 > (15*pi/8)){
        						AiAnimation2 = img.getWalk(Images::AIb, Images::E);
        						dir2 = Images::E;}
        					else if(a2 > (13*pi/8)){
        						AiAnimation2 = img.getWalk(Images::AIb, Images::NE);
        						dir2 = Images::NE;}
        					else{
        						AiAnimation2 = img.getWalk(Images::AIb, Images::N);
        						dir2 = Images::N;}

        					AiMovement2.x = std::cos(a2) * speed;
        					AiMovement2.y = std::sin(a2) * speed;
        					robotMoving2 = false;
        				}
        			}
        			else
        			{
        				a2 += pi;
        				if(mouseRightRelease.y > animatedAi2.getPosition().y)
        				{
        					if(a2 > (7*pi/8)){
								AiAnimation2 = img.getWalk(Images::AIb, Images::W);
								dir2 = Images::W;}
							else if(a2 > (5*pi/8)){
								AiAnimation2 = img.getWalk(Images::AIb, Images::SW);
								dir2 = Images::SW;}
							else{
								AiAnimation2 = img.getWalk(Images::AIb, Images::S);
        						dir2 = Images::S;}
        					AiMovement2.x = std::cos(a2) * speed;
        					AiMovement2.y = std::sin(a2) * speed;
        					robotMoving2 = false;
        				}
        				else
        				{
        					if(a2 < (9*pi/8)){
								AiAnimation2 = img.getWalk(Images::AIb, Images::W);
								dir2 = Images::W;}
							else if(a2 < (11*pi/8)){
								AiAnimation2 = img.getWalk(Images::AIb, Images::NW);
								dir2 = Images::NW;}
							else{
								AiAnimation2 = img.getWalk(Images::AIb, Images::N);
        						dir2 = Images::N;}
							AiMovement2.x = std::cos(a2) * speed;
        					AiMovement2.y = std::sin(a2) * speed;
        					robotMoving2 = false;
        				}
        			}
        }
        else
        {
        	robotMoving2 = true;
  			AiMovement2.x = 0;
        	AiMovement2.y = 0;
        	target2 = animatedAi2.getPosition();
        }
    }
//===================== END MOUSE PRESSES =======================================


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
    	AiAnimation = img.getAiAttack(dir);
    	robotMoving = false;
		AiMovement.x = 0;
    	AiMovement.y = 0;
    	target = animatedAi.getPosition();
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
		// add to class
		animatedAi.play(*AiAnimation);
		animatedAi.move(AiMovement * frameTime.asSeconds());

		animatedAi2.play(*AiAnimation2);
		animatedAi2.move(AiMovement2 * frameTime.asSeconds());

		animatedSm.play(*SmAnimation);
		animatedSm.move(SmMovement * frameTime.asSeconds());

		animatedSp.play(*SpAnimation);

        // if no key was pressed stop the animation
        if (noKeyWasPressed)
        {
        	animatedSm.stop();
        }
        noKeyWasPressed = true;

//add to class
        if (robotMoving)
        {
        	animatedAi.stop();
        }
        robotMoving = true;

        if (robotMoving2)
        {
        	animatedAi2.stop();
        }
        robotMoving2 = true;


        if (spawning)
        {
        	animatedSp.stop();
        }
        spawning = true;
//================== PERFORM UPDATES ============================================
        //update AnimatedSprite
        //add to class
        animatedAi.update(frameTime);
        animatedAi2.update(frameTime);
        animatedSm.update(frameTime);
        animatedSp.update(frameTime);


//================== DISPLAY ====================================================
        window.clear();
        window.draw(img.getBG());
        window.draw(animatedSp);
        window.draw(animatedSm);
        window.draw(animatedAi);
        window.draw(animatedAi2);

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

