#ifndef MYSOCKET_HPP
# define MYSOCKET_HPP

# include "../Project.hpp"
# include "mySocketErrors.hpp"

class mySocket
{
  public:
	mySocket(void);
	mySocket(const mySocket &ref);
	~mySocket(void);

	// INIT
	void init(void);
	// MEMBER

	int fd;
	int flags;
	int addrlen;
	int opt;
	struct sockaddr_in addr;

	// FUNCTION
	mySocket &get_me(void);
	int get_fd(void);
	void set_nonBlocking(void);

	// EXCEPTION
	mySocketErrors errors;
};

#endif
