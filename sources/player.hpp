#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <stdio.h>
#include <stdexcept>
#include "card.hpp"

using namespace std;
#include "iostream"
#include <stack>
//#include "stdio.h"


class Player{
    
    private:
        std::string nameP;

    public:
        int count_win;
        bool in_play;
        vector<Card> stack_card;
        vector<Card> cardes_Taken;
        // Player(){}
        Player(std::string name);

        std::string getString();

        int stacksize(); //prints the amount of cards left. should be 21 but can be less if a draw was played

        int cardesTaken();

};

#endif



