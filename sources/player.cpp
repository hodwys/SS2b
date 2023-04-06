# include "player.hpp"
# include <string>
#include <stdexcept>


Player::Player(std::string str){
    nameP=str;
    in_play = false;
    this->cardesTaken = {};
    this->stacksize = {};
}// constructor 

int Player::stacksize(){

    return this->stack_card.size();

}  //prints the amount of cards left. should be 21 but can be less if a draw was played


int Player::cardesTaken(){

    return this->cardesTaken.size();

}// prints the amount of cards this player has won. 

string Plater::getString(){
    
    return this->nameP;
}

