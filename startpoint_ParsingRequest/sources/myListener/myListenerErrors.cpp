#include "../../includes/myListener/myListenerErrors.hpp"

/*PUBLIC FUNCTIONS*/

/*Cannonical Form*/
myListenerErrors::myListenerErrors(void)
{
}

myListenerErrors::~myListenerErrors(void)
{
}

myListenerErrors::myListenerErrors(const myListenerErrors &ref)
{
	*this = ref;
}

myListenerErrors &myListenerErrors::operator=(const myListenerErrors &ref)
{
	(void)ref;
	return *this;
}

/// EXCEPTIONS
const char* myListenerErrors::SELECT_ERROR::what() const throw()
{

	return ("(myListener) SELECT : error\n");
}
const char* myListenerErrors::EMPTY_ARRAY_ERROR::what() const throw()
{

	return ("(myListener) File directory error\n");
}

const char* myListenerErrors::FD_ERROR::what() const throw()
{

	return ("(myListener) File directory error\n");
}

const char* myListenerErrors::IP_ERROR::what() const throw()
{
	return ("(myListener) IP error\n");
}

const char* myListenerErrors::CONNECT_ERROR::what() const throw()
{
	return ("(myListener) Connect error\n");
}

const char* myListenerErrors::READ_ERROR::what() const throw()
{
	return ("(myListener) Read error\n");
}

const char* myListenerErrors::SEND_ERROR::what() const throw()
{
	return ("(myListener) Send error\n");
}
const char* myListenerErrors::INDEX_ERROR::what() const throw()
{
	return ("(myListener) INDEX error\n");
}
