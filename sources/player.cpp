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


int Player::cardesTaken(){

    return this->cardes_Taken.size();

}// prints the amount of cards this player has won. 

string Player::getString(){
    
    return this->nameP;
}


    int Get_count_win(){
        return this->count_win;
    }
    
    void Set_count_win(int point){
        this->count_win = point;
    }

    int Get_stack_card(){

    return this->stack_card.size();
    }

    void Puse_stack_card(Card cardto){
        this->stack_card.push_back(cardto);
    }

    Card back_stack_card(){
        return this->stack_card.back();
    }

    void pop_stack_card(){
        this->stack_card.pop_back();
    }