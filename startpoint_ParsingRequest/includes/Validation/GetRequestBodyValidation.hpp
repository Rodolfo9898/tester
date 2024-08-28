#pragma once
#include "../Http/HttpRequest.hpp"
#include "../Project.hpp"
#include "RequestBodyValidation.hpp"

class GetRequestBodyValidation : public RequestBodyValidation
{
  public:
	/* Cannonical form*/
	GetRequestBodyValidation(void);
	~GetRequestBodyValidation(void);
	GetRequestBodyValidation(const GetRequestBodyValidation &other);
	GetRequestBodyValidation &operator=(const GetRequestBodyValidation &other);
	bool validate(std::string &bodyLine, HttpRequest &request);
};