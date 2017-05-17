//
// Created by Ovi on 25.03.2017.
//

#ifndef LAB5_6_REPOSITORY_H
#define LAB5_6_REPOSITORY_H

#include "Coat.h"
#include "assert.h"
//#include "DynamicVector.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Repository {
private:

    vector<Coat> coats;
    std::string filename;

public:
    //default constructor
    Repository(const std::string &filename);

    //Add a coat to the repository.
    //Input: c - a Coat
    //Output:the coat is added to the repository.
    void add_coat(const Coat& c);

    //Deletes a coat from the repository.
    //Input: size- the size of the searched coat
    //      colour-the colour of the searched coat.
    //Output:the coat is deleted.
    void delete_coat(const int&size,const std::string &colour);

    //Updates a coat from the repository.
    //Input: size- the size of the searched coat
    //      colour-the colour of the searched coat
    //      c-the updated coat
    //Output:the coat is updated.
    void update_coat(const int &size, const std::string &colour,Coat c);

    Coat find_by_size_and_colour(const int &size, const std::string &colour);
    //Coat find_by_size_and_colour2(const int &size, const std::string &colour);

    vector<Coat> get_coats() const { return coats; }


private:
    void readFromFile();


    void writeToFile();
};


#endif //LAB5_6_REPOSITORY_H
