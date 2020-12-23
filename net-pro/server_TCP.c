#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdlib.h> 

#define MAX 80
#define PORT 4045
#define SA struct sockaddr

int main ()
{ 
  //int connfd.len;
  //struct sockaddr_in r;
  //struct sockaddr_in cli;

int sockfd = socket(AF_INET, SOCK_STREAM,0);
if (sockfd==-1)
{
   printf("APOTYXIA DHMIOYRGEIAS SOCKET");
   exit(0);
}
else printf("TO SOCKET DHMIOYRGHTHIKE ME EPITYXIA\n");
struct sockaddr_in servaddr;
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family= AF_INET;
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
servaddr.sin_port= htons(PORT);
if((bind(sockfd, (struct sockaddr*)&servaddr , sizeof(servaddr)))!=0)
{
	printf("H DESMEFSI TOY SOCKET APETYXE\n");
	exit(0);
}
else
	printf("EPITYXHMENH DESMEYSH SOCKET\n");
if ((listen(sockfd,5))!=0)
{ 
	printf("DEN AKOYEI...\n");
	exit(0);
}
else printf("O DIAKOMISTHS AKOYEI...\n");
struct sockaddr_in cli;
int len= sizeof(cli);
int new_socket = accept(sockfd,(struct sockaddr*)&cli,(socklen_t*) &len);
if(new_socket <0)
{
	printf("APOTYXIA SYNDESHS ME DIAKOMISTH\n");
	exit(0);
}
	else 
{
	printf("\n NEOS PELATHS SYNDETHIKE\n");
	char buff[]="hello client";
	write(new_socket, &buff,sizeof(buff));
	printf("%s\n", buff);
}
	close(sockfd);
printf("H SYNDESH XATHIKE\n"); 
}
