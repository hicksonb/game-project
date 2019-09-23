/*********************************************************************
** Program name: space.cpp
** Author: Bryce Hickson
** Date: 03/19/2019
** Description: This is the implementation file for the Space class 
** and its derived classes. It includes spaces for Plyaer, Empty, 
** Block, Ladder, Health, Missile, Jump, Charge, Key, Metroid, Queen, 
** and Ship. Each class has pointers in four directions to other 
** Space objects, allowing these objects to link to each other on a 
** grid. Each derived class has members and functions to support its 
** purpose in the Metroid game.
*********************************************************************/

#include <random>

#include "space.hpp"

/***********
** Player **
***********/

/*********************************************************************
** Description: Constructor and destructor.
*********************************************************************/

Player::Player()
{
    this -> top = nullptr;
    this -> right = nullptr;
    this -> left = nullptr;
    this -> bottom = nullptr;
    this -> type = 'S';
    this -> under = nullptr;
    this -> jumpUsed = 0;
    this -> jumpMax = 1;
    this -> health = 200;
    this -> maxHealth = 200;
    this -> power = 20;
    this -> basePower = 20;
}

Player::Player(Space* topIn, Space* rightIn, Space* leftIn, Space* bottomIn)
{
    this -> top = nullptr;
    this -> right = nullptr;
    this -> left = nullptr;
    this -> bottom = nullptr;
    this -> type = 'S';
    this -> under = nullptr;
    this -> jumpUsed = 0;
    this -> jumpMax = 1;
    this -> health = 200;
    this -> maxHealth = 200;
    this -> power = 20;
    this -> basePower = 20;
}

Player::~Player()
{
    this -> top = nullptr;
    this -> right = nullptr;
    this -> left = nullptr;
    this -> bottom = nullptr;
    this -> under = nullptr;
}

/*********************************************************************
** Description: Increments jumpUsed.
*********************************************************************/

int Player::incJumpUsed()
{
    jumpUsed++;
}

/*********************************************************************
** Description: Increments jumpMax.
*********************************************************************/

int Player::incJumpMax()
{
    jumpMax++;
}

/*********************************************************************
** Description: Sets jumpUsed to 0.
*********************************************************************/

int Player::jumpLanded()
{
    jumpUsed = 0;
}

/*********************************************************************
** Description: Increases or decreases health by passed int. Will not 
** allow health to go under 0 or maxHealth.
*********************************************************************/

void Player::changeHealth(int changeIn)
{
    health = health + changeIn;
    
    if (health < 0)
    {
        health = 0;
    }
    
    if (health > maxHealth)
    {
        health = maxHealth;
    }
}

/*********************************************************************
** Description: Increases or decreases power by passed int.
*********************************************************************/

void Player::changePower(int changeIn)
{
    power = power + changeIn;
}

/*********************************************************************
** Description: Increases or decreases basePower by passed int.
*********************************************************************/

void Player::changeBasePower(int changeIn)
{
    basePower = basePower + changeIn;
}

/*********************************************************************
** Description: Returns int of power and resets power to basePower.
*********************************************************************/

int Player::attack()
{
    int attack = power;
    
    power = basePower;
    
    return attack;
}

/*********************************************************************
** Description: Set functions for member variables.
*********************************************************************/

void Player::setUnder(Space* underIn)
{
    this -> under = underIn;
}

/*********************************************************************
** Description: Get functions for member variables.
*********************************************************************/

Space* Player::getUnder()
{
    return under;
}

int Player::getJumpUsed()
{
    return jumpUsed;
}

int Player::getJumpMax()
{
    return jumpMax;
}

int Player::getHealth()
{
    return health;
}

int Player::getPower()
{
    return power;
}

int Player::getBasePower()
{
    return basePower;
}

/**********
** Empty **
**********/

/*********************************************************************
** Description: Constructor and destructor.
*********************************************************************/

Empty::Empty()
{
    this -> top = nullptr;
    this -> right = nullptr;
    this -> left = nullptr;
    this -> bottom = nullptr;
    this -> type = ' ';
}

Empty::Empty(Space* topIn, Space* rightIn, Space* leftIn, Space* bottomIn)
{
    this -> top = topIn;
    this -> right = rightIn;
    this -> left = leftIn;
    this -> bottom = bottomIn;
    this -> type = ' ';
}

Empty::~Empty()
{
    this -> top = nullptr;
    this -> right = nullptr;
    this -> left = nullptr;
    this -> bottom = nullptr;
}

/**********
** Block **
**********/

/*********************************************************************
** Description: Constructor and destructor.
*********************************************************************/

Block::Block()
{
    this -> top = nullptr;
    this -> right = nullptr;
    this -> left = nullptr;
    this -> bottom = nullptr;
    this -> type = 'T';
}

