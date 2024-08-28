#include "../../includes/Parsing/PostRequestBodyParsing.hpp"

/*PUBLIC FUNCTIONS*/

/*Canonical form*/

PostRequestBodyParsing::PostRequestBodyParsing(void)
{
}

PostRequestBodyParsing::~PostRequestBodyParsing(void)
{
}

void PostRequestBodyParsing::parse(HttpRequest &request)
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

PostRequestBodyParsing::PostRequestBodyParsing(const PostRequestBodyParsing &other) : RequestBodyParsing(other)
{
	*this = other;
}

PostRequestBodyParsing &PostRequestBodyParsing::operator=(const PostRequestBodyParsing &other)
{
	(void)other;
	return (*this);
}

// add here the validation of the body
void PostRequestBodyParsing::parseBody(std::istringstream &stream, HttpRequest &request) const
{
	std::string body;
	std::string line;


    /*
        Take appart the body of a post request into its components
        Look how it is done
    */

    //read the body
    std::getline(stream, line);
    //if the body is empty, the request is invalid
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