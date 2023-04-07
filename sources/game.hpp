#ifndef GAME_HPP
#define GAME_HPP

#include "iostream"
#include <stdexcept>
namespace ariel{}
using namespace  ariel;
#include <string>
#include "player.hpp"
using namespace std;
#include "card.hpp"
#include <vector>



class Game{
    private:
        Player *p1;
        Player *p2;


    public:

        Game(){}
        Game(Player &One, Player &Two);
        vector<Card> Card_Of_game;
        vector<string> Turn_Of_game;
        int draw;
        
        void creating_the_card();
        void print_card(size_t g);
        void Shuffle();
        void div_card();
        void print_stack(size_t g);
        


        void playAll(); //playes the game untill the end
        void printWiner(); // prints the name of the winning player
        void printLog(); // prints all the turns played one line per turn (same format as game.printLastTurn())
        void printStats();// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
        
        void playTurn();
            // print the last turn stats. For example:
                                                            // Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
                                           // Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds. draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.

        void printLastTurn(); // print the last turn stats. For example:
                                                            // Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
                                                            // Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds. draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.



};
  
#endif