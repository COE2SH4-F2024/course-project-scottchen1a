#include "Player.h"



Player::Player(GameMechs* thisGMRef)
{
    playerPos = objPos();
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    objPos playerPos(10, 5, '*');
    // playerPos.pos->x = 10;
    // playerPos.pos->y = 5;
    // player.symbol = '*';
    // more actions to be included
}


Player::~Player()
{
    delete[] mainGameMechsRef;
    //delete[] playerPos;
    // delete any heap members here
}




//add copy constructor and assignment operator

// //Copy Constructor
// Player::Player(const Player& p)
// {
//     playerPos = new objPos;

// }

// //Copy Assignment Operator
// Player& Player::operator=(const Player& p)
// {

// }




objPos Player::getPlayerPos() const
{
    return playerPos;
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput();

    if(input != 0)  // if not null character
    {
        switch(input)
        {                      
            case ' ':  // exit
                // lose = 1;
                // exitFlag = 1;
                mainGameMechsRef->setExitTrue();
                break;
            case 'w':
            {
                if(myDir == LEFT || myDir == RIGHT) 
                {
                    myDir = UP;
                }
                break;
            }
            case 's':
            {
                if(myDir == LEFT || myDir == RIGHT) 
                {
                    myDir = DOWN;
                }
                break;
            }
            case 'a':
            {
                if(myDir == UP || myDir == DOWN) 
                {
                    myDir = LEFT;
                }
                break;
            }
            case 'd':
            {
                if(myDir == UP || myDir == DOWN) 
                {
                    myDir = RIGHT;
                }
                break;
            }
   
            default:
                break;
        }
        input = 0;
    }
        // PPA3 input processing logic          
}

void Player::movePlayer()
{
    switch(myDir)
    {
        case UP:
            if(playerPos.pos->y == 1)
            {
                playerPos.pos->y = mainGameMechsRef->getBoardSizeY() - 2;
            }
            else
            {
                playerPos.pos->y--;
            }
            break;

        case DOWN:
            if(playerPos.pos->y == mainGameMechsRef->getBoardSizeY() - 2)
            {
                playerPos.pos->y = 1;
            }
            else
            {
                playerPos.pos->y++;
            }
            break;
        
        case LEFT:
            if(playerPos.pos->x == 1)
            {
                playerPos.pos->x = mainGameMechsRef->getBoardSizeX() - 2;
            }
            else
            {
                playerPos.pos->x--;
            }
            break;

        case RIGHT:
            if(playerPos.pos->x == mainGameMechsRef->getBoardSizeX() - 2)
            {
                playerPos.pos->x = 1;
            }
            else
            {
                playerPos.pos->x++;
            }
            break;
    }
   
    // PPA3 Finite State Machine logic
}

// More methods to be added