#pragma once
#include "../Project.hpp"
#include "RequestParsing.hpp"
#include "../Http/HttpRequest.hpp"

class RequestHeadersParsing : public RequestParsing
{
  public:
	/*Canonical form*/
	// We dont need to instanciate it via copy
	RequestHeadersParsing(void);
	virtual ~RequestHeadersParsing(void);
	RequestHeadersParsing(const RequestHeadersParsing &other);
	RequestHeadersParsing &operator=(const RequestHeadersParsing &other);

	/*
		Function to pasre depending on what you will parse
		request line, headers, body, etc...
	*/
	virtual void parse(HttpRequest &httpRequest);

  private:
	/*
		Function to parse a single header
		A header is defined as KEY: VALUE
		So we will look for the : to split it into a key, value pair.
		If you find one then proceed to populate the map that holds all the headers.

		STILL MISSING: what happens if you dont find one?
	*/
	void parseSingleHeader(const std::string &line, HttpRequest &request);
};
