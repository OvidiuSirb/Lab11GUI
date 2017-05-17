//
// Created by Ovi on 16.05.2017.
//

#include "FilePhoto.h"

FilePhoto::FilePhoto() : Photo{}, filename{""}
{
}

void FilePhoto::setFilename(const std::string &filename) {
    this->filename=filename;
}
