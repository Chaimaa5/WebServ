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
		void read_file(const char *);
		std::vector<Server> parser(const char *file_name);
		std::vector<Location> ParseLocation();
};