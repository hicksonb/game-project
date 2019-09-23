/*********************************************************************
** Program name: Input Functions
** Author: Bryce Hickson
** Date: 02/10/2019
** Description: This is the implementation file for the Input 
** Functions. It includes getInt(), which allows for input validation 
** when getting an int from a user and getString(), which allows for 
** input validation when getting a string from a user. It also 
** contains menu functions for the Metroid game.
*********************************************************************/

#include <iostream>
#include <string>
#include <limits>

#include "input.hpp"

using std::string;
using std::cin;
using std::stringstream;
using std::cout;
using std::endl;

/*********************************************************************
** Description: getInt() takes requests an int from the user, and 
** will continue asking until the user provides a valid int that is 
** 9 digits or less. Once provided a valid int, it will return it.
*********************************************************************/

int getInt()
{
    string inputStr;
    string unsignedStr;
    int inputInt;
    const int MAX_LENGTH = 9;

    std::getline(cin, inputStr);

    if (inputStr == "" || inputStr.length() > MAX_LENGTH || inputStr == "-")
    {
        inputStr = " ";
    }
    
    if (inputStr.length() > 1)
    {
        unsignedStr = inputStr.substr(1, inputStr.length());
    }
    else
    {
        unsignedStr = "0000";
    }
    
    while (inputStr.find_first_not_of("0123456789-") != string::npos 
            || unsignedStr.find_first_not_of("0123456789") != string::npos)
    {
        cout << "Invalid input, try again: ";
 
        if (inputStr.find_first_not_of("0123456789-") == string::npos 
            && unsignedStr.find_first_not_of("0123456789") == string::npos)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
 
        std::getline(cin, inputStr);
        
        if (inputStr == "" || inputStr.length() > MAX_LENGTH || inputStr == "-")
        {
            inputStr = " ";
        }
        
        if (inputStr.length() > 1)
        {
            unsignedStr = inputStr.substr(1, inputStr.length());
        }
        else
        {
            unsignedStr = "0000";
        }
    }
    
    inputInt = std::stoi(inputStr);
    
    return inputInt;
}

/*********************************************************************
** Description: getInt() (overloaded) takes requests an int from the 
** user, and will continue asking until the user provides a valid int 
** that is within the bounds that have been passed as arguments. 
** Once provided a valid int, it will return it.
*********************************************************************/

int getInt(int min, int max)
{
    string inputStr;
    string unsignedStr;
    int inputInt;
    const int MAX_LENGTH = 9;

    do
    {
    
        std::getline(cin, inputStr);
    
        if (inputStr == "" || inputStr.length() > MAX_LENGTH || inputStr == "-")
        {
            inputStr = " ";
        }
        
        if (inputStr.length() > 1)
        {
            unsignedStr = inputStr.substr(1, inputStr.length());
        }
        else
        {
            unsignedStr = "0000";
        }
        
        while (inputStr.find_first_not_of("0123456789-") != string::npos 
                || unsignedStr.find_first_not_of("0123456789") != string::npos)
        {
            cout << "Invalid input, try again: ";
     
            if (inputStr.find_first_not_of("0123456789-") == string::npos 
                && unsignedStr.find_first_not_of("0123456789") == string::npos)
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
     
            std::getline(cin, inputStr);
            
            if (inputStr == "" || inputStr.length() > MAX_LENGTH || inputStr == "-")
            {
                inputStr = " ";
            }
            
            if (inputStr.length() > 1)
            {
                unsignedStr = inputStr.substr(1, inputStr.length());
            }
            else
            {
                unsignedStr = "0000";
            }
        }
        
        inputInt = std::stoi(inputStr);
        
        if (inputInt < min || inputInt > max)
        {
            cout << "Please enter an integer between " << min << " and " << max << ": ";
        }
        
    }
    while (inputInt < min || inputInt > max);    
        
    return inputInt;
}

/*********************************************************************
** Description: getString() gets a string from the user, allowing for 
** spaces. It must contain at least one non whitespace character. 
** Once provided a valid string, it will be returned.
*********************************************************************/

string getString()
{
    string inputStr;
    
    do
    {
        std::getline(cin, inputStr);
        
        if (inputStr.find_first_not_of(" \n\t") == string::npos)
        {
            cout << "Please enter at least one non-whitespace character: ";
        }
    }
    while (inputStr.find_first_not_of(" \n\t") == string::npos);
    
    return inputStr;
}