Block::Block(Space* topIn, Space* rightIn, Space* leftIn, Space* bottomIn)
{
    this -> top = topIn;
    this -> right = rightIn;
    this -> left = leftIn;
    this -> bottom = bottomIn;
    this -> type = 'T';
}

Block::~Block()
{
    this -> top = nullptr;
    this -> right = nullptr;
    this -> left = nullptr;
    this -> bottom = nullptr;
}

/***********
** Ladder **
***********/

/*********************************************************************
** Description: Constructor and destructor.
*********************************************************************/

Ladder::Ladder()
{
    this -> top = nullptr;
    this -> right = nullptr;
    this -> left = nullptr;
    this -> bottom = nullptr;
    this -> type = 'H';
}

Ladder::Ladder(Space* topIn, Space* rightIn, Space* leftIn, Space* bottomIn)
{
    this -> top = topIn;
    this -> right = rightIn;
    this -> left = leftIn;
    this -> bottom = bottomIn;
    this -> type = 'H';
}

Ladder::~Ladder()
{
    this -> top = nullptr;
    this -> right = nullptr;
    this -> left = nullptr;
    this -> bottom = nullptr;
}

/***********
** Health **
***********/

/*********************************************************************
** Description: Constructor and destructor.
*********************************************************************/

Health::Health()
{
    this -> top = nullptr;
    this -> right = nullptr;
    this -> left = nullptr;
    this -> bottom = nullptr;
    this -> type = '*';
}

Health::Health(Space* topIn, Space* rightIn, Space* leftIn, Space* bottomIn)
{
    this -> top = topIn;
    this -> right = rightIn;
    this -> left = leftIn;
    this -> bottom = bottomIn;
    this -> type = '*';
}

Health::~Health()
{
    this -> top = nullptr;
    this -> right = nullptr;
    this -> left = nullptr;
    this -> bottom = nullptr;
}

/***********
** Missile **
***********/

/*********************************************************************
** Description: Constructor and destructor.
*********************************************************************/

Missile::Missile()
{
    this -> top = nullptr;
    this -> right = nullptr;
    this -> left = nullptr;
    this -> bottom = nullptr;
    this -> type = '^';
}

Missile::Missile(Space* topIn, Space* rightIn, Space* leftIn, Space* bottomIn)
{
    this -> top = topIn;
    this -> right = rightIn;
    this -> left = leftIn;
    this -> bottom = bottomIn;
    this -> type = '^';
}

Missile::~Missile()
{
    this -> top = nullptr;
    this -> right = nullptr;
    this -> left = nullptr;
    this -> bottom = nullptr;
}

/*********
** Jump **
*********/

/*********************************************************************
** Description: Constructor and destructor.
*********************************************************************/

Jump::Jump()
{
    this -> top = nullptr;
    this -> right = nullptr;
    this -> left = nullptr;
    this -> bottom = nullptr;
    this -> type = 'J';
}

Jump::Jump(Space* topIn, Space* rightIn, Space* leftIn, Space* bottomIn)
{
    this -> top = topIn;
    this -> right = rightIn;
    this -> left = leftIn;
    this -> bottom = bottomIn;
    this -> type = 'J';
}

Jump::~Jump()
{
    this -> top = nullptr;
    this -> right = nullptr;
    this -> left = nullptr;
    this -> bottom = nullptr;
}

/***********
** Charge **
***********/

/*********************************************************************
** Description: Constructor and destructor.
*********************************************************************/

Charge::Charge()
{
    this -> top = nullptr;
    this -> right = nullptr;
    this -> left = nullptr;
    this -> bottom = nullptr;
    this -> type = 'C';
}

Charge::Charge(Space* topIn, Space* rightIn, Space* leftIn, Space* bottomIn)
{
    this -> top = topIn;
    this -> right = rightIn;
    this -> left = leftIn;
    this -> bottom = bottomIn;
    this -> type = 'C';
}

Charge::~Charge()
{
    this -> top = nullptr;
    this -> right = nullptr;
    this -> left = nullptr;
    this -> bottom = nullptr;
}

/********
** Key **
********/

/*********************************************************************
** Description: Constructor and destructor.
*********************************************************************/

Key::Key()
{
    this -> top = nullptr;
    this -> right = nullptr;
    this -> left = nullptr;
    this -> bottom = nullptr;
    this -> type = 'K';
}

Key::Key(Space* topIn, Space* rightIn, Space* leftIn, Space* bottomIn)
{
    this -> top = topIn;
    this -> right = rightIn;
    this -> left = leftIn;
    this -> bottom = bottomIn;
    this -> type = 'K';
}

Key::~Key()
{
    this -> top = nullptr;
    this -> right = nullptr;
    this -> left = nullptr;
    this -> bottom = nullptr;
}

