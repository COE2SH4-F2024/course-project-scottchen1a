#include "Player.h"
#include "MacUILib.h"




Player::Player(GameMechs* thisGMRef, Food* food)
{
    playerPosList = new objPosArrayList();
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    f = food;
    headInsert = objPos(15,5,'*');
    playerPosList->insertHead(headInsert);
    // playerPos.pos->x = 10;
    // playerPos.pos->y = 5;
    // player.symbol = '*';
    // more actions to be included
}


Player::~Player()
{
    //delete mainGameMechsRef;
    delete playerPosList; 
    playerPosList = nullptr;
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




objPosArrayList& Player::getPlayerPos() const
{
    return *playerPosList;
    // return the reference to the playerPos arrray list
}

int Player::getDirection()
{
    return myDir;
}
void Player::updatePlayerDir()
{

    if(mainGameMechsRef->getInput())  // if not null character
    {
        switch(mainGameMechsRef->getInput())
        {                      
            case ' ':  // exit
                mainGameMechsRef->setExitTrue();
                break;
            case 'w':
            {
                if(myDir == LEFT || myDir == RIGHT || myDir == STOP) 
                {
                    myDir = UP;
                }
                break;
            }
            case 's':
            {
                if(myDir == LEFT || myDir == RIGHT || myDir == STOP) 
                {
                    myDir = DOWN;
                }
                break;
            }
            case 'a':
            {
                if(myDir == UP || myDir == DOWN || myDir == STOP) 
                {
                    myDir = LEFT;
                }
                break;
            }
            case 'd':
            {
                if(myDir == UP || myDir == DOWN || myDir == STOP) 
                {
                    myDir = RIGHT;
                }
                break;
            }
   
            default:
                break;
        }
    }
        // PPA3 input processing logic          
}

void Player::movePlayer()
{
    switch(myDir)
    {
        case UP:
            if(playerPosList->getElement(0).pos->y == 1)
            {
                headInsert = objPos(playerPosList->getElement(0).pos->x,mainGameMechsRef->getBoardSizeY() - 2,'*');
                playerPosList->insertHead(headInsert);
                playerPosList->removeTail();
            }
            else
            {
                headInsert = objPos(playerPosList->getElement(0).pos->x,(playerPosList->getElement(0).pos->y)-1,'*');
                playerPosList->insertHead(headInsert);
                playerPosList->removeTail();
            }
            break;

        case DOWN:
            if(playerPosList->getElement(0).pos->y == mainGameMechsRef->getBoardSizeY() - 2)
            {   
                headInsert = objPos(playerPosList->getElement(0).pos->x,1,'*');
                playerPosList->insertHead(headInsert);
                playerPosList->removeTail();
            }
            else
            {
                headInsert = objPos(playerPosList->getElement(0).pos->x,(playerPosList->getElement(0).pos->y)+1,'*');
                playerPosList->insertHead(headInsert);
                playerPosList->removeTail();
            }
            break;
        
        case LEFT:
            if(playerPosList->getElement(0).pos->x == 1)
            {
                headInsert = objPos(mainGameMechsRef->getBoardSizeX() - 2,(playerPosList->getElement(0).pos->y),'*');
                playerPosList->insertHead(headInsert);
                playerPosList->removeTail();
            }
            else
            {
                headInsert = objPos((playerPosList->getElement(0).pos->x)-1,(playerPosList->getElement(0).pos->y),'*');
                playerPosList->insertHead(headInsert);
                playerPosList->removeTail();
            }
            break;

        case RIGHT:
            if(playerPosList->getElement(0).pos->x == mainGameMechsRef->getBoardSizeX() - 2)
            {
                headInsert = objPos(1,playerPosList->getElement(0).pos->y,'*');
                playerPosList->insertHead(headInsert);
                playerPosList->removeTail();
            }
            else
            {
                headInsert = objPos((playerPosList->getElement(0).pos->x)+1,(playerPosList->getElement(0).pos->y),'*');
                playerPosList->insertHead(headInsert);
                playerPosList->removeTail();
            }
            break;
        case(STOP):
            break;
    }
   
    // PPA3 Finite State Machine logic
}

bool Player::checkFoodConsumption()
{
    bool collision = false;

    if ((playerPosList->getElement(0).pos->x==f->getFoodPos().pos->x) && (playerPosList->getElement(0).pos->y==f->getFoodPos().pos->y))
    {
        collision = true;
    }

    return collision;

}

void Player::addLength()
{
    
    switch(myDir)
    {
        case(UP):
        {
            headInsert = objPos((playerPosList->getElement(0).pos->x),(playerPosList->getElement(0).pos->y)-1,'*');
            playerPosList->insertHead(headInsert);
            break;
        }
        case(DOWN):
        {
            headInsert = objPos((playerPosList->getElement(0).pos->x),(playerPosList->getElement(0).pos->y)+1,'*');
            playerPosList->insertHead(headInsert);
            break;
        }
        case(LEFT):
        {
            headInsert = objPos((playerPosList->getElement(0).pos->x)-1,(playerPosList->getElement(0).pos->y),'*');
            playerPosList->insertHead(headInsert);
                break;
        }
        case(RIGHT):
        {
            headInsert = objPos((playerPosList->getElement(0).pos->x)+1,(playerPosList->getElement(0).pos->y),'*');
            playerPosList->insertHead(headInsert);
            break;
        }
        case(STOP):
            break;
    }

    
}


// More methods to be added