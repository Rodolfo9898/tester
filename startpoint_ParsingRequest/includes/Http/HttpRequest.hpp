#pragma once
#include "../Project.hpp"
#include "../Request/RequestBody.hpp"
#include "../Request/RequestHeaders.hpp"
#include "../Request/RequestLine.hpp"
#include "../Request/RequestInformation.hpp"

class HttpRequest
{
  public:
	// Stores the Extra information about the request
	RequestInformation info;

	// Stores the parsed request line (method, URI, HTTP version, and full line)
	RequestLine requestLine;

	// Stores headers
	RequestHeaders headers;

	// Stores the body of the request/response
	RequestBody body;

	// Canonical form
	HttpRequest(void);
	HttpRequest(const std::string &raw);
	HttpRequest(const HttpRequest &other);
	HttpRequest &operator=(const HttpRequest &other);
	virtual ~HttpRequest(void);

	// Overriding the abstract method to handle the request
	virtual void handleElement(void) const;

	// Clone method for deep copy
	virtual HttpRequest *clone(void) const;
};
