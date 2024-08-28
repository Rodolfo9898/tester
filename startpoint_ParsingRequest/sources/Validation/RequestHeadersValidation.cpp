#include "../../includes/Validation/RequestHeadersValidation.hpp"

/*PUBLIC FUNCTIONS*/

/*Canonical form*/

RequestHeadersValidation::RequestHeadersValidation(void) : duplicates(), validheaders(true)
{
}

RequestHeadersValidation::~RequestHeadersValidation(void)
{
}

RequestHeadersValidation::RequestHeadersValidation(const RequestHeadersValidation &other)
{
	*this = other;
}

RequestHeadersValidation &RequestHeadersValidation::operator=(const RequestHeadersValidation &other)
{
	if (this != &other)
	{
		duplicates = other.duplicates;
		validheaders = other.validheaders;
	}
	return (*this);
}

/*
	Function to valdiate an entire header
*/
bool RequestHeadersValidation::isValidHeader(const std::string &header)
{
	size_t	pos;

	pos = header.find(':');
	if (pos == std::string::npos)
		return (false);
	const std::string key = header.substr(0, pos) + ':';
	const std::string value = header.substr(pos + 1);
	if (!isValidKey(key) || !isValidValue(value) || isDupliacte(key))
	{
		setValidHeaders(false);
		return (false);
	}
	setValidHeaders(true);
	return (true);
}

/*
	GETTERS to get the atributes of the class
*/
bool RequestHeadersValidation::getValidHeaders(void) const
{
	return (validheaders);
}

/*
	SETTERS to modify the atributes of the class
*/
void RequestHeadersValidation::setSingleHeader(const std::string &name, const std::string &value)
{
	duplicates[name] = value;
}

void RequestHeadersValidation::setValidHeaders(bool valid)
{
	validheaders = valid;
}
/*PRIVATE FUNCTIONS*/
bool RequestHeadersValidation::isSpecialChar(char c) const
{
	std::string specialChars = "!#$%&'*+-.^_`|~";
	if (specialChars.find(c) != std::string::npos)
		return (true);
	else
		return (false);
}

bool RequestHeadersValidation::isValidKey(const std::string &key) const
{
	if (key.empty())
		return (false);
	for (size_t i = 0; i < key.length() - 1; i++)
	{
		if (!isalnum(key[i]) && !isSpecialChar(key[i]))
			return (false);
	}
	return (true);
}

bool RequestHeadersValidation::isValidValue(const std::string &value) const
{
	if (value.empty())
		return (false);
	return (true);
}

bool RequestHeadersValidation::isDupliacte(const std::string &key) const
{
	int found = duplicates.count(key);
	if (found)
		return (true);
	return (false);
}
