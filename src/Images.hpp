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
	enum UnitType{SM, AIr, AIb, AIg, SPr, SPb, SPg, DEDr, DEDb, DEDg, DED};
	UnitType _unitType;

	Images();
	Images(int xSz, int ySz);
	int notLoaded() const;
	int loadImages();
	void loadSprites();
	sf::Sprite getBG();
	Animation* getWalk(UnitType u, Direction d);
	Animation* getAiAttack(Direction d);
	Animation* getSpawner(UnitType u, Direction d);
	Animation* getDeadAi();


private:
	int NotLoaded = 0;
	int _xSize;
	int _ySize;
								//width x height sheet.. width x height sprite.. #frames
	sf::Texture Background;		//
	sf::Texture SmWalk;
	sf::Texture SmDeath;
	sf::Texture AiDeath, AiWalkBlue, AiWalkGreen, AiWalkRed, AiAttack;
	sf::Texture Spawner, Destroyed;
	sf::Texture HealthBar, EnergyBar, HPBitFirst, HPBit, SPBitFirst, SPBit, EBitFirst, EBit;
	sf::Sprite BG;
//AI
	//Red
	Animation WalkRed_S, WalkRed_N, WalkRed_W, WalkRed_E, WalkRed_NW, WalkRed_NE, WalkRed_SE, WalkRed_SW;
	Animation Attack_S, Attack_N, Attack_W, Attack_E, Attack_NW, Attack_NE, Attack_SE, Attack_SW;
	Animation SpawnRed_N, SpawnRed_E, SpawnRed_W;
	Animation DestroyedRed_N, DestroyedRed_E, DestroyedRed_W;
	//Blue
	Animation WalkBlue_S, WalkBlue_N, WalkBlue_W, WalkBlue_E, WalkBlue_NW, WalkBlue_NE, WalkBlue_SE, WalkBlue_SW;
	Animation SpawnBlue_N, SpawnBlue_E, SpawnBlue_W;
	Animation DestroyedBlue_N, DestroyedBlue_E, DestroyedBlue_W;
	//Green
	Animation WalkGreen_S, WalkGreen_N, WalkGreen_W, WalkGreen_E, WalkGreen_NW, WalkGreen_NE, WalkGreen_SE, WalkGreen_SW;
	Animation SpawnGreen_N, SpawnGreen_E, SpawnGreen_W;

	Animation AiDed;
	Animation DestroyedGreen_N, DestroyedGreen_E, DestroyedGreen_W;
//SM
	Animation WalkDown, WalkUp, WalkLeft, WalkRight;


	sf::Sprite HealthBarSpr, HPBitFirstSpr, HPBitSpr, SPBitFirstSpr, SPBitSpr;
};

#endif // IMAGES_HPP
