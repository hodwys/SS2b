#include "card.hpp"
# include <string>
#include <stdexcept>
#include "iostream"
namespace ariel{}
using namespace  ariel;
using namespace std;

Card::Card(int Num, string sha , string Number){
    num = Num;
    shape = sha;
    number = Number;
}
//constructor 


int Card ::Get_Num(){
    return this->num;
}

string Card ::Get_shape(){
    return this->shape;
}
        
string Card ::Get_number(){
    return this->number;
}

void Card ::print_Card(){

    cout << number << " of " << shape << endl;
}

       
       


