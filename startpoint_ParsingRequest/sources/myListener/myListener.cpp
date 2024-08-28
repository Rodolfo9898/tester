/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myListener.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <rperez-t@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:34:41 by abaccari          #+#    #+#             */
/*   Updated: 2024/08/27 20:18:21 by rperez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/myListener/myListener.hpp"

myListener::myListener() : nb_serv(0), nb_client(0), max_fd(0), max_count(0)
{
	//	std::cout << "Default myListener\n";
	// init strcut timevalue for slect() timeout
	this->tv.tv_sec = 5;
	this->tv.tv_usec = 0;
	return ;
}

myListener::myListener(const myListener &ref) : nb_serv(0), nb_client(0),
	max_fd(0), max_count(0)
{
	(void)ref;
	//	std::cout << "Constructor myListener\n";
	// init strcut timevalue for slect() timeout
	this->tv.tv_sec = 5;
	this->tv.tv_usec = 0;
	return ;
}

myListener::~myListener()
{
	//	std::cout << "Destructor myListener\n";
	return ;
}

////////INIT////////

// - go through Server to set them ready to listen
// - go through Client to set them and sendign msg
// - put Server[i] to Listen mode
void myListener::init()
{
	//	std::cout << " Init myListener\n";
	if (!this->nb_client || !this->nb_serv)
		throw myListenerErrors::EMPTY_ARRAY_ERROR();
	this->max_count = this->get_maxCount();
	// Server/Client Init
	for (int i = 0; i < this->max_count; i++)
	{
		if (i < this->nb_serv)
		{
			try
			{
				this->_myServer[i].init();
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
		} /*
			if(i < this->nb_client )
			{
				try
				{
				this->_myClient[i].init();
				}
				catch(std::exception &e)
				{
				std::cout << e.what()<<std::endl;
				}
			} */
	}
	std::cout << "\033[2J\033[H" << std::endl;
	// try FD_MANAGER
	// Server getConnection
	// Client sendmsg
	// Server myListen
	// One Server / multi clien -> nb_client
	for (int i = 0; i < this->nb_client; i++)
	{
		try
		{
			// this->_myClient[i].sendmsg();
			this->fd_manager();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

///////FUNCTION/////

int myListener::getMax_fd()
{
	int	max_c;
	int	max_s;

	max_c = 0;
	max_s = 0;
	/* 	for(int i = 0 ; i < nb_client ; i ++)
			if(this->_myClient[i]._mySocket->fd > max_c)
				max_c = this->_myClient[i]._mySocket->fd;
			*/
	for (int i = 0; i < nb_serv; i++)
		if (this->_myServer[i]._mySocket->fd > max_c)
			max_s = this->_myServer[i]._mySocket->fd;
	if (max_c < max_s)
		return (max_s);
	else
		return (max_c);
}

int myListener::get_maxCount()
{
	if (this->nb_serv < this->nb_client)
		return (this->nb_client);
	else
		return (this->nb_serv);
}

// go throught the FD_SET and see which one its ready for i/o
int myListener::fd_manager()
{
	int	n_client;

	this->max_fd = this->getMax_fd();
	fd_set set_cp; // set copy
	FD_ZERO(&this->set);
	// add MASTER(server) to fd_set
	FD_SET(this->_myServer[0]._mySocket->fd, &this->set);
	while (true)
	{
		// select modifi fd_set so we need a cpy
		FD_ZERO(&set_cp);
		set_cp = this->set;
		if (select(FD_SETSIZE, &set_cp, NULL, NULL, &this->tv) < 0)
		{
			perror("select");
			this->close_all();
			throw myListenerErrors::SELECT_ERROR();
		}
		for (int i = 0; i < MAX_FD; i++)
		{
			// i = 0 > fd_server is ready and added to set
			// then
			if (FD_ISSET(i, &set_cp))
			{
				// q fd is ready for i/o
				if (i == this->_myServer[0]._mySocket->fd)
				{
					// the server is ready for i/oi
					// get the new_socket from accept and put it FD_SET
					if (!(n_client = this->_myServer[0].getConnection()))
					{
						perror("accept");
						throw myListenerErrors::SELECT_ERROR();
					}
					else
					{
						// put new fd in fd_set set
						FD_SET(n_client, &set_cp);
						std::cout << "client added : " << n_client << std::endl;
					}
					this->_myServer[0].printer("2");
				}
				else
				{
					// its client fd ready i/o
					this->_myServer[0].myListen(i);
					// we need to clear the fd from the set
					FD_CLR(i, &set_cp);
				}
			}
		}
		break ;
	}
	return (0);
}
void myListener::set_myServer(Server *server)
{
	if (!server)
		return ;
	if (this->nb_serv >= MAX_FD)
		throw myListenerErrors::INDEX_ERROR();
	_myServer[nb_serv] = *server;
	this->nb_serv++;
	this->print("NB_SERVER : ");
	std::cout << this->nb_serv << std::endl;
	return ;
}
void myListener::print(const std::string &str)
{
	std::cout << "[LISTENER] server : " << (this->nb_serv > 0 ? this->nb_serv : 0) << "- client "
	<< (this->nb_client > 0 ? this->nb_serv : 0) << " >> " << str << std::endl;
}

Server myListener::get_myServer(int index)
{
	if (index >= MAX_FD) // or !myServer[i]
		throw myListenerErrors::INDEX_ERROR();
	return (this->_myServer[index]);
}

/* void myListener::set_myClient(Client *client)
{
	if(!client)
		return ;
	if(this->nb_client >= MAX_FD)
		throw myListener::INDEX_ERROR();
	this->_myClient[nb_client] = *client;
	this->nb_client++;
	this->print("NB_client : ");
	std::cout << this->nb_client << std::endl;
	return ;
}


Client myListener::get_myClient(int index)
{
	int	max;
	int	max;

	if(index >= MAX_FD) // or !_myClient[i]
		throw myListener::INDEX_ERROR();
	return (this->_myClient[index]);
} */
void myListener::close_all()
{
	int max = this->get_maxCount();
	for (int i = 0; i < max; i++)
	{
		if (i < this->nb_serv)
			this->_myServer[i].closing();
		/* 		if(i < this->nb_client)
					this->_myClient[i].closing();  */
	}
}
