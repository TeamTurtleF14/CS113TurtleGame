#include "AiUnit.hpp"

namespace{
Images::Direction invert(Images::Direction dir1)
{
	Images::Direction dir2;
	if(dir1 == Images::S)
		dir2 = Images::N;
	if(dir1 == Images::N)
		dir2 = Images::S;
	if(dir1 == Images::W)
		dir2 = Images::E;
	if(dir1 == Images::E)
		dir2 = Images::W;
	if(dir1 == Images::NE)
		dir2 = Images::SW;
	if(dir1 == Images::NW)
		dir2 = Images::SE;
	if(dir1 == Images::SW)
		dir2 = Images::NE;
	if(dir1 == Images::SE)
		dir2 = Images::NW;

	return dir2;
}
const double pi = std::acos(-1);
}


AiUnit::AiUnit(float x, float y, Images::UnitType type, Animation* initAnimation)
	:Unit{x, y}
{

	_type = type;
	_Ai = initAnimation;

	if(_type == Images::AIr || type == Images::AIb || type == Images::AIg)
	{	_dir = Images::S;
    	_AiSprite.setFrameTime(sf::seconds(0.05));
    	_AiSprite.pause();
    	_AiSprite.setLooped(false);
    	_AiSprite.setPosition(x,y);
    	_AiSprite.setOrigin(25.f,25.f);
	}
	if(_type == Images::SPr || _type == Images::SPb || _type == Images::SPg )
	{
		_AiSprite.setFrameTime(sf::seconds(0.1));
    	_AiSprite.pause();
    	_AiSprite.setLooped(false);
    	_AiSprite.setPosition(x,y);
	}

    _velocity.x = 0.f;
    _velocity.y = 0.f;

    _NoKeyPressed = true;
    _active = false;


    if (_type == Images::SPb){
    	_MaxHP = 30;
    	_speed = 0.f;
    	_radius = 50;
    }
    if (_type == Images::SPr){
    	_MaxHP = 30;
    	_speed = 0.f;
    	_radius = 50;
    }
    if (_type == Images::SPg){
    	_MaxHP = 30;
    	_speed = 0.f;
    	_radius = 50;
    }


    if (_type == Images::AIb){
    	_MaxHP = 2;
    	_speed = 55.f;
    	_radius = 20;
    }
    if (_type == Images::AIr){
    	_MaxHP = 4;
    	_speed = 65.f;
    	_radius = 20;
    }
    if (_type == Images::AIg){
    	_MaxHP = 3;
    	_speed = 60.f;
    	_radius = 20;
    }

}

void AiUnit::activate()
{
	if(isActive()){
		std::cout << "Deactivated" << std::endl;
		if (_type == Images::AIb)
			_speed = 55.f;
		if (_type == Images::AIr)
			_speed = 65.f;
		if (_type == Images::AIg)
			_speed = 60.f;
	}
	else{
		std::cout << "Activated" << std::endl;
		if (_type == Images::AIb)
			_speed = 75.f;
		if (_type == Images::AIr)
			_speed = 80.f;
		if (_type == Images::AIg)
			_speed = 75.f;
	}
	_active = !_active;
}

bool AiUnit::isActive() const
{
	return _active;
}

void AiUnit::setVelocity(float x, float y)
{
	_velocity.x = x;
	_velocity.y = y;
}

void AiUnit::keyPressed()
{
	_NoKeyPressed = false;
}

void AiUnit::notPressed()
{
	_NoKeyPressed = true;
}

void AiUnit::setAiAnimation(Animation* animation)
{
	_Ai = animation;
}

void AiUnit::setFrameTime(sf::Time frameTime)
{
	_frameTime = frameTime;
}

void AiUnit::play(){
	_AiSprite.play(*_Ai);
	_AiSprite.move(_velocity * _frameTime.asSeconds());

    if (_NoKeyPressed)
    {
    	_AiSprite.stop();
    }
    _NoKeyPressed = true;
}

void AiUnit::update()
{
    _AiSprite.update(_frameTime);
}

AnimatedSprite AiUnit::getAiSprite()
{
	return _AiSprite;
}

Images::Direction AiUnit::getDir()
{
	return _dir;
}

Images::UnitType AiUnit::getType()
{
	return _type;
}

float AiUnit::getRadius()
{
	return _radius;
}

sf::Vector2f AiUnit::getVelocity()
{
	return _velocity;
}

sf::Vector2f AiUnit::getPosition()
{
	return _AiSprite.getPosition();
}

float AiUnit::getSpeed()
{
	return _speed;
}

float AiUnit::angle(sf::Vector2f end)
{
	float a = std::atan((end.y - _AiSprite.getPosition().y)/(end.x - _AiSprite.getPosition().x));

	if (end.x > _AiSprite.getPosition().x)
		{
			if (end.y > _AiSprite.getPosition().y)
			{
				if (a < (pi/8))
					_dir  = Images::E;
				else if (a < (3*pi/8))
					_dir = Images::SE;
				else
					_dir = Images::S;
			}
			else
			{
				a += 2*pi;
				if(a > (15*pi/8))
					_dir = Images::E;
				else if(a > (13*pi/8))
					_dir = Images::NE;
				else
					_dir = Images::N;
			}
		}
		else
		{
			a += pi;
			if(end.y > _AiSprite.getPosition().y)
			{
				if(a > (7*pi/8))
					_dir = Images::W;
				else if(a > (5*pi/8))
					_dir = Images::SW;
				else
					_dir = Images::S;
			}
			else
			{
				if(a < (9*pi/8))
					_dir = Images::W;
				else if(a < (11*pi/8))
					_dir = Images::NW;
				else
					_dir = Images::N;
			}
		}
	return a;
}



