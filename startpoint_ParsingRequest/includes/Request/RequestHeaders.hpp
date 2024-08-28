#pragma once
#include "../Project.hpp"

class RequestHeaders
{
  private:
	/** Stores headers */
	std::map<std::string, std::string> headers;

  public:
	/* Cannonical form*/
	RequestHeaders(void);
	RequestHeaders(const std::map<std::string, std::string> &headers);
	RequestHeaders(const RequestHeaders &other);
	RequestHeaders &operator=(const RequestHeaders &other);
	~RequestHeaders(void);

	/*
		GETTERS to access all the atributes of the class
	*/
	std::string getSingleHeaderValueFromKey(const std::string &key) const;
	std::string getSingleHeaderKeyFromKey(const std::string &key) const;
	std::string getSingleHeaderValueFromValue(const std::string &value) const;
	std::string getSingleHeaderKeyFromValue(const std::string &value) const;
	std::map<std::string, std::string> getAllHeaders(void) const;
	std::string getHeadersString(void) const;

	/*
		SETTERS to modify the atributes of the class
	*/
	void setSingleHeader(const std::string &name, const std::string &value);
};
