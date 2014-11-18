#include <SFML/Graphics.hpp>
#include <iostream>
#include "Unit.hpp"
#include "Animation.hpp"
#include "AnimatedSprite.hpp"
int wWidth(1080), wHeight(720);
float unitVelocity{1.f};

int main()
{
	Unit unit(wWidth/2, wHeight/2);

	sf::RenderWindow window(sf::VideoMode(1080, 720), "Zeroth Law");
    window.setFramerateLimit(60);

    sf::Texture texture;
    if (!texture.loadFromFile("spritesheet.png"))
    {
    	std::cout << "Failed to load player spritesheet!" << std::endl;
    	return 1;
    }

    Animation walkingAnimationDown;
    walkingAnimationDown.setSpriteSheet(texture);
    walkingAnimationDown.addFrame(sf::IntRect(0,0,50,50));
    walkingAnimationDown.addFrame(sf::IntRect(50,0,50,50));
    walkingAnimationDown.addFrame(sf::IntRect(100,0,50,50));
    walkingAnimationDown.addFrame(sf::IntRect(150,0,50,50));
    walkingAnimationDown.addFrame(sf::IntRect(200,0,50,50));
    walkingAnimationDown.addFrame(sf::IntRect(250,0,50,50));
    walkingAnimationDown.addFrame(sf::IntRect(300,0,50,50));
    walkingAnimationDown.addFrame(sf::IntRect(350,0,50,50));

    Animation* currentAnimation = &walkingAnimationDown;
    AnimatedSprite animatedSprite(sf::seconds(0.05), true, false);
    animatedSprite.setPosition(sf::Vector2f(wWidth/ 2, wHeight/2));


    sf::Clock frameClock;

        float speed = 80.f;
        bool noKeyWasPressed = true;

    while (window.isOpen())	//start game loop
    {
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            	window.close();}

        sf::Time frameTime = frameClock.restart();

                // if a key was pressed set the correct animation and move correctly
                sf::Vector2f movement(0.f, 0.f);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                        {
                            currentAnimation = &walkingAnimationDown;
                            movement.y += speed;
                            noKeyWasPressed = false;
                        }

        //=============================================================================
        // get key presses
        // diagonal movement direction must be placed before regular cardinal movement direction
                // nw
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                	unit.velocity.y = -unitVelocity;
                	unit.velocity.x = -unitVelocity;
                }
                // ne
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                	unit.velocity.y = -unitVelocity;
                	unit.velocity.x = unitVelocity;
                }
                // se
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                	unit.velocity.y = unitVelocity;
                	unit.velocity.x = unitVelocity;
                }
                // sw
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                	unit.velocity.y = unitVelocity;
                	unit.velocity.x = -unitVelocity;
                }
                // north
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                	unit.velocity.y = -unitVelocity;
                	unit.velocity.x = 0;
                }
                // south
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                	unit.velocity.y = unitVelocity;
                	unit.velocity.x = 0;
                }
                // west
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                	unit.velocity.y = 0;
                	unit.velocity.x = -unitVelocity;
                }
                // east
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                	unit.velocity.y = 0;
                	unit.velocity.x = unitVelocity;

                }
                else{ unit.velocity.y = 0; unit.velocity.x = 0;}
        // end keypress detections
        //=============================================================================

                animatedSprite.play(*currentAnimation);
                        animatedSprite.move(movement * frameTime.asSeconds());

                        // if no key was pressed stop the animation
                        if (noKeyWasPressed)
                        {
                            animatedSprite.stop();
                        }
                        noKeyWasPressed = true;

                        // update AnimatedSprite
                        animatedSprite.update(frameTime);

                        // draw


        window.clear();
        unit.update();
        window.draw(animatedSprite);
        window.draw(unit.shape);
        window.display();







    }//end game loop

    return 0;
}
