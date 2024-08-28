#pragma once
#include "../Project.hpp"

class RequestBody
{
  private:
	std::string body;

  public:
	/* Cannonical form*/
	RequestBody(void);
	RequestBody(const std::string &content);
	RequestBody(const RequestBody &other);
	RequestBody &operator=(const RequestBody &other);
	~RequestBody(void);

	/*
		GETTERS & SETTERS
	*/
	std::string getBody(void) const;
	void setBody(const std::string &content);
};
