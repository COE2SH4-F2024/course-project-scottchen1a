#include "GameMechs.h"
#include "MacUILib.h"

//default constructor for GameMechs
GameMechs::GameMechs()
{
    //initialize board size, input, flags, score
    boardSizeX = 30;
    boardSizeY = 15;
    input = 0;
    exitFlag = 0;
    loseFlag = 0;
    score = 0;
}

//constructor with parameters
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

// gets exitflag status
bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

//gets loseflag status
bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    
//gets current input character
char GameMechs::getInput() const
{
    return input;
}

//gets current score
int GameMechs::getScore() const
{
    return score;
}

//increments score by 1
void GameMechs::incrementScore()
{
    score++;
}

//gets the width of the game board
int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

//gets the height of the game board
int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}

//sets exitflag to true
void GameMechs::setExitTrue()
{   
    exitFlag = true;
}

//sets loseflag to true
void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

//sets current input character
void GameMechs::setInput(char this_input)
{
    input = this_input;
}

//clears current input character
void GameMechs::clearInput()
{
    input = 0;
}

//dynamically allocating a game board
void GameMechs::makeGameBoard(char **&array)
{
    array = new char*[boardSizeY];//allocating memory
    int i;

    //loop for allocating memory for each row of the board
    for(i = 0; i<(boardSizeY); i++) 
    {
        array[i] = new char[boardSizeX];
    }
}

// More methods should be added here