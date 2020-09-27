/*  
 * Author: Aidan Wesloskie
 * 
 * TicTacToe CPP
 */

#include "TicTacToe.h"
#include <cstdlib>


TicTacToe::TicTacToe()
{
    isOver = false; 
    board = new char*[3];
    //Generate the array
    for (int i = 0; i < 3; i++)
        board[i] = new char[3];
        
    //Fills array with default values
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

TicTacToe::~TicTacToe()
{
    for (int i = 0; i < 3; i++)
        delete [] board[i];
    delete [] board;
}

void TicTacToe::computerMove()
{
    bool pass = false;
    int x, y;
    //Continuously generates coordinates until successful
    while(!pass){
        x = (rand() % 3);
        y = (rand() % 3);

        if(board[x][y] == ' ')
            pass = true;
    }
    
    board[x][y] = 'X';
    x++; y++;
    //Displays outcome
    std::cout<< "The computer made its move at (" << x << ", " << y << ")\n";
    std::cout << "===============\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            std::cout << "| " << board[i][j] << " |";
        std::cout << "\n===============\n";
    }
    std::cout << "\n";
}

void TicTacToe::makeMove()
{
    int x, y;
    std::cout << "Where would you like to make a move?\n";
    std::cin >> x >> y; //User input
    x--; y--; //Subtracts to account for 0 based indexing in arrays
    board[x][y] = 'O';
    x++; y++; //Add value back to original
    
    //Displays outcome
    std::cout<< "You made your move at (" << x << ", " << y << ")\n";
    std::cout << "===============\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            std::cout << "| " << board[i][j] << " |";
        std::cout << "\n===============\n";
    }
    std::cout << "\n";
}

bool TicTacToe::isGameOver()const
{
    // Checks Rows
    for (int i = 0; i < 3; i++) 
            if (board[i][0] == board[i][1]&& 
                board[i][0] == board[i][2]&& 
                board[i][0] != ' ') 
                return true;
            
    for (int i = 0; i < 3; i++)
        if (board[0][i] == board[1][i]&& 
            board[0][i] == board[2][i]&& 
            board[0][i] != ' ') 
            return true;

    if (board[0][0] == board[1][1]&& 
        board[0][0] == board[2][2]&& 
        board[0][0] != ' ' && 
        board[1][1] != ' ' &&
        board[2][2] != ' ') 
        return true;
        
    if (board[0][2] == board[1][1]&&
        board[0][2] == board[2][0]&& 
        board[0][0] != ' ' && 
        board[1][1] != ' ' && 
        board[2][2] != ' ') 
        return true;
        
    return false;
}

