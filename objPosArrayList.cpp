#include "objPosArrayList.h"
#define ARRAY_MAX_CAP 200 //capacity of array list

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP];//allocate memory for array list
    listSize = 0;
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;//deallocate memory for the array list
}

//return current list size
int objPosArrayList::getSize() const
{
    return listSize;
}

//inserts head onto snake
void objPosArrayList::insertHead(objPos thisPos)
{
    if (listSize == ARRAY_MAX_CAP)
    {
        return;
    }

    for (int i = listSize; i > 0; i--)
    {
        aList[i] = aList[i - 1]; //shifts elements to the right
    }
    aList[0] = thisPos; //inserts new element at the beginning
    listSize++; 
}

//inserts tail onto snake
void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize == ARRAY_MAX_CAP)
    {
        // Optionally resize the array here
        return;
    }

    aList[listSize] = thisPos; //inserts new element at the end
    listSize++;
}

//removes head of the snake
void objPosArrayList::removeHead()
{
    if (listSize == 0)
    {
        return;
    }

    for (int i = 0; i < listSize - 1; i++)
    {
        aList[i] = aList[i + 1]; //shifts all elements to the left
    }

    listSize--;
}

//removes tail of snake
void objPosArrayList::removeTail()
{
    if (listSize == 0)
    {
        return;
    }

    listSize--;
}

//gets head element
objPos objPosArrayList::getHeadElement() const
{
    if (listSize > 0)
        return aList[0]; //returns first element
    return objPos(); // Return an empty objPos object if the list is empty
}

//gets tail element
objPos objPosArrayList::getTailElement() const
{
    if (listSize > 0)
        return aList[listSize - 1];//return the last element
    return objPos(); // Return an empty objPos object if the list is empty
}

objPos objPosArrayList::getElement(int index) const
{
    if ((index >= 0) && (index < listSize))
        return aList[index]; //returns element at specified index
    return objPos(); // Return an empty objPos object if the list is empty
}
