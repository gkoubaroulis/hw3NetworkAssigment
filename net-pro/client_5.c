
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4045

int main(){

	int clientSocket, ret;
	struct sockaddr_in serverAddr;
	char buffer[1024];

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(clientSocket < 0){
		printf("Apotyxia syndesis.\n");
		exit(1);
	}
	printf(" To Socket dimiourgithike me epitixia.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("Lathos stin syndesi.\n");
		exit(1);
	}
	printf("O diakomistis einai syndedemenos.\n");

	while(1){
		printf("Peite to mynhma sas: \t");
		scanf("%s", &buffer[0]);
		send(clientSocket, buffer, strlen(buffer), 0);

		if(strcmp(buffer, "exit\n") == 0)
		{
			close(clientSocket);
			printf(buffer,"O diakomistis aposyndethike\n");
		        send(clientSocket ,buffer,strlen(buffer),0);
			exit(1);
		}

		if(recv(clientSocket, buffer, 1024, 0) < 0){
			printf("Provlima stin epikoinwnia\n");
		}else{
			printf("Diakomistis: \t%s\n", buffer);
		}
	}

	return 0;
} 
