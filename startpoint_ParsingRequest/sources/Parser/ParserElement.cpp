#include "../../includes/Parser/ParserElement.hpp"

/*PUBLIC FUNCTIONS*/

/* Cannonical form*/
ParserElement::ParserElement(void) : requestParser()
{
}

ParserElement::ParserElement(const ParserElement &other) : requestParser(other.requestParser)
{
}

ParserElement &ParserElement::operator=(const ParserElement &other)
{
	if (this != &other)
	{
		requestParser = other.requestParser;
	}
	return (*this);
}

ParserElement::~ParserElement(void)
{
}
