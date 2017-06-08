//
// Created by Ovi on 25.03.2017.
//
/*
#include <cstring>
#include <fstream>
#include "Ui.h"
#include "RepositoryExceptions.h"

using namespace std;

void Ui::run() {
    while(true)
    {
        this->add_coats_to_photos();
        Ui::print_menu();
        int command{0};
        cout << "Input the command: \n";
        cin >> command;
        cin.ignore();
        if(command == 0)
            break;

        //repository management
        if(command == 1)
        {
            while(true)
            {
                Ui::print_administrator_menu();
                int command_repo{0};
                cout << "Input the command: ";
                cin >> command_repo;
                cin.ignore();
                if(command_repo == 0)
                    break;
                switch(command_repo) {
                    case 1:
                        this->add_coat_to_repo();
                        this->add_coats_to_photos();
                        break;
                    case 2:
                        this->delete_coat();
                        break;
                    case 3:
                        this->update_coat();
                        break;
                    case 4:
                        this->display_all_coats_in_repo();
                        break;
                    case 5:
                        while (true) {
                            Ui::print_photos();
                            int command_photos{0};
                            cout << "Input the command: ";
                            cin >> command_photos;
                            cin.ignore();
                            if (command_photos == 0)
                                break;
                            Coat c;
                            Coat c2;
                            switch (command_photos)
                            {
                                case 1:
                                    if(this->ctrl.get_photos().is_empty())
                                    {
                                        cout << "Nothing to show,there are no photos."<< endl;
                                        continue;
                                    }
                                    this->ctrl.open_photos(1);
                                    c = this->ctrl.get_photos().get_current_photo();
                                    cout <<  c.get_colour()<< " - " << c.get_quantity() << " - " << c.get_size() << " - " << c.get_price()<<endl;
                                    break;
                                case 2:
                                    if(this->ctrl.get_photos().is_empty())
                                    {
                                        cout << "Nothing to show,there are no photos."<< endl;
                                        continue;
                                    }
                                    this->ctrl.next_photo();
                                    c2 = this->ctrl.get_photos().get_current_photo();
                                    cout <<  c2.get_colour()<< " - " << c2.get_quantity() << " - " << c2.get_size() << " - " << c2.get_price()<<endl;
                                    break;
                                default:break;
                            }
                        }
                    default:break;
                }
            }
        }
        if (command == 2)
        {
            Ui::print_user_menu();
            int command_repo{0};
            cout << "Input the command: ";
            cin >> command_repo;
            cin.ignore();
            if(command_repo == 0)
                break;
            cout << "View the shopping basket:" << '\n' << "1-In CSV\n" << "2-In html\n";
            int type;
            cin >> type;
            switch(command_repo) {
                case 1: {
                    int cmd;
                    cout << "1-View all\n";
                    cout << "2-Search by size\n";
                    cout << "3-See the shopping basket.\n";
                    cin >> cmd;
                    int size2;
                    if(cmd == 2) {
                        cout << "Input the size:\n";
                        cin >> size2;
                        cin.ignore();
                    }
                    else
                        size2 = 100213098;
                    vector<Coat> v = this->ctrl.get_repo().get_coats();
                    Coat* coats = v.data();
                    int sum = 0;
                    string str = "";
                    for(int i = 0;i < v.size(); i++)
                    {
                        Coat c = coats[i];
                        if (c.get_size() == size2 || size2 == 100213098) {
                            //const int& size,const std::string& colour,const std::string& photograph,const int& quantity,const int& price
                            cout << c.get_size() << " - " << c.get_colour() << " - " << c.get_quantity() << " - "
                                 << c.get_price() << "$" << endl;
                            this->ctrl.next_photo(i + 1);
                            cout << "Add to the basket?\n";
                            cout << "1-Yes\n";
                            cout << "2-No\n";
                            int answer;
                            cin >> answer;
                            if (answer==1) {
                                sum += c.get_price();
                                str += to_string(c.get_size());
                                str += " - ";
                                str += c.get_colour();
                                str += '\n';
                                this->file_photos.push_back(c);
                                Ui::savePhotosToFile(type);
                            }
                            cout <<"The sum is:"<< sum << '\n';
                            cout << str << '\n';
                        }
                        if (i == v.size()-1)
                        {
                            cout << "Review?\n";
                            cout << "1-Yes\n";
                            cout << "2-No\n";
                            cout << "3-Show\n";
                            int answer;
                            cin >> answer;
                            if (answer==1)
                                i = 0;
                            if(answer==3)
                            {
                                if(type==1)
                                    this->ctrl.open_file(type);
                                else
                                    this->ctrl.open_file(type,"file:///C:/Users/Ovi/Desktop/Lab5-6%20-%20Copie%20-%20Copie/Coats.html");
                            }

                        }
                    }
                    break;
                }
                default:break;
            }
    }
}}

void Ui::print_menu() {
    cout << endl;
    cout << "1 - Administrator mode.\n";
    cout << "2 - User mode.\n";
    cout << "0 - Exit.\n";
}

void Ui::print_administrator_menu() {
    cout << "Possible commands: " << endl;
    cout << "\t 1 - Add a coat." << endl;
    cout << "\t 2 - Delete a coat." << endl;
    cout << "\t 3 - Update a coat." << endl;
    cout << "\t 4 - List the coats." << endl;
    cout << "\t 5 - Show the photos." << endl;

}

//Todo print_user_menu

void Ui::update_coat() {
    cout << "Enter size: ";
    int size;
    cin >> size;
    cout << "Enter colour: ";
    std::string colour;
    cin >> colour;

    cout << "Enter the new colour: ";
    std::string colour2;
    cin >> colour2;
    cout << "Enter the new photograph's link:";
    std::string photograph;
    cin >> photograph;
    cout << "Enter the new quantity: ";
    int quantity = 0;
    cin >> quantity;
    cout << "Enter the new price: ";
    int price;
    cin >> price;
    cout << "Enter the new size: ";
    int size2 = 0;
    cin >> size2;

    this->ctrl.update_coat(size,colour,size2,colour2,photograph,quantity,price);
    this->ctrl.add_coats_to_photos();
}

void Ui::delete_coat() {
    cout << "Enter size: ";
    int size;
    cin >> size;
    cout << "Enter colour: ";
    std::string colour;
    cin >> colour;

    this->ctrl.delete_coat(size,colour);
    this->ctrl.add_coats_to_photos();
}
void Ui::add_coat_to_repo() {
    cout << "Enter the colour: ";
    std::string colour;
    cin >> colour;
    cout << "Enter the photograph's link:";
    std::string photograph;
    cin >> photograph;
    cout << "Enter the quantity: ";
    int quantity = 0;
    cin >> quantity;
    cout << "Enter the price: ";
    int price;
    cin >> price;
    cout << "Enter the size: ";
    int size = 0;
    cin >> size;

    this->ctrl.add_coat_to_repository(size,colour,photograph,quantity,price);
    this->ctrl.add_coats_to_photos();
}

void Ui::display_all_coats_in_repo() {
    vector<Coat> v = this->ctrl.get_repo().get_coats();
    Coat* coats = v.data();
    if(coats == NULL)
        return;

    if (v.size() == 0)
    {
        cout << "There are no coats in the repository.\n";
        return;
    }

    for(int i = 0;i < v.size();i++)
    {
        Coat c = coats[i];
        //const int& size,const std::string& colour,const std::string& photograph,const int& quantity,const int& price
        cout << c.get_size() << " - " << c.get_colour() << " - " << c.get_quantity() << " - " << c.get_price() << "$" << endl;
    }
}

void Ui::print_photos() {
    cout << "Possible commands: " << endl;
    cout << "\t 1 - Start." << endl;
    cout << "\t 2 - Next." << endl;
}

void Ui::add_coats_to_photos() {
    this->ctrl.add_coats_to_photos();
}

void Ui::print_user_menu() {
    cout << "Possible commands: " << endl;
    cout << "\t 1 - See the trench coats." << endl;
}

void Ui::savePhotosToFile(int type) {
    if(type==1) {
        std::string filename = "..\\Coats2.txt";
        try {
            ofstream file(filename);
            if (!file.is_open())
                throw FileException("The file could not be opened!");

            for (auto s : this->file_photos) {
                file << s;
            }

            if (this->file_photos.size() == 0) {
                cout << "Photos cannot be displayed!" << endl;
                return;
            }
            file.close();
        }
        catch (FileException &e) {
            cout << e.what() << endl;
        }
    }
    else {
        std::string filename = "..\\Coats.html";
        try {
            ofstream file(filename);
            if (!file.is_open())
                throw FileException("The file could not be opened!");

            file << "<!DOCTYPE html>\n"<<
                     "<html>\n"<<
                    "<head>\n"<<
                    "<title>COATS</title>\n"<<
                    "</head>\n"<<
                    "<body>\n"<<
                    "<table border=\"1\">\n"<<
                    " <tr>\n"<<
                    "<td>Size</td>\n"<<
                    "<td>Colour</td>\n"<<
                    "<td>Quantity</td>\n"<<
                    "<td>Price</td>\n"<<
                    "<td>Image</td>\n"<<
                    " </tr>\n";
            for (auto s : this->file_photos) {
//const int& size,const std::string& colour,const std::string& photograph,const int& quantity,const int& price
                file << " <tr>\n"<<
                         "<td>"<<s.get_size()<<"</td>\n"<<
                         "<td>"<<s.get_colour().c_str()<<"</td>\n"<<
                         "<td>"<<s.get_quantity()<<"</td>\n"<<
                         "<td>"<<s.get_price()<<"</td>\n"<<
                         "<td><a href="<<s.get_photo().c_str()<<">Link</a></td>\n"<<
                         " </tr>\n";
            }
            file << "</table>\n" << "</body>\n" << "</html>";

            if (this->file_photos.size() == 0) {
                cout << "Photos cannot be displayed!" << endl;
                return;
            }
            file.close();
        }
        catch (FileException &e) {
            cout << e.what() << endl;
        }
    }
}
*/

