#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

class Food
{
    private:
    
    objPos foodPos;

    public:

    //CONSTRUCTORS AND DESTRUCTORS
    Food();
    Food(int num);
    ~Food();
    //---------------------------


    void generateFood(objPos blockOff);
    objPos getFoodPos() const;
    void seed();


};

#endif