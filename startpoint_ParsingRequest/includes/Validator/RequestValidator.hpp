#pragma once
#include "../Project.hpp"
#include "../Validation/GetRequestBodyValidation.hpp"
#include "../Validation/PostRequestBodyValidation.hpp"
#include "../Validation/RequestBodyValidation.hpp"
#include "../Validation/RequestHeadersValidation.hpp"
#include "../Validation/RequestLineValidation.hpp"

class RequestValidator
{
 	public:
	/* Cannonical form*/
	RequestValidator(void);
	~RequestValidator(void);
	RequestValidator(const RequestValidator &other);
	RequestValidator &operator=(const RequestValidator &other);
	RequestBodyValidation *createRequestBodyValidator(const HttpRequest &httpRequest);

	RequestLineValidation requestLineValidator;
	RequestHeadersValidation requestHeadersValidator;
	RequestBodyValidation *requestBodyValidator;
};
