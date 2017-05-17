//
// Created by Ovi on 03.04.2017.
//

#include "tests.h"
#include "Repository.h"
#include "Controller.h"
#include "CSVPhoto.h"
#include "PhotoValidator.h"
#include "Coat.h"
#include "RepositoryExceptions.h"
#include <assert.h>
#include <vector>
#include <string.h>

using namespace std;

void tests::test_repo() {
    Repository repo("..\\Tests.txt");
    assert(repo.get_coats().size()==3);

    const Coat c{13,"black","https://s-media-cache-ak0.pinimg.com/736x/59/7a/7b/597a7b5309e515cad0c25613ea6a74e3.jpg",100,1000};

    repo.add_coat(c);
    assert(repo.get_coats().size()==4);

    repo.delete_coat(13,"black");
    assert(repo.get_coats().size()==3);

    const Coat c3= repo.find_by_size_and_colour(13,"black");
    assert(c3.get_price()==1000 && c3.get_quantity()==100);

    repo.add_coat(c);
    const Coat c2{14,"white","http://i01.i.aliimg.com/img/pb/815/673/406/406673815_098.jpg",200,2000};
    repo.update_coat(13,"black",c2);
    repo.delete_coat(14,"white");
    assert(repo.get_coats().size()==3);
}


void tests::test_controller()
{
    Repository repo("..\\Tests.txt");
    FilePhoto* p= new CSVPhoto{};
    Controller ctrl(repo, p, PhotoValidator());
    assert(ctrl.get_repo().get_coats().size()==3);

    ctrl.add_coat_to_repository(13,"black","https://s-media-cache-ak0.pinimg.com/736x/59/7a/7b/597a7b5309e515cad0c25613ea6a74e3.jpg",100,1000);
    assert(ctrl.get_repo().get_coats().size()==4);

    ctrl.delete_coat(13,"black");
    assert(repo.get_coats().size()==3);

    ctrl.add_coat_to_repository(13,"black","https://s-media-cache-ak0.pinimg.com/736x/59/7a/7b/597a7b5309e515cad0c25613ea6a74e3.jpg",100,1000);

    ctrl.update_coat(13,"black",14,"white","http://i01.i.aliimg.com/img/pb/815/673/406/406673815_098.jpg",200,2000);
    ctrl.delete_coat(14,"white");
    assert(repo.get_coats().size()==3);


    ctrl.add_coat_to_photos();
    assert(ctrl.get_photos()->get_size()==repo.get_coats().size());

    Coat c{14,"white","http://i01.i.aliimg.com/img/pb/815/673/406/406673815_098.jpg",200,2000};

}

void tests::test_coats()
{
    Coat c;
    assert(c.get_size()==0);
    assert(c.get_price()==0);
    assert(c.get_quantity()==0);
    assert(c.get_colour()=="");
    assert(c.get_photo()=="");

    Coat other{14,"white","http://i01.i.aliimg.com/img/pb/815/673/406/406673815_098.jpg",200,2000};
    assert(other.get_size()==14);
    assert(other.get_price()==2000);
    assert(other.get_quantity()==200);
    assert(other.get_colour()=="white");
    assert(other.get_photo()=="http://i01.i.aliimg.com/img/pb/815/673/406/406673815_098.jpg");

    c = other;
    assert(c.get_size()==14);
    assert(c.get_price()==2000);
    assert(c.get_quantity()==200);
    assert(c.get_colour()=="white");
    assert(c.get_photo()=="http://i01.i.aliimg.com/img/pb/815/673/406/406673815_098.jpg");
}

void tests::test_photo_validator()
{
    int counter=0;
    Coat c{14,"wh","http://i01.i.aliimg.com/img/pb/815/673/406/406673815_098.jpg",200,2000};
    try{
        PhotoValidator().validate(c);
    }
    catch(PhotoException& p) {
        assert(p.getErrors()[0]=="The colour cannot be less than 2 characters!\n");
        counter = 1;
    }
    assert(counter==1);
    counter=0;

    Coat c2{14,"white","i01.i.aliimg.com/img/pb/815/673/406/406673815_098.jpg",200,2000};
    try{
        PhotoValidator().validate(c2);
    }
    catch(PhotoException& p) {
        assert(p.getErrors()[0]=="The google source must start with one of the following strings: \"www\" or \"http\"");
        counter=1;
    }
    assert(counter==1);
    counter=0;

    Coat c3{0,"white","www.i01.i.aliimg.com/img/pb/815/673/406/406673815_098.jpg",200,2000};
    try{
        PhotoValidator().validate(c3);
    }
    catch(PhotoException& p) {
        assert(p.getErrors()[0]=="The size cannot be 0 or less!\n");
        counter=1;
    }
    assert(counter==1);
    counter=0;

    Coat c4{100,"white","www.i01.i.aliimg.com/img/pb/815/673/406/406673815_098.jpg",0,2000};
    try{
        PhotoValidator().validate(c4);
    }
    catch(PhotoException& p) {
        assert(p.getErrors()[0]=="The quantity cannot be 0 or less!\n");
        counter=1;
    }
    assert(counter==1);
    counter=0;

    Coat c5{100,"white","www.i01.i.aliimg.com/img/pb/815/673/406/406673815_098.jpg",10,0};
    try{
        PhotoValidator().validate(c5);
    }
    catch(PhotoException& p) {
        assert(p.getErrors()[0]=="The price cannot be 0 or less!\n");
        counter=1;
    }
    assert(counter==1);
}

void tests::test_photo(){
    Photo p;
    assert(p.is_empty()==1);

    Coat c{14,"white","http://i01.i.aliimg.com/img/pb/815/673/406/406673815_098.jpg",200,2000};
    p.add(c);
    assert(p.get_size()==1);
}

void tests::test_csv(){
    CSVPhoto c;
    int counter=0;
    try{
        c.writeToFile();
    }
    catch(FileException& e){
        counter=1;
    }
    assert(counter==1);
}

