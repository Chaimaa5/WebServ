#pragma once
#include "Socket.hpp"
class Manager{
	private:
		std::vector<Socket> socket;
		std::vector<int>	fd;
		//FD_SET FOR SELECT
		fd_set _readfds;
		fd_set _writefds;
		fd_set _tmpreadfds;
		// fd_set _tmpwritefds;
		fd_set _errorfds;
	public:
		//CTORS
		Manager();
		~Manager();
		Manager(const Manager &);
		Manager & operator=(const Manager &);

		//GETTRES
		std::vector<Socket> GetSocket();

		//SETERS
		void SetSocket(std::vector<Socket> socket);

		//METHODS
		void Start(std::vector<Server> servers);
		void Accepter();
};