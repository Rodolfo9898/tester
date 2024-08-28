#pragma once

#include "../Project.hpp"

class mySocketErrors
{
  public:
	/*Cannonical Form*/
	mySocketErrors(void);
	~mySocketErrors(void);
	mySocketErrors(const mySocketErrors &ref);
	mySocketErrors &operator=(const mySocketErrors &ref);

	// EXCEPTION
	class FCNTL_ERROR : public std::exception
	{
		public:
		virtual const char *what(void) const throw();
	};
	class FD_ERROR : public std::exception
	{
		public:
		virtual const char *what(void) const throw();
	};
	class IP_ERROR : public std::exception
	{
		public:
		virtual const char *what(void) const throw();
	};
	class CONNECT_ERROR : public std::exception
	{
		public:
		virtual const char *what(void) const throw();
	};
	class READ_ERROR : public std::exception
	{
		public:
		virtual const char *what(void) const throw();
	};
	class SEND_ERROR : public std::exception
	{
		public:
		virtual const char *what(void) const throw();
	};
};
