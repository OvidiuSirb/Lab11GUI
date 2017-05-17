//
// Created by Ovi on 16.05.2017.
//

#ifndef LAB5_6_CSVPHOTO_H
#define LAB5_6_CSVPHOTO_H
#include "FilePhoto.h"
#include <string>

class CSVPhoto : public FilePhoto{
public:
    /* Writes the photos to the file.
     * Throws: FileException - if it cannot write.
     */
    void writeToFile() override;
    /* Displays the playlist using Microsoft Excel.
     */
    void displayPhoto(int type,std::string html="") const override;
};


#endif //LAB5_6_CSVPHOTO_H
