#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    boardSizeX = 30;
    boardSizeY = 15;
    input = 0;
    exitFlag = 0;
    loseFlag = 0;
    score = 0;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;
    input = 0;
    exitFlag = 0;
    loseFlag = 0;
    score = 0;
}

// d o you need a destructor?
GameMechs::~GameMechs()
{
    
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput() const
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{   
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

void GameMechs::makeGameBoard(char **&array)
{
    array = new char*[boardSizeY];
    int i;

    for(i = 0; i<(boardSizeY); i++)
    {
        array[i] = new char[boardSizeX];
    }
}

// More methods should be added here