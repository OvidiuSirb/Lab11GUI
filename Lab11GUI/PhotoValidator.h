#pragma once
#include <string>
#include "Coat.h"
#include <vector>

class PhotoException
{
private:
    std::vector<std::string> errors;

public:
    PhotoException(std::vector<std::string> _errors);
    std::vector<std::string> getErrors() const;
};

class PhotoValidator
{
public:
    PhotoValidator() {}
    static void validate(const Coat& c);
};

