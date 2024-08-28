#include "../../includes/Http/HttpResponse.hpp"

// Canonical form
HttpResponse::HttpResponse(void) :_valid(false)
{
    this->_request = new HttpRequest();
}

// HttpResponse::HttpResponse(const std::string &raw) : _valid(false),	_request(NULL)
// {
// }

HttpResponse::HttpResponse(const HttpResponse &other) 
{
	
        this->_request = other._request->clone();
}

HttpResponse &HttpResponse::operator=(const HttpResponse &other)
{
    if(this==&other)
        return *this;
    // add HttpResponse member ..
    if(_request)
        delete _request;
    this->_request = new HttpRequest();
    this->_request = other._request->clone(); 
    return *this;
}

HttpResponse::~HttpResponse(void)
{
    if(_request)
        delete _request;
}

std::ostream& operator<<(std::ostream& out, const HttpResponse& ref)
{
    out << "[HttpResponse] : "  << std::endl << ref._request->info.getFullRequest()
     << std::endl << "[END]";
	return out;
}

// BUILDING RESPONSE 

// how to build   ?
// -!-!-!-!-! the build Response happpen after
// the server process the request  

// check if request is present / valid  
// if is valid > parse the content > Http > status_code
void HttpResponse::Build()
{
    //if no request 
    if(!this->_request )
    {
        std::cout << " resquest Empty\n"; 
        return; 
    }
    if( !this->_request->info.getValidRequest())
    {
        // Handle invalide request
    }

    if(!status_line())
    {
        // what can cause a wrong status line  ?
        // not same as Wrong request 
    }


    //what to do ? 
    // GET - POST - DELETE - ERROR 

    // at the end , set valid to true 
    this->_valid = true; 
    return;
}

bool HttpResponse::status_line()
{
    // How to set code on Error ? 
    // we need the HTTTP Version on the request line 
    std::string http; 
    http = this->_request->requestLine.getHttp();
    if(http.empty())
    {
        std::cout << "no Http version\n";
        return false; 
    }
    else 
        this->setHttp(http);
    
    
    return true;

}



// Implementing the handleElement method
void HttpResponse::handleElement(void) const
{
	std::cout << "Handling HTTP HttpResponse" << std::endl;
}

// Implementing the clone method
HttpResponse *HttpResponse::clone(void) const
{
	return (new HttpResponse(*this));
}

// Additional Setters and Getters
void HttpResponse::setValid(bool b)
{
	_valid = b;
}

bool HttpResponse::getValid(void) const
{
	return (_valid);
}

void HttpResponse::setClientRequest(HttpRequest &ref)
{
    if(this->_request)
        delete this->_request;
    this->_request = ref.clone();
}

HttpRequest *HttpResponse::getClientRequest(void)
{
	return (_request);
}



void HttpResponse::setEmptyLine(bool b)
{
	this->_empty_line = b;
}

bool HttpResponse::getEmptyLine() const
{
		return this->_empty_line;
}

void HttpResponse::setHttp(const std::string& ref)
{
    (void)ref;

}
void HttpResponse::setInfo(const std::string& ref)
{
    (void)ref;

}

void HttpResponse::setStatuscode(unsigned int n)
{
    // to handle int 
    this->_status_code = n; 
}