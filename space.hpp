/*********************************************************************
** Program name: space.hpp
** Author: Bryce Hickson
** Date: 03/19/2019
** Description: This is the specification file for the Space class 
** and its derived classes. It includes spaces for Plyaer, Empty, 
** Block, Ladder, Health, Missile, Jump, Charge, Key, Metroid, Queen, 
** and Ship. Each class has pointers in four directions to other 
** Space objects, allowing these objects to link to each other on a 
** grid. Each derived class has members and functions to support its 
** purpose in the Metroid game.
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

class Space
{
protected:
    Space* top;
    Space* right;
    Space* left;
    Space* bottom;
    char type;
public:
    virtual ~Space() = 0;

    virtual int incJumpUsed() = 0;
    virtual int incJumpMax() = 0;
    virtual int jumpLanded() = 0;
    virtual void changeHealth(int) = 0;
    virtual void changePower(int) = 0;
    virtual void changeBasePower(int) = 0;
    virtual int attack() = 0;
    
    virtual void setUnder(Space*) = 0;    
    virtual Space* getUnder() = 0;
    virtual int getJumpUsed() = 0;
    virtual int getJumpMax() = 0;
    virtual int getHealth() = 0;
    virtual int getPower() = 0;
    virtual int getBasePower() = 0;
    
    void setTop(Space*);
    void setRight(Space*);
    void setLeft(Space*);
    void setBottom(Space*);
    void setType(char);
    Space* getTop();
    Space* getRight();
    Space* getLeft();
    Space* getBottom();
    char getType();
};

class Player : public Space
{
private:
    Space* under;
    int jumpUsed;
    int jumpMax;
    int health;
    int maxHealth;
    int power;
    int basePower;
public:
    Player();
    Player(Space*, Space*, Space*, Space*);
    ~Player();
    
    int incJumpUsed();
    int incJumpMax();
    int jumpLanded();
    void changeHealth(int);
    void changePower(int);
    void changeBasePower(int);
    int attack();
    void setUnder(Space*);
    Space* getUnder();
    int getJumpUsed();
    int getJumpMax();
    int getHealth();
    int getPower();
    int getBasePower();
};

class Empty : public Space
{
private:
    
public:
    Empty();
    Empty(Space*, Space*, Space*, Space*);
    ~Empty();
    
    int incJumpUsed(){};
    int incJumpMax(){};
    int jumpLanded(){};
    void changeHealth(int){};
    void changePower(int){};
    void changeBasePower(int){};
    int attack(){};
    void setUnder(Space*){};
    Space* getUnder(){};
    int getJumpMax(){};
    int getJumpUsed(){};
    int getHealth(){};
    int getPower(){};
    int getBasePower(){};
};

class Block : public Space
{
private:
    
public:
    Block();
    Block(Space*, Space*, Space*, Space*);
    ~Block();
    
    int incJumpUsed(){};
    int incJumpMax(){};
    int jumpLanded(){};
    void changeHealth(int){};
    void changePower(int){};
    void changeBasePower(int){};
    int attack(){};
    void setUnder(Space*){};
    Space* getUnder(){};
    int getJumpMax(){};
    int getJumpUsed(){};
    int getHealth(){};
    int getPower(){};
    int getBasePower(){};
};

class Ladder : public Space
{
private:
    
public:
    Ladder();
    Ladder(Space*, Space*, Space*, Space*);
    ~Ladder();
    
    int incJumpUsed(){};
    int incJumpMax(){};
    int jumpLanded(){};
    void changeHealth(int){};
    void changePower(int){};
    void changeBasePower(int){};
    int attack(){};
    void setUnder(Space*){};
    Space* getUnder(){};
    int getJumpMax(){};
    int getJumpUsed(){};
    int getHealth(){};
    int getPower(){};
    int getBasePower(){};
};

class Health : public Space
{
private:
    
public:
    Health();
    Health(Space*, Space*, Space*, Space*);
    ~Health();
    
    int incJumpUsed(){};
    int incJumpMax(){};
    int jumpLanded(){};
    void changeHealth(int){};
    void changePower(int){};
    void changeBasePower(int){};
    int attack(){};
    void setUnder(Space*){};
    Space* getUnder(){};
    int getJumpMax(){};
    int getJumpUsed(){};
    int getHealth(){};
    int getPower(){};
    int getBasePower(){};
};

class Missile : public Space
{
private:
    
public:
    Missile();
    Missile(Space*, Space*, Space*, Space*);
    ~Missile();
    
    int incJumpUsed(){};
    int incJumpMax(){};
    int jumpLanded(){};
    void changeHealth(int){};
    void changePower(int){};
    void changeBasePower(int){};
    int attack(){};
    void setUnder(Space*){};
    Space* getUnder(){};
    int getJumpMax(){};
    int getJumpUsed(){};
    int getHealth(){};
    int getPower(){};
    int getBasePower(){};
};

class Jump : public Space
{
private:
    
public:
    Jump();
    Jump(Space*, Space*, Space*, Space*);
    ~Jump();
    
    int incJumpUsed(){};
    int incJumpMax(){};
    int jumpLanded(){};
    void changeHealth(int){};
    void changePower(int){};
    void changeBasePower(int){};
    int attack(){};
    void setUnder(Space*){};
    Space* getUnder(){};
    int getJumpMax(){};
    int getJumpUsed(){};
    int getHealth(){};
    int getPower(){};
    int getBasePower(){};
};

class Charge : public Space
{
private:
    
public:
    Charge();
    Charge(Space*, Space*, Space*, Space*);
    ~Charge();
    
    int incJumpUsed(){};
    int incJumpMax(){};
    int jumpLanded(){};
    void changeHealth(int){};
    void changePower(int){};
    void changeBasePower(int){};
    int attack(){};
    void setUnder(Space*){};
    Space* getUnder(){};
    int getJumpMax(){};
    int getJumpUsed(){};
    int getHealth(){};
    int getPower(){};
    int getBasePower(){};
};

class Key : public Space
{
private:
    
public:
    Key();
    Key(Space*, Space*, Space*, Space*);
    ~Key();
    
    int incJumpUsed(){};
    int incJumpMax(){};
    int jumpLanded(){};
    void changeHealth(int){};
    void changePower(int){};
    void changeBasePower(int){};
    int attack(){};
    void setUnder(Space*){};
    Space* getUnder(){};
    int getJumpMax(){};
    int getJumpUsed(){};
    int getHealth(){};
    int getPower(){};
    int getBasePower(){};
};

class Metroid : public Space
{
private:
    int health;
    int power;
public:
    Metroid();
    Metroid(Space*, Space*, Space*, Space*);
    ~Metroid();
    
    void changeHealth(int);
    int attack();
    int getHealth();
    int getPower();
    
    void setUnder(Space*){};
    Space* getUnder(){};
    int getJumpMax(){};
    int getJumpUsed(){};
    int incJumpMax(){};
    int incJumpUsed(){};
    int jumpLanded(){};
    void changePower(int){};
    void changeBasePower(int){};
    int getBasePower(){};
};

class Queen : public Space
{
private:
    Space* under;
    int health;
    int maxHealth;
    int jumpMax;
    int jumpUsed;
    int power;
    int basePower;
public:
    Queen();
    Queen(Space*, Space*, Space*, Space*);
    ~Queen();
    
    void changeHealth(int);
    int attack();
    int getHealth();
    int getPower();
    
    void setUnder(Space*){};
    Space* getUnder(){};
    int getJumpMax(){};
    int getJumpUsed(){};
    int incJumpMax(){};
    int incJumpUsed(){};
    int jumpLanded(){};
    void changePower(int){};
    void changeBasePower(int){};
    int getBasePower(){};
};

class Ship : public Space
{
private:
    
public:
    Ship();
    Ship(Space*, Space*, Space*, Space*);
    ~Ship();
    
    int incJumpUsed(){};
    int incJumpMax(){};
    int jumpLanded(){};
    void changeHealth(int){};
    void changePower(int){};
    void changeBasePower(int){};
    int attack(){};
    void setUnder(Space*){};
    Space* getUnder(){};
    int getJumpMax(){};
    int getJumpUsed(){};
    int getHealth(){};
    int getPower(){};
    int getBasePower(){};
};

#endif