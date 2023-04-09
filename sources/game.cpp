#include "game.hpp"
#include "player.hpp"
#include <stdexcept>
# include <string>
# include "card.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>



// Game::Game(){

//     vector<Card> Card_Of_game ={};
//     vector<string> Turn_Of_game ={};
//     float draw=0;

// }
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
    //for(size_t j = 1; j<=this->Card_Of_game.size(); j++){
        //print_card(j);
    //}
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

    else if(p2-> cardesTaken() == p1-> cardesTaken())
    {
        cout<<"The game ended in a draw. "<<endl;
    }
// if(p1->stacksize() == 0 && p2->stacksize() == 0){
//         if(this->p1->cardesTaken() > this->p2->cardesTaken()){
//             cout << this->p1->getString() << endl;
//         }
//         else if(this->p1->cardesTaken() < this->p2->cardesTaken()){
//             cout << this->p2->getString() << endl;
//         }
//         else{
//             cout << this->p1->cardesTaken() << endl;
//             cout << this->p2->cardesTaken() << endl;
//             cout << "there is a draw" << endl;
//         }
//     }
//     else{

//         cout << "-------- GAME IS NOT OVER---------" << endl;
//     }




 } 
 // prints the name of the winning player



 void Game::playTurn(){

    if(p2->stack_card.size()>0 && (p1 != p2)){
        bool ended= false;
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

        bool isok = !(card2.Get_Num()==2 && card1.Get_Num()==100);
        bool isok2 = !(card1.Get_Num()==2 && card2.Get_Num()==100);
        cout<<isok2<<endl;
  //      bool isok3 = !(card1.Get_Num()==2 && card2.Get_Num()==100);


        
        if(card1.Get_Num() > card2.Get_Num()  && isok){
            print += p1->getString() + " wins ";
            p1->cardes_Taken.push_back(card1);
            p1->cardes_Taken.push_back(card2);
            p1->count_win++;
            Turn_Of_game.push_back(print);
            cout<<"line 187///////////////////////////////////////////////////////"<<endl;

            return;
        }
        else if(card2.Get_Num() > card1.Get_Num() && isok2){
            print += p2->getString() + " wins ";
            p2->cardes_Taken.push_back(card1);
            p2->cardes_Taken.push_back(card2);
            p2->count_win++;
            Turn_Of_game.push_back(print);
            cout<<"line 197///////////////////////////////////////////////////////"<<endl;

            return;
        
        }
        else if(card2.Get_Num() == card1.Get_Num()){
            print +="Draw. ";
            draw++;
          //  Turn_Of_game.push_back(print);

            //p1->cardesTaken() + p2->cardesTaken() == 52
            vector<Card> Card_temp = {};
            while(p2->stack_card.size()>0 && card1.Get_Num() == card2.Get_Num()){
 

                if(p2->stack_card.size() == 1){
                //נשארו 2 קלפים לכל אחד

                    p1->cardes_Taken.push_back(p1->stack_card.back());
                    p1->stack_card.pop_back();
                    p1->cardes_Taken.push_back(card1);

            
                    p2->cardes_Taken.push_back(p2->stack_card.back());
                    p2->stack_card.pop_back(); 
                    p2->cardes_Taken.push_back(card2);   

            
                    cout<<"/n line 204///////////////////////////////////////////////////////////"<<endl;
                    Turn_Of_game.push_back(print);
                    return;
                }
                else{

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
                    // Card_temp.push_back(card1);
                    // Card_temp.push_back(card2);


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

                    //bool isok4 = !(card2.Get_Num()==2 && card1.Get_Num()==100);
                    if(card1.Get_Num() > card2.Get_Num() && isok){
                        print += p1->getString() + " wins ";
                        Card_temp.push_back(card1);
                        Card_temp.push_back(card2);
                        while(Card_temp.size()>0){
                            p1->cardes_Taken.push_back(Card_temp.back());
                            Card_temp.pop_back();
                        }
                        ended = true;
                        p1->count_win++;
                        Turn_Of_game.push_back(print);
                        cout<<"line 269///////////////////////////////////////////////////////"<<endl;
                        return;          

                    }
                    else if(card2.Get_Num() > card1.Get_Num() && isok2 ){
                        print += p2->getString() + " wins   ";
                        Card_temp.push_back(card1);
                        Card_temp.push_back(card2);
                        while(Card_temp.size()>0){
                            p2->cardes_Taken.push_back(Card_temp.back());
                            Card_temp.pop_back();
                        }
                    // Card_temp={};
                        p2->count_win++;
                        ended = true;
                        Turn_Of_game.push_back(print);
                        cout<<"line 290///////////////////////////////////////////////////////"<<endl;

                        return;
                    }

                    else if (card2.Get_Num() == card1.Get_Num()){
                        print +="Draw. ";
                        draw++;
                        cout<< "line 298////////////////////////////////////////////////////////"<<endl;
                        continue;
                    }

                

                }
    // && (p2->cardesTaken() + p1->cardesTaken()!=52)

                if(card1.Get_Num() == card2.Get_Num() &&  !ended){
                    print += "over in draw";
                    //p1->cardes_Taken.push_back(card1);
    //                 p2->cardes_Taken.push_back(card2);
                    cout<<"jechi jechi//////////////////////////////////////////////////////////"<<endl;

                    for(size_t i= 0; i<Card_temp.size(); i++){
                        if(i%2 ==0 ){
                            p2->cardes_Taken.push_back(Card_temp.back());
                            Card_temp.pop_back();
                        }
                        else{
                            p1->cardes_Taken.push_back(Card_temp.back());
                            Card_temp.pop_back();
                        
                        }
                    
                    }
                    

                }
                
                cout<<"line 329///////////////////////////////////////////////////////"<<endl;

            }

            if(Card_temp.size() >0){
                while(Card_temp.size()>0){
                    int i=0;
                    if(i%2 == 0){
                        p2->cardes_Taken.push_back(Card_temp.back());
                        Card_temp.pop_back(); 
                        i++;

                    }
                    else{
                        p1->cardes_Taken.push_back(Card_temp.back());
                        Card_temp.pop_back(); 
                        i++;
                    }
                //print+="lime 347";
                
                cout<<"line 349///////////////////////////////////////////////////////"<<endl;

 
                }
            }
            Turn_Of_game.push_back(print);
            // אם זה תיקו אבל הקלף האחרון ולא נכנסו בכלל לוייל
            p1->cardes_Taken.push_back(card1);
            p2->cardes_Taken.push_back(card2);
            cout<<"line 330///////////////////////////////////////////////////////"<<endl;
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

    while(p1->stack_card.size()>0){
        playTurn();
        printLastTurn();
      // printStats();
    }
    
} //playes the game untill the end


void Game::printStats(){

cout<<"amount of draws: "<< to_string(draw)<<endl;

float pre= (draw/Turn_Of_game.size()*100);
cout<<" of draws: "<< to_string(pre)<<"%"<<endl;
cout <<p1->getString() <<" won "<< p1->cardesTaken() << endl; // prints the amount of cards this player has won. 
cout <<p2->getString()<< " won "<< p2->cardesTaken() << endl;
cout<< p1->getString() <<" won "<<p1->count_win<<" timse "<<endl;
cout<< p2->getString() <<" won "<<p2->count_win<<" timse "<<endl;



}// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )










