#ifndef CARD_HPP
#define CARD_HPP


#include "iostream"
#include <stdexcept>
namespace ariel{}
using namespace  ariel;
#include <string>
using namespace std;

class Card{

    private:
        int num;
        string shape;
        string number;
        

    public:
        Card(){}
        Card(int num, string shape, string number);

        int Get_Num();
        string Get_shape();
        string Get_number();

        void print_Card();

};







#endif
