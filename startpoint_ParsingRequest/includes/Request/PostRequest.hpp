#pragma once
#include "../Project.hpp"
#include "../Http/HttpRequest.hpp"

class PostRequest : public HttpRequest
{
  public:
	/* Cannonical form*/
	PostRequest(void);
	PostRequest(const std::string &raw);
	PostRequest(const PostRequest &other);
	PostRequest &operator=(const PostRequest &other);
	virtual ~PostRequest(void);

	/*
		Implementation of the pure virtual function
		At the moment it just prints out the URI
		will be extended in the future
	*/
	void handleElement(void) const;
	HttpRequest* clone() const;
};
