/*********************************************************************
** Program name: spacematrix.cpp
** Author: Bryce Hickson
** Date: 03/19/2019
** Description: This is the implementation file for the SpaceMatrix 
** class. This class represents a 2D board of Space objects for the 
** Metroid game. The functions support the gameplay for the game.
*********************************************************************/

#include <iostream>
#include <string>
#include <iomanip>

#include "space.hpp"
#include "spacematrix.hpp"
#include "input.hpp"

using std::cout;
using std::endl;
using std::string;
using std::setw;

/*********************************************************************
** Description: Default constructor that creates level.
*********************************************************************/

SpaceMatrix::SpaceMatrix()
{
    this -> head = nullptr;
    
    Space* topSpace = nullptr;
    Space* leftSpace = nullptr;
    
    Space* currentHead = nullptr;
    Space* newRowHead = nullptr;
    Space* newSpace = nullptr;
    
    // Creates matrix of level size made of Blocks
    for (int count1 = 0; count1 < ROWS; count1++)
    {
        if (head == nullptr)
        {
            head = new Block(nullptr, nullptr, nullptr, nullptr);
            newRowHead = head;
        }
        else
        {
            newRowHead = new Block(currentHead, nullptr, nullptr, nullptr);
            currentHead -> setBottom(newRowHead);
            topSpace = currentHead -> getRight();
        }
        
        currentHead = newRowHead;
        leftSpace = currentHead;
        
        for (int count2 = 0; count2 < COLS - 1; count2++)
        {
            newSpace = new Block(topSpace, nullptr, leftSpace, nullptr);
            
            if (topSpace != nullptr)
            {
                topSpace -> setBottom(newSpace);
                topSpace = topSpace -> getRight();
            }
            
            leftSpace -> setRight(newSpace);
            leftSpace = newSpace;
            newSpace = nullptr;
        }
    }
    
    topSpace = nullptr;
    leftSpace = nullptr;
    currentHead = nullptr;
    newRowHead = nullptr;
    newSpace = nullptr;
    
    // Map is filled into matrix, player is created
    loadLevel();
    
    // Inventory is created
    items = new Inventory;
}


/*********************************************************************
** Description: Destructor that deletes level and prevents memory 
** leaks.
*********************************************************************/

SpaceMatrix::~SpaceMatrix()
{
    Space* currentSpace = nullptr;
    Space* nextSpace = nullptr;
    Space* nextHead = nullptr;
    
    // Deletes matrix
    currentSpace = head;
    nextHead = head -> getBottom();
    
    while (currentSpace != nullptr)
    {
        if (currentSpace -> getRight() != nullptr)
        {
            nextSpace = currentSpace -> getRight();
        }
        else
        {
            if (nextHead != nullptr)
            {
                nextSpace = nextHead;
                nextHead = nextHead -> getBottom();
            }
            else
            {
                nextSpace = nextHead;
            }
        }
        
        delete currentSpace;
        currentSpace = nextSpace;
    }
    
    // Deletes player
    delete player;
    player = nullptr;
    
    // Deletes inventory
    delete items;
    items = nullptr;
}

/*********************************************************************
** Description: Replaces all Space objects with Space objects 
** determined by the chars in a string.
*********************************************************************/

void SpaceMatrix::loadLevel()
{
    string level = 
    "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT  "
    "T                   TT           ^         "
    "T          *       TTTT                  O "
    "T K  M M  M M     TTTTTT       M M M Q HTTT"
    "TTTTTTHTTTTTTTTHTTTTTTTTHTT * HTTTHTTTTTTTT"
    "T     H        H  TTTTTTHTTTTTT           T"
    "T  *  H        H   TT   HTTTTTT      ^    T"
    "T       ^      H    T   HTTTTTT      M    T"
    "TTTHTTTTTTT  M   M      HTTTTTTTHTTTTTH   T"
    "T     *     HTTTTTH     H       H     H * T"
    "T *          TTTTTH     H    ^        H C T"
    "T M M J M M  TTTTTH  M  H    M        TTTTT"
    "TTTTTTTTTTTTTTTTTTTTTTTTHTTTTTTTTT     TTTT"
    "TT                      H              TTTT"
    "TT S         *       *  H           * TTTTT"
    "TTTTT  M  HTTTTTT    M  H  ^  M M HTTTTTTTT"
    "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT";
    int count = 0;
    Space* currentSpace = nullptr;
    Space* nextSpace = nullptr;
    Space* nextHead = nullptr;
    char loadSpace;
    
    // Replaces all Space objects with Space objects that match type in string
    currentSpace = head;
    nextHead = head -> getBottom();
    
    while (currentSpace != nullptr)
    {
        loadSpace = level.at(count);
        count++;
        
        currentSpace = replace(currentSpace, loadSpace);
        
        if (currentSpace -> getRight() != nullptr)
        {
            nextSpace = currentSpace -> getRight();
        }
        else
        {
            if (nextHead != nullptr)
            {
                nextSpace = nextHead;
                nextHead = nextHead -> getBottom();
            }
            else
            {
                nextSpace = nextHead;
            }
        }
        
        if (currentSpace -> getRight() == nullptr)
        {
            cout << endl;
        }
        
        currentSpace = nextSpace;
    }
}

