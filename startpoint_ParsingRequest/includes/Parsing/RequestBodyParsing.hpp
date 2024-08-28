#pragma once
#include "../Project.hpp"
#include "RequestParsing.hpp"
#include "../Http/HttpRequest.hpp"

class RequestBodyParsing : public RequestParsing
{
  public:
	/*Canonical form*/
	// We dont need to instanciate it via copy
	RequestBodyParsing(void);
	virtual ~RequestBodyParsing(void);
	RequestBodyParsing(const RequestBodyParsing &other);
	RequestBodyParsing &operator=(const RequestBodyParsing &other);

	/*
		Function to pasre depending on what you will parse
		request line, headers, body, etc...
	*/
	virtual void parse(HttpRequest &httpRequest) = 0;

  protected:
	/*
		Function to parse the body.
		right now we focus on GetRequests,they dont have a body so we dont do anything
		but the other request have a body,it would be nice to have an abstract class and then a,
		pure method to parse the body,since this is the only difference for each type of request.
	*/
	virtual void parseBody(std::istringstream &stream, HttpRequest &request) const = 0;
};
