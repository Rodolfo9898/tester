#include "../../includes/Request/RequestHeaders.hpp"

/*PUBLIC FUNCTIONS*/

/* Cannonical form*/
RequestHeaders::RequestHeaders(void) : headers()
{
}

RequestHeaders::RequestHeaders(const std::map<std::string,std::string> &headers) : headers(headers)
{
}

RequestHeaders::RequestHeaders(const RequestHeaders &ref)
{
	*this = ref;
}

RequestHeaders &RequestHeaders::operator=(const RequestHeaders &ref)
{
	if (this != &ref)
		this->headers = ref.headers;
	return (*this);
}

RequestHeaders::~RequestHeaders(void)
{
}

/*
	GETTERS to access all the atributes of the class
*/
std::string RequestHeaders::getSingleHeaderValueFromKey(const std::string &key) const
{
	std::map<std::string, std::string>::const_iterator it = headers.find(key);
	std::string value; // you want to retrun the second element of the pair

	if (it != headers.end())
		value = it->second;
	else
		value = "";
	return (value);
}

std::string RequestHeaders::getSingleHeaderKeyFromKey(const std::string &key) const
{
	std::map<std::string, std::string>::const_iterator it = headers.find(key);
	std::string value; // you want to retrun the first element of the pair
	if (it != headers.end())
		value = it->first;
	else
		value = "";
	return (value);
}

std::string RequestHeaders::getSingleHeaderValueFromValue(const std::string &value) const
{
	for (std::map<std::string,
		std::string>::const_iterator it = headers.begin(); it != headers.end(); ++it)
	{
		if (it->second == value)
			return (it->second);
	}
	return ("");
}

std::string RequestHeaders::getSingleHeaderKeyFromValue(const std::string &value) const
{
	for (std::map<std::string,
		std::string>::const_iterator it = headers.begin(); it != headers.end(); ++it)
	{
		if (it->second == value)
			return (it->first);
	}
	return ("");
}

std::map<std::string, std::string> RequestHeaders::getAllHeaders(void) const
{
	return (headers);
}

/*
	SETTERS to modify the atributes of the class
*/

void RequestHeaders::setSingleHeader(const std::string &name,
	const std::string &value)
{
	headers[name] = value;
}

std::string RequestHeaders::getHeadersString(void) const
{
	std::string headersString;
	for (std::map<std::string, std::string>::const_iterator it = headers.begin(); it != headers.end(); ++it)
		headersString += it->first + " " + it->second + "\n";
	return (headersString);
}