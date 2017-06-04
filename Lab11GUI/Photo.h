//
// Created by Ovi on 02.04.2017.
//

#ifndef LAB5_6_PHOTO_H
#define LAB5_6_PHOTO_H
#include <vector>
#include "PhotoValidator.h"

using namespace std;

class Photo {
protected:
    vector<Coat> photos;
    int current;

public:
    Photo();

    //adds a current coat to the photographs
    void add(const Coat& coat);

    //return the current photo
    Coat get_current_photo();

    //starts showing the photographs
    void show();

    //shows the next photo
    void next(int x);

    //checks if there are no photos
    bool is_empty();

    virtual ~Photo(){}

    int get_size();

    int get_current();

	std::vector<Coat> getAll() { return this->photos; }
};


#endif //LAB5_6_PHOTO_H
