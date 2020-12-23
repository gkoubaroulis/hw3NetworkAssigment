#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define MAXRCVLEN 1024

int main(){


int port;
printf("DOSE MOY THN PORT:");
scanf("%d",&port);

char  ip[15];
printf("DOSE MOY THN IP:");
scanf("%s",ip);


	int clientSocket, ret;
	struct sockaddr_in serverAddr;
	char buffer[1024];

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(clientSocket < 0){
		printf("LATHOS STHN SYNDESH.\n");
		exit(1);
	}
	printf("EPITYXHMENH DHMIOYRGIA SOCKET.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(port);
	serverAddr.sin_addr.s_addr = inet_addr(ip);

	ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("Connection Error.\n");
		exit(1);
	}
	printf("LATHOS STHN SYNDESH.\n");

	while(1){
		memset(buffer,'\0', sizeof(buffer));		
		printf("Client: \t");
		fgets(buffer, 1024, stdin);		
		//scanf("%s", buffer);
		//scanf("%s", &buffer[0]);
		send(clientSocket, buffer, strlen(buffer), 0);

		if(strcmp(buffer, "exit\n") == 0){
			close(clientSocket);
			printf("APOSYNDESH APO TO DIAKOMISTH.\n");
			send(clientSocket, buffer, strlen(buffer), 0);
			exit(1);
		}

		if(recv(clientSocket, buffer, 1024, 0) < 0){
			printf("LATHOS STHN EPIKOINWNIA\n");
		}else{
			printf("DIAKOMISTHS: \t%s\n", buffer);
		}
	}

	return 0;
}