/*********************************************************************
** Description: Replaces a Space object with a different type of 
** Space object, determined by a passed char.
*********************************************************************/

Space* SpaceMatrix::replace(Space* currentSpace, char newType)
{
    bool headCheck = false;
    Space* newSpace;
    Space* topSpace = currentSpace -> getTop();
    Space* rightSpace = currentSpace -> getRight();
    Space* leftSpace = currentSpace -> getLeft();
    Space* bottomSpace = currentSpace -> getBottom();
    
    if (currentSpace == head)
    {
        headCheck = true;
    }
    else
    {
        headCheck = false;
    }
    
    switch (newType)
    {
        case 'S':
            // Creates an Empty object in matrix, has player point to it
            newSpace = new Empty(topSpace, rightSpace, leftSpace, bottomSpace);
            this -> player = new Player();
            player -> setUnder(newSpace);
            break;
        case ' ':
            newSpace = new Empty(topSpace, rightSpace, leftSpace, bottomSpace);
            break;
        case 'T':
            newSpace = new Block(topSpace, rightSpace, leftSpace, bottomSpace);
            break;
        case 'H':
            newSpace = new Ladder(topSpace, rightSpace, leftSpace, bottomSpace);
            break;
        case '*':
            newSpace = new Health(topSpace, rightSpace, leftSpace, bottomSpace);
            break;
        case '^':
            newSpace = new Missile(topSpace, rightSpace, leftSpace, bottomSpace);
            break;
        case 'J':
            newSpace = new Jump(topSpace, rightSpace, leftSpace, bottomSpace);
            break;
        case 'C':
            newSpace = new Charge(topSpace, rightSpace, leftSpace, bottomSpace);
            break;
        case 'K':
            newSpace = new Key(topSpace, rightSpace, leftSpace, bottomSpace);
            break;
        case 'M':
            newSpace = new Metroid(topSpace, rightSpace, leftSpace, bottomSpace);
            break;
        case 'Q':
            newSpace = new Queen(topSpace, rightSpace, leftSpace, bottomSpace);
            break;
        case 'O':
            newSpace = new Ship(topSpace, rightSpace, leftSpace, bottomSpace);
            break;
        default:
            newSpace = new Empty(topSpace, rightSpace, leftSpace, bottomSpace);
            break;
    }

    if (topSpace != nullptr)
    {
        topSpace -> setBottom(newSpace);
    }
    
    if (rightSpace != nullptr)
    {
        rightSpace -> setLeft(newSpace);
    }
    
    if (leftSpace != nullptr)
    {
        leftSpace -> setRight(newSpace);
    }
    
    if (bottomSpace != nullptr)
    {
        bottomSpace -> setTop(newSpace);
    }

    if (headCheck == true)
    {
        this -> head = newSpace;
    }

    delete currentSpace;
    currentSpace = nullptr;
    
    return newSpace;
}

/*********************************************************************
** Description: Performs the up action on player.
*********************************************************************/

void SpaceMatrix::up()
{
    Space* underSpace = player -> getUnder();
    Space* topSpace = underSpace -> getTop();
    
    // Reset jumps based on land and ladders
    if (underSpace -> getType() == 'H' 
        || underSpace -> getBottom() -> getType() == 'H'
        || underSpace -> getBottom() -> getType() == 'T')
    {
        player -> jumpLanded();
    }
    
    if (player -> getJumpMax() > player -> getJumpUsed())
    {
        // Cannot move into block
        if (topSpace -> getType() == 'T')
        {
            cout << "You cannot move there!" << endl;
        }
        else
        {
            player -> changeHealth(STEP_DAMAGE);
            player -> setUnder(topSpace);
            player -> incJumpUsed();
        }
    }
    else
    {
        cout << "You cannot jump higher!" << endl;
    }
}

