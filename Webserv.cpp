#include "Webserv.hpp"

int main(int ar, char **av){
	if (ar != 2)
		return 0;
						std::cout << "here";

	Configuration config;
	config.read_file(av[1]);
	std::vector<Server> servers = config.parser();
}