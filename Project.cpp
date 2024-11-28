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



int main(void)
{

    Initialize();

    while(board->getExitFlagStatus() == false)  
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

    board = new GameMechs();
    p = new Player(board);
    f = new Food(board);
    f->generateFood(p->getPlayerPos());

    // exitFlag = false;
}

void GetInput(void)
{
    if(MacUILib_hasChar())
    {
        board->setInput(MacUILib_getChar());
    }
    else
    {
        board->setInput(0);
    }
}

void RunLogic(void)
{
    switch(board->getInput())
    {
        case 0:
            break;
        case ' ':
            board->setExitTrue();
            break;
        case 'q': //debug key for incrementing score
            board->incrementScore();
            break;
        case 'f':
            f->generateFood(p->getPlayerPos());
            break;
        default:
            p->updatePlayerDir();
            break;
    }
    p->movePlayer();
    //p->drawPlayer();
    board->clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    

    int xBoundary = board->getBoardSizeX();
    int yBoundary = board->getBoardSizeY();
    int i, j;

    // for(i = 0; i < yBoundary; i++)
    // {
    //     for(j = 0; j < xBoundary; j++)
    //     {
    //         MacUILib_printf("%c", board->getBoard(i,j));
    //     }
    //     MacUILib_printf("\n");
    // }
    MacUILib_printf("W = Up, A = Left, S = Down, D = Right, SPACE = Stop");
    MacUILib_printf("\nScore: %d", board->getScore());
    //MacUILib_printf("\nDirection: %d", p->getDirection());
    MacUILib_printf("\nFood Position: %d %d", f->getFoodPos().pos->x, f->getFoodPos().pos->y);
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();
    delete p;
    delete f;
    delete board;
}
