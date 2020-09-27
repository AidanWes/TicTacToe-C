/*
 * Game.cpp
 * A class that models a general computer game
 */

#include "Game.h"
#include <ctime>

 Game::who Game::play()
 {
    srand((unsigned)time(NULL));
    int turn=(int)(0.5+rand()/(double)RAND_MAX);
    displayMessage();
    std::cout << ((turn==0) ? "Computer goes " : "You go ") << " first: \n";
   while(true)
   {
       if(turn==0)//Machine's turn
           computerMove();
       else
          makeMove();
       numberMove++;
       //Determines if any one wins yet
       if(isGameOver() && turn==1)
           return COMPUTER;
       else if(isGameOver() && turn==0)
           return HUMAN;
       else if(numberMove == 9)
           return NEUTRAL;
       //Switch player
       turn=(1+turn)%2;
   }
 }
 
 void Game::displayMessage()const
 {
    //Don't know what the game is
    std::cout<<"Starting game....... "; 
 }
