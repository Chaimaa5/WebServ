#pragma once
#include <iostream>
class Server{
	private:
		int 		port;
		std::string host;
		std::string server_name;
		int 		size_limit;
		std::string error_page;
		std::string location;
		std::string methods;
		std::string root;
		bool 		autoindex;
	public:
		//CTORS
		Server();
		~Server();
		Server(const Server & S);
		Server &operator=(const Server & S);

		//Getter
		int 		GetPort();
		int 		GetSizeLimit();
		bool 		GetAutoIndex();
		std::string GetHost();
		std::string GetServerName();
		std::string GetErrorPage();
		std::string GetLocation();
		std::string GetMethods();
		std::string GetRoot();

		//SETTERS;
		void SetPort(int port);
		void SetSizeLimit(int size_limit);
		void SetAutoIndex(bool autoindex);
		void SetHost(std::string host);
		void SetServerName(std::string server_name);
		void SetErrorPage(std::string error_page);
		void SetLocation(std::string location);
		void SetMethods(std::string methods);
		void SetRoot(std::string root);



};