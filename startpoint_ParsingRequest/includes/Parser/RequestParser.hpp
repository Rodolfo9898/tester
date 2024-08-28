#pragma once
#include "../Project.hpp"
#include "../Http/HttpRequest.hpp"
#include "../Parsing/RequestLineParsing.hpp"
#include "../Parsing/RequestHeadersParsing.hpp"
#include "../Parsing/RequestBodyParsing.hpp"
#include "../Parsing/GetRequestBodyParsing.hpp"
#include "../Parsing/PostRequestBodyParsing.hpp"

class RequestParser
{
  public:
	/*Canonical form*/
	RequestParser(void);
	~RequestParser(void);
	RequestParser(const RequestParser &other);
	RequestParser &operator=(const RequestParser &other);

	/*
		Function to parse the entire HTTP/1.1 request
		Note that this function will assume that the whole request is there
		there should still be some checks done to ensure that the elements are there
		before giving them to this function.

		If you encouner a problem with the parsing, the function will return adjust the 
		HttpRequest boolean to false,i n any other case it will return normaly.
		We assume that the HttpRequest is valid before parsing.
	*/
	void parseRequest(HttpRequest &httpRequest);

  private:
	
	RequestBodyParsing* selectBodyParser(const HttpRequest &request);
	void parsingError(HttpRequest &httpRequest);
	/*
		All the components that are needed to parse the request
	*/

	// Request
	RequestLineParsing requestLineParser;
	RequestHeadersParsing headersParser;
	RequestBodyParsing *bodyParser;
};
