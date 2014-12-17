#include "Images.hpp"


Images::Images()
{
	NotLoaded = loadImages();
	std::cout << NotLoaded << std::endl;
	loadSprites();
}

Images::Images(int xSz, int ySz)
	: _xSize{xSz}, _ySize{ySz}
{
	NotLoaded = loadImages();
	std::cout << NotLoaded << std::endl;
	loadSprites();
}

int Images::notLoaded() const
{
	return NotLoaded;
}

int Images::loadImages()
{
	Background.setRepeated(true);
	if (!Background.loadFromFile("Images/Backgrounds/Blue_Background-wall.jpg"))
	{
		std::cout << "Failed to load Background!" << std::endl;
	    return 1;
	}

	if (!SmWalk.loadFromFile("NewImages/HeroWalk spritesheet.png"))
	{
		std::cout << "Failed to load sprite sheet!" << std::endl;
		return 1;
	}

	if (!AiWalkRed.loadFromFile("NewImages/AiWalk Red spritesheet.png"))
	{
		std::cout << "Failed to load sprite sheet!" << std::endl;
	    return 1;
	}

	if (!AiWalkBlue.loadFromFile("NewImages/AiWalk Blue spritesheet.png"))
	{
		std::cout << "Failed to load sprite sheet!" << std::endl;
	    return 1;
	}

	if (!AiWalkGreen.loadFromFile("NewImages/AiWalk Green spritesheet.png"))
	{
		std::cout << "Failed to load sprite sheet!" << std::endl;
	    return 1;
	}

	if (!AiAttack.loadFromFile("NewImages/AiAttack spritesheet.png"))
	{
		std::cout << "Failed to load sprite sheet!" << std::endl;
	    return 1;
	}

	if (!Spawner.loadFromFile("NewImages/full spawner spritesheet.png"))
	{
		std::cout << "Failed to load sprite sheet!" << std::endl;
		return 1;
	}

	if (!Destroyed.loadFromFile("NewImages/destroyed spawner sprites.png"))
	{
		std::cout << "Failed to load sprite sheet!" << std::endl;
		return 1;
	}

	if (!HealthBar.loadFromFile("NewImages/BlueHealthBar.png"))
		return 1;

	if (!EnergyBar.loadFromFile("NewImages/Energy Container.png"))
		return 1;

	if (!HPBitFirst.loadFromFile("NewImages/FirstRedHealthBarPiece.png"))
		return 1;

	if (!HPBit.loadFromFile("NewImages/RestOfRedHealthBarPieces.png"))
		return 1;

	if (!SPBitFirst.loadFromFile("NewImages/FirstBlueHealthBarPiece.png"))
		return 1;

	if (!SPBit.loadFromFile("NewImages/RestOfBlueHealthPiece.png"))
		return 1;

	if (!EBitFirst.loadFromFile("NewImages/FirstGreenHealthBarPiece.png"))
			return 1;

	if (!EBit.loadFromFile("NewImages/RestOfGreenHealthBarPieces.png"))
			return 1;

	return 0;
}

