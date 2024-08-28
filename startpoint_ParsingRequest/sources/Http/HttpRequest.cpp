#include "../../includes/Http/HttpRequest.hpp"

// Canonical form
HttpRequest::HttpRequest(void) : info(), requestLine(), headers(), body()
{
}

HttpRequest::HttpRequest(const std::string &raw) : info(raw), requestLine(), headers(), body()
{
}

HttpRequest::HttpRequest(const HttpRequest &other)
{
	*this = other;
}

HttpRequest &HttpRequest::operator=(const HttpRequest &other)
{
	if (this != &other)
	{
		info = other.info;
		requestLine = other.requestLine;
		headers = other.headers;
		body = other.body;
	}
	return (*this);
}

HttpRequest::~HttpRequest(void)
{
}

// Implementing the handleElement method
void HttpRequest::handleElement(void) const
{
	std::cout << "Handling HTTP Request" << std::endl;
}

// Implementing the clone method
HttpRequest *HttpRequest::clone(void) const
{
	return (new HttpRequest(*this));
}
