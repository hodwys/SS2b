#include "game.hpp"
#include "player.hpp"
#include <stdexcept>
# include <string>


Game::Game(Player &one, Player &two){
    p1 = &one;
    p2 = &two;


    void Game::creating_the_card(){

        for(int j=1; j<53; j++){
            if(j<14){
                string s = "dim";
            }
            else if(j<27){
                string s = "heart";
            }
            else if(j<40){
                string s = "leaf";
            }
            else(){
                string s = "clover";
            }
            if((j-1) % 13 == 0){
            this->Card_Of_game[j]= Card(100,s,"Ace");    
            }
            else{
                this->Card_Of_game[j]= Card(j,s,to_string(j));
            }
            cout<<Card_Of_game[j]<<endl;
        }
    }


}
//constructor 

void Game::playAll(){
    
} //playes the game untill the end

void Game::printWiner(){

 } // prints the name of the winning player

void Game::printLog(){

 } // prints all the turns played one line per turn (same format as game.printLastTurn())

 void Game::printStats(){
}// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )


 void Game::playTurn(){

 }


void Game::printLastTurn() {

}
// print the last turn stats. For example:
// Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
// Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds. draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.
