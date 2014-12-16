#include "Images.hpp"

Images::Images()
{
}

int Images::loadImages()
{
	Background.setRepeated(true);
	if (!Background.loadFromFile("Images/Backgrounds/Blue_Background-wall.jpg"))
	{
		std::cout << "Failed to load Background!" << std::endl;
	    return 1;
	}

	if (!AiWalkRed.loadFromFile("NewImages/AiWalk Red spritesheet.png"))
	{
		std::cout << "Failed to load spritesheet!" << std::endl;
	    return 1;
	}

	if (!AiWalkBlue.loadFromFile("NewImages/AiWalk Blue spritesheet.png"))
	{
		std::cout << "Failed to load spritesheet!" << std::endl;
	    return 1;
	}

	if (!AiWalkGreen.loadFromFile("NewImages/AiWalk Green spritesheet.png"))
	{
		std::cout << "Failed to load spritesheet!" << std::endl;
	    return 1;
	}

	if (!AiAttack.loadFromFile("NewImages/AiAttack spritesheet.png"))
	{
		std::cout << "Failed to load spritesheet!" << std::endl;
	    return 1;
	}


	return 0;
}
/*
void Images::loadAnimations()
{
	Animation WalkRed_S;
	WalkRed_S.setSpriteSheet(AiWalkRed);
	for(int i = 0; i < 8; i++)
	{
		WalkRed_S.addFrame(sf::IntRect(i*50, 0, 50, 50));
	}
	WalkRed_S.getSpriteSheet(AiWalkRed);
	Animation* currentAnimation = &WalkRed_S;

	Animation WalkRed_N;
	WalkRed_N.setSpriteSheet(AiWalkRed);
	for(int i = 0; i < 8; i++)
	{
		WalkRed_N.addFrame(sf::IntRect(i*50, 50, 50, 50));
	}
	Animation WalkRed_W;
	WalkRed_W.setSpriteSheet(AiWalkRed);
	for(int i = 0; i < 8; i++)
	{
		WalkRed_W.addFrame(sf::IntRect(i*50, 100, 50, 50));
	}
	Animation WalkRed_E;
	WalkRed_E.setSpriteSheet(AiWalkRed);
	for(int i = 0; i < 8; i++)
	{
		WalkRed_E.addFrame(sf::IntRect(i*50, 150, 50, 50));
	}
	Animation WalkRed_NW;
	WalkRed_NW.setSpriteSheet(AiWalkRed);
	for(int i = 0; i < 8; i++)
	{
		WalkRed_NW.addFrame(sf::IntRect(i*50, 200, 50, 50));
	}

	Animation WalkRed_NE;
	WalkRed_NE.setSpriteSheet(AiWalkRed);
	for(int i = 0; i < 8; i++)
	{
		WalkRed_NE.addFrame(sf::IntRect(i*50, 250, 50, 50));
	}

	Animation WalkSE;
	WalkRed_SE.setSpriteSheet(AiWalkRed);
	for(int i = 0; i < 8; i++)
	{
		WalkRed_SE.addFrame(sf::IntRect(i*50, 300, 50, 50));
	}

	Animation WalkRed_SW;
	WalkRed_SW.setSpriteSheet(AiWalkRed);
	for(int i = 0; i < 8; i++)
	{
		WalkRed_SW.addFrame(sf::IntRect(i*50, 350, 50, 50));
	}

}
*/


sf::Texture Images::getBG()
{
	return Background;
}
