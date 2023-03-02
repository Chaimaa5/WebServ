#include "Server.hpp"

//CTORS
Server::Server(){

}
Server::~Server(){

}
Server::Server(const Server & S){
	*this = S;
}
Server  & Server::operator=(const Server & S){
	// this->server_config = S.server_config;
	this->port = S.port;
	this->size_limit = S.size_limit;
	this->host = S.host;
	this->server_name = S.server_name;
	this->error_page = S.error_page;
	this->location = S.location;
	return *this;
}

//GETTERS
// std::vector<Configuration> Server::GetServerConfig(){
// 	return server_config;
// }

int 					Server::GetPort(){return port;}
int 					Server::GetSizeLimit(){return size_limit;}
std::string 			Server::GetHost(){return host;}
std::string 			Server::GetServerName(){return server_name;}
std::string 			Server::GetErrorPage(){return error_page;}
std::vector<Location>	Server::GetLocation(){return location;}

//SETTERS;
void Server::SetPort(int port){this->port = port;}
void Server::SetSizeLimit(int size_limit){this->size_limit = size_limit;}
void Server::SetHost(std::string host){this->host = host;}
void Server::SetServerName(std::string server_name){this->server_name = server_name;}
void Server::SetErrorPage(std::string error_page){this->error_page = error_page;}
void Server::SetLocation(std::vector<Location> location){this->location = location;
	// std::cout << "location[1].GetPath()";
}

