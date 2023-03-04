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

// void Socket::create(){
// 	if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 1)
// 		throw("Failed to creat socket");
// 	//Check non-blocking socket/ set the created socket to non-blocking mode   with SO_REUSEADDR
// 	// set socket option to allow multiple connections
// 	// setsocketopt();
// 	// FD_SET(_socket_fd, &_readfds) is used to add the socket file descriptor 
// 	// to a set of file descriptors to monitor for I/O readiness. 
// 	// This is typically done so that the program can wait for 
// 	// incoming data or connections on the socket using a function like select() or poll().
// 	address.sin_family = AF_INET; 
// 	// bind the socket to a port
// 	// By calling the bind() function, the socket is associated with a specific IP address and port number. 
// 	// listen for incomming connections
// }

// void Socket::bind_sock(){
// 	address.sin_port = htons(server.GetPort());
// 	address.sin_addr.s_addr = inet_addr(server.GetHost().c_str());
// 	if (bind(fd, &address, sizeof(address)) < 0)
// 		throw "failed to bind socket";

// }