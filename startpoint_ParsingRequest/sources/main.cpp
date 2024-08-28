#include "../includes/Http/HttpElement.hpp"
#include "../includes/Http/HttpRequest.hpp"
#include "../includes/Http/HttpResponse.hpp"
#include "../includes/Parser/ParserElement.hpp"
#include "../includes/Project.hpp"
#include "../includes/Request/GetRequest.hpp"
#include "../includes/Request/PostRequest.hpp"

std::string requestSELECTOR(std::string method)
{
	std::string request;
	if (method == "GET")
	{
		request = "GET /index.html HTTP/1.1\r\n"
					"Host: localhost:8080\r\n"
					"User-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:128.0) Gecko/20100101 Firefox/128.0\r\n"
					"Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/png,image/svg+xml,*/*;q=0.8\r\n"
					"Accept-Language: en-US,en;q=0.5\r\n"
					"Accept-Encoding: gzip, deflate, br, zstd\r\n"
					"Connection: keep-alive\r\n"
					"Referer: http://localhost:8080/convert-to-pdf\r\n"
					"Upgrade-Insecure-Requests: 1\r\n"
					"Sec-Fetch-Dest: document\r\n"
					"Sec-Fetch-Mode: navigate\r\n"
					"Sec-Fetch-Site: same-origin\r\n"
					"Sec-Fetch-User: ?1\r\n"
					"Priority: u=0, i\r\n"
					"\r\n";
	}
	else if (method == "POST")
	{
		request = "POST /convert-to-pdf HTTP/1.1\r\n"
					"Host: localhost:8080\r\n"
					"User-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:128.0) Gecko/20100101 Firefox/128.0\r\n"
					"Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/png,image/svg+xml,*/*;q=0.8\r\n"
					"Accept-Language: en-US,en;q=0.5\r\n"
					"Accept-Encoding: gzip, deflate, br, zstd\r\n"
					"Content-Type: multipart/form-data; boundary=---------------------------247186729516200497973512223462\r\n"
					"Content-Length: 1061\r\n"
					"Origin: http://localhost:8080\r\n"
					"Connection: keep-alive\r\n"
					"Referer: http://localhost:8080/post\r\n"
					"Upgrade-Insecure-Requests: 1\r\n"
					"Sec-Fetch-Dest: document\r\n"
					"Sec-Fetch-Mode: navigate\r\n"
					"Sec-Fetch-Site: same-origin\r\n"
					"Sec-Fetch-User: ?1\r\n"
					"Priority: u=0, i\r\n"
					"\r\n"
					"-----------------------------247186729516200497973512223462\r\n"
					"Content-Disposition: form-data; name=txtfile; filename=simple_map.cub\r\n"
					"Content-Type: application/octet-stream"
					"\r\n"
					"\n"
					"WE textures_blue/blue1.xpm\n"
					"\n"
					"EA textures_blue/blue3.xpm\n"
					"\n"
					"NO textures_blue/blue2.xpm\n"
					"\n"
					"SO textures_blue/blue3.xpm\n"
					"\n"
					"DO textures_blue/white.xpm\n"
					"\n"
					"F 31, 18, 106\n"
					"\n"
					"C 168, 102, 102\n"
					"\n"
					"111111111111111111111111111111111\n"
					"100000000000000000000000000000001\n"
					"100000000000000000000000000000001\n"
					"100000000000000000000000000000001\n"
					"100000000000000000000000000000001\n"
					"100000000000000000000000000000001\n"
					"100000000000000000000000000000001\n"
					"100000000000000000000000000000001\n"
					"100000000000000000000000000000001\n"
					"10000000000000N000000000000000001\n"
					"100000000000000000000000000000001\n"
					"100000000000000000000000000000001\n"
					"100000000000000000000000000000001\n"
					"100000000000000000000000000000001\n"
					"100000000000000000000000000000001\n"
					"100000000000000000000000000000001\n"
					"100000000000000000000000000000001\n"
					"100000000000000000000000000000001\n"
					"111111111111111111111111111111111\n"
					"-----------------------------247186729516200497973512223462--\r\n";
	}
	// else if (method == "DELETE")
	// {
	// }
	else
		request = "";
	return (request);
}

int	main(int argc, char **argv)
{
	HttpElement		element;
	ParserElement	parser;

    if (argc != 2)
    {
        std::cerr << "Usage: ./webserv [GET|POST|DELETE]\n";
        return (1);
    }
	// Example raw GET request
	std::string raw_request = requestSELECTOR(argv[1]);
	if (raw_request.find("GET") == 0)
	{
		element.request = new GetRequest(raw_request);
		parser.requestParser.parseRequest(*element.request);
		// Parse the request using the parser
		std::cout << "Request is valid: " << element.request->info.getValidRequest() << "\n";
		std::cout << "Request has emptyline: " << element.request->info.getEmptyLine() << "\n";
        std::cout << "Request is complete: " << element.request->info.getCompleteRequest() << "\n";
		// Output the raw request
		std::cout << "Raw Request:\n" << element.request->info.getFullRequest() << "\n";
		std::cout << "--------\n";
		// Output the full request line
		std::cout << "Full Request Line:\n" << element.request->requestLine.getFullRequestLine() << "\n";
		std::cout << "--------\n";
		// Output the headers
        std::cout << "Headers:\n" << element.request->headers.getHeadersString() << "\n";
		std::cout << "--------\n";
		// Output the body
		std::cout << "Body:\n" << element.request->body.getBody() << "\n";
		std::cout << "--------\n";
		element.response = new HttpResponse();
		element.response->setClientRequest(*element.request);
		std::cout << " TEST : \n" << element.response->getClientRequest()->info.getFullRequest() << std::endl;
		// Clean up
		delete element.request;
		delete element.response;
	}
    else if (raw_request.find("POST") == 0)
	{
		element.request = new PostRequest(raw_request);
		parser.requestParser.parseRequest(*element.request);
		// Parse the request using the parser
		std::cout << "Request is valid: " << element.request->info.getValidRequest() << "\n";
		std::cout << "Request has emptyline: " << element.request->info.getEmptyLine() << "\n";
        std::cout << "Request is complete: " << element.request->info.getCompleteRequest() << "\n";
		// Output the raw request
		std::cout << "Raw Request:\n" << element.request->info.getFullRequest() << "\n";
		std::cout << "--------\n";
		// Output the full request line
		std::cout << "Full Request Line:\n" << element.request->requestLine.getFullRequestLine() << "\n";
		std::cout << "--------\n";
		// Output the headers
        std::cout << "Headers:\n" << element.request->headers.getHeadersString() << "\n";
		std::cout << "--------\n";
		// Output the body
		std::cout << "Body:\n" << element.request->body.getBody() << "\n";
		std::cout << "--------\n";
		element.response = new HttpResponse();
		element.response->setClientRequest(*element.request);
		std::cout << " TEST : \n" << element.response->getClientRequest()->info.getFullRequest() << std::endl;
		// Clean up
		delete element.request;
		delete element.response;
    }
	return (0);
}
