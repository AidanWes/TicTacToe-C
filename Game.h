/*
 * Game.h
 * A class that models a general computer game
 */
#ifndef GAME_H
#define GAME_H
#include<iostream>
class Game 
{
public:
    enum who{HUMAN, NEUTRAL, COMPUTER};
    Game(){numberMove=0;}
    /*
     *PostCondition: A player has been returned depending on who 
     * is the last player when the game is over
     */
    who play();
    /*
     * PostCondtion: true value has been returned if game is over
     *               false is returned otherwise
     */
    virtual bool isGameOver()const=0;
    /*
     * PostConditon: a message describes the game has been displayed.
     */
    virtual void displayMessage()const=0;
    /*
     *PostCondtition: The machine has made its move
     */
    virtual void computerMove()=0;
    /*
     * PostCondtion: The human has made his/her move
     */
    virtual void makeMove()=0;
    
    int getNumberMove()const
    {return numberMove;}
private:
    int numberMove; //number of moves made so far
};

#endif /* GAME_H */

