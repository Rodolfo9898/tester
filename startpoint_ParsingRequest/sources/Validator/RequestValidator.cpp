#include "../../includes/Validator/RequestValidator.hpp"
/*PUBLIC FUNCTIONS*/

/* Cannonical form*/
RequestValidator::RequestValidator(void) : requestLineValidator(), requestHeadersValidator(),requestBodyValidator(NULL)
{
}

RequestValidator::RequestValidator(const RequestValidator &other) :requestLineValidator(other.requestLineValidator)
{
}

RequestValidator &RequestValidator::operator=(const RequestValidator &other)
{
	if (this != &other)
	{
		requestLineValidator = other.requestLineValidator;
		requestHeadersValidator = other.requestHeadersValidator;
		requestBodyValidator = other.requestBodyValidator;
	}
	return (*this);
}

RequestValidator::~RequestValidator(void)
{
	if (requestBodyValidator)
		delete requestBodyValidator;
}

RequestBodyValidation *RequestValidator::createRequestBodyValidator(const HttpRequest &httpRequest)
{
	std::string method = httpRequest.requestLine.getMethode();
	if (method == "GET")
		return (new GetRequestBodyValidation());
	else if (method == "POST")
		return (new PostRequestBodyValidation());
	// else if (httpRequest.getMethod() == "POST")
	// 	return (new PostRequestBodyValidation());
	 else
	 	return (NULL);
}
