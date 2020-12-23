#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <sys/types.h>
#define MAX 80
#define PORT 4045
#define IP "127.0.0.1"
#define MAXLINE 1024
#define SA struct sockaddr 


int main ()
{
 int sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd==-1)
{
	printf("APOTYXIA DHMIOYRGEIAS SOCKET");
	exit(0);
}
 else printf("TO SOCKET DHMIOYRGHTHIKE ME EPITYXIA\n");
 struct sockaddr_in servaddr;
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(PORT);
if((bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr)))!=0)
{ 
	printf("H DESMEFSI TOY SOCKET APETYXE\n");
	exit(0);
}
else printf("EPITYXHMENH DESMEYSH SOCKET\n");
struct sockaddr_in cli;
int len=sizeof(cli);
char buff[MAX];
int n=recvfrom(sockfd, (char *)buff, MAXLINE,
MSG_WAITALL, (struct sockaddr* ) &cli,
(socklen_t*) &len);
buff[n]='\0';
printf(";\n NEOS PELATHS SYNDETHIKE: %s\n",buff);
char msg[]=" hello client";
sendto(sockfd,(const char*)msg,strlen(msg),
MSG_CONFIRM,( const struct sockaddr*)&cli,
len);
printf("%s\n",msg);
close(sockfd);
printf(" H SYNDESH XATHIKE\n");
}

