//
// Created by Ovi on 25.03.2017.
//
/*
#ifndef LAB5_6_UI_H
#define LAB5_6_UI_H


#include "Controller.h"
#include <vector>

class Ui {
private:
    Controller ctrl;
    vector<Coat> file_photos;

public:
    Ui(const Controller& c) : ctrl(c) {}

    void run();

private:
    static void print_menu();
    static void print_administrator_menu();
    static void print_photos();

    void display_all_coats_in_repo();

    void add_coat_to_repo();
    void delete_coat();
    void update_coat();
    void add_coats_to_photos();

    void print_user_menu();

    void savePhotosToFile(int type);
};


#endif //LAB5_6_UI_H
*/