#pragma once
#include "Socket.hpp"
class Manager{
	private:
		std::vector<Socket> socket;

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