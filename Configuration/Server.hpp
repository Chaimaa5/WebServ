#pragma once
#include "Location.hpp"
#include <iostream>
#include <vector>
class Server{
	private:
		size_t 					port;
		int 					size_limit;
		std::string 			host;
		std::string 			server_name;
		std::string 			error_page;
	public:
		std::vector<Location>	location;
		//CTORS
		Server();
		~Server();
		Server(const Server & S);
		Server &operator=(const Server & S);

		//Getter
		size_t 					GetPort();
		int 					GetSizeLimit();
		std::string 			GetHost();
		std::string 			GetServerName();
		std::string 			GetErrorPage();
		std::vector<Location>	GetLocation();
		

		//SETTERS;
		void SetPort(size_t port);
		void SetSizeLimit(int size_limit);
		void SetHost(std::string host);
		void SetServerName(std::string server_name);
		void SetErrorPage(std::string error_page);
		void SetLocation(std::vector<Location> location);
		



};