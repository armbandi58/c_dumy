#include "include_server.h"

#define IP_Address "127.0.0.1"
#define Size_buffer 1024
#define PORT 15000

int main()
{
	int socket_00;
	char buffer[80];
	struct sockaddr_in address;

	printf("[+] Kliens elindult.\n");

	socket_00 = socket(AF_INET, SOCK_STREAM, 0);

	address.sin_family = AF_INET;
	address.sin_port = htons(PORT);
	inet_pton(AF_INET, IP_Address, &address.sin_addr);

	connect(socket_00,(struct sockaddr *)&address, sizeof(address));

	strcpy(buffer, "Client00.\n");

	send(socket_00, buffer, 20, 0);

	recv(socket_00, buffer, Size_buffer, 0);
	printf("%s", buffer);

	close(socket_00);
	printf("Client end\n");

	return 0;
}