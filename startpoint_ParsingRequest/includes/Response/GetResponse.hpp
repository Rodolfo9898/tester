#pragma once
#include "../Project.hpp"
#include "../Http/HttpResponse.hpp"

class GetResponse : public HttpResponse
{
  public:
	/* Cannonical form*/
	GetResponse(void);
	GetResponse(const std::string &raw);
	GetResponse(const GetResponse &other);
	GetResponse &operator=(const GetResponse &other);
	virtual ~GetResponse(void);

	/*
		Implementation of the pure virtual function
		At the moment it just prints out the URI
		will be extended in the future
	*/
	void handleElement(void) const;
	HttpResponse* clone() const;
};