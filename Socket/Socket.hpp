#pragma once
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../Configuration/Server.hpp"
// #include <>
class Socket{
	private:
		std::string			host;
		size_t				port; 
		int 				domain;
		int 				type;
		int 				backlog;
		int 				protocol;

	public:
		struct sockaddr_in	serv_addr;
		int 				addrlen;
		int					sockfd;
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
		int					GetSockFd();
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
		void	SetSockFd(int sockfd);

		//METHODS
		void SockCreate(Server server);
		void SockBind(Server server);
		void SockListen();
};