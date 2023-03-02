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

std::vector<Server>  Configuration::parser(const char *file_name){
	std::fstream file;
	file.open(file_name, std::ios::in);
	std::string line;
	std::string key;
	std::string value;
	if (file.is_open()){
		Server server;
		Location location;
		while (getline(file, line))
		{
			line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
			size_t sep = line.find('=');
			key = line.substr(0, sep);
			value = line.substr(sep+1, std::string::npos);
			if (key == "location")
			{
				location.SetPath(value);
				while (getline(file, line) && key != "]")
				{
					line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
					size_t sep = line.find('=');
					key = line.substr(0, sep);
					value = line.substr(sep+1, std::string::npos);
					if (key == "root")
						location.SetRoot(value);
					if (key == "index") 
						location.SetIndex(value);
					if (key == "methods")
						location.SetMethods(value);
					if (key == "autoindex") 
						location.SetAutoIndex(value);
					// parse_location_key_value(location, key, value);
				}
				locations.push_back(location);
				server.SetLocation(locations);
			}
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
			else if (!line.find("}"))
				servers.push_back(server);
			// parse_server_key_value(server, key, value);
		}
	}
	else
		std::cout << "file is corrupted" << std::endl;
	return servers;
}

void Configuration::parse_location_key_value(Location location, std::string key, std::string value){
	if (key == "root")
		location.SetRoot(value);
	if (key == "index") 
		location.SetIndex(value);
	if (key == "methods")
		location.SetMethods(value);
	if (key == "autoindex") 
		location.SetAutoIndex(value);
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
}