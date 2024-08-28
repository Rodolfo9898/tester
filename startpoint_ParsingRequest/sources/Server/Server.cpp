#include "../../includes/Server/Server.hpp"

Server::Server() : server_fd(0), client_fd(0), flag_socket(0), client_fds()
{
	// this->printer("Default Server\n");
	return ;
}

Server::Server(const Server &ref) : server_fd(0), client_fd(0), flag_socket(0),	client_fds()
{
	(void)ref;
	this->printer("Constructor Server\n");
	return ;
}

Server::~Server()
{
	this->printer("Destructor Server\n");
	return ;
}

////////INIT////////

void Server::init()
{
	mySocket	*ms;

	ms = new mySocket();
	this->printer("Init Server\n");
	try
	{
		this->set_mySocket(ms);
		this->initSocket();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return ;
}

void Server::initSocket()
{
	try
	{
		this->_mySocket->init();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	this->_mySocket->addr.sin_addr.s_addr = INADDR_ANY;
	// Binding socket to IP
	if ((bind(this->_mySocket->fd, (struct sockaddr *)&this->_mySocket->addr,
				sizeof(this->_mySocket->addr))) < 0)
	{
		this->close_error("BINDING");
		throw ServerErrors::BIND_ERROR();
	}
	// start listening
	if ((listen(this->_mySocket->fd, 3)) < 0)
	{
		this->close_error("LISTEN");
		throw ServerErrors::LISTEN_ERROR();
	}
	this->printer("Listening on port: ");
	std::cout << PORT << std::endl;
	return ;
}

///////FUNCTION/////

void Server::printer(const std::string &str)
{
	if (this->_mySocket)
	{
		if (!this->client_fds.size())
			std::cout << "[SERVER] fd:" << this->_mySocket->fd << "| client_fd : NULL >> " << str << std::endl;
		else
			std::cout << "[SERVER] fd:" << this->_mySocket->fd << "| client_fd :" << this->client_fds.size() << " >> " << str << std::endl;
	}
	else
		std::cout << "[SERVER] fd:NULL >> " << str << std::endl;
}
void Server::set_mySocket(mySocket *ms)
{
	if (!ms)
		throw ServerErrors::SOCKET_ERROR();
	this->_mySocket = ms;
	return ;
}

mySocket *Server::get_mySocket()
{
	return (this->_mySocket);
}

int Server::getConnection()
{
	int	new_client_fd;

	if ((new_client_fd = accept(this->_mySocket->fd,
				(struct sockaddr *)&this->_mySocket->addr,
				(socklen_t *)&this->_mySocket->addrlen)) < 0)
	{
		this->close_error("ACCEPT");
		throw ServerErrors::ACCEPT_ERROR();
	}
	this->client_fds.push_back(new_client_fd);
	try
	{
		this->set_nonBlocking(this->client_fds.back());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (this->client_fds.back());
}

void Server::myListen(int client_fd)
{
	char		buffer[1024] = {0};
	const char	*ack = "message receive \n";
	int			res;

	memset(buffer, 0, 1024);
	if ((res = read(client_fd, buffer, 1024)) < 0)
		this->close_error("read");
	else
		std::cout << ack << std::endl << buffer << std::endl;
}

void Server::set_nonBlocking(int client_fd)
{
	if ((this->flag_socket = fcntl(client_fd, F_GETFL, 0)) < 0)
	{
		close_error("FCNTL - GETFL : ");
		throw ServerErrors::FCNTL_ERROR();
	}
	if (fcntl(client_fd, F_SETFL, this->flag_socket | O_NONBLOCK) == -1)
	{
		close_error("FCNTL - FSETFL : ");
		throw ServerErrors::FCNTL_ERROR();
	}
}

void Server::closing()
{
	if (this->client_fd)
		close(this->client_fd);
	if (this->server_fd)
		close(this->server_fd);
	for (size_t i = 0; i < this->client_fds.size(); i++)
	{
		if (this->client_fds[i])
			close(this->client_fds[i]);
	}
}
void Server::close_error(const char *ref)
{
	if (this->client_fd)
		close(this->client_fd);
	if (this->server_fd)
		close(this->server_fd);
	for (size_t i = 0; i < this->client_fds.size(); i++)
	{
		if (this->client_fds[i])
			close(this->client_fds[i]);
	}
	perror(ref);
}
