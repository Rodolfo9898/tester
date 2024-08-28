#pragma once
#include "../Project.hpp"
#include "HttpRequest.hpp"
#include "HttpResponse.hpp"

class HttpElement
{
  public:
	// the HttpRequest object
	HttpRequest *request;
	// the HTTPResponse object
	HttpResponse *response;

	/* Cannonical form*/
	HttpElement(void);
	HttpElement(const HttpElement &other);
	HttpElement &operator=(const HttpElement &other);
	~HttpElement(void);

};
