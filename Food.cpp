#include "Food.h"
#include "MacUILib.h"

//Constructor for food class
Food::Food(GameMechs *CurrentMech)
{
    seed();//Random number generator
    foodPos = objPos(1,1,'o'); //Setting initial position of food object
    GameMechs* currentMech;//declares pointer to GameMechs
}

//destructor
Food::~Food()
{
    
}


void Food::seed()
{
    srand(time(NULL));//seeding the random number generator to guarantee different results
}

//generates a new food position that doesn't collide with blocked positions
void Food::generateFood(const objPosArrayList& blockOff)
{
    {
    bool valid = false;
    int randX, randY;

    int maxX = currentMech.getBoardSizeX();
    int maxY = currentMech.getBoardSizeY();

    while (!valid)
    {
        randX = (rand() % (maxX - 2)) + 1;//random coordinates between 1 and maxY - 1
        randY = (rand() % (maxY - 2)) + 1;

        valid = true; // Assume valid, check for collisions

        //checks for collisions
        for (int i = 0; i < blockOff.getSize(); i++)
        {
            //if generated position matches any blocked position, valid = false
            if (randX == blockOff.getElement(i).getObjPos().pos->x &&
                randY == blockOff.getElement(i).getObjPos().pos->y)
            {
                valid = false; // Collision detected, retry
                break;
            }
        }
    }

    //sets food position to newly generated coordinates
    foodPos.setObjPos(randX, randY, 'o');
    }
}

//gets current food position
objPos Food::getFoodPos() const
{
    return foodPos;
}