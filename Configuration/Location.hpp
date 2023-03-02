#pragma once
#include <iostream>
#include <vector>
class Location{
	private:
		std::string path;
		std::string root;
		std::string index;
		bool 		autoindex;
		std::vector<std::string> methods;
	public:
		//CTORS;
		Location();
		~Location();
		Location(const Location & L);
		Location & operator=(const Location & L);

		//GETTERS
		std::string GetPath();
		std::string GetRoot();
		std::string GetIndex();
		std::vector<std::string> GetMethods();
		bool 		GetAutoIndex();
		//SETTERS
		void SetPath(std::string path);
		void SetRoot(std::string root);
		void SetIndex(std::string index);
		void SetMethods(std::string methods);
		void SetAutoIndex(std::string autoindex);
};