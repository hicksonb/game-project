/*********************************************************************
** Program name: Input Functions
** Author: Bryce Hickson
** Date: 02/10/2019
** Description: This is the specification file for the Input 
** Functions. It includes getInt(), which allows for input validation 
** when getting an int from a user and getString(), which allows for 
** input validation when getting a string from a user. It also 
** contains menu functions for the Metroid game.
*********************************************************************/

#ifndef INPUT_HPP
#define INPUT_HPP

#include <string>

int getInt();
int getInt(int, int);
std::string getString();
std::string getString(int, int);
int mainMenu();
int replayMenu();

#endif