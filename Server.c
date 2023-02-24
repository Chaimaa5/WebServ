#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <pwd.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
	int c;
	//déclaration de la socket
	int s = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in address, client; //déclaration de la structure d'adresses
	address.sin_port = htons(8080);
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_family = AF_INET;
	//déclaration de la structure de getpwnam
	struct passwd* pwd;

	//bindage de la connexion avec la socket
	int b = bind(s, (struct sockaddr *) &address, sizeof(address));
	//écoute de nouvelles connexions
	listen(s, 5);
	c = sizeof(struct sockaddr_in);
	//acceptation la connexion
	int acc = accept(s, (struct sockaddr *) &client, (socklen_t *) &c);
	//Commence la connexion avec le serveur
	char buf[256], intrus, msg[1024];
	printf("\n listening...\n");

	//lire le login qui est stocké sur le buffer de la socket
	read(acc, buf, sizeof(buf));
	//déclaration de la structure de l'adresse ip de l'intrus
	char *c_addr = inet_ntoa(client.sin_addr);

	//affiche le log des tentatives
	printf("user envoyé: %s \nL'adresse IP de l'intrus est: %s \n\n", buf, c_addr);
	//avoir le mot de passe du fichier /etc/passwd
	pwd = getpwnam(buf);
	//envoyer le résultat à l'intrus
	send(acc, pwd->pw_passwd, strlen(pwd->pw_passwd), 0);
	//fermeture de la socket
	close(s);
return 0;
}