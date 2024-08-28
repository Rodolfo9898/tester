#include "../../includes/Socket/mySocket.hpp"

mySocket::mySocket() : fd(0), flags(0)
{
	//	std::cout << "Default mySocket\n";
	return ;
}

mySocket::mySocket(const mySocket &ref)
{
	(void)ref;
	//	std::cout << "Constructor mySocket\n";
	return ;
}

mySocket::~mySocket()
{
	//	std::cout << "Destructor mySocket\n";
	return ;
}

////////INIT////////

void mySocket::init()
{
	//	std::cout << " Init mySocket\n";
	// file directory
	if ((this->fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		throw mySocketErrors::FD_ERROR();
	// init struct sockadrres
	this->addr.sin_family = AF_INET;
	this->addr.sin_port = htons(PORT);
	this->addrlen = sizeof(addr);
	return ;
}

////////FUNCTION////

mySocket &mySocket::get_me()
{
	return (*this);
}

int mySocket::get_fd()
{
	return (this->fd);
}

void mySocket::set_nonBlocking()
{
	if ((this->flags = fcntl(this->fd, F_GETFL, 0)) < 0)
		throw mySocketErrors::FCNTL_ERROR();
	if ((fcntl(this->fd, F_SETFL, this->flags | O_NONBLOCK)) < 0)
		throw mySocketErrors::FCNTL_ERROR();
}
