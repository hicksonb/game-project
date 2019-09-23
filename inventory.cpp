/*********************************************************************
** Program name: inventory.cpp
** Author: Bryce Hickson
** Date: 03/19/2019
** Description: This is the implementation file for the Inventory 
** class. This class holds up to 5 chars that represent items in the 
** Metroid game. There are functions to check if the 
** inventory is full, to check for a specific char in the inventory, 
** to add a char, and to retrieve a specific item from the inventory, 
** and to print all items in the inventory.
*********************************************************************/

#include <iostream>

#include "inventory.hpp"

using std::cout;
using std::endl;

/*********************************************************************
** Description: Default constructor that creates an Inventory for 5 
** chars.
*********************************************************************/

Inventory::Inventory()
{
    this -> size = 5;
    
    items = new char[size];
    
    for (int count = 0; count < size; count++)
    {
        items[count] = ' ';
    }
}

/*********************************************************************
** Description: Destructor that deletes Inventory and prevents memory 
** leaks.
*********************************************************************/

Inventory::~Inventory()
{
    delete [] items;
    items = nullptr;
}

/*********************************************************************
** Description: Returns whether the array is full or not.
*********************************************************************/

bool Inventory::isFull()
{
    bool full = true;
    
    for (int count = 0; count < size; count++)
    {
        if (items[count] == ' ')
        {
            full = false;
        }
    }
    
    return full;
}

/*********************************************************************
** Description: Returns whether a passed char is in the array or not.
*********************************************************************/

bool Inventory::checkFor(char itemIn)
{
    bool found = false;
    
    for (int count = 0; count < size; count++)
    {
        if (items[count] == itemIn)
        {
            found = true;
        }
    }
    
    return found;
}

/*********************************************************************
** Description: Adds a passed char to the array in the first empty 
** slot.
*********************************************************************/

void Inventory::addItem(char itemIn)
{
    if (this -> isFull() != true)
    {
        bool added = false;
        int count = 0;
        
        while (added == false)
        {
            if (items[count] == ' ')
            {
                items[count] = itemIn;
                added = true;
            }
            else
            {
                count++;
            }
        }
    }
}

/*********************************************************************
** Description: Takes an int to identify a specific char to remove 
** from the array and returns the removed char. Returns ' ' if passed 
** int is out of bounds.
*********************************************************************/

char Inventory::getItem(int itemNum)
{
    itemNum--;
    
    if (itemNum < size && itemNum > -1)
    {
        char returnItem = items[itemNum];
        
        items[itemNum] = ' ';
        
        return returnItem;
    }
    else
    {
        return ' ';
    }
}

/*********************************************************************
** Description: Prints the items in the Inventory.
*********************************************************************/

void Inventory::print()
{
    cout << "INVENTORY: ";
    for (int count = 0; count < size; count++)
    {
        cout << count + 1 << ". " << items[count] << "   ";
    }
    cout << endl;
}