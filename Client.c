#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <pwd.h>
#include <stdlib.h>
#include <netdb.h>
int main(int argc, char* argv[]){
	//création de la socket
	int s = socket(AF_INET, SOCK_STREAM, 0);
	//création de la structure pour avoir les infos du serveur
	struct hostent* server;
	//création de la structure de la connexion
	struct sockaddr_in address;
	address.sin_port = htons(8080);
	address.sin_family = AF_INET;
	//L'adresse du serveur en argument
	server = gethostbyname(argv[1]);
	//vérification de l'existence de l'argument qui contient l'adresse ip du serveur
	if(server == NULL){
		fprintf(stderr, "Pas d'hôte spécifié.\n");
		exit(0);
	}
	//collecte des informations de la structure de l'adresse du serveur
	bcopy((char *) server -> h_addr, (char *) &address.sin_addr.s_addr, server ->
	h_length);
	//bindage de la connexion avec la socket
	int b = connect(s, (struct sockaddr *) &address, sizeof(address));
	//Commence la connexion avec le client
	char buf[255];
	//input de l'utilisateur qu'on veut avoir son mot de passe
	printf("Entrer l'utilisateur: ");
	scanf("%s", buf);

	//envoie le login qu'on veut sur le buffer du socket
	write(s, &buf, sizeof(buf));
	char msg[256];
	//lit les resultats de la socket
	read(s, &msg, sizeof(msg));
	printf("le mot de passe voulu est: %s\n\n", msg);
	//fermeture de la socket
	close(s);
	return 0;
}