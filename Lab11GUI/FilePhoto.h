#pragma once
#include "Photo.h"

class FilePhoto : public Photo
{
protected:
    std::string filename;

public:
    FilePhoto();
    virtual ~FilePhoto() {}

    void setFilename(const std::string& filename);
    virtual void writeToFile() = 0;
    virtual void displayPhoto(int type,std::string html="") const = 0;
};
