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
	enum UnitType{SM, AIr, AIb, AIg};
	UnitType _unitType;

	Images(int xSz, int ySz);
	int notLoaded() const;
	int loadImages();
	void loadSprites();
	sf::Sprite getBG();
	Animation* getWalk(UnitType u, Direction d);
	Animation* getAiAttack(Direction d);
	Animation* getSpawner(UnitType u, Direction d);


private:
	int NotLoaded = 0;
	int _xSize;
	int _ySize;
								//width x height sheet.. width x height sprite.. #frames
	sf::Texture Background;		//
	sf::Texture SmWalk;			//160x280.. 40x70.. 1x4
	sf::Texture Death;			//1540x85.. 70x85.. 1x22
	sf::Texture AiWalkBlue;		//400x400.. 50x50.. 1x8
	sf::Texture AiWalkGreen;	//400x400.. 50x50.. 1x8
	sf::Texture AiWalkRed; 		//400x400.. 50x50.. 1x8
	sf::Texture AiAttack; 		//300x400.. 50x50.. 1x6
	sf::Texture Spawner; 		//1000x900.. 100x100.. 1x10
	sf::Texture Destroyed;		//3x3.. b/r/g.. top/right/left..

	sf::Sprite BG;
//AI
	//Red
	Animation WalkRed_S, WalkRed_N, WalkRed_W, WalkRed_E, WalkRed_NW, WalkRed_NE, WalkRed_SE, WalkRed_SW;
	Animation Attack_S, Attack_N, Attack_W, Attack_E, Attack_NW, Attack_NE, Attack_SE, Attack_SW;
	Animation SpawnRed_N, SpawnRed_E, SpawnRed_W;
	sf::Sprite DestroyedRed_N, DestroyedRed_E, DestroyedRed_W;
	//Blue
	Animation WalkBlue_S, WalkBlue_N, WalkBlue_W, WalkBlue_E, WalkBlue_NW, WalkBlue_NE, WalkBlue_SE, WalkBlue_SW;
	Animation SpawnBlue_N, SpawnBlue_E, SpawnBlue_W;
	sf::Sprite DestroyedBlue_N, DestroyedBlue_E, DestroyedBlue_W;
	//Green
	Animation WalkGreen_S, WalkGreen_N, WalkGreen_W, WalkGreen_E, WalkGreen_NW, WalkGreen_NE, WalkGreen_SE, WalkGreen_SW;
	Animation SpawnGreen_N, SpawnGreen_E, SpawnGreen_W;
	sf::Sprite DestroyedGreen_N, DestroyedGreen_E, DestroyedGreen_W;
//SM
	Animation WalkDown, WalkUp, WalkLeft, WalkRight;
};

#endif // IMAGES_HPP
