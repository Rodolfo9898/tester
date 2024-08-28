#include "../includes/Http/HttpElement.hpp"
#include "../includes/Http/HttpRequest.hpp"
#include "../includes/Http/HttpResponse.hpp"
#include "../includes/Parser/ParserElement.hpp"
#include "../includes/Project.hpp"
#include "../includes/Request/GetRequest.hpp"

int	main(void)
{
	ParserElement parser;
	std::string raw_request = "GET /index.html HTTP/5.1\r\n";
	HttpElement element;
	element.request = new GetRequest(raw_request);
	HttpRequest *request = element.request;
	parser.requestParser.parseRequest(*request);
	std::cout << "URI: " << request->requestLine.getUri() << std::endl;

	delete request;
	return (0);
}