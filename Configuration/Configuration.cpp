#include "Configuration.hpp"

Configuration::Configuration(const Configuration & C){
	*this = C;
}
Configuration & Configuration::operator=(const Configuration & C){
	this->port = C.port;
	this->size_limit = C.size_limit;
	this->autoindex = C.autoindex;
	this->host = C.host;
	this->server_name = C.server_name;
	this->error_page = C.error_page;
	this->location = C.location;
	this->methods = C.methods;
	this->root = C.root;
	return *this;
}
Configuration::~Configuration(){

}
//GETTERS
int 		Configuration::GetPort(){return port;}
int 		Configuration::GetSizeLimit(){return size_limit;}
bool 		Configuration::GetAutoIndex(){return autoindex;}
std::string Configuration::GetHost(){return host;}
std::string Configuration::GetServerName(){return server_name;}
std::string Configuration::GetErrorPage(){return error_page;}
std::string Configuration::GetLocation(){return location;}
std::string Configuration::GetMethods(){return methods;}
std::string Configuration::GetRoot(){return root;}

//SETTERS;
void Configuration::SetPort(int port){this->port = port;}
void Configuration::SetSizeLimit(int size_limit){this->size_limit = size_limit;}
void Configuration::SetAutoIndex(bool autoindex){this->autoindex = autoindex;}
void Configuration::SetHost(std::string host){this->host = host;}
void Configuration::SetServerName(std::string server_name){this->server_name = server_name;}
void Configuration::SetErrorPage(std::string error_page){this->error_page = error_page;}
void Configuration::SetLocation(std::string location){this->location = location;}
void Configuration::SetMethods(std::string methods){this->methods = methods;}
void Configuration::SetRoot(std::string root){this->root = root;}