/*********************************************************************
** Description: Performs the right action on player.
*********************************************************************/

void SpaceMatrix::right()
{
    Space* underSpace = player -> getUnder();
    Space* rightSpace = underSpace -> getRight();

    // Next to enemy
    if (rightSpace -> getType() == 'M' || rightSpace -> getType() == 'Q')
    {
        combat(rightSpace);
    }
    // Next to Ship
    else if (rightSpace -> getType() == 'O')
    {
        bool hasKey = false;
        
        if (items -> checkFor('K') == true)
        {
            player -> setUnder(rightSpace);
        }
        else
        {
            cout << "You need the key to board the ship!" << endl;
        }
    }
    else
    {
        // Only move on Blocks
        if (underSpace -> getBottom() -> getType() == 'T' 
            || underSpace -> getType() == 'H' 
            || underSpace -> getBottom() -> getType() == 'H')
        {
            player -> jumpLanded();
            
            if (rightSpace -> getType() == 'T')
            {
                cout << "You cannot move there!" << endl;
            }
            else
            {
                player -> changeHealth(STEP_DAMAGE);
                player -> setUnder(rightSpace);
            }
        }
        else
        {
            cout << "You cannot move in the air!" << endl;
        }
    }
}

/*********************************************************************
** Description: Performs the left action on player.
*********************************************************************/

void SpaceMatrix::left()
{
    Space* underSpace = player -> getUnder();
    Space* leftSpace = underSpace -> getLeft();

    // Next to enemy
    if (leftSpace -> getType() == 'M' || leftSpace -> getType() == 'Q')
    {
        combat(leftSpace);
    }
    else
    {
        // Only move on Blocks
        if (underSpace -> getBottom() -> getType() == 'T'
            || underSpace -> getType() == 'H' 
            || underSpace -> getBottom() -> getType() == 'H')
        {
            player -> jumpLanded();
            
            if (leftSpace -> getType() == 'T')
            {
                cout << "You cannot move there!" << endl;
            }
            else
            {
                player -> changeHealth(STEP_DAMAGE);
                player -> setUnder(leftSpace);
            }
        }
        else
        {
            cout << "You cannot move in the air!" << endl;
        }
    }
}

/*********************************************************************
** Description: Performs the down action on player.
*********************************************************************/

void SpaceMatrix::down()
{
    Space* underSpace = player -> getUnder();
    Space* downSpace = underSpace -> getBottom();
    
    // Reset jumps based on land and ladders
    if (underSpace -> getBottom() -> getType() == 'T'
        || underSpace -> getType() == 'H' 
        || underSpace -> getBottom() -> getType() == 'H')
    {
        player -> jumpLanded();
    }
    
    // Cannot move into block
    if (downSpace -> getType() == 'T')
    {
        cout << "You cannot move there!" << endl;
    }
    else
    {
        player -> changeHealth(STEP_DAMAGE);
        player -> setUnder(downSpace);
    }
}

/*********************************************************************
** Description: Prints a desciption of the Space the player is at.
*********************************************************************/

void SpaceMatrix::checkUnder()
{
    char charUnder;
    Space* underSpace = player -> getUnder();
    
    charUnder = underSpace -> getType();
    
    switch (charUnder)
    {
        case ' ':
            cout << "There is nothing here." << endl;
            break;
        case 'H':
            cout << "You are on a ladder. Reach new heights!" << endl;
            break;
        case '*':
            cout << "An Energy Tank! Heals 100 health upon use." << endl;
            break;
        case '^':
            cout << "A Missile Tank! Boosts your next attack by 100 upon use." << endl;
            break;
        case 'J':
            cout << "High Jump Boots! They will allow you to jump higher." << endl;
            break;
        case 'C':
            cout << "The Charge Shot! All your attacks will increase in power!" << endl;
            break;
        case 'K':
            cout << "The Key! You'll need this to board your ship." << endl;
            break;
        default:
            cout << "To be honest, I'm not sure what this is..." << endl;
            break;
    }
}

/*********************************************************************
** Description: Performs the grab action on player. Adds the item 
** represented in the Space the player is on to the Inventory, then 
** changes the Space under the player to Empty.
*********************************************************************/

