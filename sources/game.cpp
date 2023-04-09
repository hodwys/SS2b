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
    if(p1->Get_in_play()==true || p2->Get_in_play()== true){
        throw std::runtime_error("the player alredy play");
    }

    p1->Set_in_play(true);
    p2->Set_in_play(true);
    
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
            s = "diamond ";
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
        this->Card_Of_game.push_back( Card(1,s,"Ace "));    
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


}

// void Game::print_stack(size_t g){
//         if(g<26){
//             cout<<p1->stack_card[g%26].Get_number()<<endl;
//         }
//         else{
//             cout<<p2->stack_card[g%26].Get_number()<<endl;
//         }
//          cout<<p1->stack_card.size()<<endl;
//          cout<<p2->stack_card.size()<<endl;
// }

void Game:: div_card(){
    for(size_t i=0 ; i<52; i++){
        if(i<26){
            p1->Puse_stack_card(this->Card_Of_game[i]);
        }
        else{

            p2->Puse_stack_card(this->Card_Of_game[i]);  
        }
        
    }
}


void Game::printWiner(){

    if(p1-> cardesTaken() > p2-> cardesTaken()){

        cout<<p1->getString()<< " wins. " <<endl;
    }

    else if(p2-> cardesTaken() > p1-> cardesTaken()){

        cout<<p2->getString()<<" wins. " << endl;
    }

    else if(p2-> cardesTaken() == p1-> cardesTaken())
    {
        cout<<"The game ended in a draw. "<<endl;
    }

 } 

 void Game::playTurn(){

    if(p2-> Get_stack_card() >0 && (p1 != p2)){
        bool ended= false;       
        Card card1 = p1->back_stack_card();
        p1->pop_stack_card();

        Card card2 = p2->back_stack_card();
        p2->pop_stack_card();

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

        bool isok = ((card2.Get_Num()!=2 && card2.Get_Num()!=1 && card1.Get_Num()==1)) ||(card1.Get_Num() ==2 && card2.Get_Num() ==1);
        bool isok2 = ((card1.Get_Num()!=2 && card1.Get_Num()!=1 && card2.Get_Num()==1)) ||(card2.Get_Num() ==2 && card1.Get_Num() ==1);

       
  //      bool isok3 = !(card1.Get_Num()==2 && card2.Get_Num()==100);



        if(((card1.Get_Num() > card2.Get_Num()) && (card2.Get_Num() != 1)|| isok)){
            print += p1->getString() + " wins ";
            p1->Push_cardes_Taken(card1);
            p1->Push_cardes_Taken(card2);
            p1->Set_count_win(p1->Get_count_win()+1);
            Turn_Of_game.push_back(print);
          
            if(p1->Get_stack_card()==0){
                p1->Set_in_play(false);
                p2->Set_in_play(false);
            }
            return;
        }
        else if(((card2.Get_Num() > card1.Get_Num()) && (card1.Get_Num() != 1) || isok2)){
            print += p2->getString() + " wins ";
            p2->Push_cardes_Taken(card1);
            p2->Push_cardes_Taken(card2);
            p2->Set_count_win(p2->Get_count_win()+1);
            Turn_Of_game.push_back(print);
          
            if(p1->Get_stack_card()==0){
                p1->Set_in_play(false);
                p2->Set_in_play(false);
            }
            return;
        
        }
        else if(card2.Get_Num() == card1.Get_Num()){
            print +="Draw. ";
            draw++;
         
            vector<Card> Card_temp = {};
            while(p2->Get_stack_card()>0){

                if(p2->Get_stack_card()== 1){
              
                    p1->Push_cardes_Taken(p1->back_stack_card());
                    p1->pop_stack_card();
                    p1->Push_cardes_Taken(card1);

            
                    p2->Push_cardes_Taken(p2->back_stack_card());
                    p2->pop_stack_card(); 
                    p2->Push_cardes_Taken(card2);

                    while(Card_temp.size()> 0 ){
                    int i=0;
                    if(i%2 == 0){
                        p2->Push_cardes_Taken(Card_temp.back());
                        Card_temp.pop_back(); 
                        i++;

                    }
                    else{
                        p1->Push_cardes_Taken(Card_temp.back());
                        Card_temp.pop_back(); 
                        i++;
                    }
                    }   

                    Turn_Of_game.push_back(print);
                    if(p1->Get_stack_card()==0){
                        p1->Set_in_play(false);
                        p2->Set_in_play(false);
                    }
                    return;
                }
                else{

                    Card_temp.push_back(card1);
                    Card_temp.push_back(card2);

                    Card_temp.push_back(p1->back_stack_card());
                    p1->pop_stack_card();

                    Card_temp.push_back(p2->back_stack_card());
                    p2->pop_stack_card();

                    card1 = p1-> back_stack_card();
                    p1->pop_stack_card();
                    card2 = p2-> back_stack_card();
                    p2->pop_stack_card();

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


                    isok = ((card2.Get_Num()!=2 && card2.Get_Num()!=1 && card1.Get_Num()==1)) ||(card1.Get_Num() ==2 && card2.Get_Num() ==1);
                    isok2 = ((card1.Get_Num()!=2 && card1.Get_Num()!=1 && card2.Get_Num()==1)) ||(card2.Get_Num() ==2 && card1.Get_Num() ==1);

                    if(((card1.Get_Num() > card2.Get_Num()) && card2.Get_Num() != 1) || isok){
                        print += p1->getString() + " wins ";
                        Card_temp.push_back(card1);
                        Card_temp.push_back(card2);
                        while(Card_temp.size()>0){
                            p1->Push_cardes_Taken(Card_temp.back());
                            Card_temp.pop_back();
                        }
                        ended = true;
                        p1->Set_count_win(p1->Get_count_win()+1);
                        Turn_Of_game.push_back(print);

                        if(p1->Get_stack_card()==0){
                            p1->Set_in_play(false);
                            p2->Set_in_play(false);
                        }
                        return;          

                    }
                    else if(card2.Get_Num() > card1.Get_Num() && (card1.Get_Num() != 1) || isok2 ){
                        print += p2->getString() + " wins   ";
                        Card_temp.push_back(card1);
                        Card_temp.push_back(card2);
                        while(Card_temp.size()>0){
                            p2->Push_cardes_Taken(Card_temp.back());
                            Card_temp.pop_back();
                        }

                        p2->Set_count_win(p2->Get_count_win()+1);
                        ended = true;
                        Turn_Of_game.push_back(print);

                        if(p1->Get_stack_card()==0){
                            p1->Set_in_play(false);
                            p2->Set_in_play(false);
                        }
                        return;
                    }

                    else if (card2.Get_Num() == card1.Get_Num()){
                        print +="Draw. ";
                        draw++;

                        continue;
                    }

                

                }

            }

            if(Card_temp.size() >0){
                while(Card_temp.size()>0){
                    int i=0;
                    if(i%2 == 0){
                        p2->Push_cardes_Taken(Card_temp.back());
                        Card_temp.pop_back(); 
                        i++;

                    }
                    else{
                        p1->Push_cardes_Taken(Card_temp.back());
                        Card_temp.pop_back(); 
                        i++;
                    }

 
                }
            }
            Turn_Of_game.push_back(print);

            p1->Push_cardes_Taken(card1);
            p2->Push_cardes_Taken(card2);
     
            if(p1->Get_stack_card()==0){
                p1->Set_in_play(false);
                p2->Set_in_play(false);
            }
            return;

        }
    }
    else
    {
        throw std::runtime_error("The game is illegal");
    }

}
 
 void Game::printLastTurn(){
    cout<< Turn_Of_game[Turn_Of_game.size()-1] <<endl;

 }
void Game:: printLog(){

for(size_t k=0; k<Turn_Of_game.size(); k++){
    cout<< Turn_Of_game[k] <<endl;
}
}

 void Game::playAll(){

    while(p1->Get_stack_card()>0){
        playTurn();
    }
    p1->Set_in_play(false);
    p2->Set_in_play(false);

    
} //playes the game untill the end


void Game::printStats(){

cout<<"amount of draws: "<< to_string(draw)<<endl;

float pre= (draw/Turn_Of_game.size()*100);
cout<<" of draws: "<< to_string(pre)<<"%"<<endl;
cout <<p1->getString() <<" won "<< p1->cardesTaken() << endl; // prints the amount of cards this player has won. 
cout <<p2->getString()<< " won "<< p2->cardesTaken() << endl;
cout<< p1->getString() <<" won "<<p1->Get_count_win()<<" timse "<<endl;
cout<< p2->getString() <<" won "<<p2->Get_count_win()<<" timse "<<endl;



}// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )










