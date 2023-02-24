#include "Server.hpp"

Server::Server(){

}
Server::~Server(){

}
Server::Server(const Server & S){
	*this = S;
}
Server  & Server::operator=(const Server & S){
	this->server_config = S.server_config;
	return *this;
}

//Getter
std::vector<Configuration> Server::GetServerConfig(){
	return server_config;
}

//PARSING

void Server::parser(std::fstream & file){
	std::string line;
	while (getline(file, line))
		std::cout << line << std::endl;
}