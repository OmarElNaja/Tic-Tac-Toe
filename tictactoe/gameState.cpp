#include "tictactoe.h"
#include "gameState.h"

//Return clickedRow
int gameState::get_clickedRow()
{
    return clickedRow;
}

//Return clickedColumn
int gameState::get_clickedColumn()
{
    return clickedColumn;
}

//Set clickedRow to the input value
void gameState::set_clickedRow (int value)
{
    clickedRow=value;
}

//Set clickedColumn to the input value
void gameState::set_clickedColumn (int value)
{
    clickedColumn=value;
}

//Get the moveValid value (check if the move was valid)
bool gameState::get_moveValid ()
{
    return moveValid;
}

//Set the moveValid value to the input value
void gameState::set_moveValid (bool value)
{
    moveValid=value;
}

//Get the gameOver value (check if the game is over)
bool gameState::get_gameOver ()
{
    return gameOver;
}

//Set the gameOver value to the input value
void gameState::set_gameOver (bool value)
{
    gameOver=value;
}

//Get the winCode (check how a player won)
int gameState::get_winCode ()
{
    return winCode;
}

//Set the winCode to a value from 0 to 8 depending on how a player won
void gameState::set_winCode (int value)
{
    winCode=value;
}

//Get the turn value (check whose turn it is)
bool gameState::get_turn ()
{
    return turn;
}

//Set the turn value to the input value
void gameState::set_turn (bool value)
{
    turn=value;
}

//Get the value at position (row,col) on the gameBoard
int gameState::get_gameBoard (int row, int col)
{
    return (gameBoard [row][col]);
}

//Set the value at position (row,col) on the gameBoard to the input value, value
void gameState::set_gameBoard (int row, int col, int value)
{
    gameBoard[row][col]=value;
}
