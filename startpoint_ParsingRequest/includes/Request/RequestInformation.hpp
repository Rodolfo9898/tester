#pragma once

#include "../Project.hpp"

class RequestInformation
{
  private:
	// Stores the full request/response
	std::string full;

	// Stores if there is an empty line between the headers and the body
	bool emptyLine;

	// stores if the request is valid
	bool validRequest;

	// store if the request is a complete request
	bool completeRequest;

  public:
	// Canonical form
	RequestInformation(void);
    RequestInformation(const std::string &raw);
    RequestInformation(const RequestInformation &other);
    RequestInformation &operator=(const RequestInformation &other);
	~RequestInformation(void);


    /*
		Getters
	*/
	std::string getFullRequest(void) const;
	bool getEmptyLine(void) const;
	bool getValidRequest(void) const;
    bool getCompleteRequest(void) const;

	/*
		Setters
	*/
	void setFullRequest(const std::string &raw);
	void setEmptyLine(bool b);
	void setValidRequest(bool b);
    void setCompleteRequest(bool b);
};
