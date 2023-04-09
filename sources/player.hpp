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
        vector<Card> cardes_Taken;
        bool in_play;
    public:

        // Player(){}
        Player(std::string name);

        std::string getString();

        int stacksize(); //prints the amount of cards left. should be 21 but can be less if a draw was played

        int cardesTaken();

        int Get_count_win();
        
        void Set_count_win(int poin);

        int Get_stack_card();

        void Puse_stack_card(Card tpmi);

        Card back_stack_card();

        void pop_stack_card();





        void Push_cardes_Taken(Card tompi);

        Card back_cardes_Taken();

        void pop_cardes_Taken();
                    

        bool Get_in_play();

        void Set_in_play(bool tochen);

};

#endif



