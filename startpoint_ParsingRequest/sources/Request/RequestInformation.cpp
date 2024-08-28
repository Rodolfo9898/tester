#include "../../includes/Request/RequestInformation.hpp"

/*PUBLIC FUNCTIONS*/

// Canonical form
RequestInformation::RequestInformation(void) : full("NULL"), emptyLine(false), validRequest(true), completeRequest(false)
{
}

RequestInformation::RequestInformation(const std::string &raw) : full(raw), emptyLine(false), validRequest(true), completeRequest(false)
{
}

RequestInformation::RequestInformation(const RequestInformation &other)
{
    *this = other;
}

RequestInformation &RequestInformation::operator=(const RequestInformation &other)
{
    if (this != &other)
    {
        full = other.full;
        emptyLine = other.emptyLine;
        validRequest = other.validRequest;
        completeRequest = other.completeRequest;
    }
    return (*this);
}

RequestInformation::~RequestInformation(void)
{
}

/*Getters*/
std::string RequestInformation::getFullRequest(void) const
{
    return (full);
}

bool RequestInformation::getEmptyLine(void) const
{
    return (emptyLine);
}

bool RequestInformation::getValidRequest(void) const
{
    return (validRequest);
}

bool RequestInformation::getCompleteRequest(void) const
{
    return (completeRequest);
}

/*Setters*/
void RequestInformation::setFullRequest(const std::string &raw)
{
    full = raw;
}

void RequestInformation::setEmptyLine(bool b)
{
    emptyLine = b;
}

void RequestInformation::setValidRequest(bool b)
{
    validRequest = b;
}

void RequestInformation::setCompleteRequest(bool b)
{
    completeRequest = b;
}
