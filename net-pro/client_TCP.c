#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#define MAX 80
#define PORT 4045
#define IP "127.0.0.1"

int main ()
{
 int sockfd=socket(AF_INET,SOCK_STREAM,0);
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
printf("\n PROSPATHEIA SYNDESIS...\n");
if(connect(sockfd,(struct sockaddr*) &servaddr,sizeof(servaddr))<0)
{ 
	printf("\n APOTYXIA SYNDESHS ME TO DIAKOMISTH\n");
	exit(0);
}
else
{
printf("SYNDEDEMENO\n");
char buff[MAX];
read(sockfd,buff,sizeof(buff));
printf("\n O DIAKOMISTHS LEEI %s\n",buff  );
}
close(sockfd);
printf("H SYNDESH XATHIKE\n");
}
