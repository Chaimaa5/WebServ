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

std::vector<Server> Configuration::parser(const char *file_name){
	std::fstream file;
	file.open(file_name, std::ios::in);
	std::string line;
	Server server;
	if (file.is_open()){
		while (getline(file, line))
		{
			if (line.find("server") != std::string::npos)
			{
				if (line.find("port") != std::string::npos)
					server.SetPort(atoi(line.substr(line.find("port") + 5).c_str()));
				if (line.find("host") != std::string::npos)
					server.SetHost(line.substr(line.find("host") + 5));
				if (line.find("server_name") != std::string::npos)
					server.SetServerName(line.substr(line.find("server_name") + 13));
				if (line.find("size_limit") != std::string::npos)
					server.SetSizeLimit(atoi(line.substr(line.find("size_limit")).c_str()));
				if (line.find("error_page") != std::string::npos)
					server.SetErrorPage(line.substr(line.find("error_page") + 11));
				if (line.find("location") != std::string::npos)
					server.SetLocation(ParseLocation());
			}
			servers.push_back(server);
		}
	}
	else
		std::cout << "file is corrupted" << std::endl;
	return servers;
}

std::vector<Location> Configuration::ParseLocation(){
	return locations;
}