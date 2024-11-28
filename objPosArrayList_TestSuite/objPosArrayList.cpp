#include "objPosArrayList.h"
#define ARRAY_MAX_CAP 200

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP];
    listSize = 0;
}

objPosArrayList::~objPosArrayList()
{
    if (aList)
        delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if (listSize == ARRAY_MAX_CAP)
    {
        // Optionally resize the array here
        return;
    }

    for (int i = listSize; i > 0; i--)
    {
        aList[i] = aList[i - 1];
    }
    aList[0] = thisPos;
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize == ARRAY_MAX_CAP)
    {
        // Optionally resize the array here
        return;
    }

    aList[listSize] = thisPos;
    listSize++;
}

void objPosArrayList::removeHead()
{
    if (listSize == 0)
    {
        return;
    }

    for (int i = 0; i < listSize - 1; i++)
    {
        aList[i] = aList[i + 1];
    }

    listSize--;
}

void objPosArrayList::removeTail()
{
    if (listSize == 0)
    {
        return;
    }

    listSize--;
}

objPos objPosArrayList::getHeadElement() const
{
    if (listSize > 0)
        return aList[0];
    return objPos();
}

objPos objPosArrayList::getTailElement() const
{
    if (listSize > 0)
        return aList[listSize - 1];
    return objPos();
}

objPos objPosArrayList::getElement(int index) const
{
    if ((index >= 0) && (index < listSize))
        return aList[index];
    return objPos();
}
