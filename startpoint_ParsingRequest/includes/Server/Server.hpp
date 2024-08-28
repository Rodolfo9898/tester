#pragma once

#include "../Project.hpp"
#include "../Socket/mySocket.hpp"
#include "ServerErrors.hpp"

class	mySocket;
class Server
{
  private:
  public:
	Server(void);
	Server(const Server &ref);
	~Server(void);
	// MEMBER

	mySocket *_mySocket;
	int server_fd;
	int client_fd;
	int flag_socket;
	std::vector<int> client_fds;

	// INIT
	void init(void);
	void initSocket(void);

	// FUNCTION
	void printer(const std::string &str);
	int getConnection(void);
	void myListen(int client_fd);
	void set_mySocket(mySocket *ms);
	mySocket *get_mySocket(void);
	void set_nonBlocking(int new_socket);
	void closing(void);
	void close_error(const char *ref);

	// EXCEPTION
	ServerErrors errors;
};
