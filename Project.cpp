#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Food.h"
#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

GameMechs *board;
Player *p;
Food *f;

char **gameBoard = NULL;


int main(void)
{

    Initialize();

    while((board->getExitFlagStatus() == false))  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    //Creates all objects needed for runtime on the heap
    board = new GameMechs();
    f = new Food(board);
    p = new Player(board,f);
    f->generateFood(p->getPlayerPos());
    //---------------------

    //Makes an array for the gameboard depening on the constuctor used
    board->makeGameBoard(gameBoard);
    //-----------------------

}

void GetInput(void)
{
    int tempInp = 0;
    if (MacUILib_hasChar())
    {
        tempInp = MacUILib_getChar();
    }
    board->setInput(tempInp);
}

void RunLogic(void)
{
    switch(board->getInput())
    {
        case 'q': //debug key for incrementing score
            board->incrementScore();
            break;
        case 'f':
            f->generateFood(p->getPlayerPos());
            break;
    }

    p->updatePlayerDir();
    p->movePlayer();

    if (!p->checkLoss())
    {   
        board->setLoseFlag();
        board->setExitTrue();
    }
    
    if (p->checkFoodConsumption())
    {
        board->incrementScore();
        p->addLength();

        f->generateFood(p->getPlayerPos());

    }

    board->clearInput();

    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    

    // int xBoundary = board->getBoardSizeX();
    // int yBoundary = board->getBoardSizeY();
    // int i, j;

   
    // MacUILib_printf("W = Up, A = Left, S = Down, D = Right, SPACE = Stop");
    objPos head = p->getPlayerPos().getHeadElement();
    objPos food = f->getFoodPos();

    // Debugging
    MacUILib_printf("Head Position: (%d, %d)\n", head.pos->x, head.pos->y);
    MacUILib_printf("Food Position: (%d, %d)\n", food.pos->x, food.pos->y);
    MacUILib_printf("\nScore: %d", board->getScore());
    MacUILib_printf("\nFood Position: %d %d", f->getFoodPos().pos->x, f->getFoodPos().pos->y);
    MacUILib_printf("\nPlayer Position : %d %d", p->getPlayerPos().getElement(0).getObjPos().pos->x,p->getPlayerPos().getElement(0).getObjPos().pos->y);
    MacUILib_printf("\n");

    // Populating Game Board
    for (int row = 0; row < board->getBoardSizeY(); row++)
    {

        for (int column = 0; column < board->getBoardSizeX(); column++)
        {

            if (row == 0 || (row == board->getBoardSizeY() - 1 )) // Header and Footer
            {
                gameBoard[row][column] = '#';
            }

            else if ((column == 0) || (column == board->getBoardSizeX() - 1 )) // Sides
            {
                gameBoard[row][column] = '#';
            }


            // Accessing Food Items
            
            else if (row == f->getFoodPos().pos->y && column == f->getFoodPos().pos->x) // Player Object
            {
                gameBoard[row][column] = f->getFoodPos().getSymbol();
            }


            else // Non Active
            {
                gameBoard[row][column] = ' ';
            }

            for (int i = 0; i < p->getPlayerPos().getSize(); i++) 
            {                
               
                if (row == p->getPlayerPos().getElement(i).pos->y && column == p->getPlayerPos().getElement(i).pos->x) // Player Object
                {
                    gameBoard[row][column] = p->getPlayerPos().getElement(i).symbol;
                }

            }

        }
    }


    // Printing Game Board 
    for (int row = 0; row < board->getBoardSizeY(); row++)
    {

        for (int column = 0; column < board->getBoardSizeX(); column++)
        {

            MacUILib_printf("%c", gameBoard[row][column]);
        }

        MacUILib_printf("\n");
    }

    if(board->getLoseFlagStatus())
    {   
        MacUILib_Delay(1000000);
        MacUILib_clearScreen();
        MacUILib_Delay(1000000);
        MacUILib_printf("\n");
        MacUILib_printf("##################################\n\n");
        MacUILib_printf("     YOU LOSE!!! TRY AGAIN D:\n\n");
        MacUILib_printf("##################################");
        MacUILib_Delay(1000000);
    }

    if((board->getExitFlagStatus()) && !(board->getLoseFlagStatus()))
    {   
        MacUILib_Delay(1000000);
        MacUILib_clearScreen();
        MacUILib_Delay(1000000);
        MacUILib_printf("\n");
        MacUILib_printf("##################################\n\n");
        MacUILib_printf("     DON'T BE A QUITTER >:(\n\n");
        MacUILib_printf("##################################");
        MacUILib_Delay(1000000);
    }



}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();
    //Deletion of gameboard
    // Store board dimensions before deleting board
    int boardSizeY = board->getBoardSizeY();

    // Deletion of gameboard
    for (int i = 0; i < boardSizeY; i++) 
    {
        delete[] gameBoard[i];
    }
    delete[] gameBoard;

    delete p;
    delete f;
    delete board;
}
