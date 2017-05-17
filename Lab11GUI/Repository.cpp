//
// Created by Ovi on 25.03.2017.
//

#include "Coat.h"
#include "Repository.h"
#include <string.h>
#include <fstream>
#include "RepositoryExceptions.h"

using namespace std;

Repository::Repository(const std::string& filename) {
    this->filename = filename;
    this->readFromFile();

}

void Repository::add_coat(const Coat &c) {
    this->coats.push_back(c);
    this->writeToFile();
}

void Repository::delete_coat(const int &size,const std::string &colour) {
    Coat index;
    index = Repository::find_by_size_and_colour(size, colour);
    const std::string photo = index.get_photo();
    const int quantity = index.get_quantity();
    const int price = index.get_price();
    Coat c(size, colour, photo, quantity, price);
    auto it = find(coats.begin(), coats.end(), c);

    if (index.get_size() == -1)
        cout << "RAHAT";
    else {
        this->coats.erase(it);
        this->writeToFile();
    }
}

void Repository::update_coat(const int &size, const std::string &colour,Coat c) {
    Coat index;
    index = Repository::find_by_size_and_colour(size,colour);
    auto it = find(coats.begin(),coats.end(),index);
    this->coats.erase(it);
    this->writeToFile();
    this->add_coat(c);
}

Coat Repository::find_by_size_and_colour(const int &size, const std::string &colour) {

    if(coats.size() == 0)
        return Coat(-1,"asa","sasasda",121,121);

    for( auto& el:coats)
    {
        if(el.get_size() == size && el.get_colour() == colour)
            return el;
    }

    return Coat(-1,"asa","sasasda",121,121);
}

void Repository::readFromFile()
{
    ifstream file(this->filename);
    if (!file.is_open())
        throw FileException("The file could not be opened!");

    Coat c;
    while (file >> c)
        this->coats.push_back(c);

    file.close();
}
void Repository::writeToFile()
{
    ofstream file(this->filename);
    if (!file.is_open())
        throw FileException("The file could not be opened!");

    for (auto s : this->coats)
    {
        file << s;
    }

    file.close();
}


/*
Coat Repository::find_by_size_and_colour2(const int &size, const std::string &colour) {

    Coat* coats_in_dynamic_vector = this->coats.getAllElems();
    if(coats_in_dynamic_vector == NULL)
        Coat{};

    for(int i = 0;i < this->coats.getSize(); i++)
    {
        Coat c = coats_in_dynamic_vector[i];
        if (c.get_colour() == colour && c.get_size() == size)
            return c;

    }

    return Coat();
}*/




