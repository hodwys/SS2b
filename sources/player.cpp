# include "player.hpp"
# include <string>
#include <stdexcept>
#include "card.hpp"

Player::Player(std::string str){
    nameP=str;
    in_play = false;
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

