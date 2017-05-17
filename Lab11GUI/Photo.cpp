//
// Created by Ovi on 02.04.2017.
//

#include "Photo.h"
Photo::Photo() {
    this->current = 0;
}

void Photo::add(const Coat& coat) {

    PhotoValidator p;
    p.validate(coat);
    this->photos.push_back(coat);
}

Coat Photo::get_current_photo(){
    if(this->current == this->photos.size())
        this->current = 0;
    Coat* elems = this->photos.data();
    if(elems != NULL)
        return elems[this->current];
    return Coat{};
}

void Photo::show(){
    if(this->photos.size() == 0)
        return;
    this->current = 0;
    Coat current_photo = this->get_current_photo();
    current_photo.photo();
}

void Photo::next(int x){
    if(this->photos.size() == 0)
        return;
    if(x != 1)
        this->current=0;
    this->current+=x;
    Coat current_coat = this->get_current_photo();
    current_coat.photo();
}

bool Photo::is_empty() {
    return this->photos.size() == 0;
}

int Photo::get_size() {
    return (int) this->photos.size();
}

int Photo::get_current(){
    return this->current;
}