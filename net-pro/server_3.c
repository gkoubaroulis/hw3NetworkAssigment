#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define maxlenrcv 2014
int main(){

int port;
printf("DOSE MOY THN PORTA:");
scanf("%d",&port);

char  ip[15];
printf("DOSE MOY THN IP:");
scanf("%s",ip);


	int sockfd, ret;
	 struct sockaddr_in serverAddr;

	int newSocket;
	struct sockaddr_in newAddr;

	socklen_t addr_size;

	char buffer[1024];
	pid_t childpid;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
		printf("PROVLIMA STHN SYNDESH.\n");
		exit(1);
	}
	printf("EPITYXHMENH DHMIOYRGEIA SOCKET.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(port);
	serverAddr.sin_addr.s_addr = inet_addr(ip);

	ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("LATHOS STHN DESMEYSH TOY SOCKET.\n");
		exit(1);
	}
	printf("DESMEYMENH PORTA %d\n", port);

	if(listen(sockfd, 10) == 0){
		printf("AKOYEI.\n");
	}else{
		printf("LATHOS.\n");
	}


	while(1){
		newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
		if(newSocket < 0){
			exit(1);
		}
		printf("H SYNDESH APODEXTHIKE APO  %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));

		if((childpid = fork()) == 0){
			close(sockfd);

			while(1){
				recv(newSocket, buffer, 1024, 0);
				if(strcmp(buffer, "exit\n") == 0){
					printf("APOSYNDESH APO %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
					break;
				}else{
					printf("MHNYMA PELATH APO THN DIEYTHINSI %d is: %s\n", ntohs(newAddr.sin_port), buffer);
					printf("MHNYMA STON PELATH:");
					//scanf("%s", buffer);
					fgets(buffer, 1024, stdin);
					send(newSocket, buffer, strlen(buffer), 0);
					memset(buffer,'\0', sizeof(buffer));
				}
			}
		}

	}

	close(newSocket);


	return 0;
}
