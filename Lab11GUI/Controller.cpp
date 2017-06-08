//
// Created by Ovi on 25.03.2017.
//

#include "Controller.h"
#include "Coat.h"
#include "RepositoryExceptions.h"

void Controller::add_coat_to_repository(const int &size, const std::string &colour, const std::string &photograph,
                                            const int &quantity, const int &price) {
    Coat c{size, colour, photograph, quantity, price}; //TODO mi-a dat o eroare legată de constructor
    this->repo.add_coat(c);

	this->UndoActions.push_back(std::make_unique<UndoAdd>(this->repo, c));
}


void Controller::delete_coat(const int& size,const std::string &colour)
{
	Coat c = this->repo.find_by_size_and_colour(size, colour);
    this->repo.delete_coat(size,colour);
	this->UndoActions.push_back(std::make_unique<UndoRemove>(this->repo, c));
}

void Controller::update_coat(const int &size, const std::string &colour,const int& size2,const std::string& colour2,const std::string& photograph,const int& quantity,const int& price) {
    Coat c{size2,colour2,photograph,quantity,price};
	Coat c2 = this->repo.find_by_size_and_colour(size, colour);
    this->repo.update_coat(size,colour,c);
	this->UndoActions.push_back(std::make_unique<UndoUpdate>(this->repo, c2, c));
}

void Controller::add_coats_to_photos() {
    vector<Coat> v = this->repo.get_coats();
    Coat* coats = v.data();
    for(int i = 0;i < v.size();i++)
    {
        Coat c = coats[i];
        this->photos.add(c);
    }
}

void Controller::add_coat_to_photos(const Coat& c) {
	this->photos.add(c);
}

void Controller::open_photos(int type) const{

    this->photos.displayPhoto(type);
}

void Controller::next_photo(int x) {
    this->photos.next(x);
}

void Controller::savePhotos(const std::string &filename) {
    
    this->photos.setFilename(filename);
    this->photos.writeToFile();
}

void Controller::open_file(int type,std::string html) const {

    this->photos.displayPhoto(type,html);
}

void Controller::undo()
{
	if (UndoActions.empty())
	{
		throw RepositoryException{"There are no more actions to undo."};
	}

	try {
		UndoActions.back()->executeUndo();
		UndoActions.pop_back();
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
}