/************
** Metroid **
************/

/*********************************************************************
** Description: Constructor and destructor.
*********************************************************************/

Metroid::Metroid()
{
    this -> top = nullptr;
    this -> right = nullptr;
    this -> left = nullptr;
    this -> bottom = nullptr;
    this -> type = 'M';
    this -> health = 60;
    this -> power = 10;
}

Metroid::Metroid(Space* topIn, Space* rightIn, Space* leftIn, Space* bottomIn)
{
    this -> top = topIn;
    this -> right = rightIn;
    this -> left = leftIn;
    this -> bottom = bottomIn;
    this -> type = 'M';
    this -> health = 60;
    this -> power = 10;
}

Metroid::~Metroid()
{
    this -> top = nullptr;
    this -> right = nullptr;
    this -> left = nullptr;
    this -> bottom = nullptr;
}

/*********************************************************************
** Description: Increases or decreases health by passed int. Will not 
** allow health to drop below 0.
*********************************************************************/

void Metroid::changeHealth(int changeIn)
{
    health = health + changeIn;
    
    if (health < 0)
    {
        health = 0;
    }
}

/*********************************************************************
** Description: Returns power.
*********************************************************************/

int Metroid::attack()
{
    return power;
}

/*********************************************************************
** Description: Get functions for member variables.
*********************************************************************/

int Metroid::getHealth()
{
    return health;
}

int Metroid::getPower()
{
    return power;
}

/**********
** Queen **
**********/

/*********************************************************************
** Description: Constructor and destructor.
*********************************************************************/

Queen::Queen()
{
    this -> top = nullptr;
    this -> right = nullptr;
    this -> left = nullptr;
    this -> bottom = nullptr;
    this -> type = 'Q';
    this -> health = 600;
    this -> power = 20;
}

Queen::Queen(Space* topIn, Space* rightIn, Space* leftIn, Space* bottomIn)
{
    this -> top = topIn;
    this -> right = rightIn;
    this -> left = leftIn;
    this -> bottom = bottomIn;
    this -> type = 'Q';
    this -> health = 600;
    this -> power = 20;
}

Queen::~Queen()
{
    this -> top = nullptr;
    this -> right = nullptr;
    this -> left = nullptr;
    this -> bottom = nullptr;
}

/*********************************************************************
** Description: Increases or decreases health by passed int. Will not 
** allow health to drop below 0.
*********************************************************************/

void Queen::changeHealth(int changeIn)
{
    health = health + changeIn;
    
    if (health < 0)
    {
        health = 0;
    }
}

/*********************************************************************
** Description: Returns a random value between power -10 and power + 
** 30.
*********************************************************************/

int Queen::attack()
{
    int attack;
    std::mt19937 randomNum;
    randomNum.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> numRange(power - 10, power + 30);
    
    attack = numRange(randomNum);
    
    return attack;
}

/*********************************************************************
** Description: Get functions for member variables.
*********************************************************************/

int Queen::getHealth()
{
    return health;
}

int Queen::getPower()
{
    return power;
}

/*********
** Ship **
*********/

/*********************************************************************
** Description: Constructor and destructor.
*********************************************************************/

Ship::Ship()
{
    this -> top = nullptr;
    this -> right = nullptr;
    this -> left = nullptr;
    this -> bottom = nullptr;
    this -> type = 'O';
}

Ship::Ship(Space* topIn, Space* rightIn, Space* leftIn, Space* bottomIn)
{
    this -> top = topIn;
    this -> right = rightIn;
    this -> left = leftIn;
    this -> bottom = bottomIn;
    this -> type = 'O';
}

Ship::~Ship()
{
    this -> top = nullptr;
    this -> right = nullptr;
    this -> left = nullptr;
    this -> bottom = nullptr;
}

/**********
** Space **
**********/

/*********************************************************************
** Description: Destructor 
*********************************************************************/

Space::~Space()
{
    // Defined in derived classes
}
    
/*********************************************************************
** Description: Set functions for member variables.
*********************************************************************/

void Space::setTop(Space* topIn)
{
    this -> top = topIn;
}

void Space::setRight(Space* rightIn)
{
    this -> right = rightIn;
}

void Space::setLeft(Space* leftIn)
{
    this -> left = leftIn;
}

void Space::setBottom(Space* bottomIn)
{
    this -> bottom = bottomIn;
}

void Space::setType(char typeIn)
{
    this -> type = typeIn; 
}

/*********************************************************************
** Description: Get functions for member variables.
*********************************************************************/

Space* Space::getTop()
{
    return top;
}

Space* Space::getRight()
{
    return right;
}

Space* Space::getLeft()
{
    return left;
}

Space* Space::getBottom()
{
    return bottom;
}

char Space::getType()
{
    return type;
}