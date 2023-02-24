#include "Server.hpp"

Server::~Server(){

}
Server::Server(const Server & S){
	*this = S;
}
Server  Server::operator=(const Server & S){
	this->server_config = S.server_config;
}

//Getter
std::vector<Configuration> Server::GetServerConfig(){
	return server_config;
}