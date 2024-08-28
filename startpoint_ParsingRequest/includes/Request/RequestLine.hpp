#pragma once
#include "../Project.hpp"

class RequestLine
{
  private:
	// full request line
	std::string requestLine;

	// GET, POST, PUT, DELETE, etc.
	std::string methode;

	// URI of the request
	std::string uri;

	// HTTP version
	std::string version;

  public:
	/* Cannonical form*/
	RequestLine(void);
	RequestLine(const std::string &full_line, const std::string &method,
		const std::string &url, const std::string &http);
	RequestLine(const RequestLine &ref);
	RequestLine &operator=(const RequestLine &ref);
	~RequestLine(void);

	/*
		GETTERS to access all the atributes of the class
	*/
	std::string getFullRequestLine(void) const;
	std::string getMethode(void) const;
	std::string getUri(void) const;
	std::string getHttp(void) const;

	/*
		SETTERS to modify the atributes of the class
	*/
	void setFullRequestLine(const std::string &fullLine);
	void setMethode(const std::string &method);
	void setUri(const std::string &url);
	void setHttp(const std::string &http);
};
