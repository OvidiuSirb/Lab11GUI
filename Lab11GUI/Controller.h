//
// Created by Ovi on 25.03.2017.
//

#ifndef LAB5_6_CONTROLLER_H
#define LAB5_6_CONTROLLER_H
#include "Repository.h"
#include "Photo.h"
#include <iostream>
#include "FilePhoto.h"
#include "PhotoValidator.h"
#include "Undo.h"
#include <memory>
#include <vector>

class Controller {
private:
    Repository& repo;
    FilePhoto& photos;
    PhotoValidator validator;

	std::vector<std::unique_ptr<UndoAction>> UndoActions;
	std::vector<std::unique_ptr<Coat>> UndoElements;
	
public:
    Controller(Repository& r,FilePhoto& p,PhotoValidator v): repo { r }, photos{p}, validator{v} {}

	Controller(const Controller& ctrl) = delete;		// controller cannot be copied now, because it contains unique_ptr
	void operator=(const Controller& ctrl) = delete;	// same for assignment

//Controller(const Repository& r,FilePhoto* p,PhotoValidator v)
    Repository get_repo() const {return repo;}
    Photo get_photos() const {return photos;}
	std::vector<Coat> get_coats_from_photos() { return this->photos.getAll(); }

    //Add a coat to the repository.
    //Input: size,colour,photograph,quantity,price - the coat's infos
    //Output:the coat is added to the repository.
    void add_coat_to_repository(const int& size,const std::string& colour,const std::string& photograph,const int& quantity,const int& price);

    //Deletes a coat from the repository.
    //Input: size- the size of the searched coat
    //      colour-the colour of the searched coat.
    //Output:the coat is deleted.
    void delete_coat(const int& size,const std::string &colour);

    //Updates a coat from the repository.
    //Input: size,colour- the infos of the searched coat
    //      size2,colour2,photograph,quantity - the new infos
    //Output:the coat is updated.
    void update_coat(const int &size, const std::string &colour,const int& size2,const std::string& colour2,const std::string& photograph,const int& quantity,const int& price);

    //All the coats from the repository are added to the list of photos.
    void add_coats_to_photos();

	void add_coat_to_photos(const Coat & c);

    //The first photo is shown.If there aren't any,it displays a message.
    void open_photos(int type) const;

    //The next photo is shown
    void next_photo(int x = 1);

    /*
		Saves the photos.
		Throws: FileException - if the given file cannot be opened.
	*/
    void savePhotos(const std::string& filename);

    void open_file(int type,std::string html="") const;

	void undo();
};


#endif //LAB5_6_CONTROLLER_H
