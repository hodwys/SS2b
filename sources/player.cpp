# include "player.hpp"
# include <string>
#include <stdexcept>
#include "card.hpp"



// Player::Player(){
//     nameP="";
//     in_play = false;
//     count_win = 0;
//     this->cardes_Taken = {};
//     this->stack_card = {};
// }




Player::Player(std::string str){
    nameP=str;
    in_play = false;
    count_win = 0;
    this->cardes_Taken = {};
    this->stack_card = {};
}// constructor 

int Player::stacksize(){

    return this->stack_card.size();

}  //prints the amount of cards left. should be 21 but can be less if a draw was played


bool Player::Get_in_play(){
    return this->in_play;
}

void Player:: Set_in_play(bool tochen){
    this->in_play = tochen;
}

string Player::getString(){
    
    return this->nameP;
}


    int Player:: Get_count_win(){
        return this->count_win;
    }
    
    void Player::Set_count_win(int point){
        this->count_win = point;
    }

    int Player::Get_stack_card(){

    return this->stack_card.size();
    }

    void Player::Puse_stack_card(Card cardto){
        this->stack_card.push_back(cardto);
    }

    Card Player::back_stack_card(){
        return this->stack_card.back();
    }

    void Player::pop_stack_card(){
        this->stack_card.pop_back();
    }



    int Player::cardesTaken(){

        return this->cardes_Taken.size();
    }

    void Player::Push_cardes_Taken(Card cardtecen){

        this->cardes_Taken.push_back(cardtecen);
    }

    Card Player::back_cardes_Taken(){
        return this->cardes_Taken.back();
    }

    void Player::pop_cardes_Taken(){
         this->cardes_Taken.pop_back();
    }