#pragma once
#include "../Project.hpp"

class RequestLineValidation
{
  public:
	/*Canonical form*/
	RequestLineValidation(void);
	~RequestLineValidation(void);
	RequestLineValidation(const RequestLineValidation &other);
	RequestLineValidation &operator=(const RequestLineValidation &other);

	/*
		Function to valdiate the entire request line
	*/
	bool isValidRequestLine(const std::vector<std::string> &parts) const;

  private:
	/*
		Checkers for the request line
	*/
	bool isValidMethod(const std::string &method) const;
	bool isValidUri(const std::string &uri) const;
	bool isValidVersion(const std::string &version) const;
};