void Images::loadSprites()
{

	BG.setTexture(Background); BG.setTextureRect(sf::IntRect(0,0,_xSize,_ySize));

//===Red Ai ===========================================================================
	WalkRed_S.setSpriteSheet(AiWalkRed);
	for(int i = 0; i < 8; i++){
		WalkRed_S.addFrame(sf::IntRect(i*50, 0, 50, 50));}

	WalkRed_N.setSpriteSheet(AiWalkRed);
	for(int i = 0; i < 8; i++){
		WalkRed_N.addFrame(sf::IntRect(i*50, 50, 50, 50));}

	WalkRed_W.setSpriteSheet(AiWalkRed);
	for(int i = 0; i < 8; i++){
		WalkRed_W.addFrame(sf::IntRect(i*50, 100, 50, 50));}

	WalkRed_E.setSpriteSheet(AiWalkRed);
	for(int i = 0; i < 8; i++){
		WalkRed_E.addFrame(sf::IntRect(i*50, 150, 50, 50));}

	WalkRed_NW.setSpriteSheet(AiWalkRed);
	for(int i = 0; i < 8; i++){
		WalkRed_NW.addFrame(sf::IntRect(i*50, 200, 50, 50));}

	WalkRed_NE.setSpriteSheet(AiWalkRed);
	for(int i = 0; i < 8; i++){
		WalkRed_NE.addFrame(sf::IntRect(i*50, 250, 50, 50));}

	WalkRed_SE.setSpriteSheet(AiWalkRed);
	for(int i = 0; i < 8; i++){
		WalkRed_SE.addFrame(sf::IntRect(i*50, 300, 50, 50));}

	WalkRed_SW.setSpriteSheet(AiWalkRed);
	for(int i = 0; i < 8; i++){
		WalkRed_SW.addFrame(sf::IntRect(i*50, 350, 50, 50));}



//===Blue Ai ==========================================================================
	WalkBlue_S.setSpriteSheet(AiWalkBlue);
	for(int i = 0; i < 8; i++){
		WalkBlue_S.addFrame(sf::IntRect(i*50, 0, 50, 50));}

	WalkBlue_N.setSpriteSheet(AiWalkBlue);
	for(int i = 0; i < 8; i++){
		WalkBlue_N.addFrame(sf::IntRect(i*50, 50, 50, 50));}

	WalkBlue_W.setSpriteSheet(AiWalkBlue);
	for(int i = 0; i < 8; i++){
		WalkBlue_W.addFrame(sf::IntRect(i*50, 100, 50, 50));}

	WalkBlue_E.setSpriteSheet(AiWalkBlue);
	for(int i = 0; i < 8; i++){
		WalkBlue_E.addFrame(sf::IntRect(i*50, 150, 50, 50));}

	WalkBlue_NW.setSpriteSheet(AiWalkBlue);
	for(int i = 0; i < 8; i++){
		WalkBlue_NW.addFrame(sf::IntRect(i*50, 200, 50, 50));}

	WalkBlue_NE.setSpriteSheet(AiWalkBlue);
	for(int i = 0; i < 8; i++){
		WalkBlue_NE.addFrame(sf::IntRect(i*50, 250, 50, 50));}

	WalkBlue_SE.setSpriteSheet(AiWalkBlue);
	for(int i = 0; i < 8; i++){
		WalkBlue_SE.addFrame(sf::IntRect(i*50, 300, 50, 50));}

	WalkBlue_SW.setSpriteSheet(AiWalkBlue);
	for(int i = 0; i < 8; i++){
		WalkBlue_SW.addFrame(sf::IntRect(i*50, 350, 50, 50));}



//===Green Ai =========================================================================
	WalkGreen_S.setSpriteSheet(AiWalkGreen);
	for(int i = 0; i < 8; i++){
		WalkGreen_S.addFrame(sf::IntRect(i*50, 0, 50, 50));}

	WalkGreen_N.setSpriteSheet(AiWalkGreen);
	for(int i = 0; i < 8; i++){
		WalkGreen_N.addFrame(sf::IntRect(i*50, 50, 50, 50));}

	WalkGreen_W.setSpriteSheet(AiWalkGreen);
	for(int i = 0; i < 8; i++){
		WalkGreen_W.addFrame(sf::IntRect(i*50, 100, 50, 50));}

	WalkGreen_E.setSpriteSheet(AiWalkGreen);
	for(int i = 0; i < 8; i++){
		WalkGreen_E.addFrame(sf::IntRect(i*50, 150, 50, 50));}

	WalkGreen_NW.setSpriteSheet(AiWalkGreen);
	for(int i = 0; i < 8; i++){
		WalkGreen_NW.addFrame(sf::IntRect(i*50, 200, 50, 50));}

	WalkGreen_NE.setSpriteSheet(AiWalkGreen);
	for(int i = 0; i < 8; i++){
		WalkGreen_NE.addFrame(sf::IntRect(i*50, 250, 50, 50));}

	WalkGreen_SE.setSpriteSheet(AiWalkGreen);
	for(int i = 0; i < 8; i++){
		WalkGreen_SE.addFrame(sf::IntRect(i*50, 300, 50, 50));}

	WalkGreen_SW.setSpriteSheet(AiWalkGreen);
	for(int i = 0; i < 8; i++){
		WalkGreen_SW.addFrame(sf::IntRect(i*50, 350, 50, 50));}


//===Red Attacks ======================================================================
		Attack_S.setSpriteSheet(AiAttack);
		for(int i = 0; i < 6; i++){
			Attack_S.addFrame(sf::IntRect(i*50, 0, 50, 50));}

		Attack_N.setSpriteSheet(AiAttack);
		for(int i = 0; i < 6; i++){
			Attack_N.addFrame(sf::IntRect(i*50, 50, 50, 50));}

		Attack_E.setSpriteSheet(AiAttack);
		for(int i = 0; i < 6; i++){
			Attack_E.addFrame(sf::IntRect(i*50, 100, 50, 50));}

		Attack_W.setSpriteSheet(AiAttack);
		for(int i = 0; i < 6; i++){
			Attack_W.addFrame(sf::IntRect(i*50, 150, 50, 50));}

		Attack_NW.setSpriteSheet(AiAttack);
		for(int i = 0; i < 6; i++){
			Attack_NW.addFrame(sf::IntRect(i*50, 200, 50, 50));}

		Attack_NE.setSpriteSheet(AiAttack);
		for(int i = 0; i < 6; i++){
			Attack_NE.addFrame(sf::IntRect(i*50, 250, 50, 50));}

		Attack_SE.setSpriteSheet(AiAttack);
		for(int i = 0; i < 6; i++){
			Attack_SE.addFrame(sf::IntRect(i*50, 300, 50, 50));}

		Attack_SW.setSpriteSheet(AiAttack);
		for(int i = 0; i < 6; i++){
			Attack_SW.addFrame(sf::IntRect(i*50, 350, 50, 50));}



//===Spawners =========================================================================
//===blue
	SpawnBlue_N.setSpriteSheet(Spawner);
	for(int i = 0; i < 10; i++){
		SpawnBlue_N.addFrame(sf::IntRect(i*100, 0, 100, 100));}
	SpawnBlue_E.setSpriteSheet(Spawner);
	for(int i = 0; i < 10; i++){
		SpawnBlue_E.addFrame(sf::IntRect(i*100, 100, 100, 100));}
	SpawnBlue_W.setSpriteSheet(Spawner);
	for(int i = 0; i < 10; i++){
		SpawnBlue_W.addFrame(sf::IntRect(i*100, 200, 100, 100));}
//===red
	SpawnRed_N.setSpriteSheet(Spawner);
	for(int i = 0; i < 10; i++){
		SpawnRed_N.addFrame(sf::IntRect(i*100, 300, 100, 100));}
	SpawnRed_E.setSpriteSheet(Spawner);
	for(int i = 0; i < 10; i++){
		SpawnRed_E.addFrame(sf::IntRect(i*100, 400, 100, 100));}
	SpawnRed_W.setSpriteSheet(Spawner);
	for(int i = 0; i < 10; i++){
		SpawnRed_W.addFrame(sf::IntRect(i*100, 500, 100, 100));}
//===green
	SpawnGreen_N.setSpriteSheet(Spawner);
	for(int i = 0; i < 10; i++){
		SpawnGreen_N.addFrame(sf::IntRect(i*100, 600, 100, 100));}
	SpawnGreen_E.setSpriteSheet(Spawner);
	for(int i = 0; i < 10; i++){
		SpawnGreen_E.addFrame(sf::IntRect(i*100, 700, 100, 100));}
	SpawnGreen_W.setSpriteSheet(Spawner);
	for(int i = 0; i < 10; i++){
		SpawnGreen_W.addFrame(sf::IntRect(i*100, 800, 100, 100));}



//===Destroyed Spawners ===============================================================
//====blue
	DestroyedBlue_N.setTexture(Destroyed); DestroyedBlue_N.setTextureRect(sf::IntRect(0,0,100,100));
	DestroyedBlue_E.setTexture(Destroyed); DestroyedBlue_E.setTextureRect(sf::IntRect(100,0,100,100));
	DestroyedBlue_W.setTexture(Destroyed); DestroyedBlue_W.setTextureRect(sf::IntRect(200,0,100,100));
//====red
	DestroyedRed_N.setTexture(Destroyed); DestroyedRed_N.setTextureRect(sf::IntRect(300,100,100,100));
	DestroyedRed_E.setTexture(Destroyed); DestroyedRed_E.setTextureRect(sf::IntRect(400,100,100,100));
	DestroyedRed_W.setTexture(Destroyed); DestroyedRed_W.setTextureRect(sf::IntRect(500,100,100,100));
//====green
	DestroyedGreen_N.setTexture(Destroyed); DestroyedGreen_N.setTextureRect(sf::IntRect(600,200,100,100));
	DestroyedGreen_E.setTexture(Destroyed); DestroyedGreen_E.setTextureRect(sf::IntRect(700,200,100,100));
	DestroyedGreen_W.setTexture(Destroyed); DestroyedGreen_W.setTextureRect(sf::IntRect(800,200,100,100));



//===SM Animations ====================================================================
    WalkDown.setSpriteSheet(SmWalk);
    for(int i = 0; i < 4; i++){
    	WalkDown.addFrame(sf::IntRect(i*40, 70, 40, 70));}
    WalkUp.setSpriteSheet(SmWalk);
    for(int i = 0; i < 4; i++){
    	WalkUp.addFrame(sf::IntRect(i*40, 0, 40, 70));}
    WalkLeft.setSpriteSheet(SmWalk);
    for(int i = 0; i < 4; i++){
    	WalkLeft.addFrame(sf::IntRect(i*40, 140, 40, 70));}
    WalkRight.setSpriteSheet(SmWalk);
    for(int i = 0; i < 4; i++){
		WalkRight.addFrame(sf::IntRect(i*40, 210, 40, 70));}


	HealthBarSpr.setTexture(HealthBar);
	HPBitFirstSpr.setTexture(HPBitFirst);
	HPBitSpr.setTexture(HPBit);
	SPBitFirstSpr.setTexture(SPBitFirst);
	SPBitSpr.setTexture(SPBit);



}

