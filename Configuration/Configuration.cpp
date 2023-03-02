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
	cr = file_lines.find_first_not_of(" \n\t");

	if (cr == std::string::npos)
		std::cout << "parsing error\n";
	else {
		while (cr != std::string::npos)
		{
			pv = file_lines.find_first_not_of("\n", cr);
			cr = file_lines.find_first_not_of(" \n\t", pv);
			key = file_lines.substr(pv, cr - pv);
			if (key == "server")
				server = parse_server(&cr);
			servers.push_back(server);
		}
	} 
	return servers;
}

Server Configuration::parse_server(size_t *start)
{
	Server server;
	std::string key;
	std::string value;
	size_t key_start;
	size_t value_end;
	size_t pv  = file_lines.find_first_not_of("\n", *start);

	if (pv == std::string::npos ||  file_lines[pv] != '{')
		std::cout << "parse error\n";
	size_t cr = file_lines.find_first_not_of("\n", pv++);
	while(cr != std::string::npos){
		if ((pv  = file_lines.find_first_not_of("\n", cr)) == std::string::npos)
			std::cout << "parse error\n";
		key_start = pv;
		if ((cr = file_lines.find_first_not_of("\n", pv)) == std::string::npos)
			std::cout << "parse error\n";
		key = file_lines.substr(pv, cr - pv);
		if (key == "}")
		{
			*start = file_lines.find_first_not_of(pv, cr - pv);
			break;
		}
		else
		{
			value_end = file_lines.find_first_not_of(pv, cr - pv);
			value = file_lines.substr(pv, value_end - pv + key_start + 1);
			parse_server_key_value(server, key, value);
		}
	}
	return server;
}


std::vector<Location> Configuration::ParseLocation(){
	return locations;
}
void Configuration::parse_server_key_value(Server server, std::string key, std::string value){
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