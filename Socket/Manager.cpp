#include "Manager.hpp"

//CTORS
Manager::Manager(){}
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
		}
		ports.push_back(port);
	}
}

void Manager::Accepter(){}


