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
        int count_win;
        vector<Card> stack_card;
    public:
        
        bool in_play;
        
        vector<Card> cardes_Taken;
        // Player(){}
        Player(std::string name);

        std::string getString();

        int stacksize(); //prints the amount of cards left. should be 21 but can be less if a draw was played

        int cardesTaken();

        int Get_count_win();
        
        void Set_count_win();

        int Get_stack_card();

        void Puse_stack_card();

        Card back_stack_card();

        void pop_stack_card();
                    


};

#endif



