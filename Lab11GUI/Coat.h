//
// Created by Ovi on 25.03.2017.
//

#ifndef LAB5_6_COAT_H
#define LAB5_6_COAT_H
#include <iostream>
#include <vector>
#include "Utils.h"
#include <ciso646>

using namespace std;

class Coat {
private:
    std::string colour;
    std::string photograph;
    int size;
    int price;
    int quantity;

public:
    //default constructor
    Coat();

    //constructor with parameters
    Coat(const int &size, const std::string &colour, const std::string &photograph, const int &quantity,
         const int &price);

    std::string get_colour() const { return colour; }

    std::string get_photo() const { return photograph; }

    int get_size() const { return size; }

    int get_price() const { return price; }

    int get_quantity() const { return quantity; }

    //The page corresponding to the coat's link is opened in a browser.
    void photo();

    bool operator==(const Coat &other) {
        return this->colour == other.colour and this->photograph == other.photograph and this->size == other.size and
               this->size == other.size and this->quantity == other.quantity;
    }

    friend std::istream& operator>>(std::istream& is, Coat& s);
    friend std::ostream& operator<<(std::ostream& os, const Coat& s);
};


#endif //LAB5_6_COAT_H
