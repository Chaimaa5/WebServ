#include "Webserv.hpp"
#include <iterator>
int main(int ar, char **av){
	if (ar != 2)
		return 0;
	Configuration config;
	std::vector<Server> servers = config.parser(av[1]);
	// std::cout << servers.size() <<std::endl;
	// for (size_t i = 0; i < 3; i++)
	// {
	// 	std::cout <<  "--- Server " << i << "---\n";
	// 	std::cout << servers[i].GetPort() << std::endl;
	// 	std::cout << servers[i].GetSizeLimit() << std::endl;
	// 	std::cout << servers[i].GetHost() << std::endl;
	// 	std::cout << servers[i].GetServerName() << std::endl;
	// 	std::cout << servers[i].GetErrorPage() << std::endl;
	// 	for(size_t z = 0; z < 3; z++)
	// 	{
	// 		std::vector<Location> location = servers[i].GetLocation();
	// 		std::cout <<  "    --- Location " << z << "---\n";
	// 		std::cout << location[z].GetPath() << std::endl;
		// 	std::cout << location[z].GetRoot() << std::endl;
		// 	std::cout << location[z].GetIndex() << std::endl;
		// 	std::cout << location[z].GetAutoIndex() << std::endl;
		// 	std::vector<std::string> methods = location[z].GetMethods();
		// 	for(size_t r = 0; r < methods.size() ; r++)
		// 	{
		// 		std::cout << methods[r] << std::endl;

			// }
	// 	}

	// }
	
}