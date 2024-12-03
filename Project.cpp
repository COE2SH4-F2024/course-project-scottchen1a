#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Food.h"
#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000//delay constant

bool exitFlag;

//function prototypes
void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

//pointers for game objects
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
    board = new GameMechs(); //Create a new GameMechs object
    f = new Food(board);// Create a new Food object, passing the board reference
    p = new Player(board,f);// Create a new Player object, passing the board and food references
    f->generateFood(p->getPlayerPos()); // Generate initial food position based on player position
    //---------------------

    //Makes an array for the gameboard depening on the constuctor used
    board->makeGameBoard(gameBoard);
    //-----------------------

}

void GetInput(void)
{
    int tempInp = 0; // Temporary variable to hold input
    if (MacUILib_hasChar())
    {
        tempInp = MacUILib_getChar();
    }
    board->setInput(tempInp); // Set the input in the board object
}

void RunLogic(void)
{

    p->updatePlayerDir();// Update player direction based on input
    p->movePlayer();// Move the player based on direction

    // Check if the player has lost the game
    if (!p->checkLoss())
    {   
        board->setLoseFlag(); // Set the lose flag in the board
        board->setExitTrue(); // Set the exit flag to true
    }
    
    // Check if the player has consumed food
    if (p->checkFoodConsumption())
    {
        board->incrementScore();
        p->addLength();

        f->generateFood(p->getPlayerPos());// Generate new food at player's position

    }

    board->clearInput();

    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    

    // int xBoundary = board->getBoardSizeX();
    // int yBoundary = board->getBoardSizeY();
    // int i, j;

   
    
   
    objPos food = f->getFoodPos(); // Get the position of the food

    

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

            // Check for player positions and populate accordingly
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

    //UI
    
    MacUILib_printf("\n\nScore: %d\n", board->getScore());
    MacUILib_printf("\nW = Up, A = Left, S = Down, D = Right, SPACE = Stop\n");
    MacUILib_printf("\nFood Position: (%d, %d)\n", food.pos->x, food.pos->y);
   

    //checks if player has lost
    if(board->getLoseFlagStatus())
    {   
        MacUILib_Delay(500000);
        MacUILib_clearScreen();
        MacUILib_Delay(500000);
        MacUILib_printf("\n");
        MacUILib_printf("##################################\n\n");
        MacUILib_printf("     YOU LOSE!!! TRY AGAIN D:\n\n");
        MacUILib_printf("##################################");
        MacUILib_Delay(1500000);
    }

    //checks if the game has been exited without losing
    if((board->getExitFlagStatus()) && !(board->getLoseFlagStatus()))
    {   
        MacUILib_Delay(500000);
        MacUILib_clearScreen();
        MacUILib_Delay(500000);
        MacUILib_printf("\n");
        MacUILib_printf("##################################\n\n");
        MacUILib_printf("     DON'T BE A QUITTER >:(\n\n");
        MacUILib_printf("##################################");
        MacUILib_Delay(1500000);
    }



}

//delay
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
    int boardSizeY = board->getBoardSizeY();//height of board

    // Deletion of gameboard
    for (int i = 0; i < boardSizeY; i++) 
    {
        delete[] gameBoard[i]; //delete each row of the game board
    }
    delete[] gameBoard; // Delete the game board array itself

    delete p; //deletes player, food, and gamemechs objects
    delete f;
    delete board;
}
