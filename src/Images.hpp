#ifndef IMAGES_HPP
#define IMAGES_HPP

#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "AnimatedSprite.hpp"

class Images
{
public:
	enum Direction{N, E, S, W, NW, NE, SE, SW};
	Direction _dir;
	enum AnimationType{};

	Images();
	int loadImages();
	void loadAnimations();

	sf::Texture getBG();


private:
								//width x height sheet.. width x height sprite.. #frames
	sf::Texture Background;		//
	sf::Texture Death;			//1540x85.. 70x85.. 1x22
	sf::Texture AiWalkBlue;		//400x400.. 50x50.. 1x8
	sf::Texture AiWalkGreen;	//400x400.. 50x50.. 1x8
	sf::Texture AiWalkRed; 		//400x400.. 50x50.. 1x8
	sf::Texture AiAttack; 		//300x400.. 50x50.. 1x6
	sf::Texture Spawner; 		//1000x900.. 100x100.. 1x10
	sf::Texture Destroyed;		//3x3.. b/r/g.. top/right/left..
};

#endif // IMAGES_HPP
