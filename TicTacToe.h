/*
 * TicTacToe H file
 */

#ifndef TICTACTOE_H
#define TICTACTOE_H
#include "Game.h"

class TicTacToe:public Game {
public:
    /*
     * Constructor for the TicTacToe game
     */
    TicTacToe();
    
    /*
     Deconstructor for TicTacToe
     */
    virtual ~TicTacToe();
    
    /*
     * PostCondition: Displays the welcome message for the game
     */
    virtual void displayMessage()const
     {
         Game::displayMessage();
         std::cout<<"\nTicTacToe LOADED\n";
     }
    
    /*
     * PostCondition: Creates a random move for the computer, if the move
     * is in a spot that is already taken it generates a new one, then it
     * displays the current board
     */
    virtual void computerMove();
    /*
     *PostCondition: Allows the user to make a move at a chosen spot, after
     * they make their move the grid is displayed with the new move
     */
    virtual void makeMove();
    
    /*
     * Checks to see if 3 matching symbols are found in a line
     */
    virtual bool isGameOver()const;
    
private:
    bool isOver;
    char **board;
};

#endif /* TICTACTOE_H */

