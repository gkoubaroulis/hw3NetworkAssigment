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


int main ()
{
 int sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd<0)
{
	printf("APOTYXIA DHMIOYRGEIAS SOCKET");
	exit(0);
}
 else printf("TO SOCKET DHMIOYRGHTHIKE ME EPITYXIA\n");
 struct sockaddr_in servaddr;
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr= inet_addr(IP);
servaddr.sin_port=htons(PORT);
char msg[]="hello server";
sendto(sockfd,(const char *)msg, strlen(msg),
MSG_CONFIRM,(const struct sockaddr*)&servaddr,
sizeof(servaddr));
printf("%s\n",msg);
int len;
char buff[MAX];
int n=recvfrom(sockfd,(char*)buff,MAXLINE,
MSG_WAITALL,(struct sockaddr*) &servaddr,
(socklen_t*)&len);
buff[n]='\n';
printf("O DIAKOMISTHS ANTAPOKRITHIKE: %s\n",buff);
close (sockfd);
printf("H SYNDESH XATHIKE\n");
}
