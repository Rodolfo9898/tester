#include "../../includes/Parsing/RequestBodyParsing.hpp"

/*PUBLIC FUNCTIONS*/

/*Canonical form*/
// We dont need to instanciate it via copy
RequestBodyParsing::RequestBodyParsing(void)
{
}

RequestBodyParsing::~RequestBodyParsing(void)
{
}

/*PRIVATE FUNCTIONS*/

/*Canonical form*/
RequestBodyParsing::RequestBodyParsing(const RequestBodyParsing &other) : RequestParsing(other)
{
	*this = other;
}

RequestBodyParsing &RequestBodyParsing::operator=(const RequestBodyParsing &other)
{
	(void)other;
	return (*this);
}
