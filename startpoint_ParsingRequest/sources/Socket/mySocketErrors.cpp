#include "../../includes/Socket/mySocketErrors.hpp"

/*PUBLIC FUNCTIONS*/

/*Cannonical Form*/
mySocketErrors::mySocketErrors(void)
{
}

mySocketErrors::~mySocketErrors(void)
{
}

mySocketErrors::mySocketErrors(const mySocketErrors &ref)
{
	*this = ref;
}

mySocketErrors &mySocketErrors::operator=(const mySocketErrors &ref)
{
	(void)ref;
	return (*this);
}

/// EXCEPTIONS
const char *mySocketErrors::FCNTL_ERROR::what() const throw()
{
	return ("(mySocket) FCNTL : error\n");
}

const char *mySocketErrors::FD_ERROR::what() const throw()
{
	return ("(mySocket) FD : error\n");
}

const char *mySocketErrors::IP_ERROR::what() const throw()
{
	return ("(mySocket) IP : error\n");
}

const char *mySocketErrors::CONNECT_ERROR::what() const throw()
{
	return ("(mySocket) CONNECT : error\n");
}

const char *mySocketErrors::READ_ERROR::what() const throw()
{
	return ("(mySocket) READ : error\n");
}

const char *mySocketErrors::SEND_ERROR::what() const throw()
{
	return ("(mySocket) SEND : error\n");
}
