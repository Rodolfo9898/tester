#include "../../includes/Validation/RequestLineValidation.hpp"

/*PUBLIC FUNCTIONS*/

/* Canonical form */

RequestLineValidation::RequestLineValidation(void)
{
	
}

RequestLineValidation::~RequestLineValidation(void)
{
}

RequestLineValidation::RequestLineValidation(const RequestLineValidation &other)
{
	*this = other;
}

RequestLineValidation &RequestLineValidation::operator=(const RequestLineValidation &other)
{
	(void)other;
	return (*this);
}


/*
	Function to valdiate the entire request line
*/
bool RequestLineValidation::isValidRequestLine(const std::vector<std::string> &parts) const
{
	if (parts.size() != 3)
		return (false);

	std::string method = parts[0];
	std::string uri = parts[1];
	std::string version = parts[2];

	return (isValidMethod(method) && isValidUri(uri) && isValidVersion(version));
}

/*PRIVATE FUNCTIONS*/

/*
		Checkers for the request line:
*/
bool RequestLineValidation::isValidMethod(const std::string &method) const
{
	// list of valid methods
	std::string validMethodsList[] = {"GET", "POST", "PUT", "DELETE", "HEAD", "OPTIONS", "PATCH"};
	// calculate the size of the array
	int lastElement = sizeof(validMethodsList) / sizeof(std::string);
	std::string *validMethodsEnd = validMethodsList + lastElement;
	// create a vector with the valid methods
	std::vector<std::string> validMethods(validMethodsList, validMethodsEnd);
	// check if the method is in the list of valid methods
	bool inside = (std::find(validMethods.begin(), validMethods.end(),
				method) != validMethods.end());
	return (inside);
}

bool RequestLineValidation::isValidUri(const std::string &uri) const
{
	return (!uri.empty() && uri[0] == '/');
}

/*
	Check if the version is valid
	split the version into its components
	and check if each component is valid
*/
bool RequestLineValidation::isValidVersion(const std::string &version) const
{
	//total size
	if (version.size() != 8)
		return (false);

	// check if the version starts with "HTTP/"
	if (version.substr(0, 5) != "HTTP/")
		return (false);

	// check if the version is 1.0 or 1.1 or 2.0
	if (version[5] < '0' || version[5] > '2')
		return (false);
	
	// check if the version has a dot
	if (version[6] != '.')
		return (false);

	// check if the version is 1.0 or 1.1 or 2.0
	if (version[7] < '0' || version[7] > '2')
		return (false);

	return (true);
}
