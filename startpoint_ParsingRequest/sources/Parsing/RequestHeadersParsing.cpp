#include "../../includes/Parsing/RequestHeadersParsing.hpp"

/*PUBLIC FUNCTIONS*/

/*
	We dont need to instanciate it via copy
	So no assign operation or copy as public
*/

/* Cannonical form*/
RequestHeadersParsing::RequestHeadersParsing(void)
{
}

RequestHeadersParsing::~RequestHeadersParsing(void)
{
}

/*
  Function to pasre depending on what you will parse
  request line, headers, body, etc...
  //what happens when we receive a request with \n\r\n?
*/
void RequestHeadersParsing::parse(HttpRequest &request)
{
	std::istringstream stream(request.info.getFullRequest());
	std::string line;

	// Skip the request line
	std::getline(stream, line);

	// Parse all headers
	while (std::getline(stream, line) && line != "\r")
	{
		line = trim(line);
		if (line.empty() || requestValidator.requestHeadersValidator.getValidHeaders() == false)
			break ;
		parseSingleHeader(line, request);
	}
	if(requestValidator.requestHeadersValidator.getValidHeaders() == false)
		request.headers = RequestHeaders();
	
}

/*PRIVATE FUNCTIONS*/

/*Canonical form*/
RequestHeadersParsing::RequestHeadersParsing(const RequestHeadersParsing &other) : RequestParsing(other)
{
	*this = other;
}

RequestHeadersParsing &RequestHeadersParsing::operator=(const RequestHeadersParsing &other)
{
	(void)other;
	return (*this);
}

/*
	Function to parse a single header
	A header is defined as KEY: VALUE
	So we will look for the : to split it into a key, value pair.
	If you find one then proceed to populate the map that holds all the headers.
*/
void RequestHeadersParsing::parseSingleHeader(const std::string &line, HttpRequest &request)
{
	
	if (requestValidator.requestHeadersValidator.isValidHeader(line))
	{
		size_t pos = line.find(':');
		const std::string header_name = trim(line.substr(0, pos)) + ":";
		const std::string header_value = trim(line.substr(pos + 1));
		requestValidator.requestHeadersValidator.setSingleHeader(header_name, header_value);
		request.headers.setSingleHeader(header_name, header_value);
	}
}
