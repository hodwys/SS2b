#include "game.hpp"
#include "player.hpp"
#include <stdexcept>
# include <string>
# include "card.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

Game::Game(Player &one, Player &two){
    p1 = &one;
    p2 = &two;
    
    creating_the_card();
    cout<<"/////////////////////////////"<<endl;
    Shuffle();
    div_card();

}
//constructor 


// print Card
void Game::print_card(size_t g){

        cout<<this->Card_Of_game[g-1].Get_number()<<endl;
        cout<<this->Card_Of_game[g-1].Get_shape()<<endl;
}

//crait
void Game::creating_the_card(){

    string s="";
    for(size_t j=1; j<53; j++){
        if(j<14){
            s = "dim";
        }
        else if(j<27){
            s = "heart";
        }
        else if(j<40){
            s = "leaf";
        }
        else{
            s = "clover";
        }
        if((j) % 13 == 1){
        this->Card_Of_game.push_back( Card(100,s,"Ace"));    
        }
        else if(j%13 == 0){

            this->Card_Of_game.push_back(Card(13,s,"King"));
        }
        else if(j%13 == 12){

            this->Card_Of_game.push_back(Card(12,s,"Queen"));
        }
        else if(j%13 == 11){

            this->Card_Of_game.push_back( Card(11,s,"Prince"));
        }

        else{
            this->Card_Of_game.push_back( Card(j%13,s,to_string(j%13)));
        }
       // print_card(j);
    }
}

void Game:: Shuffle(){
    // Shuffle the cards
    std::random_device rd;
    std::mt19937 g(rd()); // Seed the random number generator
    std::shuffle(this->Card_Of_game.begin(), this->Card_Of_game.end(), g);

    // Print the shuffled cards
    for(size_t j = 1; j<=this->Card_Of_game.size(); j++){
        //print_card(j);
    }
}

void Game::print_stack(size_t g){
        if(g<26){
            cout<<p1->stack_card[g%26].Get_number()<<endl;
        }
        else{
            cout<<p2->stack_card[g%26].Get_number()<<endl;
        }
         cout<<p1->stack_card.size()<<endl;
         cout<<p2->stack_card.size()<<endl;
}

void Game:: div_card(){
    for(size_t i=0 ; i<52; i++){
        if(i<26){
            p1->stack_card.push_back(this->Card_Of_game[i]);

        }
        else{

            p2->stack_card.push_back(this->Card_Of_game[i]);  
        }
        
        print_stack(i);
    }
}


void Game::printWiner(){

    if(p1-> cardes_Taken.size()>p2-> cardes_Taken.size()){

        cout<<p1->getString()<< "'winn" <<endl;
    }

    else if(p2-> cardes_Taken.size()>p1-> cardes_Taken.size()){

        cout<<p2->getString()<<"winn" << endl;
    }

    else{
        cout<<"The game ended in a draw"<<endl;
    }

 } // prints the name of the winning player



 void Game::playTurn(){

    if(p2->stack_card.size()>0){



        





    else{
        throw std::runtime_error("ran out of cards");
    }

    }



//  ווינ מי שניצח להגדיל את הקונט  
 }


 void Game::playAll(){

    while(p1->stack_card.size()>0){
        playTurn();
    }
    
} //playes the game untill the end




 void Game::printStats(){



}// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )

// כמה פעמים זכה
// כמה קלפים זכה
// דברים אחרים
// מספר התיקו כולל תיקו בתוך תיקו
// אחוזי התיקו









void Game::printLog(){

 } // prints all the turns played one line per turn (same format as game.printLastTurn())



void Game::printLastTurn() {

}
// print the last turn stats. For example:
// Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
// Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds. draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.