void SpaceMatrix::grabUnder()
{
    char charUnder;
    Space* underSpace = player -> getUnder();
    
    charUnder = underSpace -> getType();
    
    if (items -> isFull() == false)
    {
        switch (charUnder)
        {
            case ' ':
                cout << "There is nothing here." << endl;
                break;
            case 'H':
                cout << "You are on a ladder. You cannot take this with you." << endl;
                break;
            case '*':
                items -> addItem('*');
                items -> print();
                underSpace = replace(underSpace, ' ');
                player -> setUnder (underSpace);
                break;
            case '^':
                items -> addItem('^');
                items -> print();
                underSpace = replace(underSpace, ' ');
                player -> setUnder (underSpace);
                break;
            case 'J':
                items -> addItem('J');
                items -> print();
                underSpace = replace(underSpace, ' ');
                player -> setUnder (underSpace);
                
                player -> incJumpMax();
                cout << "You can now double jump!" << endl;
                
                break;
            case 'C':
                items -> addItem('C');
                items -> print();
                underSpace = replace(underSpace, ' ');
                player -> setUnder (underSpace);
                
                player -> changeBasePower(CHARGE_VAL);
                cout << "Your base attack power has increased to " 
                << player -> getBasePower() << "!" << endl;
                
                player -> changePower(CHARGE_VAL);
                
                break;
            case 'K':
                items -> addItem('K');
                items -> print();
                underSpace = replace(underSpace, ' ');
                player -> setUnder (underSpace);
                cout << "You have the key to the ship!" << endl;
                break;
            default:
                cout << "I'm not sure what this is... So you can't have it." << endl;
                break;
        }
    }
    else
    {
        cout << "Your inventory is full. Use an item to open space." << endl;
    }
}

/*********************************************************************
** Description: Performs the open inventory action. Shows user items 
** in the Inventory and allows user to select one to use.
*********************************************************************/

void SpaceMatrix::openInventory()
{
    int selection = 0;
    char itemSelected = ' ';
    
    printStats();
    print();
    items -> print();
    cout << endl << endl << endl << endl;
    cout << "Enter the number of the item you would like " << endl;
    cout << "to use, or 6 to close inventory: ";
    selection = getInt(1, 6);
    for (int count = 0; count < 25; count++)
    {
        cout << endl << endl << endl << endl;
    }
    
    while (selection > 0 && selection < 6)
    {
        itemSelected = items -> getItem(selection);
        
        switch (itemSelected)
        {
            case ' ':
                cout << "There is nothing in that slot." << endl;
                break;
            case '*':
                player -> changeHealth(HEALTH_PACK_VAL);
                cout << "Your health has increased by " << HEALTH_PACK_VAL << "!" << endl;
                break;
            case '^':
                player -> changePower(MISSILE_VAL);
                cout << "The power of your next attack is increased by " << MISSILE_VAL << "!" << endl;
                break;
            case 'J':
                cout << "This item is already equipped and cannot be dropped." << endl;
                items -> addItem(itemSelected);
                break;
            case 'C':
                cout << "This item is already equipped and cannot be dropped." << endl;
                items -> addItem(itemSelected);
                break;
            case 'K':
                cout << "This item is already equipped and cannot be dropped." << endl;
                items -> addItem(itemSelected);
                break;
            default:
                cout << "I'm not sure what this is... Returned back to inventory." << endl;
                items -> addItem(itemSelected);
                break;
        }
        
        selection = 6;
    }
}

/*********************************************************************
** Description: Performs combat between player and passed Space 
** object. Player attacks first, enemy attacks back if it survived.
*********************************************************************/

void SpaceMatrix::combat(Space* enemyIn)
{
    int enemyHealth;
    int damageRecieved;
    enemyIn -> changeHealth(0 - (player -> attack()));
    enemyHealth = enemyIn -> getHealth();
    
    if (enemyHealth > 0)
    {
        if (enemyIn -> getType() == 'M')
        {
            cout << "METROID HEALTH: " << enemyHealth;
        }
        
        if (enemyIn -> getType() == 'Q')
        {
            cout << "QUEEN HEALTH: " << enemyHealth;
        }
        
        damageRecieved = enemyIn -> attack();
        player -> changeHealth(0 - (damageRecieved));
        cout << "\tDAMAGE RECIEVED: " << damageRecieved << endl;
    }
    else
    {
        if (enemyIn -> getType() == 'M')
        {
            cout << "METROID DEFEATED" << endl;
            enemyIn = replace(enemyIn, ' ');
        }
        
        if (enemyIn -> getType() == 'Q')
        {
            cout << "QUEEN DEFEATED" << endl;
            enemyIn = replace(enemyIn, '*');
        }
    }
}

/*********************************************************************
** Description: Prints stats of player.
*********************************************************************/

