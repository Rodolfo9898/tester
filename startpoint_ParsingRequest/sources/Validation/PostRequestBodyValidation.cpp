#include "../../includes/Validation/PostRequestBodyValidation.hpp"

/*PUBLIC FUNCTIONS*/

/*Canonical form*/
PostRequestBodyValidation::PostRequestBodyValidation(void)
{
}

PostRequestBodyValidation::~PostRequestBodyValidation(void)
{
}

PostRequestBodyValidation::PostRequestBodyValidation(const PostRequestBodyValidation &other) : RequestBodyValidation(other)
{
	*this = other;
}

PostRequestBodyValidation &PostRequestBodyValidation::operator=(const PostRequestBodyValidation &other)
{
	(void)other;
	return (*this);
}

// need to check it out
bool PostRequestBodyValidation::validate(std::string &bodyLine, HttpRequest &request)
{
	// get should not have a body
	if (bodyLine.size() > 0)
	{
		request.info.setValidRequest(false);
		return (false);
	}
	request.info.setCompleteRequest(true);
	return (true);
}
