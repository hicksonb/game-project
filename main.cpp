/******************************************************************************
** Program name: main.cpp - Metroid
** Author: Bryce Hickson
** Date: 03/19/2019
** Description: This is the main program for Metroid. It runs an 
** interactive platforming game.
** Credits: 
** Metroid IP: I do not own the rights for Metroid. Metroid IP belongs to 
** Nintendo. This game will not be sold, it's just for fun.
** Title Graphic: The title graphic was generated with the help of the 
** following website - 
** http://patorjk.com/software/taag/#p=display&f=Big&t=METROID
*******************************************************************************/

#include <iostream>

#include "input.hpp"
#include "space.hpp"
#include "spacematrix.hpp"
#include "inventory.hpp"

using std::cout;
using std::endl;

int main()
{
    int mainChoice = 0;

    mainChoice = mainMenu();
    
    while (mainChoice != 2)
    {
        SpaceMatrix* metroid = new SpaceMatrix;
        int controlChoice = 0;
        int gameStatus = 0;
        
        metroid -> printStats();
        metroid -> print();
        
        while (gameStatus == 0)
        {
            metroid -> printOptions();
            controlChoice = getInt(0, 9);
            
            for (int count = 0; count < 25; count++)
            {
                cout << endl << endl << endl << endl;
            }
            
            switch(controlChoice)
            {
                case 8:
                    metroid -> up();
                    break;
                case 7:
                    metroid -> up();
                    break;
                case 9:
                    metroid -> up();
                    break;
                case 4:
                    metroid -> left();
                    break;
                case 6:
                    metroid -> right();
                    break;
                case 5:
                    metroid -> down();
                    break;
                case 1:
                    metroid -> checkUnder();
                    break;
                case 2:
                    metroid -> grabUnder();
                    break;
                case 3:
                    metroid -> openInventory();
                    break;
                case 0:
                    metroid -> quit();
                    break;
                default:
                    break;
            }
            
            gameStatus = metroid -> getGameStatus();
            
            metroid -> printStats();
            metroid -> print();
        }
        
        delete metroid;
        metroid = nullptr;
        
        if (gameStatus == 3)
        {
            cout << "MISSION FAILED" << endl;
        }
        
        if (gameStatus == 2)
        {
            cout << "MISSION FAILED" << endl;
        }
        
        if (gameStatus == 1)
        {
            cout << "SAMUS LIVES ANOTHER DAY" << endl;
        }
        
        mainChoice = replayMenu();
        
    }
    
    return 0;
}