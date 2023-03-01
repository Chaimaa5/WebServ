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

// std::vector<Server> Configuration::parser(const char *file_name){
// 	std::fstream file;
// 	file.open(file_name, std::ios::in);
// 	std::string line;
// 	Server server;
// 	if (file.is_open()){
// 		while (getline(file, line))
// 		{
// 			if (line.find("server") != std::string::npos)
// 			{
// 				if (line.find("port") != std::string::npos)
// 					server.SetPort(atoi(line.substr(line.find("port") + 5).c_str()));
// 				if (line.find("host") != std::string::npos)
// 					server.SetHost(line.substr(line.find("host") + 5));
// 				if (line.find("server_name") != std::string::npos)
// 					server.SetServerName(line.substr(line.find("server_name") + 13));
// 				if (line.find("size_limit") != std::string::npos)
// 					server.SetSizeLimit(atoi(line.substr(line.find("size_limit")).c_str()));
// 				if (line.find("error_page") != std::string::npos)
// 					server.SetErrorPage(line.substr(line.find("error_page") + 11));
// 				if (line.find("location") != std::string::npos)
// 					server.SetLocation(ParseLocation());
// 			}
// 			servers.push_back(server);
// 		}
// 	}
// 	else
// 		std::cout << "file is corrupted" << std::endl;
// 	return servers;
// }

// std::vector<Server> Configuration::parser(const char *file_name){
// 	std::fstream file;
// 	file.open(file_name, std::ios::in);
// 	std::string line;
// 	Server server;
// 	size_t pv = 0;
// 	size_t cr;
// 	std::string key;
// 	std::string value;
// 	if (file.is_open()){
// 		while (getline(file, line))
// 		{
// 			if (line.find("server") != std::string::npos)
// 			{
// 				if ((cr = line.find_first_not_of(" \n\t", pv)) != std::string::npos)
// 					server.SetPort(atoi(line.substr(line.find("port") + 5).c_str()));
// 				// if (line.find("host") != std::string::npos)
// 				// 	server.SetHost(line.substr(line.find("host") + 5));
// 				// if (line.find("server_name") != std::string::npos)
// 				// 	server.SetServerName(line.substr(line.find("server_name") + 13));
// 				// if (line.find("size_limit") != std::string::npos)
// 				// 	server.SetSizeLimit(atoi(line.substr(line.find("size_limit")).c_str()));
// 				// if (line.find("error_page") != std::string::npos)
// 				// 	server.SetErrorPage(line.substr(line.find("error_page") + 11));
// 				// if (line.find("location") != std::string::npos)
// 				// 	server.SetLocation(ParseLocation());
// 			}
// 			servers.push_back(server);
// 		}
// 	}
// 	else
// 		std::cout << "file is corrupted" << std::endl;
// 	return servers;
// }

std::vector<Server> Configuration::parser(){
	Server server;
	size_t pv = 0;
	size_t cr = 0;
	std::string key;
	std::string value;
	pv = file_lines.find_first_not_of("server {");
	if (pv == std::string::npos)
		std::cout << "parsing error\n";
	else {
		while (cr != std::string::npos)
		{
			pv = file_lines.find_first_not_of(" \t\n",  pv);
			std::cout <<"--" <<key << " -- " << pv <<"--"<< std::endl;
			while ((file_lines.find_first_not_of("}", cr)) != std::string::npos)
			{
				if ((cr = file_lines.find_first_not_of(" \t", pv)) != std::string::npos)
					key = file_lines.substr(pv, cr);
					std::cout <<"cr" << file_lines[cr]<<  std::endl;
				if ((pv = file_lines.find_first_not_of("\n", cr)) != std::string::npos)
					value = file_lines.substr(cr, pv);
				file_lines = file_lines.substr(pv, std::string::npos);
				set_server_key_value(server, key, value);
				std::cout <<"--" <<key << " -- " << value <<"--"<< std::endl;
			exit(0);
			}
			servers.push_back(server);
		}
	} 
	return servers;
}

void Configuration::set_server_key_value(Server server, std::string key, std::string value){
	if (key == "port")
		server.SetPort(atoi(value.c_str()));
	if (key == "host")
		server.SetHost(value);
	if (key == "server_name") 
		server.SetServerName(value);
	if (key == "size_limit")
		server.SetSizeLimit(atoi(value.c_str()));
	if (key == "error_page") 
		server.SetErrorPage(value);
	if (key == "location") 
		server.SetLocation(ParseLocation());
}
std::vector<Location> Configuration::ParseLocation(){
	return locations;
}