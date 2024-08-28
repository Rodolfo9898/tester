#include "../../includes/Request/RequestBody.hpp"

/*PUBLIC FUNCTIONS*/

/* Cannonical form*/

RequestBody::RequestBody(void): body("NULL")
{
}

RequestBody::RequestBody(const std::string &content) : body(content)
{
}

RequestBody::RequestBody(const RequestBody &other)
{
	*this = other;
}

RequestBody &RequestBody::operator=(const RequestBody &other)
{
	if (this != &other)
		this->body = other.body;
	return (*this);
}

RequestBody::~RequestBody(void)
{
}

/*
** GETTERS & SETTERS
*/

std::string RequestBody::getBody(void) const
{
	return (this->body);
}

void RequestBody::setBody(const std::string &content)
{
	this->body = content;
}