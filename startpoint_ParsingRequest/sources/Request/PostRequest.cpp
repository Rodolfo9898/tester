#include "../../includes/Request/PostRequest.hpp"

/*PUBLIC FUNCTIONS*/

/* Cannonical form*/

PostRequest::PostRequest(void)
{
}

PostRequest::PostRequest(const std::string &raw) : HttpRequest(raw)
{
}

PostRequest::PostRequest(const PostRequest &other) : HttpRequest(other)
{
}

PostRequest &PostRequest::operator=(const PostRequest &other)
{
	if (this != &other)
		HttpRequest::operator=(other);
	return (*this);
}

PostRequest::~PostRequest(void)
{
}

/*
	Implementation of the pure virtual function
	At the moment it just prints out the URI
	will be extended in the future
*/

void PostRequest::handleElement(void) const
{
	std::cout << "Handling POST request for URI: " << requestLine.getUri() << std::endl;
}
HttpRequest *PostRequest::clone() const
{
	return (new PostRequest(*this));
}