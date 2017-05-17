//
// Created by Ovi on 25.03.2017.
//

#include "Controller.h"


void Controller::add_coat_to_repository(const int &size, const std::string &colour, const std::string &photograph,
                                            const int &quantity, const int &price) {
    Coat c{size, colour, photograph, quantity, price}; //TODO mi-a dat o eroare legată de constructor
    this->repo.add_coat(c);
}


void Controller::delete_coat(const int& size,const std::string &colour)
{
    this->repo.delete_coat(size,colour);
}

void Controller::update_coat(const int &size, const std::string &colour,const int& size2,const std::string& colour2,const std::string& photograph,const int& quantity,const int& price) {
    Coat c{size2,colour2,photograph,quantity,price};
    this->repo.update_coat(size,colour,c);
}

void Controller::add_coat_to_photos() {
    vector<Coat> v = this->repo.get_coats();
    Coat* coats = v.data();
    for(int i = 0;i < v.size();i++)
    {
        Coat c = coats[i];
        this->photos->add(c);
    }
}

void Controller::open_photos(int type) const{

    if(this->photos ==nullptr)
        return;

    this->photos->displayPhoto(type);
}

void Controller::next_photo(int x) {
    this->photos->next(x);
}

void Controller::savePhotos(const std::string &filename) {
    if(this->photos== nullptr)
        return;
    this->photos->setFilename(filename);
    this->photos->writeToFile();
}

void Controller::open_file(int type,std::string html) const {
    if(this->photos == nullptr)
        return;

    this->photos->displayPhoto(type,html);
}
//TODO open_photos si next_photos
