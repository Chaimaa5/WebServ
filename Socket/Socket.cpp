#include "Socket.hpp"

//CTORS
Socket::Socket(){}
Socket::~Socket(){}
Socket::Socket(const Socket & S){
	*this = S;
}
Socket & Socket::operator=(const Socket & S){
	this->port = S.port;
	this->host = S.host;
	this->domain = S.domain;
	this->type = S.type;
	this->backlog = S.backlog;
	this->address_len = S.address_len;
	this->address = S.address;
	return (*this);
}

//GETTERS
size_t	Socket::GetPort(){return port;}
std::string		Socket::GetHost(){return host;}
int		Socket::GetDomain(){return domain;}
int		Socket::GetType(){return type;}
int		Socket::GetAddressLen(){return address_len;}
int		Socket::GetBacklog(){return backlog;}
struct sockaddr_in Socket::GetAddress(){return address;}

//SETTERS
void	Socket::SetPort(size_t port){this->port = port;}
void	Socket::SetHost(std::string	 host){this->host = host;}
void	Socket::SetDomain(int domain){this->domain = domain;}
void	Socket::SetType(int type){this->type = type;}
void	Socket::SetProtocol(int protocol){this->protocol = protocol;}
void	Socket::SetBacklog(int backlog){this->backlog = backlog;}
void	Socket::SetAddressLen(int address_len){this->address_len = address_len;}
void	Socket::SetAddress(struct sockaddr_in address){this->address = address;}