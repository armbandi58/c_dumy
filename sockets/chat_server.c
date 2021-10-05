
#include "chat_include.h"
/*
#define PORT 15000
#define Size_buffer 80

void func_server(int sock);

int main(int argc, char *argv[])
{
	int socket_server, length, socket_accept;
	struct sockaddr_in address_server, cli;

	if(argc > 1){
		printf("...\n");
	}else{
		printf("[+] Nincs bemeneti parameter.\n");
	}

	socket_server = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_server == -1){
		printf("[-] Sikertelen socket létrehozás.\n");
		exit(-1);
	}else{
		printf("[+] Sikeres socket létrehozás.\n");
		//exit(-1);
	}
	//törlés, nullázás
	bzero(&address_server, sizeof(address_server));

	address_server.sin_family = AF_INET;
	address_server.sin_port = htons(PORT);
	address_server.sin_addr.s_addr = INADDR_ANY;

	if(bind(socket_server, (struct sockaddr*)&address_server, sizeof(address_server)) != 0){
		printf("[-] Sikertelen bind.\n");
		exit(-1);
	}else{
		printf("[+] Sikeres bind.\n");
	}


	if((listen(socket_server, 5)) != 0){
		printf("[-] Listazas sikertelen.\n");
		exit(-1);
	}else{
		printf("[+] Listazas sikeres.\n");
	}
	
	length = sizeof(cli);
	

	socket_accept = accept(socket_server, (struct sockaddr*)&cli, &length);
	if(socket_accept < 0){
		printf("[-] Sikertelen csatlakozás.\n");
		exit(-1);
	}else{
		printf("[+] Sikeres csatlakozás.\n");
	}

	func_server(socket_accept);

	close(socket_server);
	printf("[+] Server leáll.\n");
	return 0;
}

void func_server(int sock){
	printf("[+] Server funkció elindult.\n");

	char buffer[Size_buffer];
	u32 n;

	while(1){
		//printf("Na mehet");
		//nullazuk a buffert
		bzero(buffer, Size_buffer);

		read(sock, buffer, sizeof(buffer));
		printf("Kliens: %s\n", buffer);
		bzero(buffer, Size_buffer);
		n = 0;
		while(buffer[n] != '\n'){
			buffer[n] = getchar();
			n++;
		}

		write(sock, buffer, sizeof(buffer));
		if (strncmp("exit", buffer, 4) == 0) {
        	printf("Server Exit...\n");
         	break;
        }
	}
	printf("[+] Server funkció leáll...\n");
}
*/

#define MAX 80
#define PORT 15000
#define SA struct sockaddr
   
// Function designed for chat between client and server.
void func(int sockfd)
{
    char buff[MAX];
    int n;
    // infinite loop for chat
    for (;;) {
        bzero(buff, MAX);
   
        // read the message from client and copy it in buffer
        read(sockfd, buff, sizeof(buff));
        // print buffer which contains the client contents
        printf("From client: %s\t To client : ", buff);
        bzero(buff, MAX);
        n = 0;
        // copy server message in the buffer
        while ((buff[n++] = getchar()) != '\n')
            ;
   
        // and send that buffer to client
        write(sockfd, buff, sizeof(buff));
   
        // if msg contains "Exit" then server exit and chat ended.
        if (strncmp("exit", buff, 4) == 0) {
            printf("Server Exit...\n");
            break;
        }
    }
}
   
// Driver function
int main()
{
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;
   
    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));
   
    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
   
    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");
   
    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");
    len = sizeof(cli);
   
    // Accept the data packet from client and verification
    connfd = accept(sockfd, (SA*)&cli, &len);
    if (connfd < 0) {
        printf("server accept failed...\n");
        exit(0);
    }
    else
        printf("server accept the client...\n");
   
    // Function for chatting between client and server
    func(connfd);
   
    // After chatting close the socket
    close(sockfd);
}





