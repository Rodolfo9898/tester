#pragma once
#include "../Project.hpp"
#include "HttpRequest.hpp"

/*
 *	IF error => Response need to send code error + info in response body
 *	IF Request POST = > take body of Request to make the response
 */
class HttpResponse
{
  protected:
	bool _valid;
	bool _empty_line;
	std::string _http; 
	std::string _status_code; 
	std::string _info;
	std::string _statusLine; 

  public:
	HttpRequest *_request;
	// Canonical form
	HttpResponse(void);
	//HttpResponse(const std::string &raw);
	HttpResponse(const HttpResponse &other);
	HttpResponse &operator=(const HttpResponse &other);
	virtual ~HttpResponse(void);
	
	//Build Response 
	void Build();
	bool status_line();	
	// Overriding the abstract method to handle the response
	void handleElement(void) const;

	// Clone method for deep copy
	virtual HttpResponse *clone(void) const;

	// Additional Setters and Getters
	void setClientRequest(HttpRequest &ref);
	HttpRequest *getClientRequest(void);
	void setValid(bool b);
	bool getValid(void) const;
	void setEmptyLine(bool b);
	bool getEmptyLine() const;
	void setHttp(const std::string& ref); 
	void setInfo(const std::string& ref); 
	void setStatuscode(unsigned int n);
};

std::ostream &operator<<(std::ostream &out, const HttpResponse &ref);