void SpaceMatrix::printStats()
{
    cout << "POWER: " << player -> getPower();
    cout << "\t\tHEALTH: " << player -> getHealth();
    cout << endl;
}

/*********************************************************************
** Description: Prints the level.
*********************************************************************/

void SpaceMatrix::print()
{
    Space* currentSpace = nullptr;
    Space* nextSpace = nullptr;
    Space* nextHead = nullptr;
    
    currentSpace = head;
    nextHead = head -> getBottom();
    
    while (currentSpace != nullptr)
    {
        if (currentSpace -> getRight() != nullptr)
        {
            nextSpace = currentSpace -> getRight();
        }
        else
        {
            if (nextHead != nullptr)
            {
                nextSpace = nextHead;
                nextHead = nextHead -> getBottom();
            }
            else
            {
                nextSpace = nextHead;
            }
        }
        
        if (player -> getUnder() == currentSpace)
        {
            cout << player -> getType();
        }
        else
        {
            cout << currentSpace -> getType();
        }
        
        if (currentSpace -> getRight() == nullptr)
        {
            cout << endl;
        }
        
        currentSpace = nextSpace;
    }
    
    cout << endl;
    
}

/*********************************************************************
** Description: Prints the control options for user.
*********************************************************************/

void SpaceMatrix::printOptions()
{
    int upVal;
    int rightVal;
    int leftVal;
    int downVal;
    int checkVal;
    int getVal;
    int invVal;
    int quitVal;
    
    string upOpt = "Jump          ";
    string rightOpt = "Move Right    ";
    string leftOpt = "Move Left     ";
    string downOpt = "Fall          ";
    string checkOpt = "Check Space   ";
    string getOpt = "Grab          ";
    string invOpt = "Open Inventory";
    string quitOpt = "Quit Game     ";
    
    if (controls == 1)
    {
        upVal = 8;
        rightVal = 6;
        leftVal = 4;
        downVal = 5;
        checkVal = 1;
        getVal = 2;
        invVal = 3;
        quitVal = 0;
    }
    
    Space* underSpace = player -> getUnder();
    Space* topSpace = underSpace -> getTop();
    Space* rightSpace = underSpace -> getRight();
    Space* leftSpace = underSpace -> getLeft();
    Space* downSpace = underSpace -> getBottom();
    
    if (underSpace -> getType() == 'H')
    {
        upOpt = "Climb Up      ";
        downOpt = "Climb Down    ";
    }
    
    if (rightSpace -> getType() == 'M')
    {
        rightOpt = "Attack Metroid";
    }
    
    if (leftSpace -> getType() == 'M')
    {
        leftOpt = "Attack Metroid";
    }
    
    if (rightSpace -> getType() == 'Q')
    {
        rightOpt = "Attack Queen  ";
    }
    
    if (leftSpace -> getType() == 'Q')
    {
        leftOpt = "Attack Queen  ";
    }
    
    if (rightSpace -> getType() == 'O')
    {
        rightOpt = "Board Ship    ";
    }
    
    if (leftSpace -> getType() == 'O')
    {
        leftOpt = "Board Ship    ";
    }
    
    cout << setw(27) << "Controls:" << endl;
    
    cout << setw(19) << upVal << ". " << upOpt << endl;
    cout << leftVal << ". " << leftOpt << setw(2) << downVal << ". " << downOpt << setw(2) << rightVal << ". " << rightOpt << endl;
    cout << checkVal << ". " << checkOpt << setw(2) << getVal << ". " << getOpt << setw(2) << invVal << ". " << invOpt << endl;
    cout << setw(19) << quitVal << ". " << quitOpt << endl;
    cout << endl;
    cout << "Enter your choice: ";
}

/*********************************************************************
** Description: Returns the int of the game's status. 0 for ongoing, 
** 1 for winning, 2 for losing, 3 for quitting.
*********************************************************************/

int SpaceMatrix::getGameStatus()
{
    if (player -> getHealth() <= 0)
    {
        gameStatus = 2;
    }
    
    if (player -> getUnder() -> getType() == 'O')
    {
        // Make player look like Ship
        player -> setType('O');
        
        // Remove ship
        Space* underSpace = player -> getUnder();

        underSpace = replace(underSpace, ' ');
        player -> setUnder (underSpace);
        
        // Move ship up
        up();
        
        gameStatus = 1;
    }
    
    return gameStatus;
}

/*********************************************************************
** Description: Sets gameStatus to quit status (3).
*********************************************************************/

void SpaceMatrix::quit()
{
    gameStatus = 3;
}