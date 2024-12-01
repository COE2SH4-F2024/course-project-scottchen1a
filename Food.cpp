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
    seed();

    bool valid = false;
    int check = 0;

    int randX;
    int randY;

    int maxX = currentMech.getBoardSizeX();
    int maxY = currentMech.getBoardSizeY();

    while(!valid)
    {
        randX = (rand() % (maxX -2))+1;
        randY = (rand() % (maxY -2))+1;

        for (int i = 0; i < blockOff.getSize(); i++)
        {
            if(!(randX == blockOff.getElement(i).getObjPos().pos->x) && !(randY == blockOff.getElement(i).getObjPos().pos->y))
            {
                check++;
            }

        }
        if(check == blockOff.getSize())
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