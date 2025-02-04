#include "../../includes/Parsing/GetRequestBodyParsing.hpp"

/*PUBLIC FUNCTIONS*/

/*Canonical form*/

GetRequestBodyParsing::GetRequestBodyParsing(void)
{
}

GetRequestBodyParsing::~GetRequestBodyParsing(void)
{
}

void GetRequestBodyParsing::parse(HttpRequest &request)
{
	std::istringstream stream(request.info.getFullRequest());
	std::string body;
	std::string line;
	// Skip the request line and headers
	while (std::getline(stream, line) && line != "\r")
		;
    // Store the remaining content
    std::string remainingContent((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
    // Create a new stream with the remaining content
    std::istringstream remaining(remainingContent);
	// Select the appropriate body validator based on the request method
	requestValidator.requestBodyValidator = requestValidator.createRequestBodyValidator(request);
	if (requestValidator.requestBodyValidator)
	{
		// Parse the body
        if(requestValidator.requestBodyValidator->hasEmptyLine(line))
        {
            request.info.setEmptyLine(true);
		    parseBody(remaining, request);
		    delete requestValidator.requestBodyValidator; // Clean up the dynamically allocated body validator
		    requestValidator.requestBodyValidator = NULL;
        }
        else
        {
			request.info.setEmptyLine(false);
            delete requestValidator.requestBodyValidator; // Clean up the dynamically allocated body validator
            requestValidator.requestBodyValidator = NULL;
        }
	}
}

/*PRIVATE FUNCTIONS*/

/*Canonical form*/

GetRequestBodyParsing::GetRequestBodyParsing(const GetRequestBodyParsing &other) : RequestBodyParsing(other)
{
	*this = other;
}

GetRequestBodyParsing &GetRequestBodyParsing::operator=(const GetRequestBodyParsing &other)
{
	(void)other;
	return (*this);
}

// add here the validation of the body
void GetRequestBodyParsing::parseBody(std::istringstream &stream, HttpRequest &request) const
{
	std::string body;
	std::string line;

    //read the body
    std::getline(stream, line);
    //if the body is not empty, the request is invalid
    requestValidator.requestBodyValidator->validate(line, request);
	while (std::getline(stream, line))
	{
		if(requestValidator.requestBodyValidator->validate(line, request) == false)
            break;
		body += line + "\n";
	}
    //only set the body if the request is valid
    if(request.info.getValidRequest() == true && body.empty() == false)
	    request.body.setBody(trim(body));
}