#include "Player.h"
#include "MacUILib.h"



//constructor for the player class
Player::Player(GameMechs* thisGMRef, Food* food)
{
    playerPosList = new objPosArrayList();// Initialize the player position list
    mainGameMechsRef = thisGMRef;// Reference to the game mechanics
    myDir = STOP;
    f = food;// Reference to the food object
    headInsert = objPos(15,5,'*');// Create the initial head position of the player
    playerPosList->insertHead(headInsert);// Insert the head position into the player position list
    // playerPos.pos->x = 10;
    // playerPos.pos->y = 5;
    // player.symbol = '*';
    // more actions to be included
}

//destructor
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

//gets direction of current player
int Player::getDirection()
{
    return myDir;
}

//updates players direction
void Player::updatePlayerDir()
{

    if(mainGameMechsRef->getInput())  // if not null character
    {
        switch(mainGameMechsRef->getInput())
        {                      
            case ' ':  // exit
                mainGameMechsRef->setExitTrue();
                break;
            case 'w': //moves up
            {
                if(myDir == LEFT || myDir == RIGHT || myDir == STOP) 
                {
                    myDir = UP;
                }
                break;
            }
            case 's'://moves down
            {
                if(myDir == LEFT || myDir == RIGHT || myDir == STOP) 
                {
                    myDir = DOWN;
                }
                break;
            }
            case 'a'://moves left
            {
                if(myDir == UP || myDir == DOWN || myDir == STOP) 
                {
                    myDir = LEFT;
                }
                break;
            }
            case 'd'://moves right
            {
                if(myDir == UP || myDir == DOWN || myDir == STOP) 
                {
                    myDir = RIGHT;
                }
                break;
            }
   
            default://ignore everything else
                break;
        }
    }
        // PPA3 input processing logic          
}

//moves player based on current direction
void Player::movePlayer()
{
    switch(myDir)
    {
        case UP:
            // wrap-around for up movement
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
            // wrap-around for down movement
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
            // wrap-around for left movement
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
            // wrap-around for right movement
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
        case(STOP): //stops
            break;
    }
   
    // PPA3 Finite State Machine logic
}

//check if the player has consumed food
bool Player::checkFoodConsumption()
{
    bool collision = false;

    //checks if the players head pos matches the food pos
    if ((playerPosList->getElement(0).pos->x==f->getFoodPos().pos->x) && (playerPosList->getElement(0).pos->y==f->getFoodPos().pos->y))
    {
        collision = true;
    }

    return collision;

}

//adds length to the player when food is consumed
void Player::addLength()
{
    
    switch(myDir)
    {
        case(UP):
        {
            //wrap-around for up
            if((playerPosList->getElement(0).pos->y) == 1)
            {
                headInsert = objPos((playerPosList->getElement(0).pos->x),mainGameMechsRef->getBoardSizeY()-2,'*');
                playerPosList->insertHead(headInsert);
                break;
            }
            else
            {
                headInsert = objPos((playerPosList->getElement(0).pos->x),(playerPosList->getElement(0).pos->y)-1,'*');
                playerPosList->insertHead(headInsert);
                break;
            }
            
        }
        case(DOWN):
        {
            //wrap-around for down
            if((playerPosList->getElement(0).pos->y) == mainGameMechsRef->getBoardSizeY()-2)
            {
                headInsert = objPos((playerPosList->getElement(0).pos->x),1,'*');
                playerPosList->insertHead(headInsert);
                break;
            }
            else
            {
                headInsert = objPos((playerPosList->getElement(0).pos->x),(playerPosList->getElement(0).pos->y)+1,'*');
                playerPosList->insertHead(headInsert);
                break;
            }
        }
        case(LEFT):
        {
            //wrap-around for left
            if((playerPosList->getElement(0).pos->x) == 1)
            {
                headInsert = objPos((mainGameMechsRef->getBoardSizeX()-2),(playerPosList->getElement(0).pos->y),'*');
                playerPosList->insertHead(headInsert);
                break;
            }
            else
            {
                headInsert = objPos((playerPosList->getElement(0).pos->x)-1,(playerPosList->getElement(0).pos->y),'*');
                playerPosList->insertHead(headInsert);
                break;
            }
        }
        case(RIGHT):
        {
            //wrap-around for right
            if((playerPosList->getElement(0).pos->x) == (mainGameMechsRef->getBoardSizeX()-2))
            {
                headInsert = objPos(1,(playerPosList->getElement(0).pos->y),'*');
                playerPosList->insertHead(headInsert);
                break;
            }
            else
            {
                headInsert = objPos((playerPosList->getElement(0).pos->x)+1,(playerPosList->getElement(0).pos->y),'*');
                playerPosList->insertHead(headInsert);
                break;
            }
        }
        case(STOP):
            break;
    }

    
}


//checks if the player has lost by colliding with itself
bool Player::checkLoss()
{
    bool valid = true; // Assume valid, check for collisions
        for (int i = 1; i < playerPosList->getSize(); i++)
        {
            //checks if the players head position matches any of its body segments
            if (playerPosList->getElement(0).pos->x == playerPosList->getElement(i).pos->x && playerPosList->getElement(0).pos->y == playerPosList->getElement(i).pos->y)
            {
                valid = false; // Collision detected, retry
                break;
            }
        }
    return valid;
}


// More methods to be added