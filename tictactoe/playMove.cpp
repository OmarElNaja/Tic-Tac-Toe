#include "tictactoe.h"
#include "gameState.h"

void playMove(gameState& game_state) {

   //The move is valid if the clicked tile is empty and not valid if it is occupied
   if (game_state.get_gameBoard (game_state.get_clickedRow (), game_state.get_clickedColumn ()) == Empty)
    {
        game_state.set_moveValid (true);

    } else
    {
        game_state.set_moveValid (false);
    }

    //If the move is valid, update the clicked tile depending on whose turn it was when the click was made
    if(game_state.get_moveValid() == true)
    {
        if (game_state.get_turn() == true)
        {
           //Change the clicked tile to X if it was player X's turn when clicked
           //And change the turn to player O
           game_state.set_gameBoard(game_state.get_clickedRow(), game_state.get_clickedColumn(), X);
           game_state.set_turn(false);

        } else if (game_state.get_turn() == false)
        {
           //Change the clicked tile to O if it was player O's turn when clicked
           //And change the turn to player X
           game_state.set_gameBoard(game_state.get_clickedRow(), game_state.get_clickedColumn(), O);
           game_state.set_turn(true);
        }
    }

    //Set winCode to 8 if a player won by forming a line from the bottom left to the top right of the board
    //And set gameOver to true
    if ((game_state.get_gameBoard (2,0) == X) && (game_state.get_gameBoard (1,1) == X) && (game_state.get_gameBoard (0,2) == X))
    {
       game_state.set_winCode(8);
       game_state.set_gameOver(true);

    } else if ((game_state.get_gameBoard (2,0) == O) && (game_state.get_gameBoard (1,1) == O) && (game_state.get_gameBoard (0,2) == O))
    {
       game_state.set_winCode(8);
       game_state.set_gameOver(true);
    }

   //Set winCode to 7 if a player won by forming a line from the bottom right to the top left of the board
   //And set gameOver to true
   if ((game_state.get_gameBoard (0,0) == X) && (game_state.get_gameBoard (1,1) == X) && (game_state.get_gameBoard (2,2) == X) && (game_state.get_winCode()!=8))
    {
        game_state.set_winCode(7);
        game_state.set_gameOver(true);

    } else if ((game_state.get_gameBoard (0,0) == O) && (game_state.get_gameBoard (1,1) == O) && (game_state.get_gameBoard (2,2) == O) && (game_state.get_winCode()!=8))
    {
        game_state.set_winCode(7);
        game_state.set_gameOver(true);
    }

    //If a player won by forming a vertical line, set winCode to 4, 5, or 6 depending on the column number
    //And set gameOver to true
    if ((game_state.get_winCode()!=8) && (game_state.get_winCode()!=7))
    {
        //For loop to check if player X has won by forming a vertical line
        for (int col=0; col<boardSize; col++)
        {
          if ((game_state.get_gameBoard (0,col) == X) && (game_state.get_gameBoard (1,col) == X) && (game_state.get_gameBoard (2,col) == X))
          {
              //Set winCode to 4 if player X won by making a line on the first (0th index) column
              if (col == 0)
              {
                  game_state.set_winCode(4);
                  game_state.set_gameOver(true);

              } else if (col == 1) //Set winCode to 5 if player X won by making a line on the second (1st index) column
              {
                  game_state.set_winCode(5);
                  game_state.set_gameOver(true);

              } else if (col == 2) //Set winCode to 6 if player X won by making a line on the third (2nd index) column
              {
                  game_state.set_winCode(6);
                  game_state.set_gameOver(true);
              }
          }
        }

        //For loop to check if player O has won by forming a vertical line
        for (int col=0; col<boardSize; col++)
        {
          if ((game_state.get_gameBoard (0,col) == O) && (game_state.get_gameBoard(1, col) == O) && (game_state.get_gameBoard (2,col) == O))
          {
              //Set winCode to 4 if player O won by making a line on the first (0th index) column
              if (col == 0)
              {
                  game_state.set_winCode(4);
                  game_state.set_gameOver(true);

              } else if (col == 1) //Set winCode to 5 if player O won by making a line on the second (1st index) column
              {
                  game_state.set_winCode(5);
                  game_state.set_gameOver(true);

              } else if (col == 2) //Set winCode to 6 if player O won by making a line on the third (2nd index) column
              {
                  game_state.set_winCode(6);
                  game_state.set_gameOver(true);
              }
          }
        }
    }

   //If a player won by forming a horizontal line, set winCode to 1, 2, or 3 depending on the row number
   //And set gameOver to true
   if ((game_state.get_winCode()!=8) && (game_state.get_winCode()!=7) && (game_state.get_winCode()!=6) && (game_state.get_winCode()!=5) && (game_state.get_winCode()!=4))
   {
        //For loop to check if player O has won by forming a horizontal line
        for (int row = 0; row<boardSize; row++)
        {
          if ((game_state.get_gameBoard (row,0) == X) && (game_state.get_gameBoard (row,1) == X) && (game_state.get_gameBoard (row,2) == X))
          {
              //Set winCode to 1 if player X won by making a line on the first (0th index) row
              if (row == 0)
              {
                  game_state.set_winCode(1);
                  game_state.set_gameOver(true);

              } else if (row == 1) //Set winCode to 2 if player X won by making a line on the second (1st index) row
              {
                  game_state.set_winCode(2);
                  game_state.set_gameOver(true);

              } else if (row == 2) //Set winCode to 3 if player X won by making a line on the third (2nd index) row
              {
                  game_state.set_winCode(3);
                  game_state.set_gameOver(true);
              }
          }
        }

        //For loop to check if player O has won by forming a horizontal line
        for (int row = 0; row<boardSize; row++)
        {

          if ((game_state.get_gameBoard (row,0) == O) && (game_state.get_gameBoard(row, 1) == O) && (game_state.get_gameBoard(row, 2) == O))
          {
              //Set winCode to 1 if player O won by making a line on the first (0th index) row
              if (row == 0)
              {
                  game_state.set_winCode(1);
                  game_state.set_gameOver(true);

              } else if (row == 1) //Set winCode to 2 if player O won by making a line on the second (1st index) row
              {
                  game_state.set_winCode(2);
                  game_state.set_gameOver(true);

              } else if (row == 2) //Set winCode to 3 if player O won by making a line on the third (2nd index) row
              {
                  game_state.set_winCode(3);
                  game_state.set_gameOver(true);
              }

          }
        }
   }

    //Set winCode to 0 if it is not any number from 1 to 8 (inclusive) (i.e. no player has won)
    //This will set winCode to 0 if there is a draw, or if the game has not ended yet
    if ((game_state.get_winCode()!=1) && (game_state.get_winCode()!=2) && (game_state.get_winCode()!=3) && (game_state.get_winCode()!=4) && (game_state.get_winCode()!=5) && (game_state.get_winCode()!=6) && (game_state.get_winCode()!=7) && (game_state.get_winCode()!=8))
    {
        game_state.set_winCode (0);

        //Variable to count if the tiles are filled on the board, to determine if the game has ended in a draw
        //Or if it has not ended yet
        int count = 0;

        for (int row=0; row<boardSize; row++)
        {
            for (int col=0; col<boardSize; col++)
            {
                if (game_state.get_gameBoard(row, col) == X || game_state.get_gameBoard(row, col) == O)
                {
                    count++;
                }
            }
        }

        //If all 9 tiles are filled (either X or O), the game is over and has ended in a draw
        //Set gameOver to true
        if (count == 9)
        {
            game_state.set_gameOver(true);
        }
    }
}
