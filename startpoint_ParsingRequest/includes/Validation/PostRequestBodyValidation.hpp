#pragma once
#include "../Http/HttpRequest.hpp"
#include "../Project.hpp"
#include "RequestBodyValidation.hpp"

class PostRequestBodyValidation : public RequestBodyValidation
{
  public:
	/* Cannonical form*/
	PostRequestBodyValidation(void);
	~PostRequestBodyValidation(void);
	PostRequestBodyValidation(const PostRequestBodyValidation &other);
	PostRequestBodyValidation &operator=(const PostRequestBodyValidation &other);
	bool validate(std::string &bodyLine, HttpRequest &request);
};