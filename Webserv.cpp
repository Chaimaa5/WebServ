#include "Webserv.hpp"

int main(int ar, char **av){
	if (ar != 2)
		return 0;
	Configuration config;
	std::vector<Server> servers = config.parser(av[1]);
}