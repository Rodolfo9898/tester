#include "../../includes/Request/GetRequest.hpp"

/*PUBLIC FUNCTIONS*/

/* Cannonical form*/

GetRequest::GetRequest(void)
{
}

GetRequest::GetRequest(const std::string &raw) : HttpRequest(raw)
{
}

GetRequest::GetRequest(const GetRequest &other) : HttpRequest(other)
{
}

GetRequest &GetRequest::operator=(const GetRequest &other)
{
	if (this != &other)
		HttpRequest::operator=(other);
	return (*this);
}

GetRequest::~GetRequest(void)
{
}

/*
	Implementation of the pure virtual function
	At the moment it just prints out the URI
	will be extended in the future
*/

void GetRequest::handleElement(void) const
{
	std::cout << "Handling GET request for URI: " << requestLine.getUri() << std::endl;
}

HttpRequest *GetRequest::clone() const
{
	return (new GetRequest(*this));
}