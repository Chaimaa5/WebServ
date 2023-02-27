#pragma once
#include <iostream>
class Location{
	private:
		std::string path;
		std::string root;
		std::string index;
		std::string methods;
		bool 		autoindex;
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
		std::string GetMethods();
		bool 		GetAutoIndex();
		//SETTERS
		void SetPath(std::string path);
		void SetRoot(std::string root);
		void SetIndex(std::string index);
		void SetMethods(std::string methods);
		void SetAutoIndex(bool autoindex);
};