#pragma once
#include "Server.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

class Configuration{
	private:
		std::string file_lines;
	public:
		//PUBLIC ATTRIBUTE
		std::vector<Server>  servers;
		std::vector<Location> locations;
		//CTORS
		Configuration();
		Configuration(const Configuration & C);
		Configuration & operator=(const Configuration & C);
		~Configuration();

		// //GETTERS
		// std::vector<Server> GetServer();

		//METHODS
		std::vector<Server> parser(const char *file_name);
		Server parse_server(size_t *start);

		void parse_server_key_value(Server server, std::string key, std::string value);
		void parse_location_key_value(Location location, std::string key, std::string value);
};