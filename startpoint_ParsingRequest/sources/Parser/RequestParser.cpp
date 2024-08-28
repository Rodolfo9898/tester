#include "../../includes/Parser/RequestParser.hpp"

/*PUBLIC FUNCTIONS*/

/* Cannonical form*/
RequestParser::RequestParser(void) : requestLineParser(), headersParser(), bodyParser()
{
}

RequestParser::RequestParser(const RequestParser &other)
{
	*this = other;
}

RequestParser &RequestParser::operator=(const RequestParser &other)
{
	if (this != &other)
	{
		requestLineParser = other.requestLineParser;
		headersParser = other.headersParser;
		bodyParser = other.bodyParser;
	}
	return (*this);
}

RequestParser::~RequestParser(void)
{
	if(this->bodyParser)
		delete this->bodyParser;
}

/*
	Function to parse the entire HTTP/1.1 request
	Note that this function will assume that the whole request is there
	there should still be some checks done to ensure that the elements are there
	before giving them to this function.

	If you encouner a problem with the parsing, the function will return adjust the 
	HttpRequest boolean to false,i n any other case it will return normaly.
	We assume that the HttpRequest is valid before parsing.
*/
void RequestParser::parseRequest(HttpRequest &httpRequest)
{
	// Parse the request line
	requestLineParser.parse(httpRequest);
	if (httpRequest.requestLine.getFullRequestLine() == "NULL")
		return parsingError(httpRequest);

	// Parse the headers
	headersParser.parse(httpRequest);
	if(httpRequest.headers.getAllHeaders().empty())
		return parsingError(httpRequest);

	// Select the appropriate body parser based on the request method
    bodyParser = selectBodyParser(httpRequest);
	
	// Parse the body
	// inside the body parser you also chack for the empty line
	if(bodyParser)
	{
		bodyParser->parse(httpRequest);
		delete bodyParser; // Clean up the dynamically allocated body parser
        bodyParser = NULL;
		if(!(httpRequest.body.getBody() == "NULL"))
			return parsingError(httpRequest);
		else if (httpRequest.info.getEmptyLine() == false)
			return parsingError(httpRequest);
	}
}

/*PRIVATE FUNCTIONS*/

void RequestParser::parsingError(HttpRequest &httpRequest)
{
	httpRequest.info.setValidRequest(false);
}

RequestBodyParsing* RequestParser::selectBodyParser(const HttpRequest &request)
{
	std::string method = request.requestLine.getMethode();
    if (method == "GET")
        return new GetRequestBodyParsing();
	else if (method == "POST")
		return new PostRequestBodyParsing();
    // Add more conditions for other HTTP methods if needed
    return NULL;
}