#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <stdio.h>
#include <stdexcept>

using namespace std;
#include "iostream"
//#include "stdio.h"


class Player{
    
    private:
        std::string nameP;
        bool in_play;
        vector<Card> cardesTaken;
        stack<Card> stack_card;
 
    
    public:
        Player(){}
        Player(std::string name);

        std::string getString();

        int stacksize(); //prints the amount of cards left. should be 21 but can be less if a draw was played

        int cardesTaken();

};

#endif



