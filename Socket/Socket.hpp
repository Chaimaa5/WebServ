#pragma once
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include "../Configuration/Server.hpp"
// #include <>
class Socket{
	private:
		struct sockaddr_in	serv_addr;
		std::string			host;
		size_t				port; 
		int					sockfd;
		int 				domain;
		int 				type;
		int 				address_len;
		int 				backlog;
		int 				protocol;

		//FD_SET FOR SELECT
		fd_set _readfds;
		// fd_set _writefds;
		// fd_set _errorfds;

	public:
		Socket();
		Socket(size_t port, std::string host);
		~Socket();
		Socket(const Socket &);
		Socket & operator=(const Socket &);

		//GETTERS
		size_t				GetPort();
		std::string			GetHost();
		int					GetDomain();
		int					GetType();
		int					GetAddressLen();
		int					GetBacklog();
		struct sockaddr_in	GetAddress();

		//SETTERS
		void	SetPort(size_t port);
		void	SetHost(std::string	 host);
		void	SetDomain(int domain);
		void	SetType(int type);
		void	SetProtocol(int protocol);
		void	SetBacklog(int backlog);
		void	SetAddressLen(int address_len);
		void	SetAddress(struct sockaddr_in address);

		//METHODS
		void SockCreate(Server server);
		void SockBind(Server server);
		void SockListen();
};