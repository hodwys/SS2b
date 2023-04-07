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
            s = "dim ";
        }
        else if(j<27){
            s = "heart ";
        }
        else if(j<40){
            s = "leaf ";
        }
        else{
            s = "clover ";
        }
        if((j) % 13 == 1){
        this->Card_Of_game.push_back( Card(100,s,"Ace "));    
        }
        else if(j%13 == 0){

            this->Card_Of_game.push_back(Card(13,s,"King "));
        }
        else if(j%13 == 12){

            this->Card_Of_game.push_back(Card(12,s,"Queen "));
        }
        else if(j%13 == 11){

            this->Card_Of_game.push_back( Card(11,s,"Prince "));
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
        
       // print_stack(i);
    }
}


void Game::printWiner(){

    if(p1-> cardesTaken() > p2-> cardesTaken()){

        cout<<p1->getString()<< " wins. " <<endl;
    }

    else if(p2-> cardesTaken() > p1-> cardesTaken()){

        cout<<p2->getString()<<" wins. " << endl;
    }

    else if(p2-> cardes_Taken.size() == p1-> cardes_Taken.size())
    {
        cout<<"The game ended in a draw. "<<endl;
    }

 } // prints the name of the winning player



 void Game::playTurn(){

    if(p2->stack_card.size()>0 && (p1->getString() != p2->getString())){

        Card card1 = p1->stack_card.back();
        p1->stack_card.pop_back();

        Card card2 = p2->stack_card.back();
        p2->stack_card.pop_back();

        string one = p1->getString();
        one += " played ";
        one += card1.Get_number();
        one += " of ";
        one += card1.Get_shape();


        string two = p2->getString();
        two += " played ";
        two += card2.Get_number();
        two += " of ";
        two += card2.Get_shape();

        string print = one +two;


// who gana

        if(card1.Get_Num() > card2.Get_Num()){
            print += p1->getString() + " wins ";
            p1->cardes_Taken.push_back(card1);
            p1->cardes_Taken.push_back(card2);
            p1->count_win++;
            Turn_Of_game.push_back(print);

        }
        else if(card2.Get_Num() > card1.Get_Num()){
            print += p2->getString() + " wins ";
            p2->cardes_Taken.push_back(card1);
            p2->cardes_Taken.push_back(card2);
            p2->count_win++;
            Turn_Of_game.push_back(print);
        
        }
        else{
            print +="Draw. ";
          //  Turn_Of_game.push_back(print);

            if(p2->stack_card.size() == 1){
                //נשארו 2 קלפים לכל אחד
                for(size_t j= 0; j<p1->stack_card.size(); j++){
                    p1->cardes_Taken.push_back(p1->stack_card[j]);
                    p2->cardes_Taken.push_back(p2->stack_card[j]);
                }

            }

            while(p2->stack_card.size()>1 && card1.Get_Num() == card2.Get_Num()){
                draw++;                 

                vector<Card> Card_temp;
                Card_temp.push_back(card1);
                Card_temp.push_back(card2);

                Card_temp.push_back(p1->stack_card.back());
                p1->stack_card.pop_back();

                Card_temp.push_back(p2->stack_card.back());
                p2->stack_card.pop_back();

                card1 = p1->stack_card.back();
                p1->stack_card.pop_back();
                card2 = p2->stack_card.back();
                p2->stack_card.pop_back();
                Card_temp.push_back(card1);
                Card_temp.push_back(card2);


                print += p1->getString();
                print += " played ";
                print += card1.Get_number();
                print += " of ";
                print += card1.Get_shape();


                print += p2->getString();
                print += " played ";
                print += card2.Get_number();
                print += " of ";
                print += card2.Get_shape();


                if(card1.Get_Num() > card2.Get_Num()){
                    print += p1->getString() + " wins ";

                    for(size_t i= 0; i<Card_temp.size(); i++ ){
                        p1->cardes_Taken.push_back(Card_temp[i]);
                    }
                    p1->count_win++;
                    break;                    
                }

                else if(card2.Get_Num() > card1.Get_Num()){
                    print += p2->getString() + " wins   ";
                    for(size_t i= 0; i<Card_temp.size(); i++){
                        p2->cardes_Taken.push_back(Card_temp[i]);
                    }
                    p2->count_win++;
                    break;
                }

                else{
                    print +="Draw. ";
                }

              

            }


            if(card1.Get_Num() == card2.Get_Num()){
                print += "over in draw";
                p1->cardes_Taken.push_back(card1);
                p2->cardes_Taken.push_back(card2);
            }
            Turn_Of_game.push_back(print);
        }


    }
    else{
        throw std::runtime_error("The game is illegal");
    }




    }

 

 void Game::printLastTurn(){
    cout<< Turn_Of_game[Turn_Of_game.size()-1] <<endl;

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




// print the last turn stats. For example:
// Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
// Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds. draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.