float AiUnit::angle(sf::Vector2i end)
{
	float a = std::atan((end.y - _AiSprite.getPosition().y)/(end.x - _AiSprite.getPosition().x));

	if (end.x > _AiSprite.getPosition().x)
	{
		if (end.y > _AiSprite.getPosition().y)
		{
			if (a < (pi/8))
				_dir  = Images::E;
			else if (a < (3*pi/8))
				_dir = Images::SE;
			else
				_dir = Images::S;
		}
		else
		{
			a += 2*pi;
			if(a > (15*pi/8))
				_dir = Images::E;
			else if(a > (13*pi/8))
				_dir = Images::NE;
			else
				_dir = Images::N;
		}
	}
	else
	{
		a += pi;
		if(end.y > _AiSprite.getPosition().y)
		{
			if(a > (7*pi/8))
				_dir = Images::W;
			else if(a > (5*pi/8))
				_dir = Images::SW;
			else
				_dir = Images::S;
		}
		else
		{
			if(a < (9*pi/8))
				_dir = Images::W;
			else if(a < (11*pi/8))
				_dir = Images::NW;
			else
				_dir = Images::N;
		}
	}
	return a;
}

unsigned int AiUnit::getHP() const
{
	return _HP;
}

unsigned int AiUnit::getMax() const
{
	return _MaxHP;
}

float AiUnit::distance(sf::Vector2f end)
{
	return std::sqrt(std::pow(end.x - _AiSprite.getPosition().x, 2) + std::pow(end.y - _AiSprite.getPosition().y, 2));
}

float AiUnit::distance(sf::Vector2i end)
{
	return std::sqrt(std::pow(end.x - _AiSprite.getPosition().x, 2) + std::pow(end.y - _AiSprite.getPosition().y, 2));
}

void AiUnit::Move(sf::Vector2i target, sf::CircleShape& targetArea, Animation* animation)
{
		float a = angle(target);
		float d = distance(target);

		if (d > targetArea.getRadius())
		{
			_Ai = animation;
			_velocity.x = std::cos(a) * _speed;
			_velocity.y = std::sin(a) * _speed;
			_NoKeyPressed = false;
		}
		else
		{
			_NoKeyPressed = true;
			//_active = false;
			_velocity.x = 0;
			_velocity.y = 0;

		}

}



void AiUnit::DetectSm(const AnimatedSprite& Sm, const std::vector<AiUnit*>& units, Animation* walkAnimation, Animation* attackAnimation)
{
	float a = angle(Sm.getPosition());
	float d = distance(Sm.getPosition());
	float a2;
	float d2;
	if(!isActive())
	switch(_type)
	{
	case Images::AIr:
		if(d < 250 && d > 30)
		{
			_Ai = walkAnimation;
			_velocity.x = std::cos(a) * _speed;
			_velocity.y = std::sin(a) * _speed;
			_NoKeyPressed = false;
		}
		else if(d <= 30)
		{
			_Ai = attackAnimation;
			_velocity.x = 0;
			_velocity.y = 0;
			_NoKeyPressed = false;
		}
		break;
	case Images::AIb:
		if(d < 150)
		{
			if(a > pi){a -= pi;}
			else{a += pi;}
			_dir = invert(_dir);
			_Ai = walkAnimation;
			_velocity.x = std::cos(a)*_speed;
			_velocity.y = std::sin(a)*_speed;
			_NoKeyPressed = false;
		}
		else if(d >= 150 && d < 200)
		{
			a = angle(Sm.getPosition());
			_velocity.x = 0;
			_velocity.y = 0;
		}
		else
		{
			a = angle(Sm.getPosition());
			_Ai = walkAnimation;
			_velocity.x = std::cos(a) * _speed;
			_velocity.y = std::sin(a) * _speed;
			_NoKeyPressed = false;
		}
		break;

	case Images::AIg:
		if(d<150)
		{
			if(a > pi){a -= pi;}
			else{a += pi;}
			_dir = invert(_dir);
			_Ai = walkAnimation;
			_velocity.x = std::cos(a)*_speed;
			_velocity.y = std::sin(a)*_speed;
			_NoKeyPressed = false;
		}
		else if (d >= 150 && d< 400)
		{
			sf::Vector2f target;
			float ratio = 1;
			for(std::vector<AiUnit>::size_type i = 0; i != units.size(); i++)
			{
				d2 = distance(units[i]->getPosition());
				if (ratio > units[i]->getHP() / units[i]->getMax())
				{
					ratio = units[i]->getHP() / units[i]->getMax();
					target = units[i]->getPosition();
 				}
			}
			a2 = angle(target);
			d2 = distance(target);
			if (d2 < 200 && d2 > 25)
			{
				_Ai = walkAnimation;
				_velocity.x = std::cos(a) * _speed;
				_velocity.y = std::sin(a) * _speed;
				_NoKeyPressed = false;
			}
			else if(d2 <= 25)
			{
				_velocity.x = 0;
				_velocity.y = 0;
				_NoKeyPressed = true;
			}
		}
	}
}

void AiUnit::SetHealth(int dmg, Animation* death)
{
	_HP -= dmg;
	if(_HP <= 0)
	{
		if(_type == Images::AIr || _type == Images:: AIb || _type == Images::AIg)
		{
			_Ai = death;
		}
		else if(_type == Images::SPr || _type == Images::SPb || _type == Images::SPg)
		{
			_Ai = death;
			_type = Images::DED;
		}
	}
}

