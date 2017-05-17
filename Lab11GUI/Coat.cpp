//
// Created by Ovi on 25.03.2017.
//

#include "Coat.h"
#include <Windows.h>
#include <string.h>
#include <iostream>

Coat::Coat(): size(0),colour(""),photograph(""),quantity(0),price(0) {}
Coat::Coat(const int& size, const std::string& colour, const std::string& photograph, const int& quantity, const int& price) {
    this->size = size;
    this->colour  = colour;
    this->price = price;
    this->quantity = quantity;
    this->photograph = photograph;
}
/*
Coat::~Coat() {
    std::cout << "Destructor called for: " << this->size << ", " << this->colour << ", "<< this->price << ", "<< this->quantity << ", "<< this->photograph<< ", ";
//    delete(this->size);
//    delete(this->colour);
//    delete(this->price);
//    delete(this->quantity);
//    delete(this->photograph);
}
*/
void Coat::photo()
{
    ShellExecuteA(NULL,NULL,"chrome.exe",this->get_photo().c_str(),NULL,SW_SHOWMAXIMIZED);
}

istream& operator>>(istream &is, Coat &c)
{
    string line;
    getline(is,line);

    vector<string> tokens= tokenize(line,',');
    if(tokens.size() != 5)
        return is;
    //const int& size,const std::string& colour,const std::string& photograph,const int& quantity,const int& price
    c.size = stoi(tokens[0]);
    c.colour=tokens[1];
    c.photograph=tokens[2];
    c.quantity=stoi(tokens[3]);
    c.price=stoi(tokens[4]);
    return is;
}

ostream & operator<<(ostream & os,const Coat & c)
{
    os << c.size << "," << c.colour<<","<<c.photograph << "," << c.quantity << "," << c.price << "$\n";
    return os;
}
