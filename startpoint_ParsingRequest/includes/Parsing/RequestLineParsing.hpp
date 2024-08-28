#pragma once
#include "../Project.hpp"
#include "RequestParsing.hpp"
#include "../Http/HttpRequest.hpp"
#include "../Request/RequestLine.hpp"

class RequestLineParsing : public RequestParsing
{
  public:
	/*Canonical form*/
	// We dont need to instanciate it via copy
	RequestLineParsing(void);
	virtual ~RequestLineParsing(void);
	RequestLineParsing(const RequestLineParsing &other);
	RequestLineParsing &operator=(const RequestLineParsing &other);

	/*
		Function to pasre depending on what you will parse
		request line, headers, body, etc...
	*/
	virtual void parse(HttpRequest &httpRequest);

  private:
	/*
		Helper function to parse the request line
	*/
	RequestLine parseRequestLine(const std::string &line) const;
};
