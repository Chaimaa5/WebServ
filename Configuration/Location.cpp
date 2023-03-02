#include "Location.hpp"

//CTORS
Location::Location(){

}
Location::~Location(){

}
Location::Location(const Location & L){
	*this = L;
}
Location  & Location::operator=(const Location & L){
	this->autoindex = L.autoindex;
	this->methods = L.methods;
	this->root = L.root;
	return *this;
}

//GETTERS
std::string Location::GetPath(){return path;}
std::string Location::GetRoot(){return root;}
std::string Location::GetIndex(){return index;}
std::vector<std::string> Location::GetMethods(){return methods;}
bool 		Location::GetAutoIndex(){return autoindex;}

//SETTERS;
void Location::SetRoot(std::string root){this->root = root;}
void Location::SetPath(std::string path){this->path = path;}
void Location::SetIndex(std::string index){this->index = index;}
void Location::SetMethods(std::string methods){
	if (methods.find("GET"))
		this->methods.push_back("GET");
	if (methods.find("POST"))
		this->methods.push_back("POST");
	if (methods.find("DELETE"))
		this->methods.push_back("DELETE");
}
void Location::SetAutoIndex(std::string autoindex){
	if (autoindex == "on")
		this->autoindex = 1;
	else
		this->autoindex = 0;
	}

