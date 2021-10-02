#include "include_server.h"

int main()
{

	int socket_server, socket_cliens, addrlen;
	char buffer[80];
	struct sockaddr_in address;
	
	printf("Kapcsolat aktív. \n");

	socket_server = socket(AF_INET, SOCK_STREAM, 0);

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(15000);

	bind(socket_server, (struct sockaddr *) &address, sizeof(address));

	listen(socket_server, 20);

	addrlen = sizeof(struct sockaddr_in);
	socket_cliens = accept(socket_server, (struct sockaddr *) & address, &addrlen);

	while(1){
		recv(socket_cliens, buffer, 10, 0);
		printf("[+] Kliens-tol: %s\n", buffer);
		send(socket_cliens, "Server oldalrol: ", 10, 0);
		send(socket_cliens, buffer, 10, 0);
		//send(socket_cliens, "\n", 10, 0);
		sleep(1);
	}

	printf("[+] Server leall...");
	sleep(5);

	close(socket_cliens);
	close(socket_server);

	return 0;
}