sf::Sprite Images::getBG()
{
	return BG;
}

Animation* Images::getWalk(UnitType u, Direction d)
{
	switch(d){
		case N:
			if (u == AIr)
				return &WalkRed_N;
			if (u == AIb)
				return &WalkBlue_N;
			if (u == AIg)
				return &WalkGreen_N;
			if (u == SM)
				return &WalkUp;
			break;
		case S:
			if (u == AIr)
				return &WalkRed_S;
			if (u == AIb)
				return &WalkBlue_S;
			if (u == AIg)
				return &WalkGreen_S;
			if (u == SM)
				return &WalkDown;
			break;
		case E:
			if (u == AIr)
				return &WalkRed_E;
			if (u == AIb)
				return &WalkBlue_E;
			if (u == AIg)
				return &WalkGreen_E;
			if (u == SM)
				return &WalkRight;
			break;
		case W:
			if (u == AIr)
				return &WalkRed_W;
			if (u == AIb)
				return &WalkBlue_W;
			if (u == AIg)
				return &WalkGreen_W;
			if (u == SM)
				return &WalkLeft;
			break;
		case NW:
			if (u == AIr)
				return &WalkRed_NW;
			if (u == AIb)
				return &WalkBlue_NW;
			if (u == AIg)
				return &WalkGreen_NW;
			if (u == SM)
				return &WalkLeft;
			break;
		case NE:
			if (u == AIr)
				return &WalkRed_NE;
			if (u == AIb)
				return &WalkBlue_NE;
			if (u == AIg)
				return &WalkGreen_NE;
			if (u == SM)
				return &WalkRight;
			break;
		case SE:
			if (u == AIr)
				return &WalkRed_SE;
			if (u == AIb)
				return &WalkBlue_SE;
			if (u == AIg)
				return &WalkGreen_SE;
			if (u == SM)
				return &WalkRight;
			break;
		case SW:
			if (u == AIr)
				return &WalkRed_SW;
			if (u == AIb)
				return &WalkBlue_SW;
			if (u == AIg)
				return &WalkGreen_SW;
			if (u == SM)
				return &WalkLeft;
			break;

		default:
			if (u == AIr)
				return &WalkRed_S;
			if (u == AIb)
				return &WalkBlue_S;
			if (u == AIg)
				return &WalkGreen_S;
			if (u == SM)
				return &WalkDown;
			break;
	}
	if (u == AIr)
		return &WalkRed_S;
	if (u == AIb)
		return &WalkBlue_S;
	if (u == AIg)
		return &WalkGreen_S;
	if (u == SM)
		return &WalkDown;
}

Animation* Images::getAiAttack(Direction d)
{
	switch(d){
	case N:
		return &Attack_N;
	case S:
		return &Attack_S;
	case E:
		return &Attack_E;
	case W:
		return &Attack_W;
	case NW:
		return &Attack_NW;
	case NE:
		return &Attack_NE;
	case SE:
		return &Attack_SE;
	case SW:
		return &Attack_SW;
	}

}

Animation* Images::getSpawner(UnitType u, Direction d)
{
	switch(u){
	case AIr:
		if(d == N)
			return &SpawnRed_N;
		if(d == E)
			return &SpawnRed_E;
		if(d == W)
			return &SpawnRed_W;
		break;

	case AIb:
		if(d == N)
			return &SpawnBlue_N;
		if(d == E)
			return &SpawnBlue_E;
		if(d == W)
			return &SpawnBlue_W;
		break;

	case AIg:
		if(d == N)
			return &SpawnGreen_N;
		if(d == E)
			return &SpawnGreen_E;
		if(d == W)
			return &SpawnGreen_W;
		break;
	}
}




