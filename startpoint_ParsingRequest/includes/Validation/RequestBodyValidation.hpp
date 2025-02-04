#pragma once
#include "../Project.hpp"
#include "../Http/HttpRequest.hpp"

class RequestBodyValidation
{
  public:
    /* Cannonical form*/
    RequestBodyValidation(void);
    virtual ~RequestBodyValidation(void);
    RequestBodyValidation(const RequestBodyValidation &other);
    RequestBodyValidation &operator=(const RequestBodyValidation &other);
    virtual bool validate(std::string &bodyLine ,HttpRequest &httpRequest) = 0;
    bool hasEmptyLine(const std::string &bodyLine);

};