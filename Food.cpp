#include "Food.h"
#include "MacUILib.h"

Food::Food(GameMechs *CurrentMech)
{
    seed();
    foodPos = objPos(1,1,'o');
    currentMech = *CurrentMech;
}

Food::~Food()
{
    
}


void Food::seed()
{
    srand(time(NULL));
}

void Food::generateFood(const objPosArrayList& blockOff)
{
    {
    bool valid = false;
    int randX, randY;

    int maxX = currentMech.getBoardSizeX();
    int maxY = currentMech.getBoardSizeY();

    while (!valid)
    {
        randX = (rand() % (maxX - 2)) + 1;
        randY = (rand() % (maxY - 2)) + 1;

        valid = true; // Assume valid, check for collisions
        for (int i = 0; i < blockOff.getSize(); i++)
        {
            if (randX == blockOff.getElement(i).getObjPos().pos->x &&
                randY == blockOff.getElement(i).getObjPos().pos->y)
            {
                valid = false; // Collision detected, retry
                break;
            }
        }
    }

    foodPos.setObjPos(randX, randY, 'o');
    }
}

objPos Food::getFoodPos() const
{
    return foodPos;
}