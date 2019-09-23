/*********************************************************************
** Program name: spacematrix.hpp
** Author: Bryce Hickson
** Date: 03/19/2019
** Description: This is the specification file for the SpaceMatrix 
** class. This class represents a 2D board of Space objects for the 
** Metroid game. The functions support the gameplay for the game.
*********************************************************************/

#ifndef SPACEMATRIX_HPP
#define SPACEMATRIX_HPP

#include "space.hpp"
#include "inventory.hpp"

class SpaceMatrix
{
private:
    const int ROWS = 17;
    const int COLS = 43;
    const int HEALTH_PACK_VAL = 100;
    const int MISSILE_VAL = 100;
    const int CHARGE_VAL = 30;
    const int STEP_DAMAGE = -2;
    Space* head;
    Space* player;
    Inventory* items;
    int jumpHeight = 0;
    int controls = 1;
    int gameStatus = 0;
public:
    SpaceMatrix();
    ~SpaceMatrix();
    void loadLevel();
    Space* replace(Space*, char);
    void up();
    void right();
    void left();
    void down();
    void checkUnder();
    void grabUnder();
    void openInventory();
    void combat(Space*);
    void printStats();
    void print();
    void printOptions();
    void quit();
    int getGameStatus();
};

#endif