#include "Webserv.hpp"

int main(int ar, char **av){
	if (ar == 2)
	{
		std::string file_name = av[1];
		std::fstream file;
		file.open(file_name, std::ios::in);
		if (file.is_open()){
			Server server;
			server.parser(file);
		}
	}
	else
		std::cout << "Error: the program should enter an argument" << std::endl;	
}