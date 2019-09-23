/*********************************************************************
** Program name: inventory.hpp
** Author: Bryce Hickson
** Date: 03/19/2019
** Description: This is the specification file for the Inventory 
** class. This class holds up to 5 chars that represent items in the 
** Metroid game. There are functions to check if the 
** inventory is full, to check for a specific char in the inventory, 
** to add a char, and to retrieve a specific item from the inventory, 
** and to print all items in the inventory.
*********************************************************************/

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

class Inventory
{
private:
    int size;
    char* items;
public:
    Inventory();
    ~Inventory();
    bool isFull();
    bool checkFor(char);
    void addItem(char);
    char getItem(int);
    void print();
};

#endif