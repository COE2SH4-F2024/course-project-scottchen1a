#include "objPos.h"

//default constructor for ObjPos
objPos::objPos()
{ 
    pos = new Pos; //dynamically allocating memory for Pos
    pos->x = 0; //initializing coordinates
    pos->y = 0;
    symbol = 0; //sets the symbol to NULL
}

//constructor with parameters
objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos; //dynamically allocating memory for Pos
    pos->x = xPos; //sets coordinates
    pos->y = yPos;
    symbol = sym; //sets symbol
}

// Respect the rule of six / minimum four
// [TODO] Implement the missing special member functions to meet the minimum four rule



//Destructor Implemented
objPos::~objPos()
{
    delete pos;
}

//Copy Constructor Implemented
objPos::objPos(const objPos& o)
{
    pos = new Pos;
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

//Copy Assignment Operator Implemented
objPos& objPos::operator=(const objPos& o)
{
    if(this != &o) //checks for self-assignment
    {
        if(pos) //if pos is allocated, delete it
        {
            delete pos;
        }

        pos = new Pos;
        pos->x = o.pos->x;
        pos->y = o.pos->y;
        symbol = o.symbol;
    }
    return *this; //returns current object
}


//sets position and symbol using another objPos object
void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

//sets position and symbol using individual values
void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

//gets current objPos object
objPos objPos::getObjPos() const 
{
    return *this;
}

//gets current symbol
char objPos::getSymbol() const
{
    return symbol;
}

//checks if current position equals refPos
bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y); //returns true if both coordinates match
}

//returns symbol if current position equals refPos
char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))//checks if positions are equal
        return symbol;
    else
        return 0;
}
