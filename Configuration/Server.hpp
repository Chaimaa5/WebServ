#include "Configuration.hpp"
#include <vector>
#include <fstream>
class Server{
	private:
		std::vector<Configuration>  server_config;
	public:
		Server();
		~Server();
		Server(const Server & S);
		Server &operator=(const Server & S);

		//Getter
		std::vector<Configuration> GetServerConfig();

		//METHODS
		void parser(std::fstream & file);


};