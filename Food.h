#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"

using namespace std;

class Food
{
    private:
    
    objPos foodPos;

    GameMechs currentMech;

    public:

    //CONSTRUCTOR AND DESTRUCTOR
    Food(GameMechs *CurrentMech);
    ~Food();
    //---------------------------


    void generateFood(const objPosArrayList& blockOff);
    objPos getFoodPos() const;
    void seed();


};

#endif