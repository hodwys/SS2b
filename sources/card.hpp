#ifndef CARD_HPP
#define CARD_HPP


#include "iostream"
#include <stdexcept>
namespace ariel{}
using namespace  ariel;
#include <string>
using namespace std;
#include <vector>


class Card{

    private:
        int num;
        string shape;
        string number;
        

    public:
        //Card(){}
        Card(int num=1, string shape = "dim", string number = "1");

        int Get_Num();
        string Get_shape();
        string Get_number();

        void print_Card();

};







#endif
