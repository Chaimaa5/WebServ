#include "Webserv.hpp"
#include <iterator>
int main(int ar, char **av){
	if (ar != 2)
		return 0;
	Configuration config;
	std::vector<Server> servers = config.parser(av[1]);
	Socket socket;
	std::vector<int> ports;
	for (size_t i = 0; i < servers.size(); i++)
	{
		if (find(ports.begin(), ports.begin(), servers[i].GetPort()) == ports.end())
		{
			socket.SetPort(servers[i].GetPort());
			socket.SetHost(servers[i].GetHost());
			std::cout << socket.GetHost() << "  "<<socket.GetPort()<< std::endl;
		}
	}
	
}