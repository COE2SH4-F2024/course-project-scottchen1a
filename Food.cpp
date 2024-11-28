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
    delete foodPos.pos;
}


void Food::seed()
{
    srand(time(NULL));
}

void Food::generateFood(const objPos& blockOff)
{
    seed();

    bool valid = false;

    int randX;
    int randY;

    int maxX = currentMech.getBoardSizeX();
    int maxY = currentMech.getBoardSizeY();

    while(!valid)
    {
        randX = (rand() % maxX -2)+1;
        randY = (rand() % maxY -2)+1;

        if(!(blockOff.pos->x == randX) && !(blockOff.pos->y == randY))
        {
            valid = true;
        }
    }

    foodPos.setObjPos(randX,randY,'o');

}

objPos Food::getFoodPos() const
{
    return foodPos;
}