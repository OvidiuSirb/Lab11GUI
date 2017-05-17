//
// Created by Ovi on 16.05.2017.
//

#include "CSVPhoto.h"
#include <fstream>
#include <Windows.h>
#include "RepositoryExceptions.h"

void CSVPhoto::writeToFile() {
    ofstream f(this->filename);

    if(!f.is_open())
        throw FileException("The file could not be opened!");

    for(auto s: this->photos)
        f << s;

    f.close();
}

void CSVPhoto::displayPhoto(int type,std::string html) const {
    string aux="\""+this->filename +"\"" ;
    if(type==1)
        ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\Notepad++\\notepad++", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
    else
        ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome",html.c_str(), NULL, SW_SHOWMAXIMIZED);
}
