#include "Player.h"



Player::Player(GameMechs* thisGMRef)
{
    playerPos = new objPos;
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    player.x = 10;
    player.y = 5;
    player.symbol = '*';
    // more actions to be included
}


Player::~Player()
{
    delete playerPos;
    // delete any heap members here
}

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
            if(player.y == 1)
            {
                player.y = mainGameMechsRef->getBoardSizeY - 1;
            }
            else
            {
                player.y--;
            }
            break;

        case DOWN:
            if(player.y == mainGameMechsRef->getBoardSizeY - 1)
            {
                player.y = 1;
            }
            else
            {
                player.y++;
            }
            break;
        
        case LEFT:
            if(player.x == 1)
            {
                player.x = mainGameMechsRef->getBoardSizeX - 1;
            }
            else
            {
                player.x--;
            }
            break;

        case RIGHT:
            if(player.x == mainGameMechsRef->getBoardSizeX - 1)
            {
                player.x = 1;
            }
            else
            {
                player.x++;
            }
            break;
    }
    // PPA3 Finite State Machine logic
}

// More methods to be added