#pragma once

#include "../Project.hpp"
#include "../Server/Server.hpp"
#include "myListenerErrors.hpp"

class	Server;
class	Client;
class myListener
{
  private:
  public:
	myListener(void);
	myListener(const myListener &ref);
	~myListener(void);

	// MEMBER
	struct timeval tv;
	Server _myServer[MAX_FD];
	fd_set set;
	int nb_serv;
	int nb_client;
	int max_fd;
	int max_count;
	// INIT
	void init(void);

	// FUNCTION
	int getMax_fd(void);
	int get_maxCount(void);
	void print(const std::string &str);
	int fd_manager(void);
	void set_myServer(Server *myserver);
	Server get_myServer(int index);
	void close_all(void);
	// EXCEPTION
	myListenerErrors errors;
};
