#pragma once
#include "Server.hpp"
#include <iostream>
#include <fstream>
#include <vector>


class Configuration{
	private:
		std::string file_lines;
		std::vector<Server>  server;
	public:
		//CTORS
		Configuration();
		Configuration(const Configuration & C);
		Configuration & operator=(const Configuration & C);
		~Configuration();

		//GETTERS
		std::vector<Server> GetServer();

		//METHODS
		void read_file(const char *);
};