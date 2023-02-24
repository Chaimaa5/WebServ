#include "Configuration.hpp"
#include <vector>

class Server{
	private:
		std::vector<Configuration>  server_config;
		//UNACCESSIBLE CTOR
		Server();
	public:
		~Server();
		Server(const Server & S);
		Server &operator=(const Server & S);

		//Getter
		std::vector<Configuration> GetServerConfig();


}