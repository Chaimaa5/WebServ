#include "Configuration.hpp"

//CTORS
Configuration::Configuration(){

}
Configuration::Configuration(const Configuration & C){
	*this = C;
}
Configuration & Configuration::operator=(const Configuration & C){
	this->servers = C.servers;
	return *this;
}
Configuration::~Configuration(){

}

// //GETTERS
// std::vector<Server> Configuration::GetServer(){
// 	return server;
// }
//METHODS
void Configuration::read_file(const char *file_name){
	std::fstream file;
	file.open(file_name, std::ios::in);
	std::string line;
	if (file.is_open()){
		while (getline(file, line))
			file_lines.append(line + '\n');	}
	else
		std::cout << "file is corrupted" << std::endl;
}

std::vector<Server> Configuration::parser(){
	
	return servers;
}