#include "Manager.hpp"

//CTORS
Manager::Manager(){
	FD_ZERO(&_readfds);
	FD_ZERO(&_writefds);
	FD_ZERO(&_errorfds);
}
Manager::~Manager(){}
Manager::Manager(const Manager &M){*this = M;}
Manager & Manager::operator=(const Manager &M){
	this->socket = M.socket;
	return (*this);	
}

//GETTRES
std::vector<Socket> Manager::GetSocket(){return socket;}

//SETERS
void Manager::SetSocket(std::vector<Socket> socket){this->socket = socket;}

//METHODS
void Manager::Start(std::vector<Server> servers){
	std::vector<size_t> ports;

	for (size_t i = 0; i < servers.size(); i++)
	{
		size_t port = servers[i].GetPort();
		if (find(ports.begin(), ports.end(), port) == ports.end())
		{
			Socket sock(port, servers[i].GetHost());
			sock.SockCreate(servers[i]);
			socket.push_back(sock);
			fd.push_back(sock.GetSockFd());
			FD_SET(sock.GetSockFd(), &_readfds) ;
		}
		ports.push_back(port);
	}
	Accepter();
}

void Manager::Accepter(){

	int new_socket;
	int res;
	while(1)
    {
		int sockfd = fd[fd.size() - 1];
		
		_tmpreadfds = _readfds;
		_tmpwritefds = _writefds;
		if ((res = select(sockfd + 1, &_tmpreadfds, NULL, NULL, 0)) < 0)
			std::cout << "select failed\n";
		if (FD_ISSET(sockfd, &_tmpreadfds)){
        	printf("\n+++++++ Waiting for new connection ++++++++\n\n");
			for (size_t i = 0; i < socket.size(); i++)
			{
				if ((new_socket = accept(sockfd, (struct sockaddr *)&socket[i].serv_addr, (socklen_t*)&socket[i].addrlen))<0)
				{
					std::cout << sockfd << std::endl;
					perror("In accept");
					exit(EXIT_FAILURE);
				}
				FD_SET(new_socket, &_tmpwritefds);
				FD_CLR(sockfd, &_tmpreadfds);
				char buffer[300000] = {0};
				recv( new_socket , buffer, 300000, MSG_DONTWAIT);
				printf("%s\n",buffer );
				close(new_socket);
			}
		}
		if (FD_ISSET(new_socket, &_tmpwritefds))
			write(new_socket, "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 20\n\nHello!", 68);
    }
}


