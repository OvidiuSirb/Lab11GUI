#include "PhotoValidator.h"

using namespace std;

PhotoException::PhotoException(std::vector<std::string> _errors): errors{_errors}
{
}

std::vector<std::string> PhotoException::getErrors() const
{
    return this->errors;
}

void PhotoValidator::validate(const Coat & c)
{
    vector<string> errors;
    if (c.get_colour().size() < 3)
        errors.push_back("The colour cannot be less than 2 characters!\n");
    if (c.get_quantity()<=0)
        errors.push_back(string("The quantity cannot be 0 or less!\n"));
    if (c.get_price()<=0)
        errors.push_back(string("The price cannot be 0 or less!\n"));
    if (c.get_size()<=0)
        errors.push_back(string("The size cannot be 0 or less!\n"));

    // search for "www" or "http" at the beginning of the source string
    long long int posWww = c.get_photo().find("www");
    long long int posHttp = c.get_photo().find("http");
    if (posWww != 0 && posHttp != 0)
        errors.push_back("The google source must start with one of the following strings: \"www\" or \"http\"");

    if (errors.size() > 0)
        throw PhotoException(errors);
}
