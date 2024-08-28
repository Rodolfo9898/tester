#pragma once
#include "../Project.hpp"
#include "RequestParser.hpp"

// this class maybe is not needed
class ParserElement
{
  public:
	/* Cannonical form*/
	ParserElement(void);
	ParserElement(const ParserElement &other);
	ParserElement &operator=(const ParserElement &other);
	virtual ~ParserElement(void);

	/*
		All the elements that are capable of parsing something
	*/
	RequestParser requestParser;
};
