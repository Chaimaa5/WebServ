#pragma once
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
class Socket{
	private:
		size_t host;
		size_t port; 
		int domain;
		int type;
		int address_len;
		int backlog;
		int protocol;
		struct sockaddr_in address;

	public:
		Socket();
		~Socket();
		Socket(const Socket &);
		Socket & operator=(const Socket &);
		size_t	GetPort();
		size_t	GetHost();
		int		GetDomain();
		int		GetType();
		int		GetAddressLen();
		int		GetBacklog();
		struct sockaddr_in GetAddress();

		void	SetPort(size_t port);
		void	SetHost(size_t host);
		void	SetDomain(int domain);
		void	SetType(int type);
		void	SetProtocol(int protocol);
		void	SetBacklog(int backlog);
		void	SetAddressLen(int address_len);
		void	SetAddress(struct sockaddr_in address);
};