/*********************************************************************
** Description: getString() (overloaded) gets a string from the user, 
** allowing for spaces. It takes two int arguments, one representing 
** the minimum length of the string allowed and one from the maximum 
** length of the string. It must contain at least one non whitespace 
** character. Will continue asking until string is a valid length. 
** Once provided a valid string, it will be returned.
*********************************************************************/

string getString(int min, int max)
{
    string inputStr;
    
    do
    {
        std::getline(cin, inputStr);
        
        if (inputStr.length() > max || inputStr.length() < min)
        {
            cout << "Please enter between " << min << " and " << max << " characters: ";
        }
        else if (inputStr.find_first_not_of(" \n\t") == string::npos)
        {
            cout << "Please enter at least one non-whitespace character: ";
        }
    }
    while (inputStr.length() > max || inputStr.length() < min 
            || inputStr.find_first_not_of(" \n\t") == string::npos);
    
    return inputStr;
}

/*********************************************************************
** Description: mainMenu() prints out the intro screen for Metroid. 
** It returns the int of the user's selection.
*********************************************************************/

int mainMenu()
{
    int choice = 0;
    
    for (int count = 0; count < 50; count++)
    {
        cout << endl;
    }
    
    cout << " __  __ ______ _______ _____   ____ _____ _____  " << endl;
    cout << "|  \\/  |  ____|__   __|  __ \\ / __ \\_   _|  __ \\ " << endl;
    cout << "| \\  / | |__     | |  | |__) | |  | || | | |  | |" << endl;
    cout << "| |\\/| |  __|    | |  |  _  /| |  | || | | |  | |" << endl;
    cout << "| |  | | |____   | |  | | \\ \\| |__| || |_| |__| |" << endl;
    cout << "|_|  |_|______|  |_|  |_|  \\_\\\\____/_____|_____/ " << endl;
    cout << endl;
    cout << "CREATED BY: BRYCE HICKSON" << endl;
    cout << endl;
    cout << "NOTE: I do not own the rights to Metroid." << endl;
    cout << "This game is just for fun." << endl;
    cout << endl;
    cout << "BACKSTORY:" << endl;
    cout << "Samus (S) has crash landed on a mysterious planet! " << endl;
    cout << "There is a leak in her suit and she loses health " << endl;
    cout << "every move she makes. She needs to return to " << endl;
    cout << "her ship if she hopes to survive!" << endl;
    cout << endl;
    cout << "INSTRUCTIONS:" << endl;
    cout << "For each turn the controls are displayed under " << endl;
    cout << "the map. Navigate the planet and get back to the " << endl;
    cout << "ship (O)! Defeat enemies (M, Q) and collect items " << endl;
    cout << "(*, ^, J, C, K) along the way. Once you board the " << endl;
    cout << "ship (O), you win! Note that you'll need to find the " << endl;
    cout << "key (K) before you can board. If your health hits " << endl;
    cout << "0 before you do, it's game over for Samus (S)." << endl;
    cout << endl;
    cout << "ITEMS:" << endl;
    cout << "Energy Tank (*): Heals 100 health upon use." << endl;
    cout << "Missile (^): Boosts your next attack by 100 upon use." << endl;
    cout << "High Jump Boots (J): While in your inventory, you can double jump." << endl;
    cout << "Charge Shot (C): While in your inventory, your base power is 50." << endl;
    cout << "Key (K): While in your inventory, you can board the ship." << endl;
    cout << endl;
    cout << "Choose from the following options: " << endl;
    cout << "1. Play" << endl;
    cout << "2. Exit" << endl;
    cout << endl;
    cout << "Please enter the number of your selection: ";
    
    choice = getInt(1, 2);
        
    for (int count = 0; count < 25; count++)
    {
        cout << endl << endl << endl << endl;
    }
    
    return choice;
}

/*********************************************************************
** Description: replayMenu() prints out the replay menu for Metroid. 
** It returns the int of the user's selection.
*********************************************************************/

int replayMenu()
{
    int choice = 0;
    
    cout << endl;
    cout << "Choose from the following options: " << endl;
    cout << "1. Play again" << endl;
    cout << "2. Exit" << endl;
    cout << endl;
    cout << "Please enter the number of your selection: ";
        
    choice = getInt(1, 2);
        
    for (int count = 0; count < 25; count++)
    {
        cout << endl << endl << endl << endl;
    }
    
    return choice;
}