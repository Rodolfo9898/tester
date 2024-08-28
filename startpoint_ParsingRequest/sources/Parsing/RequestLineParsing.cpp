#include "../../includes/Parsing/RequestLineParsing.hpp"

/*PUBLIC FUNCTIONS*/

/*
	We dont need to instanciate it via copy
	So no assign operation or copy as public
*/

/* Cannonical form*/
RequestLineParsing::RequestLineParsing(void)
{
}

RequestLineParsing::~RequestLineParsing(void)
{
}

/*
  Function to pasre depending on what you will parse
  request line, headers, body, etc...
*/
void RequestLineParsing::parse(HttpRequest &request)
{
	std::istringstream stream(request.info.getFullRequest());
	std::string line;

	if (std::getline(stream, line))
		request.requestLine = parseRequestLine(trim(line));
	else
		request.requestLine = parseRequestLine("");
}

/*PRIVATE FUNCTIONS*/

/*Canonical form*/
RequestLineParsing::RequestLineParsing(const RequestLineParsing &other) : RequestParsing(other)
{
	*this = other;
}

RequestLineParsing &RequestLineParsing::operator=(const RequestLineParsing &other)
{
	(void)other;
	return (*this);
}

/*
	Function to parse only the request line
	Since you hold only the first line already you just need to split on the char 'space'
*/
RequestLine RequestLineParsing::parseRequestLine(const std::string &line) const
{
	// hold the 3 elements of the request line
	std::vector<std::string> parts = split(line, ' ');
	if (requestValidator.requestLineValidator.isValidRequestLine(parts))
		return (RequestLine(line, parts[0], parts[1], parts[2]));
	return (RequestLine());
}
