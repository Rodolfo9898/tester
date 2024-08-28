#pragma once
#include "../Project.hpp"
#include "RequestBodyParsing.hpp"


class PostRequestBodyParsing : public RequestBodyParsing
{
  public:
    /* Cannonical form*/
    PostRequestBodyParsing(void);
    virtual ~PostRequestBodyParsing(void);
    PostRequestBodyParsing(const PostRequestBodyParsing &other);
    PostRequestBodyParsing &operator=(const PostRequestBodyParsing &other);

    /*
        Function to pasre depending on what you will parse
        request line, headers, body, etc...
    */
    virtual void parse(HttpRequest &httpRequest);

  protected:
    /*
        Function to parse the body.
        right now we focus on GetRequests,they dont have a body so we dont do anything
        but the other request have a body,it would be nice to have an abstract class and then a,
        pure method to parse the body,since this is the only difference for each type of request.
    */
    void parseBody(std::istringstream &stream, HttpRequest &request) const;
};