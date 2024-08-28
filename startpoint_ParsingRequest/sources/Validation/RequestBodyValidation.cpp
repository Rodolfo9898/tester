#include "../../includes/Validation/RequestBodyValidation.hpp"

/*PUBLIC FUNCTIONS*/

/*Canonical form*/

RequestBodyValidation::RequestBodyValidation(void)
{
}

RequestBodyValidation::~RequestBodyValidation(void)
{
}

RequestBodyValidation::RequestBodyValidation(const RequestBodyValidation &other)
{
    *this = other;
}


RequestBodyValidation &RequestBodyValidation::operator=(const RequestBodyValidation &other)
{
    (void)other;
    return (*this);
}

/*PROTECTED FUNCTIONS*/

//NEED TO CHECK IT OUT
bool RequestBodyValidation::hasEmptyLine(const std::string &bodyLine)
{
    if (bodyLine.compare("\r") == 0)
        return (true);
    return (false);
}