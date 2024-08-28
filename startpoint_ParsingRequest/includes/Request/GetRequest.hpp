#pragma once
#include "../Project.hpp"
#include "../Http/HttpRequest.hpp"

class GetRequest : public HttpRequest
{
  public:
	/* Cannonical form*/
	GetRequest(void);
	GetRequest(const std::string &raw);
	GetRequest(const GetRequest &other);
	GetRequest &operator=(const GetRequest &other);
	virtual ~GetRequest(void);

	/*
		Implementation of the pure virtual function
		At the moment it just prints out the URI
		will be extended in the future
	*/
	void handleElement(void) const;
	HttpRequest* clone() const;
};
