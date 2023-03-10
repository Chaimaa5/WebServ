#include "Socket.hpp"

//CTORS
Socket::Socket(){
	backlog = 10;
}
Socket::Socket(size_t port, std::string host): host(host), port(port) {
	// memset(&serv_addr, 0, sizeof(serv_addr));
	backlog = 10;
}
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
	this->addrlen = S.addrlen;
	this->serv_addr = S.serv_addr;
	return (*this);
}

//GETTERS
size_t				Socket::GetPort(){return port;}
std::string			Socket::GetHost(){return host;}
int					Socket::GetDomain(){return domain;}
int					Socket::GetType(){return type;}
int					Socket::GetAddressLen(){return addrlen;}
int					Socket::GetBacklog(){return backlog;}
struct sockaddr_in	Socket::GetAddress(){return serv_addr;}
int					Socket::GetSockFd(){return sockfd;}

//SETTERS
void	Socket::SetPort(size_t port){this->port = port;}
void	Socket::SetHost(std::string	 host){this->host = host;}
void	Socket::SetDomain(int domain){this->domain = domain;}
void	Socket::SetType(int type){this->type = type;}
void	Socket::SetProtocol(int protocol){this->protocol = protocol;}
void	Socket::SetBacklog(int backlog){this->backlog = backlog;}
void	Socket::SetAddressLen(int addrlen){this->addrlen = addrlen;}
void	Socket::SetAddress(struct sockaddr_in serv_addr){this->serv_addr = serv_addr;}
void	Socket::SetSockFd(int sockfd){this->sockfd = sockfd;}

void 	Socket::SockCreate(Server server){
	memset(&serv_addr, 0, sizeof(serv_addr));
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 1)
		std::cout <<"Failed to creat socket\n";
	//set the created socket to non-blocking mode  
	int flags = fcntl(sockfd, F_GETFL, 0);
	fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);

	//  we set optval to 1 for some socket options to enable them
	int optval = 1;
	// set socket option to allow multiple connections with SO_REUSEADDR
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0)
		perror("setsockopt");
	// is used to add the socket file descriptor 
	// to a set of file descriptors to monitor for I/O readiness. 
	// This is typically done so that the program can wait for 
	// incoming data or connections on the socket using a function like select() or poll().
	// (void)server;
	SockBind(server);
}

// By calling the bind() function, the socket is associated with a specific IP address and port number. 
// If you're binding to a privileged port (i.e., a port number less than or equal to 1024)
// you will need root privileges to bind to that port. You can either run the program as root, 
// or use a port number greater than 1024.

void Socket::SockBind(Server server){
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(server.GetPort());
	serv_addr.sin_addr.s_addr = inet_addr(server.GetHost().c_str());
	if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
	{
		perror("bind");
		std::cout << errno  << " "<<  server.GetHost() <<std::endl;
	}
	SockListen();
}

// listen for incomming connections
void Socket::SockListen(){
	if (listen(sockfd, backlog) < 0)
		std::cout << "Failed to listen to socket";
	std::cout << "socket is listening\n";
}













